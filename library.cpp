#include "library.h"
#include <fstream>

library::library(){
}

int stringtoint(string stringtemp){
    int length = stringtemp.length();
    int temp;
    int result = 0;
    for(int i = 0; i<length; i++){
        int digit = 1;
        for(int c = length-1-i; c>0; c--){
            digit *= 10;
        }
        temp = (stringtemp[i]-48)*digit;
        result += temp;
    }
    return result;
}




void library::safe() const{
    ofstream SAFE("Library");
    if(SAFE.is_open()){
        for(unsigned int c = 0; c!=list.size(); c++)
            SAFE << list[c]->getauthor() << endl << list[c]->gettitle() << endl << list[c]->getnumber() << endl;
        SAFE.close();
        cout<< "Bibliothek erfolgreich gespeichert.\n";
    }
    else
        cout << "Datei konnte nicht geöffnet werden.\n";
}

void library::load() {
    for(unsigned int c=0; c>list.size();c++){
        delete list[c];
    }
    list.clear();
    string line;
    ifstream LOAD("Library");
    if (LOAD.is_open()){
        string loadauthor;
        string loadtitle;
        int loadnumber;
        short int c = 1;
        while(getline(LOAD, line)){
            if(c==1)
                loadauthor = line;
            else if(c==2)
                loadtitle = line;
            else if(c==3){
                loadnumber = stringtoint(line);
                list.push_back(new book(loadauthor, loadtitle, loadnumber));
                c=0;
            }
            c++;
        }
        cout<< "Bibliothek erfolgreich geladen.\n";
    }
    else
        cout << "Datei konnte nicht geöffnet werden.\n" << endl;
}

void library::recommend() const{
    vector <book*> temp;
    string searchedauthor;
    bool free = false;
    if(list.size()==0){
        cout<<"Noch kein Buch in Bibliothek\n";
        return;
    }
    cout<<"Von welchem Autor(Nachname) soll das Buch sein?\n";
    cin>>searchedauthor;
    for(unsigned int c = 0; c!=list.size(); c++){
        if(searchedauthor == list[c]->getauthor()){
            temp.push_back(list[c]);
        }
    }
    if(temp.size()==0){
        cout<<"Autor nicht gefunden.\n";
        reccomendAll();
    }
    else{
        for(unsigned int c = 0; c!=temp.size(); c++){
            if(temp[c]->getborrowed() == ""){
                free = true;
                break;
            }
        }
        if(!free){
            cout<<"Alle Bücher dieses Autors sind ausgeliehen.\n";
            reccomendAll();
            return;
        }
        int r;
        srand(time(NULL));
        cout<<"Autor gefunden, hier unsere Empfehlung:\n";
        do{
            r = rand() % temp.size();
        }while (list[r]->getborrowed() != "");
        cout<<temp[r]->getauthor()<<" "<<temp[r]->gettitle()<<endl;
    }

}

void library::reccomendAll() const{
    bool free = false;
    for(unsigned int c = 0; c!=list.size(); c++){
        if(list[c]->getborrowed() == ""){
            free = true;
            break;
        }
    }
    if(!free){
        cout<<"Keine Empfehlung moglich, alle Bücher sind ausgeliehen.\n";
        return;
    }
    cout<<"Hier eine Empfehlung aus unserer Bibliothek.\n";
    srand(time(NULL));
    int r;
    do{
        r = rand() % list.size();
    }while (list[r]->getborrowed() != "");
    cout<<list[r]->getauthor()<<" "<<list[r]->gettitle()<<endl;
}

void library::show() const{
    cout.setf(ios::left);
    cout<<setw(8)<<"Nummer:"<<"| "<<setw(25)<<"Autor:"<<"| "<<setw(25)<<"Titel:"<<"| "<<"Ausgeliehen:\n";
    for(unsigned int c = 0; c!=list.size(); c++){
        cout.width(8);
        cout<<list[c]->getnumber();
        cout<<"| ";
        cout.width(25);
        cout<<list[c]->getauthor();
        cout<<"| ";
        cout.width(25);
        cout<<list[c]->gettitle();
        cout<<"| ";
        cout<<list[c]->getborrowed()<<endl;
    }
    cout<<endl;
}

void library::showsorted() const{
    vector <book*> listcopy = list;
    string tempj;
    string tempj1;
    if(list.size()!=0){
        for (unsigned int i = 1; i<=listcopy.size()-1; i++){
            for(unsigned int j = listcopy.size()-1; j>=i; j--){
                tempj = listcopy[j]->getauthor();
                tempj1 = listcopy[j-1]->getauthor();
                for(unsigned int p = 0; p<listcopy[j-1]->getauthor().size(); p++){
                    if(listcopy[j-1]->getauthor()[p] >= 65 && listcopy[j-1]->getauthor()[p] <= 90){
                        tempj1[p] += 32;
                    }
                }
                for(unsigned int p = 0; p<listcopy[j]->getauthor().size(); p++){
                    if(listcopy[j]->getauthor()[p] >= 65 && listcopy[j]->getauthor()[p] <= 90){
                        tempj[p] += 32;
                    }
                }
                if(tempj1>tempj){
                    swap(listcopy[j-1], listcopy[j]);
                }
            }
        }
    }
    cout.setf(ios::left);
    cout<<setw(25)<<"Autor:"<<"| "<<setw(25)<<"Titel:"<<"| "<<setw(8)<<"Nummer:"<<"| "<<"Ausgeliehen:\n";
    for(unsigned int c = 0; c!=list.size(); c++){
        cout.width(25);
        cout<<listcopy[c]->getauthor();
        cout<<"| ";
        cout.width(25);
        cout<<listcopy[c]->gettitle();
        cout<<"| ";
        cout.width(8);
        cout<<listcopy[c]->getnumber();
        cout<<"| ";
        cout<<listcopy[c]->getborrowed()<<endl;
    }
    cout<<endl;
}

void library::addbook(){
    string inputauthor;
    string inputtitle;
    cout<<"Autor?\n";
    cin.ignore();
    getline(cin, inputauthor);
    cout<<"Titel?\n";
    getline(cin, inputtitle);
    list.push_back(new book(inputauthor, inputtitle));
    cout<<"Buch erfolgreich hinzugefügt\n";
}

book* library::searchbook(int &place) const{
    string inputnumbertemp;
    int inputnumber;
    cout<<"Buchnummer?\n";
    cin>>inputnumbertemp;
    inputnumber = stringtoint(inputnumbertemp);
    for(unsigned int c = 0; c!=list.size(); c++){
        if(inputnumber==list[c]->getnumber()){
            if(list[c]->getborrowed() != ""){
                cout<<"Buch ist ausgeliehen von: "<<list[c]->getborrowed()<<".\n";
                return nullptr;
            }
            place = c;
            return list[c];
        }
    }
    cout<<"Buchnummer nicht gefunden.\n";
    return nullptr;
}

void library::removebook(){
    book* remove;
    int c;
    remove = searchbook(c);
    if(remove != nullptr){
        cout<<remove->gettitle()<<" von "<<remove->getauthor()<<" erfolgreich gelöscht.\n";
        delete remove;
        list.erase(list.begin() + c);
    }
}

void library::borrowbook(){
    book* borrow;
    int c;
    string name;
    cout<<"Wie heißen Sie(Nachname)?\n";
    cin>>name;
    if(name != ""){
        borrow = searchbook(c);
        if(borrow!=nullptr){
            borrow->setborrowed(name);
        }
    }
}

void library::handinbooks(){
    string name;
    bool found = false;
    cout<<"Wie heißen Sie(Nachname)?\n";
    cin>>name;
    for(unsigned int c = 0; c!=list.size(); c++){
        if(name==list[c]->getborrowed()){
            list[c]->setborrowed("");
            found = true;
            cout<<"Buch: "<<list[c]->gettitle()<<" wieder freigegeben.\n";
        }
    }
    if(!found)
        cout<<"Name nicht gefunden.\n";
}
