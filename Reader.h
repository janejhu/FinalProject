
#ifndef PROJECT_READER_H
#define PROJECT_READER_H
#include <iostream>
#include<cstring>
#include<vector>
#include "User.h"
#include "Copy.h"


using namespace std;

class Reader: public User {
private:
    int penalty;
    vector<Copy> borrowed;
    vector<Book> reserved;
    int max_books;
    int max_days;
    bool Student;
    bool Teacher;

public:
    Reader();
    Reader(string username, string newPassword);

    int getPenalty() const;
    void setPenalty(int penalty);
    const vector<Copy> &getBorrowed() const;
    void setBorrowed(Copy aCopy);
    const vector<Book> &getReserved() const;
    void setReserved(Book aBook);
    friend ostream &operator<<(ostream &os, const Reader &reader);

    int getMax_books() const;
    void setMax_books(int max_books);
    int getMax_days() const;
    void setMax_days(int max_days);
    void removeFromBorrowed(Copy aCopy);
    void removeFromReserved(Book aBook);

    void setBorrowedVector(const vector<Copy> &borrowed);
};
#endif //PROJECT_READER_H
