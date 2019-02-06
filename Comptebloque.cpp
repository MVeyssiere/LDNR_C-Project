/*
 * Comptebloque.cpp
 *
 *  Created on: 29 janv. 2019
 *      Author: ChristopheR_JulienMo_MarineV
 */
#include "Comptebloque.h"
#include "Compte.h"

// Constructeur de compte_bloque

Compte_bloque::Compte_bloque(string nom_compte, int id_titulaire, int solde, Date date_ouverture) :Compte(nom_compte, id_titulaire, solde, date_ouverture){
	Compte::Settaux(taux_interet);
	cout << "Création du compte bloqué." << endl;
}
Compte_bloque::Compte_bloque(string nom_compte, int id_titulaire, int solde, Date date_ouverture, map <Date, float> operations) :Compte(nom_compte, id_titulaire, solde, date_ouverture, operations){
	Compte::Settaux(taux_interet);
	cout << "Création du compte bloqué." << endl;
}

void Compte_bloque::Afficher(){
	Compte::Afficher();
	cout << "Durée de blocage du compte = " << duree_blocage/12 << " ans" << endl;
	cout << "Montant de dépôt minimum = " << montant_min << " euros" << endl;
}

// Informe l'utilisateur sur l'état de blocage de son compte. Est utilisé par la fonction suivante TempsRestant.
void Compte_bloque::EtatCompte(bool etat){
	if(etat == false){
		cout << "Ce compte est actuellement bloqué. Vous ne pouvez pas prélever d'argent." << endl;
	}
	else{
		cout << "Ce compte est débloqué. Vous pouvez prélever de l'argent." << endl;
	}
}

// Calcul du temps restant avant déblocage du compte
// Appel la fonction EtatCompte qui informe l'utilisateur de l'état de blocage de son compte.
// L'utilisateur est informé sur la durée restante de blocage !!!! basé juste sur l'année. Pas le mois ni le jour. Approximatif !!!!!
bool Compte_bloque::TempsRestant(Date& date_actuelle){
	Date date_ouverture = getDateOuverture(); // appel de la date d'ouverture du compte
	int duree_mois = (date_actuelle.getAnnee() - date_ouverture.getAnnee()) * 12; // Calcul de l'age du compte
	if( duree_mois < duree_blocage){ // 84 mois == 7 ans Si l'age du compte est inférieur à la date limite de blocage...
		Compte_bloque::EtatCompte(false);
		cout << "La durée restante de blocage est de " << duree_mois << " mois." << endl;
		return false;
	}
	else { // Si l'age du compte est supérieur à la date limite de blocage...
		Compte_bloque::EtatCompte(true);
		return true;
	}
}

void Compte_bloque::CalculInterets(Date& date_actuelle){
	float result_interets;
	Date date_ouverture = getDateOuverture();
	result_interets = taux_interet * Compte::Getsolde() * (date_actuelle.getAnnee() - date_ouverture.getAnnee());
	cout << "Le montant total de vos interêts pour ce compte est de: " << result_interets << " euros" << endl;
	Compte::Setsolde(Compte::Getsolde() + result_interets);
}


void Compte_bloque::Menu(Date& date_actuelle){
	int choix_cb;
	float montant;
	cout << endl << "-------Menu de votre compte bloqué-------" << endl;
	cout << "Taper 1: Créditer votre compte bloqué " << endl;
	cout << "Taper 2: Débiter votre compte bloqué " << endl;
	cout << "Taper 3: Afficher les dernières opérations effectuées sur votre compte bloqué" << endl;
	cout << "Taper 4: Actualiser votre compte bloqué" << endl;
	cout << "Votre choix = ";
	cin >> choix_cb;

	switch(choix_cb){

		case 1: cout << "\n--Créditer votre compte bloqué " << endl;
				cout << "\nSaisir le montant que vous voulez créditer sur votre compte bloqué" << endl;
				cin >> montant;
				Compte::Crediter(montant);
				cout << "Votre compte a bien été crédité de " << montant << " euros." << endl << endl;
				Compte_bloque::Afficher();
				break;

		case 2: cout << "\n--Débiter votre compte bloqué "<< endl;
				if(Compte_bloque::TempsRestant(date_actuelle) == false){
					break;
				}
				else{
					Compte_bloque::Afficher();
					cout << "\nSaisir le montant que vous souhaitez débiter de votre compte bloqué: ";
					cin >> montant;

					while (Compte::Getsolde() - montant < montant_min){
						cout << "Le montant minimum de votre bloqué est de 100 euros.\n Veuillez ressaisir le montant que vous souhaitez débiter : " << endl;
						cin >> montant;
					}
					Compte::Debiter(montant);
					cout << "\nVotre compte a bien été débité de " << montant << " euros." << endl << endl;
					Compte_bloque::Afficher();
				}
				break;

		case 3: cout << "\n--Afficher vos dix dernières opérations sur le compte." << endl;
				Compte::AfficherOperations();
				break;

		case 4: cout << "\n--Actualiser le compte" << endl;
				if(Compte::Actualiser(date_actuelle) == 2){
					Compte_bloque::CalculInterets(date_actuelle);
				}
				Compte_bloque::Afficher();
				break;
	}
}

Compte_bloque::~Compte_bloque() {
	cout<<"\nDestruction du compte bloqué"<<long(this);
}

