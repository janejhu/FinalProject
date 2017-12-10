//
// Created by Jane on 12/06/17.
//

#ifndef INC_224_PROJECT_BOOK_H
#define INC_224_PROJECT_BOOK_H

#include<cstring>
#include<queue>

using namespace std;
class Reader;
class Student;
class Teacher;

class Book{
public:
    string ISBN;
    string title, author, category;
    int numCopies;
    int numReservers = 0;
    queue<Reader>* reservers;

public:
    Book();
    Book(string newTitle, string newAuthor, string newCategory, string ISBN);
    void setISBN(string newISBN);
    void setTitle(string newTitle);
    void setAuthor(string newAuthor);
    void setCategory(string newCategory);
    string getFirstReserver();
    void addReserver(Reader& aReader);
    void removeReserver(Reader & aReader);
    int getReserverSize();
    bool noReservers();
    void removeStudent(Student &stu);
    void removeTeacher(Teacher &teacher);

    int getNumReservers() const;

    void setNumReservers(int numReservers);

    string getISBN();
    string getTitle();
    string getAuthor();
    string getCategory();
    //queue<Reader> getReservers();

    int getNumCopies() const;

    void setNumCopies(int numCopies);

    queue<Reader> *getReservers() const;

    void setReservers(queue<Reader> *reservers);


    void setReservers(const queue<Reader> &reservers);

    //ostream &operator<<(ostream &os, const Book &book);
    friend ostream &operator<<(ostream &out, const Book &book);
    friend istream &operator>>(istream &in, Book &book);
    virtual void write(ostream&) const; //to be use by its based class
};


#endif //INC_224_PROJECT_BOOK_H
