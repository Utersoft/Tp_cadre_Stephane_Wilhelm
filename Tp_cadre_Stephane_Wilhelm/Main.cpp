/*1.1 Le constructeur est une fonction membre qui permet d'affecter des valeurs par d�fauts, donn�es par le programme ou l'utilisateur � des donn�es membres faisant
* partie de la classe. Le constructeur est ex�cut� � la cr�ation d'un objet du type de la classe.
* 
* 
* 1.2 Le destructeur est une fonction membre qui permet de lib�rer la m�moire, � l'aide d'un delete, d'un objet de type pointeur avec de la m�moire allou�. Le
* destructeur est utilis� � la fin de la fonction/proc�dure/main dans lequel il est appel�. Il est n�cessaire d'avoir un destructeur d�s lors qu'on cr�e une variable
* de type pointeur avec la m�thode "new" qui permet de lui allouer de la m�moire dans la pile et donc qu'il faut vider lorsque ce n'est plus n�cessaire pour �viter
* de surcharger la pile.
* 
* 
* 1.3 Le constructeur d'une classe se reconnait par son nom qui est le m�me que le nom de classe. Il peut y avoir plusieurs constructeurs mais, ils ne doivent pas
* avoir les m�me param�tres. Cela permet d'initialiser diff�remment un ou plusieurs objets.
* 
* 
* 1.4 Il s'agit de cr�er plusieurs fonction qui ont le m�me nom mais pas les m�me param�tres.
* 
* 
* 1.5 Public : Les donn�es, fonctions, etc, publique sont accessibles, et peuvent �tre appel� en dehors de la classe.
* Private : En priv�e, elles ne sont pas accessibles en dehors de la classe et doivent �tre manipul� via des m�thodes.
*/



#include "Cadre.h"
#include <iostream>
#include <string.h>
#define TAILLE 10

using namespace std;

int main(){

	TPoint TPtAncre;
	TPtAncre = initPoint(1, 4);

	//initialisation du pointeur de chaine de charact�re
	char* ptChar_mot = new char[TAILLE];
	strcpy_s(ptChar_mot, TAILLE, "Rectangle");

	//Construction du cadre 1
	CCadre CCadre1(TPtAncre, 4, '_', ptChar_mot);
	//Construction de la copie du cadre 1 : le cadre 2
	CCadre CCadre2(CCadre1);



	CCadre1.afficheCaractCadre();

	//Modification des valeurs largeur, longeur et motif du cadre 1
	CCadre1.setLarg(4);
	CCadre1.setLong(4);
	CCadre1.setMotif('/');

	CCadre1.afficheCaractCadre();
	CCadre2.afficheCaractCadre();


	//Affichage des valeurs des surfaces du cadre 1 et du cadre 2
	cout << "Surface Cadre1 = " << CCadre1.surfaceCadre() << endl;
	cout << "Surface Cadre2 = " << CCadre2.surfaceCadre() << endl;
	cout << "Perimetre Cadre1 = " << CCadre1.perimetreCadre() << endl;
	cout << "Perimetre Cadre2 = " << CCadre2.perimetreCadre() << endl;
	

	//On test si le cadre 1 est un carr�
	if (CCadre1.estCarre()) {
		cout << "Le cadre 1 est carre." << endl;
	}
	else {
		cout << "Le cadre 1 n'est pas carre." << endl;
	}

	//M�me test pour le cadre 2
	if (CCadre2.estCarre()) {
		cout << "Le cadre 2 est carre." << endl;
	}
	else {
		cout << "Le cadre 2 n'est pas carre." << endl;
	}

	//On fait une rotation du cadre 1 avec th�ta qui est calcul� dans la fonction theta()
	CCadre1.rotation(CCadre1.theta());

	return 0;
}