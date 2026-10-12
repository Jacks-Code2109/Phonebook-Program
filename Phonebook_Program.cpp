#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Contact {
private:

    string FullName;
    string PhoneNumber;
    string EmailAddress;
    string Address;
    string Birthday;
    string Notes;

public:
    Contact(const string& name, const string& phone, const string& email, const string& addr, const string& bday, const string& note):
    FullName(name), PhoneNumber(phone), EmailAddress(email), Address(addr), Birthday(bday), Notes(note) {
    }

    //TASK 1
    //PUBLIC MEMBER FUNCTIONS (GETTERS) TO ACCESS CONTACT INFO
    string getFullName() const {return FullName;}
    string getPhoneNumber() const {return PhoneNumber;}
    string getEmailAddress() const {return EmailAddress;}
    string getAddress() const {return Address;}
    string getBirthday() const {return Birthday;}
    string getNotes() const {return Notes;}
    
};   

class Phonebook {
 private:

    vector<Contact> contacts;

public:
    void addContact(const Contact& contact){
        contacts.push_back(contact);
    }


    //TASK 2


    void viewContacts() {
        for (const Contact& contact : contacts) {
            //This is where contact info will be displayed
            cout << "Full Name: " << contact.getFullName() << endl;
            cout << "Phone Number: " << contact.getPhoneNumber() << endl;
            cout << "Email Address: " << contact.getEmailAddress() << endl;
            cout << "Address: " << contact.getAddress() << endl;
            cout << "Birthday: " << contact.getBirthday() << endl;
            cout << "Any Notes: " << contact.getNotes() << endl;
            cout << "--------------------------------" << endl;
 
        }
    }

    void editContact(const string& name) {
        for (Contact& contact : contacts) {
            if (contact.getFullName() == name) {
                return;
            }
        }
        cout << "Contact not found." << endl;
    }

    //TASK 3

    void deleteContact(const string& name) {
      for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getFullName() == name){
          contacts.erase(contacts.begin() + i);
          cout << "Contact \"" << name << "\" has been deleted." << endl;
          return; 
        }
      }
      cout << "Contact not found" << endl;

    }




    void saveContactsToFile(const string& filename) {
        ofstream file(filename);
        if(file.is_open()) {
            for(const Contact& contact : contacts) {
                //WRITE INFO FOR FILE
                file << "Name: " << contact.getFullName() << endl;
                file << "Phone: " << contact.getPhoneNumber() << endl;
                file << "Email: " << contact.getEmailAddress() << endl;
                file << "Address: " << contact.getAddress() << endl;
                file << "Birthday: " << contact.getBirthday() << endl;
                file << "Notes: " << contact.getNotes() << endl;
                file << "--------------------------------" << endl; 
            }
            cout << "Contacts saved to " << filename << " successfully " << endl;
            file.close();
        }
        else {
            cerr << "Error: unable to open file " << filename << " for writing." << endl;
        }
    }
};

int main() {
    //CREATE PHONEBOOK TO MANAGE CONTACTS
    Phonebook phonebook;

    while (true) {
      cout << "Phonebook Menu: " << endl;
      cout << "1) Add Contact" << endl;
      cout << "2) View contacts" << endl;
      cout << "3) Delete Contact" << endl;
      cout << "4) Save Contacts to File" << endl;
      cout << "5) Quit" << endl;
      cout << "6) What do you do?" << endl;
      
      int choice;
      cout << "Enter Your Choice:   ";
      cin >> choice;

      switch (choice) {
      case 1: {
        //Task 4
        string FullName, PhoneNumber, EmailAddress, Address, Birthday, Notes;
        
        cin.ignore();
        cout << "Enter the full name of the contact: ";
        getline(cin, FullName);

        cout << "Enter the phone number of the contact: ";
        getline(cin, PhoneNumber);

        cout << "Enter the email address of the contact: ";
        getline(cin, EmailAddress);

        cout << "Enter the address of the contact: ";
        getline(cin, Address);

        cout << "Enter the birthday of the contact: ";
        getline(cin, Birthday);

        cout << "Enter at notes about this contact: ";
        getline(cin, Notes);

        Contact newContact(FullName, PhoneNumber, EmailAddress, Address, Birthday, Notes);
        phonebook.addContact(newContact);
        cout << "Contact \"" << FullName << "\" is now on your contact list." << endl;

        break;
      }

      case 2: {
        //TASK 5

        phonebook.viewContacts();
        



        //View all contacts in the phonebook
        


        break;
      }
      
      case 3: {
        //Deleting a contact from the phonebook
        string nameToDelete;
        cout << "Enter the Full Name of the Contact you want to delete:  ";
        cin.ignore();
        getline(cin,nameToDelete);
        phonebook.deleteContact(nameToDelete);
        break;
      }
      case 4: {
        //Save contacts to the file
        string filename;
        cout << "Enter the filename to save the contacts:  ";
        cin.ignore();
        getline(cin, filename);
        phonebook.saveContactsToFile(filename);
        break;
      }
      case 5: {
        //Exit the phonebook program
        cout << "Existing Phonebook" << endl;
        return 0;
      }
      case 6: {
        cout << "This is a phonebook. It allows you to add contacts" << endl;
        cout << "Option 1 allows you to add a contact by entering a full name, phone number, email, address, birthday and notes about the person" << endl;
        cout << "Option 2 allows you to view the contacts you've entered. If there are no contacts in the system, it will loop you back to the main menu" << endl;
        cout << "Option 3 allows you to delete any existing contact. when you have picked that option, Just enter the contact's full name and the whole contact will be removed" << endl;
        cout << "Option 4 allows you to save any added files to a text document. By choosing this option, any saved contacts will be copied and pasted into a text document" << endl;
        cout << "Option 5 allows you to quit out of the phonebook. you will then need to close and rerun the program before you can use it again" << endl;
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        break;
      }
      default:
        cout << "Invalid choice. please try again :) " << endl;
      }
    }
    return 0;
}