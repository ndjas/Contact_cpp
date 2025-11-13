#include <iostream>
#include "contact.h"

//using namespace std;

int main()
{
    //std::cout << "Hello world!" << std::endl;


      int choice;



    std::cout << "------------------------------------------------------" <<std::endl;
    std::cout << "Welcome To MATOBEC Contact" <<std::endl;
    std::cout << "------------------------------------------------------" <<std::endl;
    std::cout << "By @leStatois" <<std::endl;
    std::cout << "------------------------------------------------------" <<std::endl;
    std::cout << " " <<std::endl;
    first_menu:
    std::cout << "1- Add Contact " <<std::endl;
    std::cout << "Press 4 - For Exit the Prograam" <<std::endl;
    std::cout << " " <<std::endl;

    std::cout << "choose an option:" <<std::endl;
    std::cin>>choice;


    while(1){

      if(choice==1){
       
        //int var;
        //std::cin>>var;

        
            newContact();
            std::cout<<""<<std::endl;
            goto first_menu;
        

        //listClient();
        //transaction();
        //break;
        //goto first_menu;
      }
    else if(choice==4 ){
        std::cout<<"GOOD BYE!!!!\n"<<std::endl;
        break;
    }else{
        std::cout<<"\n"<<std::endl;
        std::cout<<"make a correct choice\n"<<std::endl;
        goto first_menu;
    }

    }


    return 0;
}