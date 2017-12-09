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
vector<Copy> CopiesDatabase;                // vector that stores all copies
int copyID = 0;                             // unique ID of the a book
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
void LibrarianMenu();
void printBooks();
void printAllUsers();
bool exist(string username);


int main(){
    Librarian TA224("ta224", "224");
    LibrarianDatabse.push_back(TA224);      //create 224 ta account
    mainmenu();
}
//Main Menu
void mainmenu(){
    cout << "\n---------------------------------------------------------\n"
            "Welcome to the SBU library management system. What would you like to do?\n"
            "---------------------------------------------------------\n";
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
    vector<User> bigDatabase;

    if(exist(username)){            //Returns true if this username is taken
        cout << "An account with this username already exist.\n";
        mainmenu();
    }

    else if(choice == 1) {
        Librarian newadmin(username,password);
            LibrarianDatabse.push_back(newadmin);
            cout << "A Librarian account with the username " << newadmin.getUsername() << " has been created\n";
            mainmenu();

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
    if(LibrarianLoggedin){
        LibrarianMenu();
    }
    else
        mainmenu();
}

bool exist(string username){

    vector<string> usernames;
    for(Librarian i : LibrarianDatabse){
        usernames.push_back(i.getUsername());
    }
    for(Student i : StudentDatabase){
        usernames.push_back(i.getUsername());
    }
    for(Teacher i : TeacherDatabase){
        usernames.push_back(i.getUsername());
    }
    if(find(usernames.begin(),usernames.end(),username) != usernames.end()){
        return true;
    } else
        return false;
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
                LibrarianMenu();
                break;
            }
            else {
                cout << "Invalid credential, username and password are case-sensitive, try again\n";
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
                ReaderMenu();
                studentLoggedin = true;
                break;
            }
            else {
                cout << "Invalid credential, username and password are case-sensitive, try again\n";
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
            if(password == teacher.getPassword()){
                TeacherLoggedin = true;
                ReaderMenu();
                break;
            }
            else {
                cout << "Invalid credential, username and password are case-sensitive, try again";
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
            "\n6 -- My Information\n7 -- Change Password"
            "\n8 -- Log Out\n";
    int i;
    cin >> i;
    if (i == 1) {                       //Search Book
        cout << "Search by: " << endl;
        cout << "1 -- ISBN\n2 -- Title\n3 -- Author\n4 -- Category";
        cin >> i;
        SearchBook(i);

    } else if (i == 6) {                //My information
        if (studentLoggedin) {
            cout << student;
        } else if (TeacherLoggedin) {
            cout << teacher;
        }
        ReaderMenu();
    }

    else if (i == 7) {                                    //Change password
        cout << "Enter your new Password: ";
        string newPassword;
        cin >> newPassword;
        if (studentLoggedin) {
            student.setPassword(newPassword);
        } else if (TeacherLoggedin) {
            teacher.setPassword(newPassword);
        }
        cout << "Your new password is: " << newPassword << "\n";
        ReaderMenu();
    }

    else if (i == 8) {                  //Log out
        TeacherLoggedin = false;
        studentLoggedin = false;
        cout << "You've logged out of your account\n";
        mainmenu();
    }
}

void LibrarianMenu(){

    cout << "\nWelcome, Librarian. Select your option: \n1 -- Search Book\n2 -- Add Books\n3 -- Delete Book"
            "\n4 -- Search Users\n5 -- Add Users\n6 -- Delete Users"
            "\n7 -- My Information\n8 -- Change Password"
            "\n0 -- Log Out\n";
    int i;
    cin >> i;
    if(i == 1 ){
        cout << "Search by: " << endl;
        cout << "1 -- ISBN\n2 -- Title\n3 -- Author\n4 -- Category";
        cin >> i;
        SearchBook(i);
    }
    else if(i == 2){
        bool addCopy = false;
        Book newBook;
        cout << "Enter all information about the book without any spaces (CASE SENSITIVE)\n";
        cin >> newBook;
        for(Book i : BookDatabase){
            if(i.getISBN() == newBook.getISBN()){
                addCopy = true;
                break;
            }
        }
        if(!addCopy){       //No copies exist yet, adding a new book and a copy.
            BookDatabase.push_back(newBook);
            newBook.setNumCopies(1);
            Copy bookCopy(newBook.getTitle(),newBook.getAuthor(),newBook.getCategory(),newBook.getISBN());
            bookCopy.setID(copyID++);
            CopiesDatabase.push_back(bookCopy);
            cout << newBook.getTitle() << " has been added to the database!\n";
        }
        else{               //Already has copies, add another 1, increment ID counter by 1.
            Copy bookCopy(newBook.getTitle(),newBook.getAuthor(),newBook.getCategory(),newBook.getISBN());
            bookCopy.setID(copyID++);
            newBook.setNumCopies(newBook.getNumCopies() + 1);
            CopiesDatabase.push_back(bookCopy);
            cout << "A new copy of " << newBook.getTitle() << " has been added to the database!\n";
        }

    }

    else if (i == 3){
        bool hasCopy;
        int numSameCopies = 0, idnum;
        cout << "Enter the ID number of the book you wish to delete: \n";
        cin >> idnum;
        Book deletedBook;
        Copy deletedCopy;
        string ISBN;

        for(Copy i : CopiesDatabase){
            if(idnum == i.getID()){
                hasCopy = true;
                deletedCopy = i;
                ISBN = deletedCopy.getISBN();
            }
            if(hasCopy && i.getISBN() == ISBN){         // Check how many copies of the same book there are
                numSameCopies++;
            }
        }
        if(!hasCopy){                                   //Invalid ID number, no action is done
            cout << "No copy exist with this ID number, try again\n";
            ReaderMenu();
        }
        else if(hasCopy && deletedCopy.isLent()){       //Copy is lent out, no action is done
            cout << "The copy is lent out, so it cannot be deleted\n";
            ReaderMenu();
        }

        else if(hasCopy && numSameCopies == 1){         //remove the book if this is the last copy
            for(Book i : BookDatabase){
                if(ISBN == i.getISBN()){
                    deletedBook = i;
                    break;
                }
            }
            //BookDatabase.erase(remove(BookDatabase.begin(),BookDatabase.end(), deletedBook),BookDatabase.end());
        }
        else if(hasCopy){                               //Remove from the reserver's reservation list

        }

    }


    else if(i == 4){            //Search user by username
        cout << "Enter a username";
        string name;
        cin >> name;
        bool found = false;
        Librarian lib;
        Student stu;
        Teacher teach;
        for(Librarian i : LibrarianDatabse){
            if(i.getUsername() == name){
                found = true;
                lib = i;
                cout << "\nAccount found\nUsername: " << name << "\nPassword: " << i.getPassword() << "\n";
                break;
            }
        }

        if(!found){
            for(Student i : StudentDatabase){
                if(i.getUsername() == name){
                    found = true;
                    stu = i;
                    cout << stu << "\n";
                    break;
                }
            }
        }

        if(!found){
            for(Teacher i : TeacherDatabase){
                if(i.getUsername() == name){
                    found = true;
                    teach = i;
                    cout << i << "\n";
                    break;
                }
            }
        }

        if(!found){
            cout << "No user with this user name exist.\n";
        }
        LibrarianMenu();
    }

    else if(i == 5){                        //Use create() method to add new user
        create();
        ReaderMenu();
    }

    else if( i == 6){
        int iterator = 0;
        cout << "Enter a username";
        string name;
        cin >> name;
        bool found = false;

        for(Librarian i : LibrarianDatabse){
            if(i.getUsername() == name){
                found = true;
                LibrarianDatabse.erase(LibrarianDatabse.begin() + iterator);
                cout << "Librarian account " << i.getUsername() << " has been deleted\n";
                break;
            }
            iterator++;
        }

        if(!found){
            iterator = 0;
            for(Student i : StudentDatabase){
                if(i.getUsername() == name){
                    found = true;
                    StudentDatabase.erase(StudentDatabase.begin() + iterator);
                    cout << "Student account " << i.getUsername() << " has been deleted\n";
                    break;
                }
            iterator ++;

            }
        }
        if(!found){
            iterator = 0;
            for(Teacher i : TeacherDatabase){
                if(i.getUsername() == name){
                    found = true;
                    TeacherDatabase.erase(TeacherDatabase.begin() + iterator);
                    cout << "Teacher account " << i.getUsername() << " has been deleted\n";
                    break;
                }
            iterator++;
            }
        }
        if(!found){
            cout << "No user with this user name exist.\n";
        }
        ReaderMenu();
    }

    else if(i == 0){
        LibrarianLoggedin = false;
        cout << "\nYou're logged out now, see you!";
        mainmenu();
    }


}


//Print all the users (debugging purposes)
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

//Print all the books in the system (debugging purposes)
    void printBooks() {
        for (Book i: BookDatabase) {
            cout << i.getTitle() << "\n";
        }
    }

    void SearchBook(int i) {
        if (i == 1) {
            cout << "Enter the ISBN";
            string isbn;
            cin >> isbn;
            for (Book i : BookDatabase) {
                if (i.getISBN() == isbn) {
                    cout << "Book Found\n" << i;
                }
            }
        } else if (i == 2) {
            cout << "Enter the Title (CASE SENSITIVE): ";
            string title;
            cin >> title;
            for (Book i : BookDatabase) {
                if (i.getTitle() == title) {
                    cout << "Book Found\n" << i;
                }
            }
        } else if (i == 3) {
            cout << "Enter the author (CASE SENSITIVE): ";
            string author;
            cin >> author;
            for (Book i : BookDatabase) {
                if (i.getAuthor() == author) {
                    cout << i << endl;
                }
            }

        } else if (i == 4) {
            cout << "Enter the Category (CASE SENSITIVE): ";
            string category;
            cin >> category;
            for (Book i : BookDatabase) {
                if (i.getCategory() == category) {
                    cout << i << endl;
                }
            }
        }
        cout << "\n";
        if(studentLoggedin || TeacherLoggedin)
            ReaderMenu();
        else
            LibrarianMenu();
    }




