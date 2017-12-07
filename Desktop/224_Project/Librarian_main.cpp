#include<iostream>
#include "Librarian.h"
#include "User.h"
using namespace std;

Librarian::Librarian(){

}
Librarian::Librarian(string username, string password){
    this -> username = username;
    this -> password = password;
    setasLibrarian();
}


ostream &operator<<(ostream &os, const Librarian &librarian) {
    os << "Librarian Account" << endl;
    os << "Username: " << librarian.username << endl;
    os << "Password: " << librarian.password << endl;
    return os;
}



