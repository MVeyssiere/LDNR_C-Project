/*
 * Livretepargne.cpp
 *
 *  Created on: 29 janv. 2019
 *      Author: stagldnr
 */

#include "Compte.h"
#include "Livretepargne.h"

// Constructeur de Livret_epargne
Livret_epargne::Livret_epargne(string nom_compte, int id_titulaire, int solde, Date date_ouverture) :Compte(nom_compte, id_titulaire, solde, date_ouverture){
	Compte::Settaux(taux_interet);
	cout << "Création du livret d'épargne." << endl;
}
Livret_epargne::Livret_epargne(string nom_compte, int id_titulaire, int solde, Date date_ouverture, map <Date, float> operations) :Compte(nom_compte, id_titulaire, solde, date_ouverture, operations){
	Compte::Settaux(taux_interet);
	cout << "Création du livret d'épargne." << endl;
}

void Livret_epargne::Afficher(){
	Compte::Afficher();
	cout << "Montant de dépôt minimum = "    << montant_min   << " euros" << endl;
	cout << "Montant du plafond du solde = " << plafond_solde << " euros" << endl;
}

void Livret_epargne::CalculInterets(Date& date_actuelle){
	float result_interets;
	Date date_ouverture = getDateOuverture();
	result_interets = taux_interet * Compte::Getsolde();
	cout << "Le montant total de vos interêts pour ce compte est de: " << result_interets << " euros" << endl;
	Compte::Setsolde(Compte::Getsolde() + result_interets);
}

void Livret_epargne::Menu(Date& date_actuelle){
	int choix_cb;
	float montant;
	cout << endl << "-------Menu de votre livret d'épargne-------" << endl;
	cout << "Taper 1: Créditer votre livret d'épargne " << endl;
	cout << "Taper 2: Débiter votre livret d'épargne " << endl;
	cout << "Taper 3: Afficher les dernières opérations effectuées sur votre livret d'épargne" << endl;
	cout << "Taper 4: Actualiser votre livret d'épargne" << endl;
	cout << "Votre choix = ";
	cin >> choix_cb;

	switch(choix_cb){

		case 1: cout << "\n--Créditer votre livret d'épargne " << endl;

				cout << "\nSaisir le montant que vous voulez créditer sur votre livret d'épargne: " << endl;
				cin >> montant;

				while (montant + Compte::Getsolde() > plafond_solde){
					cout << "Votre livret d'épargne étant plafonné à 7700 euros, veuillez ressaisir le montant que vous souhaitez créditer: " << endl;
					cin >> montant;
				}
				Compte::Crediter(montant);
				cout << "Votre livret d'épargne a bien été crédité de " << montant << " euros." << endl;
				Livret_epargne::Afficher();
				break;

		case 2: cout << "\n--Débiter votre livret d'épargne "<< endl;

				cout << "\nSaisir le montant que vous voulez débiter sur votre livret d'épargne: " << endl;
				cin >> montant;

				while (Compte::Getsolde() - montant < montant_min){
					cout << "Le montant minimum de votre livret d'épargne est de 20 euros, veuillez ressaisir le montant que vous souhaitez débiter : " << endl;
					cin >> montant;
				}
				Compte::Debiter(montant);
				cout << "Votre livret d'épargne a bien été crédité de " << montant << " euros." << endl;
				Livret_epargne::Afficher();
				break;

		case 3: cout << "\n--Afficher vos dix dernières opérations de votre livret d'épargne." << endl;
				Compte::AfficherOperations();
				break;

		case 4: cout << "\n--Actualiser le compte" << endl;
				int choix = Compte::Actualiser(date_actuelle);
				if(choix == 2){
					Livret_epargne::CalculInterets(date_actuelle);
				}
				Livret_epargne::Afficher();
				break;
	}
}

Livret_epargne::~Livret_epargne() {
	// TODO Auto-generated destructor stub
}

