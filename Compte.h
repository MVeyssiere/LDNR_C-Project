/*
 * Comptes.h
 *
 *  Created on: 29 janv. 2019
 *      Author: ChristopheR_JulienMo_MarineV
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;
#include "Date.h"

#ifndef COMPTE_H_
#define COMPTE_H_

class Compte {
private:
	string nom_compte;
	int id_titulaire;
	float solde;
	float taux;
	Date date_ouverture;
	map<Date, float> dix_dernieres_operations;

public:
	Compte();
	Compte(string nom_compte, int id_titulaire, float solde, Date date_ouverture);
	Compte(string nom_compte, int id_titulaire, float solde, float taux, Date date_ouverture);
	Compte(string nom_compte, int id_titulaire, float solde, float taux, Date date_ouverture, map<Date, float> o);
	Compte(string nom_compte, int id_titulaire, float solde, Date date_ouverture, map<Date, float> o);
	Compte(string nom_compte, int id_titulaire, int solde, Date date_ouverture);
	Compte(Date date_ouverture);
	//int ConsulterSolde(Compte a);
	Date getDateOuverture();
	string GetNom();
	int GetTitulaire();
	float Getsolde();
	float Gettaux();
	map<Date, float> GetOperations();
	void Settaux(float taux);
	void Setsolde(float solde);
	void Crediter(float a);
	void Debiter(float d);
	int Actualiser(Date date_actuelle);
	void Afficher();
	void AfficherOperations();
	virtual void Menu(Date& date_actuelle) = 0;
	// Fonction qui saisit le compte depuis l'intérieur de la classe
	friend istream &operator>>(istream &in, Compte &e);
	// Fonction qui affichel e compte depuis l'intérieur de la classe
	friend ostream &operator<<(ostream &out, const Compte &e);
	//menu du banquier
	//void MenuBanquier();
	virtual ~Compte();
};

	// Fonction qui saisit le compte depuis l'extérieur de la classe
	istream &operator>>(istream &in, Compte &e);
	// Fonction qui affiche le compte depuis l'extérieur de la classe
	ostream &operator<<(ostream &out, const Compte &e);

#endif /* COMPTE_H_ */
