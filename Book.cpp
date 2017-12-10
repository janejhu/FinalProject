#include<iostream>
#include<stdio.h>
#include <cstring>
#include "Book.h"
#include "Reader.h"

using namespace std;

Book::Book(){
    this -> numCopies = 0;
    this -> numReservers = 0;
}

Book::Book(string newTitle, string newAuthor, string newCategory, string ISBN){
    this -> title = newTitle;
    this -> author = newAuthor;
    this -> category = newCategory;
    this -> ISBN = ISBN;
    this -> numCopies = 0;
    this -> numReservers = 0;

}

void Book::setISBN(string newISBN){
    ISBN = newISBN;
}
bool Book::noReservers() {
    if(reservers->size() == 0){
        return true;
    }
    else{
        return false;
    }
}

int Book::getReserverSize() {
    return reservers->size();
}

void Book::setTitle(string newTitle){
    title = newTitle;
}

void Book::setAuthor(string newAuthor){
    author = newAuthor;
}

void Book::setCategory(string newCategory){
    category = newCategory;
}


string Book::getISBN(){
    return ISBN;
}

string Book::getTitle(){
    return title;
}

string Book::getAuthor(){
    return author;
}

string Book::getCategory(){
    return category;
}

string Book::getFirstReserver() {
    return reservers->front().getUsername();
}

void Book::addReserver(Reader& aReader) {
    reservers->push(aReader);
    numReservers += 1;
}
void Book::removeReserver(Reader & aReader){
    string username = aReader.getUsername();
    //doesn't work, but leaving it here
}



ostream &operator<<(ostream &os, const Book &book) {
    os << "Title: " << book.title << endl;
    os << "Author: " << book.author << endl;
    os << "ISBN: " << book.ISBN << endl;
    os << "Category: " << book.category << endl;
    return os;
}

istream &operator >>(istream &in, Book &book){

    cout << "Enter the Title: ";
    in >> book.title;
    cout << "Enter the Author: ";
    in >> book.author;
    cout << "Enter the ISBN: ";
    in >> book.ISBN;
    cout << "Enter the Category: ";
    in >> book.category;
}

void Book::write(ostream &os) const{
    os << "Title: " << title << endl;
    os << "Author: " << author << endl;
    os << "ISBN: " << ISBN << endl;
    os << "Category: " << category << endl;
}

int Book::getNumCopies() const {
    return numCopies;
}

void Book::setNumCopies(int numCopies) {
    Book::numCopies = numCopies;
}

queue<Reader> *Book::getReservers() const {
    return reservers;
}

void Book::setReservers(queue<Reader> *reservers) {
    Book::reservers = reservers;
}

int Book::getNumReservers() const {
    return numReservers;
}

void Book::setNumReservers(int numReservers) {
    Book::numReservers = numReservers;
}


