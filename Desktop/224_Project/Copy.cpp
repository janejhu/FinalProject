//
// Created by Jane on 12/05/17.
//
#include "Copy.h"
using namespace std;


const string &Copy::getID() const {
    return ID;
}

void Copy::setID(const string &ID) {
    Copy::ID = ID;
}

const string &Copy::getReaderName() const {
    return readerName;
}

void Copy::setReaderName(const string &readerName) {
    Copy::readerName = readerName;
}

const string &Copy::getBorrowDate() const {
    return borrowDate;
}

void Copy::setBorrowDate(const string &borrowDate) {
    Copy::borrowDate = borrowDate;
}

const string &Copy::getBorrowedTime() const {
    return borrowedTime;
}

void Copy::setBorrowedTime(const string &borrowedTime) {
    Copy::borrowedTime = borrowedTime;
}

const string &Copy::getExpirationDate() const {
    return expirationDate;
}

void Copy::setExpirationDate(const string &expirationDate) {
    Copy::expirationDate = expirationDate;
}

