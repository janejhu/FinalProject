#include<iostream>
#include "Librarian.h"
#include "User.h"
using namespace std;

Librarian::Librarian(){

}
Librarian::Librarian(string username, string password){

}
vector<Book> Librarian::SearchBookbyAuthor(string author) {

}
Book Librarian::SearchBookbyISBN(string ISBN) {

}
Book Librarian::SearchBookbyTitle(string Title){

}


Book Librarian::addBooks(Book aBook){

}

Book Librarian::deleteBooks(Book aBook){

}

string Librarian::getInfo(){
    return username;
}
void Librarian::changePassword(string newPassword){

}
void Librarian::logOut(){

}

ostream &operator<<(ostream &os, const Librarian &librarian) {
    os << 'a';
    return os;
}

