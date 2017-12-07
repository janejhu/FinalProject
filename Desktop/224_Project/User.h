#ifndef INC_224_PROJECT_USER_H
#define INC_224_PROJECT_USER_H
#include <iostream>
#include <cstring>
using namespace std;

class User{
    protected:
        string username, password;              //Protected fields username and password
    private:
        bool Teacher, Student, Librarian;       //Distinguish the type of subclasses (not required, but easier to read)

    public:
        User();
        User(string username, string password);
        void setUsername(string newUsername);
        void setPassword(string newPassword);
        string getPassword();
        string getUsername();
        friend ostream &operator<<(ostream &os, const User &user);
        virtual void write(ostream&) const;
       //Functions used to distinguish the type of account
        bool isTeacher();
        bool isStudent();
        bool isLibrarian();
        void setasTeacher();
        void setasStudent();
        void setasLibrarian();


};

#endif //INC_224_PROJECT_USER_H
