/*
 * Comptecourant.cpp
 *
 *  Created on: 29 janv. 2019
 *      Author: ChristopheR_JulienMo_MarineV
 */

#include "Comptecourant.h"
#include "Compte.h"
#include "Date.h"

Compte_courant::Compte_courant(string nom_compte, int id_titulaire, float solde, float taux, Date date_ouverture): Compte(nom_compte, id_titulaire, solde, taux, date_ouverture){
	cout << "Création du compte courant." << endl;
}

Compte_courant::Compte_courant(string nom_compte, int id_titulaire, float solde, float taux, Date date_ouverture, map<Date, float> operations): Compte(nom_compte, id_titulaire, solde, taux, date_ouverture, operations) {
	cout << "Création du compte courant." << endl;
}

void Compte_courant::Afficher(){
	Compte::Afficher();
	cout << "Découvert autorisé = " << decouvert_autorise << endl;
}

bool Compte_courant::SeuilAlerte(){
	if(Compte::Getsolde() <= Compte_courant::decouvert_autorise){
		return true;
	}
	else{
		return false;
	}
}

void Compte_courant::CalculAgios(){
	float montant;
	if (SeuilAlerte()==true){
		cout << "\nVotre découvert autorisé est atteint, vous allez payer des agios." <<endl;

		float calcul, newSolde;
		cout << "Saisir le montant que vous voulez débiter de votre compte courant: " ;
		cin >> montant;
		calcul = montant * Compte::Gettaux();
		cout << calcul << " euros d'agios vous ont été appliqués." << endl;
		newSolde = Compte::Getsolde() - montant - calcul;
		cout << "Votre nouveau solde est de: " << newSolde << " euros" << endl;
		Compte::Setsolde(newSolde);
	}
	else{
		cout << "Saisir le montant que vous voulez débiter de votre compte courant: " << endl;
		cin >> montant;
		Compte::Debiter(montant);
	}
}

void Compte_courant::Menu(Date& date_actuelle){
	int choix_cc;
	float montant;

	cout << "Taper 1: Créditer votre compte courant " << endl;
	cout << "Taper 2: Débiter votre compte courant " << endl;
	cout << "Taper 3: Afficher les dernières opérations effectuées sur votre compte courant" << endl;
	cout << "Taper 4: Actualiser votre compte courant " << endl;
	cout << "Votre choix = ";
	cin >> choix_cc;

	switch(choix_cc){

		case 1: cout << "Créditer votre compte courant " << endl;
				cout << "Saisir le montant que vous voulez créditer sur votre compte courant" << endl;
				cin >> montant;
				Compte::Crediter(montant);
				Compte_courant::Afficher();
				break;

		case 2: cout << "Débiter votre compte courant " << endl;
				cout << "\nInformations de votre compte:" << endl;
				Compte_courant::Afficher();

				Compte_courant::CalculAgios();  // si le solde du compte dépasse le découvert, la fonction sera appliquée sinon non.

				cout << "\nNouvelles informations de votre compte:" << endl;
				Compte_courant::Afficher();

				break;

		case 3: cout << "\n--Afficher vos dix dernières opérations sur le compte." << endl;
				Compte::AfficherOperations();
				break;

		case 4: cout << "\n--Actualiser le compte" << endl;
				Compte::Actualiser(date_actuelle);
				break;
		}
}

Compte_courant::~Compte_courant() {
	cout<<"\nDestruction du compte courant"<<long(this);
}

