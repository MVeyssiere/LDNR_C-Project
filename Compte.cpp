/*
 * Comptes.cpp
 *
 *  Created on: 29 janv. 2019
 *      Author: ChristopheR_JulienMo_MarineV
 */

#include "Compte.h"

#include "Client.h"
#include "Date.h"

// Constructeurs de la classe compte

Compte::Compte(string nom_compte, int id_titulaire, float solde, Date date_ouverture, map<Date, float> operations){
	this->nom_compte = nom_compte;
	this->id_titulaire = id_titulaire;
	this->solde = solde;
	this->date_ouverture = date_ouverture;
	this->dix_dernieres_operations = operations;
}
Compte::Compte(string nom_compte, int id_titulaire, float solde, Date date_ouverture){
	this->nom_compte = nom_compte;
	this->id_titulaire = id_titulaire;
	this->solde = solde;
	this->date_ouverture = date_ouverture;
	this->dix_dernieres_operations = {{Date(3,2,2018), 3.4},{Date(7,6,2018), 98.9}, {Date(18,9,2018), 56.4}, {Date(3,1,2019), 45.7}, {Date(4,1,2019), 79.8}};
}
Compte::Compte(string nom_compte, int id_titulaire, float solde, float taux, Date date_ouverture, map<Date, float> operations) {
	this->nom_compte = nom_compte;
	this->id_titulaire = id_titulaire;
	this->solde = solde;
	this->taux=taux;
	this->date_ouverture = date_ouverture;
	this->dix_dernieres_operations = operations;
}
Compte::Compte(string nom_compte, int id_titulaire, float solde, float taux, Date date_ouverture){
	this->id_titulaire=id_titulaire;
	this->nom_compte=nom_compte;
	this->solde=solde;
	this->taux=taux;
	this->date_ouverture = date_ouverture;
}

Compte::Compte(string nom_compte, int id_titulaire, int solde, Date date_ouverture){
	this->nom_compte = nom_compte;
	this->id_titulaire = id_titulaire;
	this->solde = solde;
	this->date_ouverture = date_ouverture;
}

Compte::Compte(Date date_ouverture){
	this->date_ouverture = date_ouverture;
}

// Getters and setters

Date Compte::getDateOuverture(){
    return date_ouverture;
}
string Compte::GetNom(){
	return nom_compte;
}
int Compte::GetTitulaire(){
	return id_titulaire;
}
float Compte::Getsolde(){
	return solde;
}
float Compte::Gettaux(){
	return taux;
}
map<Date, float> Compte::GetOperations(){
	return dix_dernieres_operations;
}
void Compte::Settaux(float taux){
	this->taux = taux;
}
void Compte::Setsolde(float solde){
	this->solde = solde;
}

// Méthodes de la classe compte
/*
int Compte::ConsulterSolde(Compte a){
	cout << "Voici le solde du compte: " << solde;
	return solde;
}
*/

void Compte::Afficher(){
	cout << "Id du titulaire = " << id_titulaire << endl;
	cout << "Nom du compte = " << nom_compte << endl;
	cout << "Date d'ouverture du compte = " << date_ouverture;
	cout << "Solde du compte = " << solde << endl;
	cout << "Taux = " << taux << " %" << endl;
}

void Compte::AfficherOperations(){
	map<Date, float> op = dix_dernieres_operations;
	for(auto it = dix_dernieres_operations.cbegin(); it != dix_dernieres_operations.cend(); ++it){
		cout << it->first << it->second << endl;
	}
}

ostream &operator<<(ostream &out, const Compte &e){
    out << "Id du titulaire :";
    out << e.id_titulaire;
    out << " / ";
    out << "Type de compte :";
    out << e.nom_compte;
    out << " / ";
    out << "Solde du compte :";
    out << e.solde;
    out << " / ";
    out << "Taux du compte :";
    out << e.taux;
    return out;
}

void Compte::Crediter(float a){
	float x;
	x=Getsolde();
	x=x+a;
	Setsolde(x);
}

void Compte::Debiter(float d){
	float x;
	x=Getsolde();
	x=x-d;
	Setsolde(x);
}
/*
 * menu du banquier qui permet la modification de l'adresse du client
void MenuBanquier(){
	cout << "modifier adresse du client = ";
	int id_client, choix_compte;
		cout << "Saisissez votre id client: ";
		cin >> id_client;
		bool client_trouve = false;
			vector<int> tab_indice_compte_client;  // stocke les indices des comptes du client du vector clients_comptes

			for(int i=0; i<5 && !client_trouve; i++){
			}
				cout << "Bonjour " << clients[i]->Client::GetNom() << " " << clients[i]->client::GetPrenom() << endl;
			}
//modification de l'adresse par rapport a l'indice client stocké dans le vector
		cout << "Saisir la nouvelle adresse = ";
		string adresse_nouvelle;
		Client::ModifierAdresse(adresse_nouvelle);

}*/


int Compte::Actualiser(Date date_actuelle){
	cout << "La date actuelle est: " << date_actuelle;

	int choix_p;
	cout << "Taper 1 pour faire un saut d'1 mois dans le futur." << endl;
	cout << "Taper 2 pour faire un saut d'1 an dans le futur." << endl;
	cin >> choix_p;

	switch(choix_p){
		case 1:
			if(date_actuelle.getMois()!=12){
				date_actuelle.setMoissaut(1);
				cout << "Saut d'1 mois effectué." << endl;
				cout << date_actuelle;
				return 1;
			}
			else{
				date_actuelle.setAnneesaut(1);
				date_actuelle.setMois(1);
				cout << "Saut d'1 mois effectué ce qui nous amène à une nouvelle année." << endl;
				cout << date_actuelle;
				return 1;
			}
			break;

		case 2:
			date_actuelle.setAnneesaut(1);
			cout << "Saut d'1 an effectué." << endl;
			cout << date_actuelle;
			return 2;
			break;
	}
	return 0;
}

void Compte::Menu(Date& date_actuelle){
	cout << "Menu compte courant TEST" << endl;
}

Compte::~Compte() {}

