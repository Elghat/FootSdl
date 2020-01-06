#pragma once
#include "ObjetMouvable.h"
class Joueur :public ObjetMouvable
{
	private:

	public:
		// Constructor
		Joueur();
		Joueur(int x, int y);

		// END Constructor
		// Getteur
		int GetPosX();
		int GetPosY();
		// END Getteur
		// Setteur

		// END Setteur

		// Function



		void MoveTo();
		void MoveTo(int x, int y);
		// END Function
};

