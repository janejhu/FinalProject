//
// Created by Jane on 12/05/17.
//
#include "Copy.h"

using namespace std;

Copy::Copy(){
    this -> borrowTime = 0;
    this -> reservationTime = 0;
    this -> expirationTime = 0;
    this -> readerName = "";

}

Copy::Copy(string Title, string Author, string Category, string ISBN){
    this -> title = Title;
    this -> author = Author;
    this -> category = Category;
    this -> ISBN = ISBN;
    this -> Lent = false;
    this -> borrowTime = 0;
    this -> reservationTime = 0;
    this -> expirationTime = 0;
    this -> readerName = "";
}
const int &Copy::getID() const {
    return ID;
}

void Copy::setID(const int &ID) {
    Copy::ID = ID;
}

const string &Copy::getReaderName() const {
    return readerName;
}

void Copy::setReaderName(const string &readerName) {
    Copy::readerName = readerName;
}



istream &operator >>(istream &in, Copy &copy){
    cout << "Enter the title: " << endl;
    in >> copy.title;
    cout << "Enter the author: " << endl;
    in >> copy.author;
    cout << "Enter the reader's name" << endl;
    in >> copy.readerName;
}

ostream &operator<<(ostream &os, const Copy &copy1) {
    os << static_cast<const Book &>(copy1)  << "ID: " << copy1.ID
       << "\nreaderName: " << copy1.readerName
       << "\nborrowTime: " << copy1.borrowTime << "\nreservationTime: " << copy1.reservationTime << "\nexpirationTime: "
       << copy1.expirationTime << "\n";
    return os;
}

void Copy::release() {
    this -> Lent = false;
    this -> borrowTime = 0;
    this -> expirationTime = 0;
    this -> readerName = "";
}

bool Copy::isLent() const {
    return Lent;
}

void Copy::setLent(bool Lent) {
    Copy::Lent = Lent;
}

int Copy::getBorrowTime() const {
    return borrowTime;
}


int Copy::getExpirationTime() const {
    return expirationTime;
}

void Copy::setExpirationTime(int expirationTime) {
    Copy::expirationTime = expirationTime;
}

bool Copy::isOverdue() const {
    return overdue;
}

void Copy::setOverdue(bool overdue) {
    Copy::overdue = overdue;
}

int Copy::getReservationTime() const {
    return reservationTime;
}

void Copy::setReservationTime(int reservationTime) {
    Copy::reservationTime = reservationTime;
}

void Copy::setBorrowTime(int borrowTime) {
    Copy::borrowTime = borrowTime;
}






