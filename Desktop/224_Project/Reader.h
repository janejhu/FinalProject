
#ifndef PROJECT_READER_H
#define PROJECT_READER_H
#include <iostream>
#include<cstring>
#include<vector>
#include "User.h"
#include "Book.h"

using namespace std;
class Book;
class User;




class Reader: public User {
private:
    int penalty;
    vector<Book> borrowed;
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
    const vector<Book> &getBorrowed() const;
    void setBorrowed(const vector<Book> &borrowed);
    const vector<Book> &getReserved() const;
    void setReserved(const vector<Book> &reserved);
    friend ostream &operator<<(ostream &os, const Reader &reader);

    int getMax_books() const;
    void setMax_books(int max_books);
    int getMax_days() const;
    void setMax_days(int max_days);
};
#endif //PROJECT_READER_H
