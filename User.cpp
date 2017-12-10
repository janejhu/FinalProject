#include<iostream>
#include "User.h"
using namespace std;

User::User(){

}

User::User(string username, string password){
    username = username;
    password = password;
}

void User::setUsername(string newUsername){
    username = newUsername;
}

void User::setPassword(string newPassword){
    password = newPassword;
}

string User::getPassword(){
    return password;
}

string User::getUsername(){
    return username;
}
bool User::isTeacher(){
    return Teacher;
}
bool User::isStudent(){
    return Student;
}
bool User::isLibrarian(){
    return Librarian;
}
void User::setasTeacher(){
    Teacher = true;
}
void User::setasStudent(){
    Teacher = true;
}
void User::setasLibrarian(){
    Librarian = true;
}

ostream &operator<<(ostream &os, const User &user) {
    os << "username: " << user.username << endl;
    os << "password: " << user.password;
    return os;
}

istream &operator>>(istream &in, User &user){
    cout << "Enter the username: " << endl;
    in >> user.username;
    cout << "Enter the password: " << endl;
    in >>  user.password;
}



void User::write(ostream & os) const{
    os<< "username: " << username <<endl;
    os << "Password: "<< password << endl;
}
