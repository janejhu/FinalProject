//
// Created by Jane on 12/06/17.
//

#include "Teacher.h"


Teacher::Teacher() {
    setasTeacher();
    setMax_books(10);
    setMax_days(50);


}

Teacher::Teacher(string username, string password){
    this -> username = username;
    this -> password = password;
    setasTeacher();
    setMax_books(10);
    setMax_days(50);

}
ostream &operator<<(ostream &os, const Teacher &teacher) {
    os << "Teacher Account" << endl;
    os << "Username: " << teacher.username << endl;
    os << "Password: " << teacher.password << endl;
    os << "Peanlty: " << teacher.getPenalty() << endl;
    os << "List of reserved books: ";
    for(Book i : teacher.getReserved()){
        os << i << endl;
    }
    os << "\nList of borrowed books: ";
    for(Book i : teacher.getBorrowed()){
        os << i << endl;
    }
    os << "\nMaximum Number of Books allowed: " << 10 << endl;
    return os;
}

istream &operator>>(istream &in, Teacher &teacher){
    cout << "Enter the username: " << endl;
    in >> teacher.username;
    cout << "Enter the password: " << endl;
    in >>  teacher.password;

}


