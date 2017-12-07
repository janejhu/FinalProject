#include<iostream>
#include "Reader.h"


using namespace std;
Reader::Reader() {
    penalty = 0;
}

Reader::Reader(string username, string newPassword){
    username = username;
    password = newPassword;
    penalty = 0;
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
    os << "List of borrowed books: ";
    for(Book i : reader.getBorrowed()){
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

const vector<Book> &Reader::getBorrowed() const {
    return borrowed;
}

void Reader::setBorrowed(const vector<Book> &borrowed) {
    Reader::borrowed = borrowed;
}

const vector<Book> &Reader::getReserved() const {
    return reserved;
}

void Reader::setReserved(const vector<Book> &reserved) {
    Reader::reserved = reserved;
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










