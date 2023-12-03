#pragma once
#include <iostream>
#include <string>

// =======================================================
class Promo {
private :
	Etudiant* listeEtudiants;
	int nb_Etudiants;
public:
	promo();
	int getNbEtudiants();
	void inputNotesUtilisateur();
	void afficherEtudiants();
	void InputNotesAUFichier(string t_fileName);
	void OutputNotesDUFichier(string t_fileName);
};

// =======================================================

class Etudiant{
private :
	string nom;
	int moyenne;
public :
	Etudiant();
	Etudiant(string t_nom, int t_moyenne);
	Etudiant(const Etudiant& t_etudiant);
	string getNom();
	int getMoyenne();
	void setNom(string t_Nom);
	void setMoyenne(int t_Moyenne);
};
