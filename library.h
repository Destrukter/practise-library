#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include <iomanip>
#include "book.h"

class library
{
public:
    library();
    void safe() const;
    void load();
    void show() const;
    void showsorted() const;
    void addbook();
    void removebook();
    void recommend() const;
    void reccomendAll() const;
    book* searchbook(int &place) const;
    void borrowbook();
    void handinbooks();
private:
    vector <book*> list;
};

int stringtoint(string stringtemp);

#endif // LIBRARY_H
