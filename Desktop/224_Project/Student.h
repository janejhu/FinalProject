//
// Created by Jane on 12/06/17.
//

#ifndef INC_224_PROJECT_STUDENT_H
#define INC_224_PROJECT_STUDENT_H


#include <ostream>
#include "Reader.h"

class Student : public Reader{
private:


public:
    Student();
    Student(string username, string password);
    friend ostream &operator<<(ostream &os, const Student &student);
    friend istream &operator>>(istream &in, Student &student);
};


#endif //INC_224_PROJECT_STUDENT_H
