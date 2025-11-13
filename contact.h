#include <string>
#include <vector>

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
//void listContact();