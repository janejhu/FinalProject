#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"

#include "Copy.h"
#include "Librarian.h"

#include "Teacher.h"
#include "Student.h"

vector<User> UserDatabase;       //vector that stores all users
vector<Book> BookDatabase;       //vector that stores all books
using namespace std;
void login();
void create();
void mainmenu();


int main(){
    mainmenu();

}


//Main Menu
void mainmenu(){
    cout << "Welcome to the SBU library management system. What would you like to do?\n";
    cout << "1. Create an account\n2. Login to your account\n";
    int select;
    cin >> select;
    if(select = 1){
        create();

    }
    else{
        login();
    }
}

//The login function
void login() {
    bool valid = false;
    cout << "Username: ";
    string username;
    cin >> username;
    cout << "Password: ";
    string password;
    cin >> password;

    User LoginUser;
    for (User i : UserDatabase) {
        if (username.compare(i.getUsername())) {
            valid = true;
            LoginUser = i;
        }
    }
    if(valid){
        if(password.compare(LoginUser.getPassword())){
            cout << "Login Succeeded, welcome" << username << "\n";
        }
        else if(!password.compare(LoginUser.getPassword())){
            cout << "Incorrect password, try again\n";
        }
    }
    else{
        cout << "No user exist with this username, try again.";
        mainmenu;
    }
}


void create(){
    bool exist;
    cout << "Select the type of account: \n1. Librarian \n2.Teacher\n3.Student";
    int choice;
    cin >> choice;

    // Takes in User input username and password
    cout << "Username: ";
    string username;
    cin >> username;
    cout << "Password: ";
    string password;
    cin >> password;

    User tempUser(username, password);
    for(User i: UserDatabase){
        if(tempUser.getUsername().compare(i.getUsername())) {
            cout << "A user with this user name already exist.";
        }
        exist = true;
    }
    if(choice == 1 && exist == false) {
        Librarian admin(username,password);
        UserDatabase.push_back(admin);
        cout << "A librarian account with the username "<< admin.getUsername() << " has been created";


    }
    else if(choice == 2 && exist == false){
       Teacher teacher(username,password);
        UserDatabase.push_back(teacher);
        cout << "A librarian account with the username "<< teacher.getUsername() << " has been created";
    }
    else if(choice == 2 && exist == false){
        Student student(username,password);
        UserDatabase.push_back(student);
        cout << "A librarian account with the username "<< student.getUsername() << " has been created";
    }





}
//Print all the users
void printUsers(){
    for(User i: UserDatabase){
        if(i.isLibrarian()){
            cout << "Librarian ";
        }
        else if(i.isStudent()){
            cout << "Student ";
        }
        else if(i.isTeacher()){
            cout << "Teacher ";
        }
        cout << i.getUsername() << "\n";
    }
}

//Print all the books in the system
void printBooks(){
    for(Book i: BookDatabase){
        cout << i.getTitle() << "\n";
    }
}


