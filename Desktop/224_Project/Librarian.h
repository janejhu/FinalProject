//
// Created by Jane on 11/21/17.
//

#ifndef INC_224_PROJECT_LIBRARIAN_H
#define INC_224_PROJECT_LIBRARIAN_H

#include <iostream>
#include "User.h"
#include "Book.h"


class Librarian: public User{

    public:
        Librarian();
        Librarian(string username, string password);
        Book SearchBookbyISBN(string ISBN);
        vector<Book> SearchBookbyAuthor(string author);
        Book SearchBookbyTitle(string Title);
        vector<Book> SearchBookbyCategory(string category);
        Book addBooks(Book aBook);
        Book deleteBooks(Book aBook);
        void addUsers(User newUser);
        void deleteUsers(User theUser);
        string getInfo();
        void changePassword(string newPassword);
        void logOut();

    const string &getCategory() const;

    void setCategory(const string &category);

    friend ostream &operator<<(ostream &os, const Librarian &librarian);

};
#endif //INC_224_PROJECT_LIBRARIAN_H
