/*
 * Comptebloque.h
 *
 *  Created on: 29 janv. 2019
 *      Author: ChristopheR_JulienMo_MarineV
 */
#include <iostream>
#include <string>
#include <map>
#include "Compte.h"
#include "Date.h"

#ifndef COMPTEBLOQUE_H_
#define COMPTEBLOQUE_H_

class Compte_bloque : public Compte{
private:
	static const int duree_blocage;
	static const float taux_interet;
	static const int montant_min;
public:
	//Compte_bloque();
	Compte_bloque(string nom_compte, int id_titulaire, int solde, Date date_ouverture);
	Compte_bloque(string nom_compte, int id_titulaire, int solde, Date date_ouverture, map<Date, float> operations);
	void Afficher();
	void EtatCompte(bool etat);
	bool TempsRestant(Date& date_actuelle);
	void Menu(Date& date_actuelle);
	void CalculInterets(Date& date_actuelle);
	~Compte_bloque();
};

#endif /* COMPTEBLOQUE_H_ */
