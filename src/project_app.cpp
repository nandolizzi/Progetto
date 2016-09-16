#include "pgm_file.h"
#include "mat.h"
#include "tools.h"
#include <iostream>
#include <string.h>

using namespace std;

#define Black 0
#define White 255
#define occupied_cell -1
#define free_cell -2


// Il robot si muove su di una cella di 60*80 metri

int main(int argc, char const *argv[])
{
	/* Si inizializza una variabile file appartenente alla classe astratta base PrintableFile*/
	
	PrintableFile *file;

	/* Si specifica l'appartennza di file alla classe derivata di tipo PgmFile*/

	file = new PgmFile();
	file -> load( argv[1] );

	/* Si ricavano gli attributi privati relativi al numero di righe e numero di colonne
	   della matrice rappresentante il file immagine; utilizzo due variabili intere perchè
	   si utilizzeranno questi valori per tre volte e quindi si preferisce utilizzare più memoria 
	   ma non richiamare più volte la stessa funzione */

	int r = file -> getRow();
	int c = file -> getCol();

	Mat <int> distance(r,c);

	/* Si prepara la matrice che verrà utilizzata per raccogliere la distanza di ogni cella 
	   dalla cella indicata come goal. Si inizializza la matrice con valori pari a -1 per le celle occupate,
	   ovvero quelle con intensità pari al nero, e pari a -2 per le celle libere, ovvero con intensità pari 
	   al bianco. Si è posta particolare attenzione nel considerare eventuali celle il cui valore di 
	   intensità di grigio risulti diverso da "0" o a "256" al più vicino dei due estremi */

	for (int i = 0; i < r ; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if ( (int) file -> getData(i, j)  > 127 )
			{
				distance( i, j) = free_cell;
			}
			else
				distance( i, j) =  occupied_cell;
		}
	}

	/* Si dichiara una nuova matrice al fine di effettuare la copia della matrice rappresentante
	   l'immagine del file ponendo particolare attenzione nel porre eventuali celle il cui valore di 
	   intensità di grigio risulti diverso da "0" o a "256" al valore più prossimo ad uno dei due estremi. */

	Mat < int > copia ( r , c );

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if ( (int) file -> getData(i, j) > 127 )
			{
				copia( i, j ) = White;
			}
			else
			{
				copia( i , j ) = Black;
			}
		}
	}
	
	cout << "You have an available area of 60 metres by 80 metres. In particoular 60 metres" << endl;
	cout << "is the vertical available space while 80 metres is the horizontal available space" << endl;

	/* Si inizializzano i valoari relativi alle righe ed alle colonne delle celle di start e di goal*/
	
	int get_row_start_index = 0;
	int get_col_start_index = 0;
	int get_row_goal_index = 0;
	int get_col_goal_index = 0;

	/* Si richiama la funzione con la quale verranno acquisiti da tastiera gli indici relativi alle righe ed alle colonne
	   delle celle di start e di goal e settata a "0" la distanza della cella goal. 
	   Inoltre, all'interno di tale funzione verrà effettuato un  controllo riguardo alla validità delle posizioni inserite. */
	
	getPosition( distance, get_row_start_index ,get_col_start_index, 
				 get_row_goal_index, get_col_goal_index, r, c);

	/* Si effettua il controllo sulla validità dei valori inseriti dalla funzione getPosition riguardo alle celle di start e goal;
	   getPosition infatti pone, in caso di errori, a -1 i valori degli indici relativi alle righe e alle colonne di start e goal. */

	while ( ( get_row_start_index == -1 && get_col_start_index == -1 ) ||
			 ( get_row_goal_index == -1 && get_col_goal_index == -1 ) )
	{
		getPosition( distance, get_row_start_index ,get_col_start_index,
					 get_row_goal_index, get_col_goal_index, r, c );
	}

	/* Si richiama la funzione che implementa l'algoritmo di Path Planning Grassfire con il quale verrà modificata la 
	   matrice delle distanze precedentemente impostate con valori indicanti le celle libere, le celle occupate e la cella goal. */

	setPathDistance ( distance, get_row_start_index ,get_col_start_index,
					  get_row_goal_index, get_col_goal_index, r, c );
	
	/* Si utilizza la funzione drawPath per tracciare sulla matrice copia il percorso più breve per il raggiungimento, 
	   dalla cella start, della cella goal. Si utilizza la matrice distance per calcolare il percorso che verrà tracciato
	   sulla matrice copia attraverso gli indici di riga e colonna corrispondenti a quelli indicati nella matrice distance. */

	drawPath( distance, copia, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);


	// Si dichiara una stringa da utilizzare per poter catturare il nome del file
 	
 	string filename;
 	
 	// Si elimina il carrattere di terminazione " \n " che rilasciato dal precedente utilizzo di cin
 	
 	cin.ignore();
	
	cout << "Please insert the name of the new map file" << endl;
	
	/* Si cattura da tastiera la stringa contenente il nome del nuovo file da stampare. */

	getline ( cin, filename);

	char *name;

	name = new char [ filename.size() + 1 ];
    memcpy( name , filename.c_str(), filename.size() + 1);

    cout << "Please wait for a while; the system is setting the new map with the robot path" << endl;
 
    /* Si riscrive il file di tipo PGM per tracciare il percorso del robot sulla mappa.*/

	for (int i = 0; i < r ; i++)
	{
		for (int j = 0; j < c; j++)
		{
			file -> setData( copia( i , j ), i , j);
		}
	}

	/* Si salva la nuova mappa il cui nome è quello indicato dall'utente. */

	file -> save(name);
	
	// Si cancella la memoria utilizzata dalla variabile file.

	delete file;

	return 0;
}
