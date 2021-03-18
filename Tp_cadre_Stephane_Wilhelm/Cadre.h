#pragma once
#include "TPoint.h"
#include <stddef.h>



class CCadre {
private:

	//Données membres
	TPoint TPtAncrage;
	int n_Largeur;
	int n_Longueur;
	char chr_Motif;
	char* ptrCharNom_Cadre;

public:

	//Constructeurs

	//CCadre(TPoint TPtAncre = { 10, 5 }, int n_Lar = 5, char chr_Motif = '*');
	CCadre(TPoint TPtAncre, int n_Lar, char chr_Motif, char* ptrChar_Nom);
	
	//Constructeur de copie
	CCadre(CCadre& CCadreCopie);
	
	//Destructeur
	~CCadre();

	//Fonction membres
	void afficheCaractCadre()const;

	int surfaceCadre()const;
	int perimetreCadre()const;

	bool estCarre()const;

	float theta()const;
	void rotation(float flt_angle);

	//Mutateurs
	void setLong(int n_Long);
	void setLarg(int n_Larg);
	void setMotif(char chr_Motif);

	//Accesseurs
	int getLong()const;
	int getLarg()const;
	char getMotif()const;
	char* getCadreNom()const;


};