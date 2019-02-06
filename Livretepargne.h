/*
 * Livretepargne.h
 *
 *  Created on: 29 janv. 2019
 *      Author: stagldnr
 */

#include <iostream>
#include <string>
#include <map>

#include "Compte.h"
#include "Date.h"

#ifndef LIVRETEPARGNE_H_
#define LIVRETEPARGNE_H_

class Livret_epargne : public Compte {
private:
	static const int montant_min;
	static const float taux_interet;
	static const int plafond_solde;
public:
	Livret_epargne(string nom_compte, int id_titulaire, int solde, Date date_ouverture);
	Livret_epargne(string nom_compte, int id_titulaire, int solde, Date date_ouverture, map<Date, float> operations);
	void Afficher();
	void Menu(Date& date_actuelle);
	void CalculInterets(Date& date_actuelle);
	~Livret_epargne();
};

#endif /* LIVRETEPARGNE_H_ */
