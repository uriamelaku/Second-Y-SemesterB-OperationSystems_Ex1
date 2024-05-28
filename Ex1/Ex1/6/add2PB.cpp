#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool checkContact(const std::string& contact) 
{
    int len = contact.length();
    bool has_comma = false;
    bool valid_format = true;

    if (len == 0) {
        return false;
    }

    // Check for comma and correct format
    for (int i = 0; i < len; ++i) {
        if (contact[i] == ',') {
            has_comma = true;
            // Check if there's a name before the comma and a number after the comma
            if (i == 0 || i == len - 1) {
                valid_format = false;
                break;
            }
        }
    }

    // If no comma was found, or format is already invalid, return false
    if (!has_comma || !valid_format) {
        return false;
    }

    return true;
}

int addContact(const std::string& contact) 
{
    if (!checkContact(contact)) 
    {
        std::cerr << "Invalid contact format\nyou need to enter a name followed by a comma and a number\n";
        return 1;
    }

    std::ofstream phonebook("phonebook.txt", std::ios::app);
    if (!phonebook) 
    {
        std::cerr << "Error opening phonebook file\n";
        return 1;
    }

    phonebook << contact << "\n";
    phonebook.close();

    return 0;
}

int main() {

    std::cout << "enter contact: " << std::endl;

    std::string contact;
    std::getline(std::cin, contact);

    if(addContact(contact))
    {
        return 1;
    }

    cout << "Contact added successfully" << endl;
    return 0;
}
