#include<iostream>
#include "Reader.h"


using namespace std;
Reader::Reader() {
    penalty = 0;
}

Reader::Reader(string username, string newPassword){
    this->username = username;
    this->password = password;
    this -> penalty = 0;
}

void Reader::reserve (Book theBook){reserved.push_back(theBook); }

//toString
ostream &operator<<(ostream &os, const Reader &reader) {
    os << reader.username;
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


Book Reader::searchBookbyISBN(string ISBN){

}
vector<Book> Reader::searchBookbyAuthor(string author){

}
Book Reader::searchBookbyTitle(string Title){

}
vector<Book> Reader::searchBookbyCategory(string category){

}

void Reader::borrowBook(Book aBook){

}
void Reader::returnBook(Book aBook){

}
void Reader::cancelReserve(Book aBook){

}



