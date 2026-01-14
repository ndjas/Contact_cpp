#include <iostream>
#include "contact.h"

//using namespace std;

int main() {
    int choice;

    std::cout << "------------------------------------------------------\n";
    std::cout << "Welcome To MATOBEC Contact\n";
    std::cout << "------------------------------------------------------\n";
    std::cout << "By @leStatois\n";
    std::cout << "------------------------------------------------------\n";

    while (true) {
        std::cout << "\n1- Add Contact\n";
        std::cout << "2- Modify Contact\n";
        std::cout << "3- Delete Contact\n";
        std::cout << "4- Search Contact\n";
        std::cout << "5- Show all contact\n";
        std::cout << "6- Exit\n";
        std::cout << "Choose an option: ";

        std::cin >> choice;
        std::cin.ignore(); // IMPORTANT

        if (choice == 1) {
            newContact();
        }
        else if (choice == 2) {
            int id;
            std::cout << "Enter ID: ";
            std::cin >> id;
            modifyContact(id);
        }
        else if (choice == 3) {
            int id;
            std::cout << "Enter ID: ";
            std::cin >> id;
            removeContact(id);
        }
        else if (choice == 4) {
            std::string chain;
            std::cout << "Search: ";
            std::cin >> chain;
            showSearch(chain);
        }
        else if (choice == 5) {
            showAllContact();
        }
        else if (choice == 6) {
            std::cout << "GOOD BYE!\n";
            break;
        }
        else {
            std::cout << "Invalid choice.\n";
        }

        //PAUSE OBLIGATOIRE
        std::cout << "\nPress ENTER to continue...";
        std::cin.get();
    }

    return 0;
}
