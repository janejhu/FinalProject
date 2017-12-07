//
// Created by Jane on 12/06/17.
//

#ifndef INC_224_PROJECT_BOOK_H
#define INC_224_PROJECT_BOOK_H


#include<cstring>
#include<queue>
#include "Reader.h"

using namespace std;
class Reader;

class Book{
public:
    string ISBN;
    string title, author, category;
    int numCopies;
    queue<Reader> reservers;

public:
    Book();
    Book(string newTitle, string newAuthor, string newCategory, string ISBN);
    void setISBN(string newISBN);
    void setTitle(string newTitle);
    void setAuthor(string newAuthor);
    void setCategory(string newCategory);
    void newReserver(Reader reserver);
    string getISBN();
    string getTitle();
    string getAuthor();
    string getCategory();
    void getReservers();

    int getNumCopies() const;

    void setNumCopies(int numCopies);


    void setReservers(const queue<Reader> &reservers);

    //ostream &operator<<(ostream &os, const Book &book);
    friend ostream &operator<<(ostream &out, const Book &book);
    friend istream &operator>>(istream &in, Book &book);
    virtual void write(ostream&) const; //to be use by its based class
};


#endif //INC_224_PROJECT_BOOK_H
