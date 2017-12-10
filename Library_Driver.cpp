#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iterator>
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

//To BE SERIALIZED
Student student;                            //To be pass to the display function
Teacher teacher;
Librarian librarian;
int init_date;
clock_t start = clock();
static bool studentLoggedin = false;
static bool TeacherLoggedin = false;
static bool LibrarianLoggedin = false;


void mainmenu();
void create();
void login();
void SearchBook(int i);
void ReaderMenu();
void LibrarianMenu();
void printBooks();
bool exist(string username);
void Serialization();


int main(){
    Librarian TA224("ta224", "224");
    LibrarianDatabse.push_back(TA224);      //create 224 ta account
    mainmenu();
}
//Main Menu
void mainmenu(){
    Serialization();






    cout << "\n---------------------------------------------------------\n"
            "Welcome to the SBU library management system. What would you like to do?\n"
            "---------------------------------------------------------\n";
    cout << "1. Create an account\n2. Login to your account\n3. Exit Program";
    int select;
    cin >> select;
    if(select == 1){
        create();
        mainmenu();

    }
    else if (select == 2){
        login();
    }
    else{
        ofstream lib("librarian.dat", ios::out | ios::binary | ios::trunc);
        lib.write((char*)&LibrarianDatabse[0], LibrarianDatabse.size() * sizeof(Librarian));
        lib.close();

        ofstream stu("student.dat", ios::out | ios::binary);
        stu.write((char*)&StudentDatabase[0], StudentDatabase.size() * sizeof(Student));
        stu.close();

        ofstream teach("teacher.dat", ios::out | ios::binary);
        teach.write((char*)&TeacherDatabase[0], TeacherDatabase.size() * sizeof(Teacher));
        teach.close();

        ofstream books("book.dat", ios::out | ios::binary);
        books.write((char*)&BookDatabase[0], BookDatabase.size() * sizeof(Book));
        books.close();

        ofstream copies("copies.dat", ios::out | ios::binary);
        copies.write((char*)&CopiesDatabase[0], CopiesDatabase.size() * sizeof(Copy));
        copies.close();


        cout << "All data are serialized. You've existed the library system. \n";
    }
}

//Sign up function
void create() {
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

    if (exist(username)) {            //Returns true if this username is taken
        cout << "An account with this username already exist.\n";
    } else if (choice == 1) {
        Librarian newadmin(username, password);
        LibrarianDatabse.push_back(newadmin);
        cout << "A Librarian account with the username " << newadmin.getUsername() << " has been created\n";
        mainmenu();

    } else if (choice == 2) {
        Teacher newteacher(username, password);
        TeacherDatabase.push_back(newteacher);
        cout << "A Teacher account with the username " << newteacher.getUsername() << " has been created\n";
    } else if (choice == 3) {
        Student newstudent(username, password);
        StudentDatabase.push_back(newstudent);
        cout << "A Student account with the username " << newstudent.getUsername() << " has been created\n";
    }
}

//Check to see if a username already exist
    bool exist(string username) {

        vector<string> usernames;
        for (Librarian i : LibrarianDatabse) {
            usernames.push_back(i.getUsername());
        }
        for (Student i : StudentDatabase) {
            usernames.push_back(i.getUsername());
        }
        for (Teacher i : TeacherDatabase) {
            usernames.push_back(i.getUsername());
        }
        if (find(usernames.begin(), usernames.end(), username) != usernames.end()) {
            return true;
        } else
            return false;
    }

//Login Authentication
    void login() {
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

        if (choice == 1) {
            for (Librarian i : LibrarianDatabse) {
                if (username == i.getUsername()) {
                    valid = true;
                    librarian = i;
                }
                if (password == librarian.getPassword()) {
                    LibrarianLoggedin = true;
                    LibrarianMenu();
                    break;
                } else {
                    cout << "Invalid credential, username and password are case-sensitive, try again\n";
                    login();
                    break;
                }
            }
        } else if (choice == 2) {
            for (Student i : StudentDatabase) {
                if (username == i.getUsername()) {
                    valid = true;
                    student = i;
                }
                if (password == student.getPassword()) {
                    studentLoggedin = true;
                    ReaderMenu();
                    break;
                } else {
                    cout << "Invalid credential, username and password are case-sensitive, try again\n";
                    login();
                    break;
                }
            }
        } else if (choice == 3) {
            for (Teacher i : TeacherDatabase) {
                if (username == i.getUsername()) {
                    valid = true;
                    teacher = i;
                }
                if (password == teacher.getPassword()) {
                    TeacherLoggedin = true;
                    ReaderMenu();
                    break;
                } else {
                    cout << "Invalid credential, username and password are case-sensitive, try again";
                    login();
                    break;
                }
            }
        }
        if (!valid) {
            cout << "Invalid credentials, try again.";
            mainmenu();
        }
    }

//Menu for the readers
    void ReaderMenu() {
    cout << studentLoggedin;
    cout << TeacherLoggedin;

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
            ReaderMenu();

        }
        if (i == 2) {                         //Borrow books by Copy ID
            cout << "Enter the copy's ID number";
            int idnum;
            cin >> idnum;
            Copy c;
            bool found;
            for (Copy i : CopiesDatabase) {
                //has the copy, but lent to other
                if (c.getID() == idnum && i.isLent() == true) {
                    cout << "You cannot borrow this copy since it is lent to another account.\n";
                    found = true;
                    ReaderMenu();
                    break;
                    //has the copy, has reservers, and the account isn't the first reserver
                } else if (c.getID() == idnum && i.isLent() == false && i.getReservers()->size() != 0
                           && (i.getFirstReserver() != student.getUsername()
                               || i.getFirstReserver() != teacher.getUsername())) {
                    found = true;
                    cout << "You cannot borrow this copy since there are other account that reserved it.\n";
                    ReaderMenu();
                    break;
                }
                    //has the copy, has reservers, and the account is the first reserver or it has no reserver
                else if (c.getID() == idnum && i.isLent() == false
                         && (i.getFirstReserver() == teacher.getUsername() ||
                             i.getFirstReserver() == student.getUsername())
                         || i.noReservers()) {
                    bool multiple = false;
                    int j;
                    vector<Copy> multipleCopies;
                    for (Copy i : CopiesDatabase) {
                        if (i.getISBN() == c.getISBN()) {
                            multipleCopies.push_back(i);
                        }
                        j++;
                    }
                    if (multipleCopies.size() > 1) {                  //Check if there are multiple copies
                        multiple = true;
                    }

                    found = true;
                    c = i;
                    c.setLent(true);
                    clock_t current = clock();               //Make a borrow time;
                    clock_t cur_date = init_date + int(current - start) / CLOCKS_PER_SEC;
                    c.setBorrowTime(cur_date);
                    if (studentLoggedin) {
                        c.setReaderName(student.getUsername()); //Set the reader as the copy's borrower
                        student.setBorrowed(c);                 //Put the copy into the reader's list of borrowed copies
                        c.setExpirationTime(cur_date + student.getMax_days());      //set expiration date
                        cout << "Borrow Time Stamp: " << cur_date;
                        cout << "\nYou have successfully borrowed the copy\n";
                        ReaderMenu();
                        break;

                    } else if (TeacherLoggedin) {
                        c.setReaderName(teacher.getUsername()); //Set the reader as the copy's borrower
                        teacher.setBorrowed(c);                 //Put the copy into the reader's list of borrowed copies
                        c.setExpirationTime(cur_date + teacher.getMax_days());      //set expiration date
                        cout << "Borrow Time Stamp: " << cur_date;
                        cout << "You have successfully borrowed the copy\n";
                        ReaderMenu();
                        break;
                    }

                } else if (!found) {
                    cout << "No copies with this ID was found, try again\n";
                    ReaderMenu();
                    break;
                }
            }
        } else if (i == 3) {                     //Return a copy
            clock_t returnTime = clock();
            bool found = false;
            int count = 0;
            vector<Copy> borrowed;
            if (studentLoggedin) {
                Student:
                cout << "\nThese are your borrowed copies: \n";
                for (Copy i: student.getBorrowed()) {
                    cout << i;
                }
                cout << "\nNow enter the ID number of the copy you wish to return: ";
                int id;
                cin >> id;
                for (Copy i : CopiesDatabase) {
                    if (i.getID() == id) {
                        found = true;
                        cout << "\nReturn time stamp: " << (int) returnTime;
                        if (i.getExpirationTime() < returnTime) {
                            student.setPenalty(student.getPenalty() + 1);
                            cout << "\nThis copy was overdued. Your peanlty is now " << student.getPenalty();
                        }
                        student.removeFromBorrowed(i);
                        i.release();            //Release the book back for borrow
                        if (student.getPenalty() > 5) {
                            cout
                                    << "You've reach the maximum penalty of 5, you're only allow to keep 4 copies at a time.\n";
                            student.setMax_books(4);
                        }
                        cout << "You've successfully returned the book\n";
                        break;
                    }
                    count++;
                }
                if (!found) {
                    cout << "Invalid ID, try again";
                    goto Student;
                }
                ReaderMenu();

            } else if (TeacherLoggedin) {
                Teacher:
                cout << "\nThese are your borrowed copies: \n";
                for (Copy i: teacher.getBorrowed()) {
                    cout << i;
                }
                cout << "\nNow enter the ID number of the copy you wish to return: ";
                int id;
                cin >> id;
                for (Copy i : CopiesDatabase) {
                    if (i.getID() == id) {
                        found = true;
                        cout << "\nThe return time is " << (int) returnTime;
                        if (i.getExpirationTime() < returnTime) {
                            teacher.setPenalty(teacher.getPenalty() + 1);
                            cout << "\nThis copy was overdued. Your peanlty is now " << teacher.getPenalty();
                        }
                        if (teacher.getPenalty() > 5) {
                            cout
                                    << "You've reach the maximum peanlty of 5, you're only allow to keep 9 copies of books at a time\n";
                            teacher.setMax_books(9);
                        }
                        teacher.removeFromBorrowed(i);
                        i.release();            //Release the book back for borrow
                        cout << "You've successfully returned the book\n";
                        break;
                    }
                    count++;
                }
                if (!found) {
                    cout << "Invalid ID, try again";
                    goto Teacher;
                }
            }
        }
        else if(i == 4){
            bool found = false;
            Book reserveBook;
            cin >> reserveBook;
            Book actualBook;
            for(Book i : BookDatabase){
                if(i.getISBN() == reserveBook.getISBN()){
                        found = true;
                        actualBook = i;
                        break;
                }
            }
            if(!found){
                cout << "Invalid information, try again\n";
                ReaderMenu();
            }

                clock_t cur = clock();
                if(studentLoggedin){
                            student.setReserved(actualBook);
                            actualBook.addReserver(student);
                            cout << "You've successfully reserve the book!\n";
                            ReaderMenu();


                }
                else if(TeacherLoggedin){

                            teacher.setReserved(actualBook);
                            actualBook.addReserver(teacher);
                            cout << "You've successfully reserve the book!\n";
                            ReaderMenu();
                }

        }

        else if(i == 5){                    //Cancel reservation
            cout << "Enter the ISBN of the book reservation that you would like to cancel: \n";
            string isbn;
            cin >> isbn;
            Book cancel;
            if(studentLoggedin) {
                if(student.getBorrowed().empty()){
                    cout << "You do not have any reservation.\n";
                    ReaderMenu();
                }
                else {
                    for (Book i : student.getBorrowed()) {
                        if(i.getISBN() == isbn){
                            cancel = i;
                            break;
                        }
                    }

                    student.removeFromReserved(cancel);
                }
            }
            else if(TeacherLoggedin){
                if(teacher.getBorrowed().empty()){
                    cout << "You do not have any reservation.\n";
                    ReaderMenu();
                }
                else {
                    for (Book i : teacher.getBorrowed()) {
                        if(i.getISBN() == isbn){
                            cancel = i;
                            break;
                        }
                    }
                    teacher.removeFromReserved(cancel);
                }

            }
            cout << "Your reservation has been canceled";
            ReaderMenu();

        }



        else if (i == 6) {                //My information
            if (studentLoggedin) {
                cout << student;
            } else if (TeacherLoggedin) {
                cout << teacher;
            }
            ReaderMenu();
        } else if (i == 7) {                                    //Change password
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
        } else if (i == 8) {                  //Log out
            TeacherLoggedin = false;
            studentLoggedin = false;
            cout << "You've logged out of your account\n";
            mainmenu();
        }
    }

//Menu for the librarians
    void LibrarianMenu() {

        cout << "\nWelcome, Librarian. Select your option: \n1 -- Search Book\n2 -- Add Books\n3 -- Delete Book"
                "\n4 -- Search Users\n5 -- Add Users\n6 -- Delete Users"
                "\n7 -- My Information\n8 -- Change Password\n9 -- See all Copies"
                "\n0 -- Log Out\n";
        int i;
        cin >> i;
        if (i == 1) {
            cout << "Search by: " << endl;
            cout << "1 -- ISBN\n2 -- Title\n3 -- Author\n4 -- Category";
            cin >> i;
            SearchBook(i);
            LibrarianMenu();
        }
        else if (i == 2) {
            bool addCopy = false;
            Book newBook;
            cout << "Enter all information about the book without any spaces (CASE SENSITIVE)\n";
            cin >> newBook;
            for (Book i : BookDatabase) {
                if (i.getISBN() == newBook.getISBN()) {
                    addCopy = true;
                    break;
                }
            }
            if (!addCopy) {       //No copies exist yet, adding a new book and a copy.
                BookDatabase.push_back(newBook);
                newBook.setNumCopies(1);
                Copy bookCopy(newBook.getTitle(), newBook.getAuthor(), newBook.getCategory(), newBook.getISBN());
                bookCopy.setID(copyID);
                CopiesDatabase.push_back(bookCopy);
                cout << newBook.getTitle() << " has been added to the database with the ID number" << copyID << "\n";
            } else {               //Already has copies, add another 1, increment ID counter by 1.
                Copy bookCopy(newBook.getTitle(), newBook.getAuthor(), newBook.getCategory(), newBook.getISBN());
                bookCopy.setID(copyID);
                newBook.setNumCopies(newBook.getNumCopies());
                CopiesDatabase.push_back(bookCopy);
                cout << newBook.getTitle() << " has been added to the database with the ID number " << copyID << "\n";
            }
            copyID++;
            LibrarianMenu();

        } else if (i == 3) {
            bool hasCopy;
            int numSameCopies = 0, idnum;
            cout << "Enter the ID number of the book you wish to delete: \n";
            cin >> idnum;
            Book deletedBook;
            Copy deletedCopy;
            string ISBN;

            for (Copy i : CopiesDatabase) {
                if (idnum == i.getID()) {
                    hasCopy = true;
                    deletedCopy = i;
                    ISBN = deletedCopy.getISBN();
                }
                if (hasCopy && i.getISBN() == ISBN) {         // Check how many copies of the same book there are
                    numSameCopies++;
                }
            }
            if (!hasCopy) {                                   //Invalid ID number, no action is done
                cout << "No copy exist with this ID number, try again\n";
                LibrarianMenu();
            }

             else if (hasCopy && deletedCopy.isLent()) {       //Copy is lent out, no action is done
                cout << "The copy is lent out, so it cannot be deleted\n";
                LibrarianMenu();
            }
            int count = 0;
            for (Book i : BookDatabase) {
                if (ISBN == i.getISBN()) {
                    deletedBook = i;
                    break;
                }
                count++;
            }
            if (hasCopy && numSameCopies == 1) {         //remove the book if this is the last copy
                BookDatabase.erase(BookDatabase.begin() + count);
            }
            if (hasCopy) {
                for (Copy i : CopiesDatabase) {
                    int j = 0;
                    if (i.getID() == idnum) {
                        cout << "The copy with ID number " << idnum << " has been deleted.\n";
                        CopiesDatabase.erase(CopiesDatabase.begin() + j-1);
                        break;
                    }
                    j++;
                }
            }
            LibrarianMenu();
        }
        else if (i == 4) {            //Search user by username
            cout << "Enter a username";
            string name;
            cin >> name;
            bool found = false;
            Librarian lib;
            Student stu;
            Teacher teach;
            for (Librarian i : LibrarianDatabse) {
                if (i.getUsername() == name) {
                    found = true;
                    lib = i;
                    cout << "\nAccount found\nUsername: " << name << "\nPassword: " << i.getPassword() << "\n";
                    LibrarianMenu();
                    break;
                }
            }

            if (!found) {
                for (Student i : StudentDatabase) {
                    if (i.getUsername() == name) {
                        found = true;
                        stu = i;
                        cout << stu << "\n";
                        LibrarianMenu();
                        break;
                    }
                }
            }

            if (!found) {
                for (Teacher i : TeacherDatabase) {
                    if (i.getUsername() == name) {
                        found = true;
                        teach = i;
                        cout << i << "\n";
                        LibrarianMenu();
                        break;
                    }
                }
            }

            if (!found) {
                cout << "No user with this user name exist.\n";
                LibrarianMenu();
            }


        } else if (i == 5) {                        //Use create() method to add new user
            create();
            LibrarianMenu();
        } else if (i == 6) {
            int iterator = 0;
            cout << "Enter a username";
            string name;
            cin >> name;
            bool found = false;
            if (name == librarian.getUsername()) {
                cout << "You cannot delete your own account.\n";
                mainmenu();
            }

            for (Librarian i : LibrarianDatabse) {
                if (i.getUsername() == name) {
                    found = true;
                    LibrarianDatabse.erase(LibrarianDatabse.begin() + iterator);
                    cout << "Librarian account " << i.getUsername() << " has been deleted\n";
                    LibrarianMenu();
                    break;
                }
                iterator++;
            }

            if (!found) {
                iterator = 0;
                for (Student i : StudentDatabase) {
                    if (i.getUsername() == name) {
                        found = true;
                        StudentDatabase.erase(StudentDatabase.begin() + iterator);
                        cout << "Student account " << i.getUsername() << " has been deleted\n";
                        LibrarianMenu();
                        break;
                    }
                    iterator++;

                }
            }
            if (!found) {
                iterator = 0;
                for (Teacher i : TeacherDatabase) {
                    if (i.getUsername() == name) {
                        found = true;
                        TeacherDatabase.erase(TeacherDatabase.begin() + iterator);
                        cout << "Teacher account " << i.getUsername() << " has been deleted\n";
                        LibrarianMenu();
                        break;
                    }
                    iterator++;
                }
            }
            if (!found) {
                cout << "No user with this user name exist.\n";
            }
            LibrarianMenu();
        } else if (i == 7) {
            cout << librarian;
            LibrarianMenu();
        } else if (i == 8) {
            cout << "Enter your new password: ";
            string password;
            cin >> password;
            librarian.setPassword(password);
            cout << "New password has been set\n";
            LibrarianMenu();
        } else if (i == 9) {
            printBooks();
            LibrarianMenu();
        } else if (i == 0) {
            LibrarianLoggedin = false;
            cout << "\nYou're logged out now, see you!";
            mainmenu();
        }


    }

//Print all the copies in the system (debugging purposes)
    void printBooks() {
        for (Copy i : CopiesDatabase) {
            cout << i;
            cout << "\n";
        }
    }

//function to search a book and print it out if found
    void SearchBook(int i) {
        bool found = false;
        if (i == 1) {
            cout << "Enter the ISBN: ";
            string isbn;
            cin >> isbn;
            for (Book i : BookDatabase) {
                if (i.getISBN() == isbn) {
                    found = true;
                    cout << "Book Found\n" << i;
                }
            }
        } else if (i == 2) {
            cout << "Enter the Title (CASE SENSITIVE): ";
            string title;
            cin >> title;
            for (Book i : BookDatabase) {
                if (i.getTitle() == title) {
                    found = true;
                    cout << "Book Found\n" << i;
                }
            }
        } else if (i == 3) {
            cout << "Enter the author (CASE SENSITIVE): ";
            string author;
            cin >> author;
            for (Book i : BookDatabase) {
                if (i.getAuthor() == author) {
                    found = true;
                    cout << i << endl;
                }
            }

        } else if (i == 4) {
            cout << "Enter the Category (CASE SENSITIVE): ";
            string category;
            cin >> category;
            for (Book i : BookDatabase) {
                if (i.getCategory() == category) {
                    found = true;
                    cout << i << endl;
                }
            }
        }
        if (!found) {
            cout << "No book was found";
        }
        cout << "\n";
    }

void Serialization (){

}






