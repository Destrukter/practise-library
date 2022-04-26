#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;

class book
{
public:
    book(string authortemp, string titletemp);
    book(string authortemp, string titletemp, int numbertemp);
    //~book();
    string getauthor() const;
    string gettitle() const;
    string getborrowed() const;
    void setborrowed(string newb);
    int getnumber() const;
private:
    string borrowed;
    string author;
    string title;
    int number;
    static int counter;
};

#endif // BOOK_H
