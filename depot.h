#ifndef DEPOT_H
#define DEPOT_H
#include <vector>
#include<iostream>
#include "warengruppe.h"
using namespace std;
class Depot
{
private:
    vector <Warengruppe> lager;
    vector <Warengruppe> lagernachname;
    int counter=100000;
    double exponetial(double,int);
    double round(double,int);
    string moneyOut(double);  
    bool loadedIn=false;
public:
    Depot();
    void warengruppeEinbuchen();
    void warengruppeAusbuchen();
    void artikelEntnehmen();
    void artikelAuffuellen();
    void preisAnpassung();
    void warenBestandNachNummer();
    void warenBestandNachName();
    void importieren();
    void exportieren();
    void inventur(vector <Warengruppe> lager);
    vector <Warengruppe> getLager();
    vector <Warengruppe> getLagerNachName();
    void sortLager();
    void gesamtInventur();
};

#endif // DEPOT_H
