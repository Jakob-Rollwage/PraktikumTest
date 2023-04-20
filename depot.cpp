#include "depot.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
string errorMessage = "Dies ist eine falsche Eingbabe. Bitte geben Sie eine Zahl von 0-10 ein.";
Depot::Depot()
{

}
void Depot::warengruppeAusbuchen()
{
    int artikelNr;
    cout<<"Zu loeschender Artikel(nr): ";
    cin >>artikelNr;
    for(int i=0;i<lager.size();i++)
    {
        if(lager.at(i).getArtikelnummer()==artikelNr)
        {
            lager.erase(lager.begin()+i);
            return;
        }
    }
    cout<<"Der Artikel mit der Artikelnummer ist nicht im System erfasst"<<endl;
    return;
}
void Depot::warengruppeEinbuchen()
{
    string warenname;
    int amount;
    double preis;
    cout<<"Warenname:"<<endl;
    cin >> warenname;
    cout<<"Anzahl:"<<endl;
    cin >> amount;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << errorMessage << endl;
        return;
    }
    cout<<"Preis"<<endl;
    cin >> preis;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << errorMessage << endl;
        return;
    }
    lager.push_back(Warengruppe(counter,warenname,preis,amount));
    counter++;
}
void Depot::artikelAuffuellen()
{
    int artikelNr;
    int anzAuffuellen;
    cout<<"Aufzufuellender Artikel(nr): ";
    cin >>artikelNr;
    cout<<"Anz Auffuellen: ";
    cin>> anzAuffuellen;
    for(int i=0;i<lager.size();i++)
    {
        if(lager.at(i).getArtikelnummer()==artikelNr)
        {
            lager.at(i).setAmount(lager.at(i).getAmount()+anzAuffuellen);
            return;
        }
    }
    cout<<"Der Artikel mit der Artikelnummer ist nicht im System erfasst"<<endl;
    return;
}
void Depot::artikelEntnehmen()
{
    int artikelNr;
    int anzLoeschen;
    cout<<"Zu entnehmender Artikel(nr): ";
    cin >>artikelNr;
    cout<<"Anz Entnehmen: ";
    cin>> anzLoeschen;
    for(int i=0;i<lager.size();i++)
    {
        if(lager.at(i).getArtikelnummer()==artikelNr)
        {
            if(lager.at(i).getAmount()-anzLoeschen>0)
            {
                lager.at(i).setAmount(lager.at(i).getAmount()-anzLoeschen);
            }
            else if(lager.at(i).getAmount()-anzLoeschen==0)
            {
                lager.erase(lager.begin()+i);
            }
            else
            {
                cout<<"So viele Artikel befinden sich nicht im Lager"<<endl;
            }
            return;
        }
    }
    cout<<"Der Artikel mit der Artikelnummer ist nicht im System erfasst"<<endl;
    return;
}
void Depot::preisAnpassung()
{
    int artikelNr;
    double neuerPreis;
    cout<<"Artikelnummer: ";
    cin >> artikelNr;
    for(int i=0;i<lager.size();i++)
    {
        if(lager.at(i).getArtikelnummer()==artikelNr)
        {
            cout<<"Prozent vom alten Preis: ";
            cin >> neuerPreis;
            lager.at(i).setPreis(lager.at(i).getPreis()*neuerPreis);
            return;
        }
    }
    cout<<"Der Artikel mit der Artikelnummer ist nicht im System erfasst"<<endl;
    return;
}
void Depot::warenBestandNachNummer()
{
    int artikelNr;
    cout<<"Artikelnummer: ";
    cin >> artikelNr;
    for(int i=0;i<lager.size();i++)
    {
        if(lager.at(i).getArtikelnummer()==artikelNr)
        {
            int spaltenBreite=10;
            cout<<setw(20)<<"Artikelnummer";
            cout<<setw(spaltenBreite)<<"Name";
            cout<<setw(spaltenBreite)<<"Preis";
            cout<<setw(spaltenBreite)<<"Anzahl";
            cout<<endl;
            cout<<setw(20)<<lager.at(i).getArtikelnummer();
            cout<<setw(spaltenBreite-1)<<lager.at(i).getName();
            cout<<setw(spaltenBreite)<<moneyOut(lager.at(i).getPreis())<<"$";
            cout<<setw(spaltenBreite)<<lager.at(i).getAmount();
            cout<<endl;
        }
    }
    cout<<"Der Artikel mit der Artikelnummer ist nicht im System erfasst"<<endl;
    return;
}
void Depot::warenBestandNachName()
{
    string name;
    cout<<"Artikelname: ";
    cin >> name;
    for(int i=0;i<lager.size();i++)
    {
        if(lager.at(i).getName()==name)
        {
            int spaltenBreite=10;
            cout<<setw(20)<<"Artikelnummer";
            cout<<setw(spaltenBreite)<<"Name";
            cout<<setw(spaltenBreite)<<"Preis";
            cout<<setw(spaltenBreite)<<"Anzahl";
            cout<<endl;
            cout<<setw(20)<<lager.at(i).getArtikelnummer();
            cout<<setw(spaltenBreite-1)<<lager.at(i).getName();
            cout<<setw(spaltenBreite)<<moneyOut(lager.at(i).getPreis())<<"$";
            cout<<setw(spaltenBreite)<<lager.at(i).getAmount();
            cout<<endl;
        }
    }
    cout<<"Der Artikel mit der Artikelnummer ist nicht im System erfasst"<<endl;
    return;
}

void Depot::exportieren()
{
    string filename ="../myDepot.txt";
    ofstream myfile(filename);
    if (myfile.is_open()){
        for (int i = 0; i < lager.size(); i++)
        {
            myfile << lager.at(i).getName() << ";" << lager.at(i).getAmount()<< ";"<<stod(moneyOut(lager.at(i).getPreis()))*100 << endl;
        }
        myfile.close();
    }
    else
    {
        cout<<"Das file konnte nicht geoeffnet werden"<<endl;
    }
    return;
}

void Depot::importieren()
{
    if(loadedIn)
    {
        cout<<"Du hast bereits geladen"<<endl;
        return;
    }
    string filename="../myDepot.txt";
    ifstream myfile(filename);
    string line = "";
    string word = "";
    string iName;
    int iAnzahl;
    double iPreis;
    if (myfile.is_open())
    {
        while(getline(myfile, line))
        {
            stringstream str(line);
            getline(str, word, ';');
            iName = word;
            getline(str, word, ';');
            iAnzahl = stoi(word);
            getline(str, word);
            iPreis = stod(word)/100;
            lager.push_back(Warengruppe(counter,iName,iPreis,iAnzahl));
            counter++;
        }
        myfile.close();
    }
    loadedIn=true;
}

void Depot::inventur(vector <Warengruppe> lager)
{
    int spaltenBreite=10;
    cout<<setw(20)<<"Artikelnummer";
    cout<<setw(spaltenBreite)<<"Name";
    cout<<setw(spaltenBreite)<<"Preis";
    cout<<setw(spaltenBreite)<<"Anzahl";
    cout<<endl;
    for(int i=0;i<20+3*spaltenBreite;i++)
    {
        cout<<"-";
    }
    cout<<endl;
    for(int i=0;i<lager.size();i++)
    {
        cout<<setw(20)<<lager.at(i).getArtikelnummer();
        cout<<setw(spaltenBreite)<<lager.at(i).getName();
        cout<<setw(spaltenBreite-1)<<moneyOut(lager.at(i).getPreis())<<"$";
        cout<<setw(spaltenBreite)<<lager.at(i).getAmount();
        cout<<endl;

    }
}

double Depot::exponetial(double input, int exponent)
{
    if(exponent<=0)
    {
        return 1;
    }
    return input*exponetial(input,exponent-1);
}
double Depot::round(double input,int nachkommastellen)
{
    int buffer=input*exponetial(10, nachkommastellen);
    input=(double)buffer/exponetial(10, nachkommastellen);
    return input;
}
string Depot::moneyOut(double moneyInput)
{
    string outputString;
    moneyInput=round(moneyInput,2);
    //cout<<"moneyInput: "<<moneyInput<<endl;
    if( (int)(moneyInput*100)%100==0 )
    {
        for(int i=0;i<to_string(round(moneyInput,2)).length()-6;i++)
        {
               outputString+=to_string(round(moneyInput,2))[i];
        }

        return outputString+"00";
    }
    if( (int)(moneyInput*100)%10==0 )
    {
        for(int i=0;i<to_string(round(moneyInput,2)).length()-5;i++)
        {
               outputString+=to_string(round(moneyInput,2))[i];
        }
        return outputString+"0";
    }
    return outputString;
}
vector <Warengruppe> Depot::getLager()
{
    return lager;
}
vector <Warengruppe> Depot::getLagerNachName()
{
    return lagernachname;
}

void Depot::sortLager()
{
    lagernachname.clear();
    lagernachname=lager;
    Warengruppe buffer;
    for(int i=0;i<lagernachname.size()-1;i++)
    {
        for(int k=0;k<lagernachname.size()-1;k--)
        {
            if(lagernachname.at(k).getName()>lagernachname.at(k+1).getName())
            {
                buffer=lagernachname.at(k);
                lagernachname.at(k)=lagernachname.at(k+1);
                lagernachname.at(k+1)=buffer;
            }
        }
    }
}
void Depot::gesamtInventur()
{
    int gesamtAnz=0;
    double gesamtpreis=0;
    int spaltenBreite=10;
    double teilpreis=0;
    cout<<setw(20)<<"Artikelnummer";
    cout<<setw(spaltenBreite)<<"Name";
    cout<<setw(spaltenBreite)<<"Preis";
    cout<<setw(spaltenBreite)<<"Anzahl";
    cout<<setw(spaltenBreite)<<"Gesamt";
    cout<<endl;
    for(int i=0;i<20+3*spaltenBreite;i++)
    {
        cout<<"-";
    }
    cout<<endl;
    for(int i=0;i<lager.size();i++)
    {
        cout<<setw(20)<<lager.at(i).getArtikelnummer();
        cout<<setw(spaltenBreite)<<lager.at(i).getName();
        cout<<setw(spaltenBreite-1)<<moneyOut(lager.at(i).getPreis())<<"$";
        cout<<setw(spaltenBreite)<<lager.at(i).getAmount();
        cout<<setw(spaltenBreite-1)<<moneyOut(lager.at(i).getAmount()*lager.at(i).getPreis())<<"$";
        cout<<endl;
        gesamtAnz+=lager.at(i).getAmount();
        teilpreis+=lager.at(i).getPreis();
        gesamtpreis+=lager.at(i).getPreis()*lager.at(i).getAmount();
    }
    for(int i=0;i<20+3*spaltenBreite;i++)
    {
        cout<<"=";
    }
    cout<<endl;
    cout<<setw(20)<<"Bestand insgesamt";
    cout<<setw(spaltenBreite)<<"";
    cout<<setw(spaltenBreite)<<"";
    //cout<<setw(spaltenBreite-1)<<moneyOut(teilpreis)<<"$";
    cout<<setw(spaltenBreite)<<gesamtAnz;
    cout<<setw(spaltenBreite-1)<<moneyOut(gesamtpreis)<<"$";
}
