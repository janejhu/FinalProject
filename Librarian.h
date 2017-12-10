//
// Created by Jane on 11/21/17.
//

#ifndef INC_224_PROJECT_LIBRARIAN_H
#define INC_224_PROJECT_LIBRARIAN_H

#include <iostream>
#include "User.h"


class Librarian: public User{

    public:
        Librarian();
        Librarian(string username, string password);

    friend ostream &operator<<(ostream &os, const Librarian &librarian);

};
#endif //INC_224_PROJECT_LIBRARIAN_H
