#include "book.h"

int book::counter = 1;

book::book(string authortemp, string titletemp){
    author = authortemp;
    title = titletemp;
    number = counter;
    borrowed = "";
    counter++;
}

book::book(string authortemp, string titletemp, int numbertemp){
    author = authortemp;
    title = titletemp;
    number = numbertemp;
    borrowed = "";
    counter = numbertemp+1;
}

//book::~book(){
//}

string book::getborrowed() const{
    return borrowed;
}

void book::setborrowed(string newb){
    borrowed = newb;
}

string book::getauthor() const{
    return author;
}

string book::gettitle() const{
    return title;
}

int book::getnumber() const{
    return number;
}
