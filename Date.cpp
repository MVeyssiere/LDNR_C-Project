/*
 * Date.cpp
 *
 *  Created on: 31 janv. 2019
 *      Author: ChristopheR_JulienMo_MarineV
 */

#include <iostream>
#include "Date.h"

// Constructeurs de la classe Date

Date::Date(){
	jour=1;
	mois=1;
	annee=00;
}

Date::Date(int j, int m, int a){
	jour=j;
	mois=m;
	annee=a;
}

Date::Date(const Date &CopieDate){
	jour=CopieDate.jour;
	mois=CopieDate.mois;
	annee=CopieDate.annee;
}

Date::Date(int i){ // Conversion d'un entier vers la date
	jour=1;
	mois=1;
	annee=i;
}

// Opérateurs de la classe Date

Date::operator double() const{
	return ((jour*1000000)+(mois*10000)+(annee));
}

Date& Date::operator= (const Date& d){
    jour=d.jour;
    mois=d.mois;
    annee=d.annee;
    return (*this);
}

istream& operator>> (istream& in, Date& d){
    do{
		cout<<"Saisissez le jour de la date"<<endl;
		in>>d.jour;
        if ((d.jour<1) || (d.jour>31)){
        	cout<<"Saisie incorrecte"<<endl;
        }
    } while ((d.jour<1) || (d.jour>31));

    do{
		cout<<"Saisissez le mois de la date"<<endl;
		in>>d.mois;
		if ((d.mois<1) || (d.mois>12)){
			cout<<"Saisie incorrecte"<<endl;
		}
    }while ((d.mois<1) || (d.mois>12));

    do{
		cout<<"Saisissez l'annee de la date"<<endl;
		in>>d.annee;
        if ((d.annee<1) || (d.annee>9999)){
        	cout<<"Saisie incorrecte"<<endl;
        }
    } while ((d.annee<1) || (d.annee>9999));

    return in;
}

ostream& operator<< (ostream& out, Date d){
    out << d.jour << " / " << d.mois <<" / " << d.annee << endl;
    return out;
}

bool operator== (const Date& d1, const Date& d2){
    if (d1.jour == d2.jour && d1.mois == d2.mois && d1.annee == d2.annee){
        cout << "Ces deux dates sont identiques" << endl;
        return true;
	}
	else{
        cout << "Ces deux dates sont différentes" << endl;
        return false;
    }
}


// Méthodes de la classe Date

void Date::SaisirDate (){
    do{
		cout << "Saisissez le jour de la date" << endl;
		cin >> jour;
		if ((jour < 1) || (jour > 31)){
			cout<<"Saisie incorrecte" << endl;
		}
    } while ((jour < 1) || (jour > 31));

    do{
		cout << "Saisissez le mois de la date" << endl;
		cin >> mois;
		if ((mois < 1) || (mois > 12)){
			cout << "Saisie incorrecte" << endl;
		}
    } while ((mois < 1) || (mois > 12));

    do{
		cout << "Saisissez l'annee de la date" << endl;
		cin >> annee;
		if ((annee < 1) || (annee > 9999)){
			cout << "Saisie incorrecte" << endl;
		}
    } while ((annee < 1) || (annee > 9999));
}

void Date::AfficherDate (){
    cout << jour << " / " << mois << " / " << annee << endl;
}

void Date::AffecterDate (Date &d){
    d.jour=jour;
    d.mois=mois;
    d.annee=annee;
}

bool Date::ComparerDate (const Date &d) const{
    if (jour == d.jour && mois == d.mois && annee == d.annee){
        cout << "Ces deux dates sont identiques" << endl;
        return true;
	}
    else{
        cout << "Ces deux dates sont différentes" << endl;
        return false;
    }
}

int Date::TempsRestant (const Date& d1, const Date& d2){
	int calcul = (d2.annee - d1.annee) * 12 + (d2.mois - d1.mois);
	return calcul;
}

void Date::Estbissextile (){
    if (annee % 400 == 0)
    cout << "Cette annee est bissextile" << endl;
    else if (annee % 4 == 0 && annee % 100 != 0)
    cout << "Cette annee est bissextile" << endl;
    else
    cout << "Cette annee n'est pas bissextile" << endl;
}

Date Date::AjouterAnnee (){
    int ajout;
    cout << "Saisissez le nombre d'annee a ajouter a la date" << endl;
    cin >> ajout;
    annee = annee + ajout;
    return *this;
}

// Getters and setters
void Date::setJour(int a){
    this->jour = a;
}
void Date::setMois(int a){
    this->mois = a;
}
void Date::setAnnee(int a){
    this->annee = a;
}
void Date::setMoissaut(int a){
    this->mois = mois+a;
}
void Date::setAnneesaut(int a){
    this->annee = annee + a;
}
void Date::getDate(){
    cout << jour << " / " << mois << "/" << annee << endl;
}
int Date::getMois(){
    return mois;
}
int Date::getAnnee(){
    return annee;
}

// Destructeur de la classe Date
Date::~Date(){}
