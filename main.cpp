//Practise_Library
//Frederik Hinz
//05.01.2021

#include "library.h"

int main(){
    library MyLib;
    while(true){
        string input;
        cout << "\nBibliotheksverwaltung\n"<<
                "(1) Buch anlegen\n"<<
                "(2) Buch löschen\n"<<
                "(3) Bestand anzeigen\n"<<
                "(4) Bücher nach Autor\n"<<
                "(5) Buch empfehlen\n"<<
                "(6) Bibliothek speichern\n"<<
                "(7) Bibliothek laden\n"<<
                "(8) Buch ausleihen\n"<<
                "(9) Buch zurückgeben\n"<<
                "(0) Programm verlassen\n";
        cin>>input;
        system("clear");
        if(input == "1")
            MyLib.addbook();
        else if(input == "2")
            MyLib.removebook();
        else if(input == "3")
            MyLib.show();
        else if(input == "4")
            MyLib.showsorted();
        else if(input == "5")
            MyLib.recommend();
        else if(input == "6")
            MyLib.safe();
        else if(input == "7")
            MyLib.load();
        else if(input == "8")
            MyLib.borrowbook();
        else if(input == "9")
            MyLib.handinbooks();
        else if(input == "0")
            return 0;
        else{
            cout<<"Ungültige Eingabe.\n";
            continue;
        }
    }
}
