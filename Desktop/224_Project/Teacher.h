//
// Created by Jane on 12/06/17.
//

#ifndef INC_224_PROJECT_TEACHER_H
#define INC_224_PROJECT_TEACHER_H
#include "Reader.h"


class Teacher : public Reader{
public:
    Teacher();
    Teacher(string username, string password);

};
ostream &operator<<(ostream &os, const Teacher &teacher);

#endif //INC_224_PROJECT_TEACHER_H
