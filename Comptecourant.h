/*
 * Comptecourant.h
 *
 *  Created on: 29 janv. 2019
 *      Author: ChristopheR_JulienMo_MarineV
 */
#include <iostream>
#include <string>
#include <map>

#include "Compte.h"
#include "Date.h"

#ifndef COMPTECOURANT_H_
#define COMPTECOURANT_H_

class Compte_courant : public Compte{
private:
	static const float decouvert_autorise;
	//map<Date, float> dix_dernieres_operations;

public:
	Compte_courant(string nom_compte, int id_titulaire, float solde, float taux, Date date_ouverture);
	Compte_courant(string nom_compte, int id_titulaire, float solde, float taux, Date date_ouverture, map<Date, float> operations);
	void Afficher();
	bool SeuilAlerte();
	void CalculAgios();
	void Menu(Date& date_actuelle);
	~Compte_courant();
};

#endif /* COMPTECOURANT_H_ */
