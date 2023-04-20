#ifndef WARENGRUPPE_H
#define WARENGRUPPE_H

#include <string>
using namespace std;
class Warengruppe
{
private:
    int artikelnummer;
    string name;
    double preis;
    int preisCent;
    int anzahl;

public:
    Warengruppe();
    Warengruppe(int,string,double,int);

    int getArtikelnummer();
    string getName();
    double getPreis();
    int getAmount();

    void setName(string);
    //void setPreis(int);
    void setPreis(double);
    void setAmount(int);
};

#endif // WARENGRUPPE_H
