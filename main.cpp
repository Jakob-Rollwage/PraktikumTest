#include <iostream>
#include <iomanip>
#include "depot.h"
using namespace std;


int main()
{
    Depot myDepot;
    int input;
    string errorMessage = "Dies ist eine falsche Eingbabe. Bitte geben Sie eine Zahl von 0-10 ein.";

while(true)
{


    cout << R"(
(1) Warengruppe einbuchen
(2) Warengruppe ausbuchen
(3) Artikel entnehmen
(4) Artikel auffuellen
(5) Preisanpassung durchfuehren
(6) Warenbestand nach Nummer ausgeben
(7) Warenbestand nach Artikel ausgeben
(8) Inventur durchfuehren
(9) Lagerbestand exportieren
(10) Lagerbestand importieren
(0) Programm-Ende
)"<<endl;

    cin >> input;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << errorMessage << endl;
        continue;
    }
    else if(input==1)
    {
        myDepot.warengruppeEinbuchen();
    }
    else if(input==2)
    {
        myDepot.warengruppeAusbuchen();
    }
    else if(input==3)
    {
        myDepot.artikelEntnehmen();
    }
    else if(input==4)
    {
        myDepot.artikelAuffuellen();
    }
    else if(input==5)
    {
        myDepot.preisAnpassung();
    }
    else if(input==6)
    {
        myDepot.inventur(myDepot.getLager());
    }
    else if(input==7)
    {
        //myDepot.warenBestandNachName();
        myDepot.inventur(myDepot.getLagerNachName());
        cout<< setw(20)<<"Algorithmus: "<<setw(20)<<"Bubblesort"<<endl;
        cout<< setw(20)<<"Komplexitaet: "<<setw(20)<<"O(n^2)"<<endl;
        cout<< setw(20)<<"Speicherbedarf "<<setw(20)<<"in place (+Buffer)"<<endl;
        cout<< setw(20)<<"Stabilitaet: "<<setw(20)<<"stabil"<<endl;
        cout<< setw(20)<<"Natuerlichkeit: "<<setw(20)<<"natuerlich"<<endl;
    }
    else if(input==8)
    {
        myDepot.gesamtInventur();
    }
    else if(input==9)
    {
        myDepot.exportieren();
    }
    else if(input==10)
    {
        myDepot.importieren();
        myDepot.inventur(myDepot.getLager());
    }
    else if(input==0)
    {
        return 10;
    }
    else
    {
        cout << errorMessage << endl;
    }
    myDepot.sortLager();
}
    return 0;
}
