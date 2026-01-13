#include <string>
#include <vector>
#include "lib/nlohmann/json.hpp"

using json = nlohmann::json;

enum type_contact{
    home,
    personnal,
    work

};
struct Numero{
    std::string value;
    enum type_contact type;
};

class Contact{

    public:
        std::string name;
        std::string surname;
        std::string patronym;
        std::string address;
        std::string born_date;
        std::string email;
        std::vector<Numero> numero;
    
    public:
    Contact();
    ~Contact();



    void setPatronym(std::string patronym);
    void setEmail(std::string email);
    void setNumero(std::vector<std::string> numero);
    void setName(std::string name);
    void setSurname(std::string surname );
    void setDate(std::string date);
    void setAddress(std::string address);
    void setNumero(Numero numero);
    
    void setContact();

    void getContact();
    



};

void newContact();
void saveContact(Contact contact);
json loadFile();
int findIndexWithId(const json& j, int id);
void modifyContact(int id);
void removeContact(int id);
void saveToFile(const json& j);
bool searchContact(const json& contact , const std::string& chain);
bool matchContact(const json& contact , const std::string& chain);
std::vector<size_t> multicriteriaSearch(const json& contact , const std::string& chain);
void showSearch(const std::string chain);
void newContact(std::string a, std::string b, std::string c, std::string d, std::string e, std::string f);
void newContact(const json& conArr );
void newContact(Contact& numero);
void showAllContact();


//void listContact();