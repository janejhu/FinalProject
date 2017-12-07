//
// Created by Jane on 12/06/17.
//

#include "Teacher.h"

Teacher::Teacher() {
    setasTeacher();
    setMax_books(10);
    setMax_days(50);


}

Teacher::Teacher(string username, string password){
    this -> username = username;
    this -> password = password;
    setasTeacher();
    setMax_books(10);
    setMax_days(50);

}

