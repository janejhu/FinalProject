#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Copy.h"
#include "Librarian.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;

//I know this is not convention, but, makes life easier than using pointers
vector<Librarian> LibrarianDatabse;         //vector that stores all users
vector<Student> StudentDatabase;
vector<Teacher> TeacherDatabase;
vector<Book> BookDatabase;                 //vector that stores all books
Student student;                            //To be pass to the display function
Teacher teacher;
Librarian librarian;
bool studentLoggedin;
bool TeacherLoggedin;
bool LibrarianLoggedin;


void mainmenu();
void create();
void login();
void SearchBook(int i);
void ReaderMenu();
void printBooks();
void printAllUsers();


int main(){
    mainmenu();
}
//Main Menu
void mainmenu(){
    cout << "Welcome to the SBU library management system. What would you like to do?\n";
    cout << "1. Create an account\n2. Login to your account\n3. Exit Program";
    int select;
    cin >> select;
    if(select == 1){
        create();

    }
    else if (select == 2){
        login();
    }
    else{
        cout << "You've existed the library system. \n";
    }
}

void create(){
    cout << "Select the type of account: \n1.Librarian \n2.Teacher\n3.Student";
    int choice;
    cin >> choice;

    // Takes in User input username and password
    cout << "Username: ";
    string username;
    cin >> username;
    cout << "Password: ";
    string password;
    cin >> password;

    Student tempStu(username, password);
    Teacher tempTeacher(username, password);
    Librarian tempLib(username, password);

    if(choice == 1) {
        Librarian newadmin(username,password);
        LibrarianDatabse.push_back(newadmin);
        cout << "A Teacher account with the username "<< newadmin.getUsername() << " has been created\n";
    }
    else if(choice == 2 ){
        Teacher newteacher(username,password);
        TeacherDatabase.push_back(newteacher);
        cout << "A Teacher account with the username "<< newteacher.getUsername() << " has been created\n";
    }
    else if(choice == 3 ){
        Student newstudent(username,password);
        StudentDatabase.push_back(newstudent);
        cout << "A Student account with the username "<< newstudent.getUsername() << " has been created\n";
    }
    mainmenu();
}

void login(){
    bool valid = false;             //To see if account exist
    cout << "\n1 -- Librarian Login\n2 -- Student Login\n3 -- Teacher Login\n";
    int choice;
    cin >> choice;

    cout << "Username: ";
    string username;
    cin >> username;
    cout << "Password: ";
    string password;
    cin >> password;

    if(choice == 1) {
        for (Librarian i : LibrarianDatabse) {
            if (username == i.getUsername()) {
                valid = true;
                librarian = i;
            }
            if(password == librarian.getPassword()){
                LibrarianLoggedin = true;
                //LibrarianMenu();
                break;
            }
            else {
                cout << "Invalid credential, try again\n";
                login();
                break;
            }
        }
    }
    else if(choice == 2){
        for (Student i : StudentDatabase) {
            if (username == i.getUsername()) {
                valid = true;
                student = i;
            }
            if(password == student.getPassword()){
                //StudentMenu();
                studentLoggedin = true;
                break;
            }
            else {
                cout << "Invalid credential, try again\n";
                login();
                break;
            }
        }
    }

    else if(choice == 3){
        for (Teacher i : TeacherDatabase) {
            if (username == i.getUsername()) {
                valid = true;
                teacher = i;
            }
            if(password == student.getPassword()){
                TeacherLoggedin = true;
                ReaderMenu();
                cout << "valid";
                break;
            }
            else {
                cout << "Invalid credential, try again";
                login();
                break;
            }
        }
    }
    if(!valid){
        cout << "Invalid credentials, try again.";
        mainmenu();
    }
}

void ReaderMenu() {
    cout << "\nWelcome, reader. Select your option: \n1 -- Search Book\n2 -- Borrow Books\n3 -- Return Book"
            "\n4 -- Reserve Books\n5 -- Cancel Reservation"
            "\n6 -- My Information\n 7 -- Change Password"
            "\n 8 -- Log Out\n";
    int i;
    cin >> i;
    if (i == 1) {
        cout << "Search by: " << endl;
        cout << "1 -- ISBN\n2 -- Title\n3 -- Author 4 -- Category";
        cin >> i;
        SearchBook(i);
    } else if (i == 6) {
        if (studentLoggedin) {
            cout << student;
        } else if (TeacherLoggedin) {
            cout << teacher;
        }
    } else if (i == 7) {                                    //Change password
        cout << "Enter your new Password: ";
        string newPassword;
        cin >> newPassword;
        if (studentLoggedin) {
            student.setPassword(newPassword);
        } else if (TeacherLoggedin) {
            teacher.setPassword(newPassword);
        }
    } else if (i == 8) {
        cout << "Logged out";
        mainmenu();
    }
}



//Print all the users
    void printAllUsers() {
        for (Librarian i : LibrarianDatabse) {
            cout << i;
        }
        for (Student i: StudentDatabase) {
            cout << i;
        }
        for (Teacher i : TeacherDatabase) {
            cout << i;
        }

    }

//Print all the books in the system
    void printBooks() {
        for (Book i: BookDatabase) {
            cout << i.getTitle() << "\n";
        }
    }

    void SearchBook(int i) {
        if (i == 1) {
            cout << "Enter the ISBN";
            string isbn;
            for (Book i : BookDatabase) {
                if (i.getISBN() == isbn) {
                    cout << "Book Found\n" << i;
                }
            }
        } else if (i == 2) {
            cout << "Enter the Title";
            string title;
            for (Book i : BookDatabase) {
                if (i.getTitle() == title) {
                    cout << "Book Found\n" << i;
                }
            }
        } else if (i == 3) {
            cout << "Enter the author";
            string author;
            for (Book i : BookDatabase) {
                if (i.getAuthor() == author) {
                    cout << i << endl;
                }
            }

        } else if (i == 4) {
            cout << "Enter the Categogry";
            string category;
            for (Book i : BookDatabase) {
                if (i.getCategory() == category) {
                    cout << i << endl;
                }
            }
        }
    }




