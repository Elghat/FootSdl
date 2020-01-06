#include "Joueur.h"
void Joueur::MoveTo(int x,int y) {
	posX = x;
	posY = y;
}

void Joueur::MoveTo() {
	MoveTo(0, 0);
}

Joueur::Joueur() :Joueur(0,0){}

Joueur::Joueur(int x, int y) {
	posX = x;
	posY = y;
}