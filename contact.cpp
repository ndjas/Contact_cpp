#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "contact.h"
#include "verification.h"
#include "lib/nlohmann/json.hpp"

using json = nlohmann::json;

static std::string const annuaire("./data/phonebook.json");



Contact::Contact(){

};
Contact::~Contact(){};

void Contact::setName(std::string name){
    this->name=name;
};
void Contact::setSurname(std::string surname){
    this->surname=name;
};
void Contact::setDate(std::string date){
    this->born_date=date;
};
void Contact::setPatronym(std::string patronym){
    this->patronym=patronym;
};
void Contact::setAddress(std::string address){
    this->address=address;
};
void Contact::setEmail(std::string email){
    this->email=email;
};
void Contact::setNumero(Numero numero){
    this->numero.push_back(numero);
}

void Contact::getContact(){
    std::cout<<this->address<<"#"<<this->name<<"#"<<this->numero[0].value<<std::endl;
}

void saveContact(Contact contact){

    std::ifstream contact_file(annuaire.c_str());
    if (!contact_file.is_open()) {
        std::cerr << "It's not possible to read the file" << std::endl;
        
    }

    
    json allContact = json::array();
  

    try {
        allContact = json::parse(contact_file);
    } catch (const json::parse_error& e) {
        std::cerr << "Erreur de parsing JSON: " << e.what() << std::endl;
        return;
    }
    contact_file.close();

    json nums_array = json::array();
    json nums_elmnt;
    json savedContact;

    std::vector<std::string> v_home; /*vector for group information*/
    std::vector<std::string> v_personnal;
    std::vector<std::string> v_work;



    savedContact["name"]=contact.name;
    savedContact["surname"]=contact.surname;
    savedContact["address"]=contact.address;
    savedContact["born_date"]=contact.born_date;
    savedContact["email"]=contact.email;

    for (int i = 0; i < contact.numero.size(); i++) {
        //json nums_elmnt;
        if(contact.numero[i].type == type_contact::personnal){
            v_personnal.push_back(contact.numero[i].value);

            //nums_elmnt["personnal"]=contact.numero[i].value;
        }
        else if(contact.numero[i].type == type_contact::home){
            v_home.push_back(contact.numero[i].value);
            //nums_elmnt["home"]=contact.numero[i].value;
        }else if(contact.numero[i].type == type_contact::work){
            v_work.push_back(contact.numero[i].value);
            //nums_elmnt["work"]=contact.numero[i].value;
        }else{

        }
        //nums_array.push_back(nums_elmnt);
    }   
    nums_elmnt["personnal"]=v_personnal;
    nums_elmnt["work"]=v_work;
    nums_elmnt["home"]=v_home;

    nums_array.push_back(nums_elmnt);

    savedContact["numero"]=nums_array;
    allContact.push_back(savedContact);

     // Affichage dans la console
    //std::cout << "=== OBJET PERSONNE ===" << std::endl;
    //std::cout << savedContact.dump(4) << std::endl;


    // Sauvegarde dans des fichiers
    try {
        // Fichier 1 : Données personnelles
        //std::ofstream contact_file("personne.json");
        std::ofstream contact_file(annuaire.c_str(), std::ios::trunc);
        contact_file << allContact.dump(4);  // Indentation de 4 espaces
        contact_file.close();
        
    } catch (const std::exception& e) {
        std::cerr << " Erreur lors de la sauvegarde : " << e.what() << std::endl;
        
    }









};

void newContact(){
    //std::ofstream myFlow(annuaire.c_str(), std::ios::app);

    std::string temp=""; //temporary variable
    char choice;
    Contact contact;
    Numero numero;
    numero.value="888374";
    numero.type=personnal;

    name:
    std::cout<<"enter the name"<<std::endl;
    std::cin >> temp;
    if(!isValidName(temp)){
        std::cout<<"The name isn't valid. please try again"<<std::endl;
        goto name;
    }
    else{
        contact.setName(temp);
    }

    surname:
    std::cout<<"enter the surname"<<std::endl;
    std::cin >> temp;
    if(!isValidName(temp)){
        std::cout<<"The surname isn't valid. please try again"<<std::endl;
        goto surname;
    }
    else{
        contact.setSurname(temp);
    }

    patronym:
    std::cout<<"do you want to add patronym y/n"<<std::endl;
    std::cin>>choice;
    if(choice=='y' || choice=='Y'){
        std::cout<<"enter the patronym"<<std::endl;
        std::cin >> temp;
        if(!isValidName(temp)){
            std::cout<<"The patronym isn't valid. please try again"<<std::endl;
            goto patronym;
        }
        else{
            contact.setPatronym(temp);
        }
    }else if(choice=='n' || choice=='N'){
        std::cout<<"patronym not saved!!"<<std::endl;

    }else{
        goto patronym;
    }

    address:
    std::cout<<"enter the address"<<std::endl;
    std::cin >> temp;
    if(!isValidName(temp)){
        std::cout<<"The address isn't valid. please try again"<<std::endl;
        goto address;
    }
    else{
        contact.setAddress(temp);
    }

    born_date:
    std::cout<<"enter the born date"<<std::endl;
    std::cin >> temp;
    if(!checkDate(temp)){
        std::cout<<"The born date isn't valid. please try again"<<std::endl;
        goto born_date;
    }
    else{
        contact.setDate(temp);
    }

   
    email:
    std::cout<<"enter the email"<<std::endl;
    std::cin >> temp;
    if(!isValidEmail(temp)){
        std::cout<<"The email isn't valid. please try again"<<std::endl;
        goto email;
    }
    else{
        contact.setEmail(temp);
    }

    numero:
    std::cout<<"enter the number"<<std::endl;
    std::cin >> temp;
    if(!isValidNumber(temp)){
        std::cout<<"the number isn't valid. please try again"<<std::endl;
        goto numero;
    }else{
        numero.value=temp;
    }
    numero_type:
    std::cout<<("which type of number it's \n 1- home \n 2- personnal \n 3- work ")<<std::endl;
    std::cin >> choice;
    if(choice == '1'){
        numero.type=home;
    }else if(choice == '2'){
        numero.type=personnal;
    }else if(choice == '3'){
        numero.type=work;
    }else{
        goto numero_type;
    }   
    contact.setNumero(numero);
    
    std::cout<<"do you want to add another number y/n"<<std::endl;
    std::cin>>choice;
    if(choice=='y' || choice=='Y'){
        goto numero;
    }else if(choice=='n' || choice=='N'){
        std::cout<<"process new number has been stopped!!"<<std::endl;

    }else{
        std::cout<<"process new number has been stopped!!"<<std::endl;
    }

    saveContact(contact);
    

    //contact.getContact();



}



