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
    username = username;
    password = password;
    setasTeacher();
    setMax_books(10);
    setMax_days(50);

}
ostream &operator<<(ostream &os, const Teacher &teacher) {
    os << "Student Account" << endl;
    os << "Username: " << teacher.username << endl;
    os << "Password: " << teacher.password << endl;
    os << "Peanlty: " << teacher.getPenalty() << endl;
    os << "List of reserved books: ";
    for(Book i : teacher.getReserved()){
        os << i << endl;
    }
    os << "List of borrowed books: ";
    for(Book i : teacher.getBorrowed()){
        os << i << endl;
    }
    os << "Maximum Number of Books: " << 5 << endl;
    return os;
}


