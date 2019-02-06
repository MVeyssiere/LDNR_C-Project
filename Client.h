/*
 * Titulaire.h
 *
 *  Created on: 29 janv. 2019
 *      Author: ChristopheR_JulienMo_MarineV
 */
#include <iostream>
#include <string>
#include <vector>
#include "Compte.h"
using namespace std;

#ifndef TITULAIRE_H_
#define TITULAIRE_H_

class Client {
private:
	int id;
	string nom;
	string prenom;
	string adresse;
	vector<Compte*> comptesClient;

public:
	Client(int id);
	Client(int id, string nom, string prenom, string adresse);
	virtual void ModifierAdresse(string adresse);
	int Getid();
	string GetNom();
	string GetPrenom();
	virtual ~Client();
	// Fonction qui affichel e compte depuis l'extérieur de la classe
	friend ostream &operator<<(ostream &out, const Client &c);

};

// Fonction qui affiche le compte depuis l'extérieur de la classe
ostream &operator<<(ostream &out, const Client &c);

#endif /* TITULAIRE_H_ */
