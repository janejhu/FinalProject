#include<iostream>
#include "Reader.h"


using namespace std;
Reader::Reader() {
    penalty = 0;
}

Reader::Reader(string username, string newPassword){
    this -> username = username;
    this -> password = newPassword;
    this -> penalty = 0;
}



//toString
ostream &operator<<(ostream &os, const Reader &reader) {
    os << "Username: " << reader.username << endl;
    os << "Password: " << reader.password << endl;
    os << "Peanlty: " << reader.getPenalty() << endl;
    os << "List of reserved books: ";
    for(Book i : reader.getReserved()){
        os << i << endl;
    }
    os << "List of borrowed copies: ";
    for(Copy i : reader.getBorrowed()){
        os << i << endl;
    }
    os << "Maximum Number of Books: " << 5 << endl;
    return os;
}

int Reader::getPenalty() const {
    return penalty;
}

void Reader::setPenalty(int penalty) {
    Reader::penalty = penalty;
}


const vector<Book> &Reader::getReserved() const {
    return reserved;
}

void Reader::setReserved(Book aBook) {
    Reader::reserved.push_back(aBook);
}

void Reader::setBorrowedVector(const vector<Copy> &borrowed) {
    Reader::borrowed = borrowed;
}

void Reader::removeFromBorrowed(Copy aCopy) {
    int count = 0;
    for(Copy i : borrowed){
        if(i.getID() == aCopy.getID()){
            borrowed.erase(borrowed.begin() + count);
            break;
        }
        count ++;
    }
}

void Reader::removeFromReserved(Book acopy) {
    int count = 0;
    for(Book i : reserved){
        if(i.getISBN() == acopy.getISBN()){
            reserved.erase(reserved.begin() + count);
            break;
        }
        count ++;
    }
}

int Reader::getMax_books() const {
    return max_books;
}

void Reader::setMax_books(int max_books) {
    Reader::max_books = max_books;
}

int Reader::getMax_days() const {
    return max_days;
}

void Reader::setMax_days(int max_days) {
    Reader::max_days = max_days;
}

const vector<Copy> &Reader::getBorrowed() const {
    return borrowed;
}

void Reader::setBorrowed(Copy aCopy) {
    Reader::borrowed.push_back(aCopy);
}










