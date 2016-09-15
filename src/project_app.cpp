#include "pgm_file.h"
#include "mat.h"
#include "tools.h"
#include <iostream>
#include <string.h>

using namespace std;

#define Black 0
#define White 255


// Il robot si muove su di una cella di 60*80 metri

int main()
{
	/* Si inizializza una variabile file appartenente alla classe astratta base PrintableFile*/
	
	PrintableFile *file;

	/* Si specifica l'appartennza di file alla classe derivata di tipo PgmFile*/

	file = new PgmFile();
	file -> load("map.pgm");

	/* Si ricavano gli attributi privati relativi al numero di righe e numero di colonne
	   della matrice rappresentante il file immagine */

	int r = file -> getRow();
	int c = file -> getCol();
	int data;

	Mat <int> distance(r,c);

	for (int i = 0; i < r ; i++)
	{
		for (int j = 0; j < c; j++)
		{
			data = (int) file -> getData(i, j);
			distance.setDataMatrix( i, j, data);
		}
	}

	/* Si effettua la copia della matrice rappresentante l'immagine del file ponendo particolare attenzione
	   nel porre eventuali celle son valori diversi da "0" o a "256" al valore più prossimo ad uno dei due */
	data = 0;

	Mat < int > copia ( r , c );

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			data = (int) file -> getData(i, j);;

			if ( data > 127 )
			{
				copia.setDataMatrix(i,j, White);
			}
			else
			{
				copia.setDataMatrix( i , j , Black );
			}
		}
	}

	putDistance( distance );

	int get_row_start_index = 0;
	int get_col_start_index = 0;
	int get_row_goal_index = 0;
	int get_col_goal_index = 0;
	getPosition( distance, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);

	while ( get_row_start_index == -1 && get_col_start_index == -1 && get_row_goal_index == -1 && get_col_goal_index == -1 )
	{
		getPosition( distance, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);
	}

	setPathDistance ( distance, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);
	

	drawPath( distance, copia, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);


	// Si dichiara una stringa da utilizzare per poter catturare il nome del file
 	string filename;
 	
 	// Si elimina il carrattere di terminazione " \n " che rilasciato dal precedente utilizzo di cin
 	cin.ignore();
	
	cout << "Please insert the name of the new map file" << endl;
	

	getline ( cin, filename);

	char *name;

	name = new char [ filename.size() + 1 ];
    memcpy( name , filename.c_str(), filename.size() + 1);

	/*for (int i = 0; i < r*c ; i ++)
	 {
	 	data [i] = 0;
	 } */

	data = 0; 

	for (int i = 0; i < r ; i++)
	{
		for (int j = 0; j < c; j++)
		{
			data= copia.getDataMatrix( i , j );
			file -> setData( data, i , j);
		}
	}

	file -> save(name);
	
	delete file;

	return 0;
}
