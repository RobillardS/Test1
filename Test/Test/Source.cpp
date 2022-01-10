// exemple procedural d'un programme affichant un sinus.
// cool ! 
// cool ! information en-tete : determinee par la norme de codage
// cool ! information en-tete : determinee par la norme de codage
// cool ! information en-tete : determinee par la norme de codage
// cool ! information en-tete : determinee par la norme de codage
// cool ! 
// 
// shortcut ecriture multi-lignes : alt gouche + shift -> fleche haut et bas
// 
//CALTAL : Code A little, Test A Little
//DRY : Don't Repeat Yourself

#include <stdio.h>
#include <math.h>

//Encapsuler les donner et les fonctions (Struct) 

int main()
{
	//Declaration des constantes de la taille du tableau
	const int width = 100;
	const int height = 20;

	const char backgroud_character = ' ';

	//Declaration et initialisation de la grille
	char grid[width][height];
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			grid[x][y] = backgroud_character;
		}
	}

	//Tracer le systeme d'axe
	//Peut etre remplacer en Fonction ---> void plotAxis(char grid[width][height], int w, int h);
	int center_x = width / 2;
	int center_y = height / 2;
	for (int x = 0; x < width; x++) {
		grid[x][center_y] = '-';
	}
	for (int y = 0; y < height; y++) {
		grid[center_x][y] = '|';
	}
	grid[center_x][center_y] = '+';
	grid[width - 1][center_y] = '>';
	grid[center_x][height - 1] = 'V';

	//Parametrer et dessiner le sinus 
	//y = amplitude * sin(frequency * x + phase) + offset;
	const double pi = 3.1415926535897932384626433832795;
	const double amplitude = 1.25;
	const double frequency = 2.0;
	const double phase = pi / 4.0;
	const double offset = -0.5;
	/*------------------------------------*/
	const double x_min = -pi;
	const double x_max = pi;
	const double x_span = x_max - x_min; //
	const double x_step = x_span / width; //
	const double y_min = -1.5;
	const double y_max = 1.5;
	const double y_span = y_max - y_min; //
	const double y_step = y_span / height; //

	for (int xi = 0; xi < width; xi++) {
		double xm = x_min + xi * x_step; // -->vraiment mauvais commentaire ex : met xm a la somme de x_min et produit de xi et x_step
		double ym = amplitude * sin(frequency * xm + phase) + offset; //
		int yi = (int)round((ym - y_min) / y_step); //
		if (yi >= 0 && yi < height) { //
			grid[xi][yi] = '*'; //
		}

	}


	//Afficher dans la console
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			printf("%c", grid[x][y]);
		}
		printf("\n");
	}



	return 0;
}
