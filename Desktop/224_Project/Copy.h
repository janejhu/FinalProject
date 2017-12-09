//
// Created by Jane on 12/06/17.
//

#ifndef INC_224_PROJECT_COPY_H
#define INC_224_PROJECT_COPY_H
#include <cstring>
#include <iostream>
using namespace std;

#include "Book.h"


class Copy : public Book{
private:
    int ID;
    bool Lent;
    string readerName;
    string borrowDate;
    string borrowedTime;
    string expirationDate;


public:
    Copy();
    Copy(string Title, string Author, string Category, string ISBN);


    const int &getID() const;
    void setID(const int &ID);
    const string &getReaderName() const;
    void setReaderName(const string &readerName);
    const string &getBorrowDate() const;
    void setBorrowDate(const string &borrowDate);
    const string &getBorrowedTime() const;
    void setBorrowedTime(const string &borrowedTime);
    const string &getExpirationDate() const;
    void setExpirationDate(const string &expirationDate);
        friend istream &operator >>(istream &in, Book &book);

    friend ostream &operator<<(ostream &os, const Copy &copy1);

    bool isLent() const;

    void setLent(bool Lent);
};


#endif //INC_224_PROJECT_COPY_H
