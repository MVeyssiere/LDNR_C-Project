/*
 * Titulaire.cpp
 *
 *  Created on: 29 janv. 2019
 *      Author: ChristopheR_JulienMo_MarineV
 */

#include "Client.h"

Client::Client(int id){
	this->id = id;
	this->nom = "Dupond";
	this->prenom = "Charles";
	this->adresse = "3 rue des Pivoines 31000 Toulouse";
}

Client::Client(int id, string nom, string prenom, string adresse){
	this->id = id;
	this->nom = nom;
	this->prenom = prenom;
	this->adresse = adresse;
}

void Client::ModifierAdresse(string addresse){
	this->adresse = adresse;
}

int Client::Getid(){
	return id;
}
string Client::GetNom(){
	return nom;
}
string Client::GetPrenom(){
	return prenom;
}

ostream &operator<<(ostream &out, const Client &c)
{
    out << "id du client ";
    out << c.id;
    out << " ";
    out << "nom = ";
    out << c.nom;
    out << " ";
    out << "prenom = ";
    out << c.prenom;
    out << " ";
    out << "adresse = ";
    out << c.adresse;

    return out;
}

Client::~Client() {
}

