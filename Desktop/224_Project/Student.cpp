//
// Created by Jane on 12/06/17.
//

#include "Student.h"

Student::Student(){
    setasStudent();
    setMax_books(5);
    setMax_days(30);
    setPenalty(0);
}

Student::Student(string username, string password){
    this -> username = username;
    this -> password = password;
    setasStudent();
    setMax_books(5);
    setMax_days(30);
    setPenalty(0);

}

ostream &operator<<(ostream &os, const Student &student) {
    os << "Student Account" << endl;
    os << "Username: " << student.username << endl;
    os << "Password: " << student.password << endl;
    os << "Peanlty: " << student.getPenalty() << endl;
    os << "List of reserved books: ";
    for(Book i : student.getReserved()){
        os << i << endl;
    }
    os << "List of borrowed books: ";
    for(Book i : student.getBorrowed()){
        os << i << endl;
    }
    os << "Maximum Number of Books: " << 5 << endl;
    return os;
}



istream &operator>>(istream &in, Student &student){
    cout << "Enter the username: " << endl;
    in >> student.username;
    cout << "Enter the password: " << endl;
    in >>  student.password;

}

