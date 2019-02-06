//============================================================================
// Name        : Banque.cpp
// Author      : ChristopheR_JulienMo_MarineV
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include "Compte.h"
#include "Comptecourant.h"
#include "Comptebloque.h"
#include "Livretepargne.h"
#include "Date.h"
#include "Client.h"
#include<typeinfo>

using namespace std;

const float Compte_courant::decouvert_autorise = -100;
const int Compte_bloque::duree_blocage = 84; // 84 mois egal 7 ans de blocage
const float Compte_bloque::taux_interet = 0.02;
const int Compte_bloque::montant_min = 100;
const int Livret_epargne::montant_min = 20;
const float Livret_epargne::taux_interet  = 0.0125;
const int Livret_epargne::plafond_solde   = 7700;
typedef map<Date, float> operations;

int main() {
	Date date_actuelle(31, 12, 2019);

	// simulation d'opérations
	operations o;
	o[Date(12, 4, 2018)] =  34.70;
	o[Date(27, 9, 2018)] = 98.90;
	o[Date(2, 12, 2017)] = 4.20;
	operations p;
	p[Date(4,4,2015)] =  19.90;
	p[Date(5,3,2016)] = 145.50;
	p[Date(3,5, 2017)] = 4.20;
	operations q;
	q[Date(1,3,1998)] =  34.70;
	q[Date(1,4,1998)] = 100.0;
	q[Date(1,5,1998)] = 10.0;
	operations r;
	r[Date(3,5,2000)] =  42.0;
	r[Date(3,6,2000)] = 42.5;
	r[Date(3,7,2000)] = 42.9;
	operations s;
	s[Date(10,4,2001)] =  21.0;
	s[Date(10,5,2001)] = 22.0;
	s[Date(10,6,2001)] = 23.0;

	// Création du tableau de clients (banquier)
	//Client*client0000 = new Client(0000, "Crédit ","Badoit", "23 avenue de la soif 31100 Gorc");

	// Création du tableau de clients


	Client *client1111 = new Client(1111,"Geralt", "Deriv", "70 rue de la source 31200 Zorc");
	Client *client2222 = new Client(2222,"Brigitte", "Foderi", "2 Avenue du puit 31400 Borc");
	Client *client3333 = new Client(3333,"Gertrude", "Fouprit", "7 rue minérale 31500 Lorc");
	Client *client4444 = new Client(4444,"Bernard", "Loitere", "10 rue meeste 31600 Morc");
	Client *client5555 = new Client(5555,"Françis", "Lalane", "3 rue du nem 31700 Forc");

	vector<Client*> clients(5);

	clients[0] = client1111;
	clients[1] = client2222;
	clients[2] = client3333;
	clients[3] = client4444;
	clients[4] = client5555;
	//clients[5] = client0000;//banquier

	// creation des comptes du client 1

	Compte_courant *client1_cc1 = new Compte_courant("Compte courant", 1111 , 3000, 0.05, Date(20,6,2010), o);
	Compte_bloque *client1_cb1 = new Compte_bloque("Compte bloque", 1111 , 2000, Date(20,6,2014), p);
	Livret_epargne *client1_lep1 = new Livret_epargne("Livret epargne", 1111 , 4500, Date(20,6,2012), q);

	// creation des comptes du client 2

	Compte_courant *client2_cc2 = new Compte_courant("Compte courant", 2222 , -101, 0.05, Date(20,6,2010), r);
	Compte_bloque *client2_cb2 = new Compte_bloque("Compte bloque", 2222 , 5000, Date(20,6,2013), s);
	Livret_epargne *client2_lep2 = new Livret_epargne("Livret epargne", 2222 , 5500, Date(20,6,2010), p);

	// creation des comptes du client 3

	Compte_courant *client3_cc3 = new Compte_courant("Compte courant", 3333 , 2500, 0.05, Date(20,6,2010), s);
	Compte_bloque *client3_cb3 = new Compte_bloque("Compte bloque", 3333 , 4000, Date(20,6,2012), p);
	Livret_epargne *client3_lep3 = new Livret_epargne("Livret epargne", 3333 , 5500, Date(20,6,2010), q);

	// creation des comptes du client 4

	Compte_courant* client4_cc4 = new Compte_courant("Compte courant", 4444 , 2500, 0.05, Date(20,6,2010), o);
	Compte_bloque* client4_cb4 = new Compte_bloque("Compte bloque", 4444 , 4000, Date(20,6,2014), r);
	Livret_epargne* client4_lep4 = new Livret_epargne("Livret epargne", 4444 , 10000, Date(20,6,2012), p);

	// creation des comptes du client 5

	Compte_courant *client5_cc5 = new Compte_courant("Compte courant", 5555 , 2500, 0.05, Date(20,6,2010),q);
	Compte_bloque *client5_cb5 = new Compte_bloque("Compte bloque", 5555 , 4000, Date(20,6,2014),s);
	Livret_epargne *client5_lep5 = new Livret_epargne("Livret epargne", 5555 , 5000, Date(20,6,2016),p);
	Livret_epargne *client5_lep51 = new Livret_epargne("Livret epargne", 5555 , 1500, Date(20,6,2019),o);

	vector<Compte*> clients_comptes(16);

	clients_comptes[0] = client1_cc1;
	clients_comptes[1] = client1_cb1;
	clients_comptes[2] = client1_lep1;
	clients_comptes[3] = client2_cc2;
	clients_comptes[4] = client2_cb2;
	clients_comptes[5] = client2_lep2;
	clients_comptes[6] = client3_cc3;
	clients_comptes[7] = client3_cb3;
	clients_comptes[8] = client3_lep3;
	clients_comptes[9] = client4_cc4;
	clients_comptes[10] = client4_cb4;
	clients_comptes[11] = client4_lep4;
	clients_comptes[12] = client5_cc5;
	clients_comptes[13] = client5_cb5;
	clients_comptes[14] = client5_lep5;
	clients_comptes[15] = client5_lep51;

	// IHM
	int id_client, choix_compte;
	cout << "\nSaisissez votre id client: ";
	cin >> id_client;
	/*if(id_client==0000)
	{
		Compte::MenuBanquier();

	}*/

	bool client_trouve = false;
	vector<int> tab_indice_compte_client;  // stocke les indices des comptes du client du vector clients_comptes

	for(int i=0; i<5 && !client_trouve; i++){
		if (id_client == clients[i]->Getid()){	// recherche du client par son ID
			cout << "Bonjour " << clients[i]->GetNom() << " " << clients[i]->GetPrenom() << endl;
			for(unsigned int j=0; j<clients_comptes.size(); j++){
				if( id_client == clients_comptes[j]->GetTitulaire()){	// recherche des comptes du client
					cout << "Vous êtes titulaire des comptes suivants: " << endl;	// Affichage pour le client
					cout << "Indice du compte: " << j << " | " << *clients_comptes[j];	// affichage de l'indice du compte pour ensuite afficher le menu du compte
					client_trouve = true;	// le client est trouvé donc stop boucle
					tab_indice_compte_client.push_back(j);	// recup des indices des comptes du client dans vector
				}
			}
		}
	}

	int exit=0;
	while(exit ==0)
	{
		cout << "\nSélectionnez l'indice du compte que vous souhaitez consulter ou taper -1 pour sortir du programme =  ";
		cin >> choix_compte;
		if (choix_compte==-1)	// Client peut sortir du programme
		{
			exit=1;
			cout << "A bientot ";
		}
		else{
		//cout << *clients_comptes[choix_compte];
		clients_comptes[choix_compte]->Menu(date_actuelle);	// Menu du type de compte selectionné
		}
	}

	return 0;
}
