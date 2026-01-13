#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h> 
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



json loadFile(){

    std::ifstream contact_file(annuaire.c_str());
    //new line
    //json allContact;
    //fin
    if (!contact_file) {
        std::ofstream out(annuaire.c_str());
        out << "[]";
        return json::array();
        
    }
    if(contact_file.peek() == std::ifstream::traits_type::eof()){
        std::ofstream out(annuaire.c_str());
        out << "[]";

        return json::array();
    }
    
    json allContact;
        try {
        //allContact = json::parse(contact_file);
            contact_file >> allContact;
        
        } catch (const json::parse_error& e) {
                std::cerr << "Erreur de parsing JSON: " << e.what() << std::endl;
                std::ofstream out(annuaire.c_str());
                out << "[]";
                return json::array();
        
    }

    if(!allContact.is_array()){
        std::ofstream out(annuaire.c_str());
        out << "[]";
        return json::array();
    }
    

    
    //json allContact = json::array();
  

    //save to garanty the structur of []
    //contact_file.close();
    //std::ofstream out(annuaire.c_str());
    //out << allContact.dump(4);
    return allContact;

}


int getMaxId(){
    json allContact = loadFile();
    int maxId = 0; //just to initialize index to 1

    for(const auto& c : allContact){
        if(c.contains("id")){
            maxId = std::max(maxId, c["id"].get<int>());
        }
    }
    return maxId;
}


void saveContact(Contact contact){

    /*
    std::ifstream contact_file(annuaire.c_str());
    if (!contact_file.is_open()) {
        std::cerr << "It's not possible to read the file" << std::endl;
        
        
    }
*/
    
    json allContact = json::array();
    allContact= loadFile();
  
/*
    try {
        allContact = json::parse(contact_file);
    } catch (const json::parse_error& e) {
        std::cerr << "Erreur de parsing JSON: " << e.what() << std::endl;
        return;
    }
    contact_file.close();
*/
    json nums_array = json::array();
    json nums_elmnt;
    json savedContact;

    int id_max= getMaxId();

    //int id_nb_object= allContact.size();// number of objects
    int id_nb_object = id_max + 1;
    std::vector<std::string> v_home; /*vector for group information*/
    std::vector<std::string> v_personnal;
    std::vector<std::string> v_work;


    savedContact["id"]=id_nb_object;
    savedContact["name"]=contact.name;
    savedContact["surname"]=contact.surname;
    savedContact["patronym"]=contact.patronym;
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

void saveToFile(const json& j){

     try {
        // Fichier 1 : Données personnelles
        //std::ofstream contact_file("personne.json");
        std::ofstream contact_file(annuaire.c_str(), std::ios::trunc);
        contact_file << j.dump(4);  // Indentation de 4 espaces
        contact_file.close();
        
    } catch (const std::exception& e) {
        std::cerr << " Erreur lors de la sauvegarde : " << e.what() << std::endl;
        
    }

}

int findIndexWithId(const json& j, int id){
    for(size_t i = 0; i<j.size();++i){
        if(j[i].contains("id") && j[i]["id"]==id){
            return i;
        }
    }
    return -1; // id not find
}
void modifyContact(int id){

    json allContact = json::array();
    allContact=loadFile();

    Contact tel;
    json nums_array = json::array();
    json nums_elmnt;

    std::vector<std::string> v_home; /*vector for group information*/
    std::vector<std::string> v_personnal;
    std::vector<std::string> v_work;

    int choice_modif;
    std::string temp;
    int index= findIndexWithId(allContact, id);
    if(index == -1){
        std::cerr << "id isn't find ! "<<std::endl;
        return;
    }

    std::cout<<"what do you whant to modify?"<<std::endl;
    std::cout<<"1-name\n2-surname\n3-adress\n4-email\n5-number\n6-born-date\n7-patronym"<<std::endl;
    std::cout<<"*************\n"<<std::endl;
    std::cin>>choice_modif;

    if(choice_modif==1){
        std::cout<<"enter new name"<<std::endl;
        std::cin>>temp;
        if(!isValidName(temp)){
            std::cerr<<"the name is not valid! \n end of the process!!!"<<std::endl;
            exit(EXIT_FAILURE);
        }else{
            allContact[index]["name"]=temp;
        
        }
        
    }else if(choice_modif == 2){
        std::cout<<"enter new surname"<<std::endl;
        std::cin>>temp;
        if(!isValidName(temp)){
            std::cerr<<"the surname is not valid! \n end of the process!!!"<<std::endl;
            exit(EXIT_FAILURE);
        }else{
            allContact[index]["surname"]=temp;
        
        }
    }else if(choice_modif == 7){
        std::cout<<"enter new patronym"<<std::endl;
        std::cin>>temp;
        if(!isValidName(temp)){
            std::cerr<<"the patronym is not valid! \n end of the process!!!"<<std::endl;
            exit(EXIT_FAILURE);
        }else{
            allContact[index]["patronym"]=temp;
        
        }
    }
    else if(choice_modif == 3){
        std::cout<<"enter new address"<<std::endl;
        std::cin>>temp;
        if(!isValidName(temp)){
            std::cerr<<"the address is not valid! \n end of the process!!!"<<std::endl;
            exit(EXIT_FAILURE);
        }else{
            allContact[index]["address"]=temp;
        
        }
    }
    else if(choice_modif == 4){
        std::cout<<"enter new email"<<std::endl;
        std::cin>>temp;
        if(!isValidEmail(temp)){
            std::cerr<<"the email is not valid! \n end of the process!!!"<<std::endl;
            exit(EXIT_FAILURE);
        }else{
            allContact[index]["email"]=temp;
        
        }
    }else if(choice_modif == 6){
        std::cout<<"enter the born date"<<std::endl;
        std::cin>>temp;
        if(!checkDate(temp)){
            std::cerr<<"the born date is not valid! \n end of the process!!!"<<std::endl;
            exit(EXIT_FAILURE);
        }else{
            allContact[index]["born_date"]=temp;
        
        }
    }else if(choice_modif == 5){

        char choice_mo_num;
        std::cout<<"you need to create a new contact to change the number"<<std::endl;
        std::cout<<"do you want to continue?(y/n)"<<std::endl;
        std::cin>>choice_mo_num;
        if(choice_mo_num=='n' || choice_mo_num =='N'){
            std::cout<<"the operation is cancelled!"<<std::endl;
            exit(EXIT_SUCCESS);
        }else if (choice_mo_num=='y' || choice_mo_num == 'Y'){
            //code de suppression
            newContact(tel); //fonction à optimiser pour éviter la redondance.

            for (int i = 0; i < tel.numero.size(); i++) {
        //json nums_elmnt;
        if(tel.numero[i].type == type_contact::personnal){
            v_personnal.push_back(tel.numero[i].value);

            //nums_elmnt["personnal"]=contact.numero[i].value;
        }
        else if(tel.numero[i].type == type_contact::home){
            v_home.push_back(tel.numero[i].value);
            //nums_elmnt["home"]=contact.numero[i].value;
        }else if(tel.numero[i].type == type_contact::work){
            v_work.push_back(tel.numero[i].value);
            //nums_elmnt["work"]=contact.numero[i].value;
        }else{

        }
        //nums_array.push_back(nums_elmnt);
    } 
    
    nums_elmnt["personnal"]=v_personnal;
    nums_elmnt["work"]=v_work;
    nums_elmnt["home"]=v_home;

    nums_array.push_back(nums_elmnt);

    allContact[index]["numero"]=nums_array;

            //removeContact(index);
        }

    }else{
        std::cerr<<"not valid choice";
    }
    saveToFile(allContact);
    std::cout<<"operation succeed!!!"<<std::endl;


};

void removeContact(int id){
    json allContact = json::array();
    allContact=loadFile();

    int index = findIndexWithId(allContact,id);

    if(index == -1){
        std::cout << "we can't find the contact !"<<std::endl;
        return;
    }
    allContact.erase(allContact.begin() + index);
    saveToFile(allContact);

    std::cout<<"contact has been deleted"<<std::endl;



};

bool searchContact(const json& allContact , const std::string& tele){
    //json allContact = json::array();
    //allContact=loadFile();

    if(!allContact.contains("numero") || !allContact["numero"].is_array()){
        return false;
    }

    for(const auto& bloc : allContact["numero"]){
        for(const auto& type : {"home", "personnal", "work"}){
            if(bloc.contains(type) && bloc[type].is_array()){
                for(const auto& tel : bloc[type]){
                    if(tel.get<std::string>().find(tele) != std::string::npos){
                        return true;
                    }
                }
            }
        }
    }

   return false;
};


bool matchContact(const json& allContact , const std::string& chain){
    //json allContact = json::array();
    //allContact=loadFile();
    if(chain.empty())return false;

    //nom
    if(allContact.contains("name") && allContact["name"].is_string() && allContact["name"].get<std::string>().find(chain)!= std::string::npos){
        return true;
    }
    //email
    if(allContact.contains("email") && allContact["email"].is_string() && allContact["email"].get<std::string>().find(chain) != std::string::npos){
        return true;
    }
    //surname
    if(allContact.contains("surname") && allContact["surname"].is_string() && allContact["surname"].get<std::string>().find(chain) != std::string::npos){
        return true;
    }
   
    return false;
}

std::vector<size_t>multicriteriaSearch(const json& allContact , const std::string& chain){

    //json allContact = json::array();
    //allContact=loadFile();

    std::vector<size_t> results;


    if(!allContact.is_array() || chain.empty()) 
        return results;
    
    for(size_t i = 0; i<allContact.size();++i){

        const auto& contact = allContact[i];

        if(matchContact(contact,chain) || searchContact(contact, chain)){
            results.push_back(i);
        }
    }
    return results;
}

void showSearch(const std::string chain){

    json allContact = json::array();
    allContact=loadFile();

    auto results = multicriteriaSearch(allContact, chain);

    std::cout<<" We founded ("<<results.size()<<") occurence(s)"<<std::endl;

    for(size_t idx : results){
        std::cout <<"Id: "<<allContact[idx]["id"]<<" - "<<allContact[idx]["name"] << "  " << allContact[idx]["numero"]<< "  " << allContact[idx]["email"] <<std::endl;
    }
}

void showAllContact() {
    json allContact = loadFile();

    if (!allContact.is_array() || allContact.empty()) {
        std::cout << "No contact to show.\n";
        return;
    }

    for (size_t i = 0; i < allContact.size(); ++i) {
        const auto& c = allContact[i];

        std::cout << "==============================\n";
        //std::cout << "ID : " << i << "\n";

        if (c.contains("id"))
            std::cout << "ID     : " << c["id"] << "\n";

        if (c.contains("name"))
            std::cout << "Nom     : " << c["name"] << "\n";

        if (c.contains("email"))
            std::cout << "Email   : " << c["email"] << "\n";

        if (c.contains("address"))
            std::cout << "Adresse : " << c["address"] << "\n";

        std::cout << "Numeros :\n";

        if (c.contains("numero") && c["numero"].is_array() && !c["numero"].empty()) {
            for (const auto& bloc : c["numero"]) {
                if (!bloc.is_object()) continue;

                for (const auto& [type, liste] : bloc.items()) {
                    std::cout << "  - " << type << " : ";
                    if (!liste.is_array() || liste.empty()) {
                        std::cout << "(empty)";
                    } else {
                        for (const auto& num : liste) {
                            std::cout << num.get<std::string>() << " ";
                        }
                    }
                    std::cout << "\n";
                }
            }
        } else {
            std::cout << "  (contact don't have a number)\n";
        }
    }

    std::cout << "------------------------------\n";
}


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
        contact.setPatronym("");
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
    std::cout<<"enter the born date (dd-MM-YYYY)"<<std::endl;
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
void newContact(std::string a, std::string b, std::string c, std::string d, std::string e, std::string f){
    //std::ofstream myFlow(annuaire.c_str(), std::ios::app);

    std::string temp=""; //temporary variable
    char choice;
    Contact contact;
    Numero numero;
    numero.value="888374";
    numero.type=personnal;

   
        contact.setName(a);
        contact.setSurname(b);
        contact.setPatronym(c);  
        contact.setAddress(d);
        contact.setDate(e);
        contact.setEmail(f);
    
//ici à bloquer
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
    
    //contact.getContact();

    saveContact(contact);
    

    //contact.getContact();



}

void newContact(Contact &tel){


    std::string temp=""; //temporary variable
    char choice;
    //Contact contact;
    Numero numero;
    numero.value="888374";
    numero.type=personnal;



    //ici à bloquer
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
    tel.setNumero(numero);
    
    std::cout<<"do you want to add another number y/n"<<std::endl;
    std::cin>>choice;
    if(choice=='y' || choice=='Y'){
        goto numero;
    }else if(choice=='n' || choice=='N'){
        std::cout<<"process new number has been stopped!!"<<std::endl;

    }else{
        std::cout<<"process new number has been stopped!!"<<std::endl;
    }

}




