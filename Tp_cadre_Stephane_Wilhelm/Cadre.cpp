#include "Cadre.h"
#include <iostream>
#include <math.h>
#include <string.h>
#define PI 3.14
#define TAILLE 10


using namespace std;


//Constructeur
//Initialisation de l'objet de type cadre via paramètre (passage par valeur)
CCadre::CCadre(TPoint TPtAncre, int n_Lar, char chr_Motif, char* ptrChar_Nom)
{
	this->TPtAncrage = TPtAncre;
	this->n_Largeur = n_Lar;
	this->n_Longueur = 2 * n_Lar;
	this->chr_Motif = chr_Motif;
	this->ptrCharNom_Cadre = new char[TAILLE];
	strcpy_s(this->ptrCharNom_Cadre, TAILLE, ptrChar_Nom);
}


//Constructeur de copie
CCadre::CCadre(CCadre& CCadreCopie)
{
	this->TPtAncrage = CCadreCopie.TPtAncrage;
	this->n_Largeur = CCadreCopie.n_Largeur;
	this->n_Longueur = CCadreCopie.n_Longueur;
	this->chr_Motif = CCadreCopie.chr_Motif;
	this->ptrCharNom_Cadre = new char[TAILLE];
	strcpy_s(this->ptrCharNom_Cadre, TAILLE, CCadreCopie.getCadreNom());
}


//Destructeur
CCadre::~CCadre()
{
	cout << "Destruction de " << this->chr_Motif << endl;
	delete[] this->ptrCharNom_Cadre;
}


//Affiche le point d'ancrage, la longeur et la largeur du cadre
void CCadre::afficheCaractCadre()const
{
	cout << "Le point d'ancrage se trouve en X : " << this->TPtAncrage.n_x << " et Y : " << this->TPtAncrage.n_y << "." << endl;
	cout << "Le cadre est largeur " << this->n_Largeur << " et de longeur " << this->n_Longueur << "." << endl;
	cout << "Le symbole d'affichage du cadre est : " << this->chr_Motif << "." << endl;
	cout << "Le mot attache au cadre est " << this->ptrCharNom_Cadre << endl;

}

//calcul de la surface d'un cadre
int CCadre::surfaceCadre()const
{
	return this->n_Largeur * n_Longueur;
}


//calcul du périmètre d'un cadre
int CCadre::perimetreCadre()const
{
	return this->surfaceCadre() * 2;
}


//On retourne true si le cadre est un carré, sinon false
bool CCadre::estCarre() const
{
	if (this->n_Longueur == this->n_Largeur)
		return true;
	else
		return false;
}


//Calcul de l'angle thêta du cadre
float CCadre::theta() const
{
	return atan(this->TPtAncrage.n_y / this->TPtAncrage.n_x);
}

//Calcul de la rotation d'un angle par rapport à un angle donné et au point d'ancrage du cadre
void CCadre::rotation(float flt_angle)
{
	int n_x = this->TPtAncrage.n_x;
	int n_y = this->TPtAncrage.n_y;

	n_x = n_x * cos(flt_angle * (PI / 180)) - n_y * sin(flt_angle * (PI / 180));
	n_y = n_x * sin(flt_angle * (PI / 180)) + n_y * cos(flt_angle * (PI / 180));
	this->TPtAncrage.n_x = n_x;
	this->TPtAncrage.n_y = n_y;

	cout << n_x << " et " << n_y << endl;
}


//modification de la longeur du cadre
void CCadre::setLong(int n_Long)
{
	this->n_Longueur = n_Long;
}


//modification de la largeur du cadre
void CCadre::setLarg(int n_Larg)
{
	this->n_Largeur = n_Larg;
}

//Modification du motif d'affichage
void CCadre::setMotif(char chr_Motif)
{
	this->chr_Motif = chr_Motif;
}


//Récupération de la valeur de la longueur
int CCadre::getLong() const
{
	return this->n_Longueur;
}


//Récupération de la valeur de la largeur
int CCadre::getLarg() const
{
	return this->n_Largeur;
}

//Récupération de la valeur du motif
char CCadre::getMotif() const
{
	return this->chr_Motif;
}


//Récupération de la valeur du pointeur de chaine de charactère
char* CCadre::getCadreNom() const
{
	return this->ptrCharNom_Cadre;
}
