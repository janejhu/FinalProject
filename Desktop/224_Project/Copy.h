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
    string ID;
    string readerName;
    string borrowDate;
    string borrowedTime;
    string expirationDate;


public:
    Copy();
    Copy(string ID);


    const string &getID() const;

    void setID(const string &ID);

    const string &getReaderName() const;

    void setReaderName(const string &readerName);

    const string &getBorrowDate() const;

    void setBorrowDate(const string &borrowDate);

    const string &getBorrowedTime() const;

    void setBorrowedTime(const string &borrowedTime);

    const string &getExpirationDate() const;

    void setExpirationDate(const string &expirationDate);

    friend ostream &operator<<(ostream &os, const Copy &copy1);
};


#endif //INC_224_PROJECT_COPY_H
