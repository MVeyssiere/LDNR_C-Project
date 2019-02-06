/*
 * Date.h
 *
 *  Created on: 31 janv. 2019
 *      Author: stagldnr
 */


#include <iostream>
#include <string.h>
using namespace std;

#ifndef DATE_H_
#define DATE_H_

class Date {
private:
	int jour;
	int mois;
	int annee;

public:
	//Setters
	void setJour (int a);
	void setMois (int a);
	void setAnnee (int a);

	//Getters
	void getDate ();
	int getMois();
	int getAnnee();

	//constructeurs
	Date();
	Date(const Date &CopieDate);
	Date(int i);
	Date(int j, int m);
	Date(int j, int m, int a);
	~Date();

	//opérateurs
	operator double() const;
	Date& operator= (const Date& d);
	friend istream& operator>> (istream& in, Date& d);
	friend ostream& operator<< (ostream& out, Date d);
	friend bool operator== (const Date& d1, const Date& d2);

	//méthodes
	void SaisirDate ();
	void AfficherDate ();
	void AffecterDate (Date &d);
	bool ComparerDate (const Date &d) const;
	int TempsRestant (const Date& d1, const Date& d2);
	void Estbissextile ();
	Date AjouterAnnee ();
	void setMoissaut(int a);
	void setAnneesaut(int a);
};

#endif /* DATE_H_ */
