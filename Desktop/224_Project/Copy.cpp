//
// Created by Jane on 12/05/17.
//
#include "Copy.h"

using namespace std;

Copy::Copy(){

}

Copy::Copy(string Title, string Author, string Category, string ISBN){
    this -> title = Title;
    this -> author = Author;
    this -> category = Category;
    this -> ISBN = ISBN;
    this -> Lent = false;
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

const string &Copy::getBorrowDate() const {
    return borrowDate;
}

void Copy::setBorrowDate(const string &borrowDate) {
    Copy::borrowDate = borrowDate;
}

const string &Copy::getBorrowedTime() const {
    return borrowedTime;
}

void Copy::setBorrowedTime(const string &borrowedTime) {
    Copy::borrowedTime = borrowedTime;
}

const string &Copy::getExpirationDate() const {
    return expirationDate;
}

void Copy::setExpirationDate(const string &expirationDate) {
    Copy::expirationDate = expirationDate;
}

istream &operator >>(istream &in, Copy &copy){

}

ostream &operator<<(ostream &os, const Copy &copy1) {
    os << static_cast<const Book &>(copy1) << "\nID: " << copy1.ID << "\nisLent: " << copy1.Lent << "\nreaderName: "
       << copy1.readerName << "\nborrowDate: " << copy1.borrowDate << "\nborrowedTime: " << copy1.borrowedTime
       << "\nexpirationDate: " << copy1.expirationDate;
    return os;
}

bool Copy::isLent() const {
    return Lent;
}

void Copy::setLent(bool Lent) {
    Copy::Lent = Lent;
}





