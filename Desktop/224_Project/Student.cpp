//
// Created by Jane on 12/06/17.
//

#include "Student.h"

Student::Student(){
    setasTeacher();
    setMax_books(10);
    setMax_days(50);
}

Student::Student(string username, string password){
    this -> username = username;
    this -> password = password;
    setasStudent();
    setMax_books(5);
    setMax_days(30);

}



