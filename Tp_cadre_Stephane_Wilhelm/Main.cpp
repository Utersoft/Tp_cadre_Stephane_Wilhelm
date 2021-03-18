/*1.1 Le constructeur est une fonction membre qui permet d'affecter des valeurs par défauts, données par le programme ou l'utilisateur à des données membres faisant
* partie de la classe. Le constructeur est exécuté à la création d'un objet du type de la classe.
* 
* 
* 1.2 Le destructeur est une fonction membre qui permet de libérer la mémoire, à l'aide d'un delete, d'un objet de type pointeur avec de la mémoire alloué. Le
* destructeur est utilisé à la fin de la fonction/procédure/main dans lequel il est appelé. Il est nécessaire d'avoir un destructeur dès lors qu'on crée une variable
* de type pointeur avec la méthode "new" qui permet de lui allouer de la mémoire dans la pile et donc qu'il faut vider lorsque ce n'est plus nécessaire pour éviter
* de surcharger la pile.
* 
* 
* 1.3 Le constructeur d'une classe se reconnait par son nom qui est le même que le nom de classe. Il peut y avoir plusieurs constructeurs mais, ils ne doivent pas
* avoir les même paramètres. Cela permet d'initialiser différemment un ou plusieurs objets.
* 
* 
* 1.4 Il s'agit de créer plusieurs fonction qui ont le même nom mais pas les même paramètres.
* 
* 
* 1.5 Public : Les données, fonctions, etc, publique sont accessibles, et peuvent être appelé en dehors de la classe.
* Private : En privée, elles ne sont pas accessibles en dehors de la classe et doivent être manipulé via des méthodes.
*/



#include "Cadre.h"
#include <iostream>
#include <string.h>
#define TAILLE 10

using namespace std;

int main(){

	TPoint TPtAncre;
	TPtAncre = initPoint(1, 4);

	//initialisation du pointeur de chaine de charactère
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
	

	//On test si le cadre 1 est un carré
	if (CCadre1.estCarre()) {
		cout << "Le cadre 1 est carre." << endl;
	}
	else {
		cout << "Le cadre 1 n'est pas carre." << endl;
	}

	//Même test pour le cadre 2
	if (CCadre2.estCarre()) {
		cout << "Le cadre 2 est carre." << endl;
	}
	else {
		cout << "Le cadre 2 n'est pas carre." << endl;
	}

	//On fait une rotation du cadre 1 avec thêta qui est calculé dans la fonction theta()
	CCadre1.rotation(CCadre1.theta());

	return 0;
}