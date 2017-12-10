//
// Created by Jane on 12/06/17.
//

#ifndef INC_224_PROJECT_COPY_H
#define INC_224_PROJECT_COPY_H
#include <cstring>
#include <iostream>
#include <ctime>
using namespace std;
#include "Book.h"


class Copy : public Book{
private:
    int ID;
    bool Lent;
    string readerName;
    int borrowTime;
    int reservationTime;
    int expirationTime;
    bool overdue;


public:
    Copy();
    Copy(string Title, string Author, string Category, string ISBN);


    const int &getID() const;
    void setID(const int &ID);
    const string &getReaderName() const;
    void setReaderName(const string &readerName);

    friend istream &operator >>(istream &in, Copy &copy);

        bool isLent() const;

    void setLent(bool Lent);

    int getReservationTime() const;
    void setReservationTime(int reservationTime);

    int getBorrowTime() const;
    void setBorrowedTime(int borrowedTime);
    int getExpirationTime() const;
    void setExpirationTime(int expirationTime);
    bool isOverdue() const;
    void setOverdue(bool overdue);
    void release();             //Release the copy as avalible again

    friend ostream &operator<<(ostream &os, const Copy &copy1);

    void setBorrowTime(int borrowTime);
};


#endif //INC_224_PROJECT_COPY_H
