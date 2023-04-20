#include "warengruppe.h"

Warengruppe::Warengruppe()
{

}
Warengruppe::Warengruppe(int inArtikelnummer,string inName ,double inPreis, int inAmount)
{
    artikelnummer=inArtikelnummer;
    name = inName;
    preis=inPreis;
    anzahl=inAmount;
}
int Warengruppe::getArtikelnummer()
{
    return artikelnummer;
}
string Warengruppe::getName()
{
    return name;
}
double Warengruppe::getPreis()
{
    return preis;
}
int Warengruppe::getAmount()
{
    return anzahl;
}
void Warengruppe::setName(string inName)
{
    name=inName;
}
void Warengruppe::setPreis(double inPreis)
{
    preis=inPreis;
}
void Warengruppe::setAmount(int inAnz)
{
    anzahl=inAnz;
}
