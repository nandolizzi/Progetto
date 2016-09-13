#include "tools.h"
#include "pgm_file.h"
#include "cell.h"
#include "list.h"

#include <iostream>
#include <math.h>

using namespace std;
#define occupied_cell -1
#define free_cell -2
#define goal_cell 0
#define path_cell 127
#define start_cell 100
#define goal_cell_color 200


void getPosition( Mat <int> &m, int &get_row_start_index , int &get_col_start_index, int &get_row_goal_index , int &get_col_goal_index)
{
	double grs, gcs, grg, gcg;
	// int *start, *goal;
	int r= m.getNumRows();
	int c= m.getNumCols();

	cout << "Please insert the robot start position and the robot goal position\n" << endl;
	//cin >> grs >> gcs >> grg >> gcg ;
	grs = 1;
	gcs = 2;
	grg = 3;
	gcg = 4;
	get_row_start_index = (int)round(grs * 10);
	get_col_start_index = (int)round(gcs * 10);
	get_row_goal_index = (int)round(grg * 10);
	get_col_goal_index = (int)round(gcg * 10);
	/*cout << grs << "\n" << gcs << "\n";
	cout << get_row_start_index << "\n" << get_col_start_index << "\n";
	cout << grg << "\n" << gcg << "\n";
	cout << get_row_goal_index << "\n" << get_col_goal_index << "\n";*/
	if (get_row_start_index == get_row_goal_index 
		&& get_col_start_index == get_col_goal_index)
	{
		cout << "Error! The goal position and the start position are the same" << endl;
		get_row_start_index = -1;
		get_col_start_index = -1;
		get_row_goal_index = -1;
		get_col_goal_index = -1;
		return ;
	}

	int start, goal;
	start = m( get_row_start_index , get_col_start_index );
	goal= m(get_row_goal_index, get_col_goal_index);
	
	if (start == occupied_cell && get_row_start_index >= r && get_col_start_index >= c 
		&& get_row_start_index < 0 && get_col_start_index < 0)
	{
		cout << "Errore" << endl;
		get_row_start_index = -1;
		get_col_start_index = -1;
		return;
	}
	else if( goal == occupied_cell && get_row_goal_index >= r && get_col_goal_index >= c 
		&& get_row_goal_index < 0 && get_col_goal_index < 0)
	
	{
		cout << "Errore" << endl;
		get_row_goal_index = -1;
		get_col_goal_index = -1;
		return;
	}
	else
	{
		m.setDataMatrix(get_row_goal_index, get_col_goal_index, goal_cell);
		m.setDataMatrix(get_row_start_index, get_col_start_index, free_cell);
	}
	return;

}

void putDistance(Mat <int> &m)
{
	int r= m.getNumRows();
	int c= m.getNumCols();
	int data ;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			data = m.getDataMatrix( i , j );

			if ( data > 127 )
			{
				m.setDataMatrix(i,j, free_cell);
			}
			else
			{
				m.setDataMatrix( i , j , occupied_cell );
			}
		}
	}

	
}

/*Funzione per la verifica della possibilità di esplorazione della cella*/
bool checkAvailable(Mat <int> &m, int r, int c)
{
	int a =  m.getNumRows() ;
	int b = m.getNumRows() ;
	/*Si verifica dapprima l'appartenenza della cella alla matrice*/
	if ( r < 0 ||r >= a || c < 0 || c >= b )
	{
		return false;
	}

	/* Si verifica se la cella corrisponde ad un ostacolo*/
	if ( m.getDataMatrix(r,c) == occupied_cell)
	{
		return false;
	}

	return true;
}

void setPathDistance(Mat <int> &m, int &get_row_start_index , int &get_col_start_index, int &get_row_goal_index , int &get_col_goal_index)
{
	List pt;
	int r= m.getNumRows();
	int c= m.getNumCols();
	unsigned int dist;
	unsigned int data;

	//cout << "Sono nella funzione, ancora nessun errore"<< endl;

/*
	if (( m.getDataMatrix( get_row_goal_index , get_col_goal_index ) ) == goal_cell )
		{ */
			/*Si effettua la ricerca della goal position e si inserisce la cella 
			  corrispondente ad essa all'interno della lista; inoltre si inizializza
			  a zero la variabile distance*/
			pt.enqueue(Cell(get_row_goal_index , get_col_goal_index, goal_cell ) );
			dist = goal_cell;
			//cout << "Sono nella funzione, ancora nessun errore_1"<< endl;
	/*	}
		else
		{
			cout << "Error! There is not a goal position.\n" << endl;
			return;
		}*/

		/* Si inizializzano le variabili riguardanti la cella che si sta analizzando*/
		Cell this_cell;
		unsigned int this_row, this_col;

		//cout << "Sono nella funzione, ancora nessun errore_2"<< endl;
		
		/* Effettuo il ciclo di "esplorazione" fino a quando la lista non risulta vuota*/
		while(pt.checkNotEmpty())
		{
			//cout << "Sono nella funzione, ancora nessun errore_3"<< endl;
			/* Leggo il primo elemento (che nel primo giro corrisponde alla 
			   goal position) e ne salvo la posizione all'interno della matrice
			   e la distanza in esso riportata*/
			this_cell = pt.getFirst();
			//cout << "Qui"<< endl;
			this_row = this_cell.getRow();
			cout << "riga "<< this_row << endl;
			this_col = this_cell.getCol();
			cout << "colonna "<< this_col << endl;
			dist = this_cell.getDistance();
			cout << "dist 0"<< dist << "\n" << endl;
			pt.dequeue();
			//cout << "Sono nella funzione, ancora nessun errore_4"<< endl;

			/*Passo ad esplorare le celle adiacenti la cella in esame*/

			for ( int i = -1 ; i < 2 ; i++)
			{
				for ( int j = -1 ; j < 2; j++)
				{
					//cout << "Sono nella funzione, ancora nessun errore_5"<< endl;
					/* Si assicura che si stanno esplorando le quattro celle
					   adiacenti a quella in esame, ovvero quelle corrispondenti alla stessa riga
					   (i=0) e alle colonne adiacenti (j= -1 e j= 1) e quelle corrispondenti alla 
					   stessa colonna ( j= 0) e righe adiacenti ( i= -1 e i= 1)*/
					if ( i*j == 0 && i != j)
					{
						//cout << "Sono nella funzione, ancora nessun errore_6"<< endl;
						/* Verifico che la cella sia libera ed interna alla mappa*/
						if ( checkAvailable (m, this_row + i, this_col +j ) 
							&& (m.getDataMatrix(  this_row + i , this_col +j )) == free_cell )
						{
							// cout << "Sono nella funzione, ancora nessun errore_7"<< endl;
							/* Si setta la distanza della cella che si sta esplorando
							   pari al valore della distanza della cella precedente più uno*/
							m.setDataMatrix( (this_row + i) , (this_col + j) , ( dist +1));
							
							/* Inserisco la cella appena in)izializzata nella lista per
							   l'iterazione sucessiva*/
							pt.enqueue(Cell((this_row + i), (this_col+j) , (dist +1) ));
						}
					}
				}
			}
		}

	data = m.getDataMatrix (get_row_start_index , get_col_start_index);

	cout << "data vale :" << data << "\n" << endl;

	cout << free_cell << "\n" << endl;
	/*Per completezza verifico di aver aggiornato il valore della distanza 
	  della start position*/
	if (m.getDataMatrix(get_row_start_index , get_col_start_index) == free_cell)
	{
		cout << "Error! Something went wrong, the start position result unexplored" << endl;
		return;
	}
	return;
}

void drawPath(Mat <int> &m, int &get_row_start_index , int &get_col_start_index, int &get_row_goal_index , int &get_col_goal_index )
{
	int path_distance, this_row, this_col;
	this_row = get_row_start_index;
	this_col = get_col_start_index;

	path_distance = m.getDataMatrix(get_row_start_index , get_col_start_index);
	m.setDataMatrix( get_row_start_index , get_col_start_index, start_cell);

	while( path_distance > 0 )
	{
		for ( int i = -1 ; i <= 1 ; i++)
		{
			for ( int j = -1 ; j <= 1; j++)
			{
				if ( checkAvailable (m, this_row + i, this_col +j ) )
				{
					if (m.getDataMatrix(this_row + i, this_col +j) < path_distance)
					{
						path_distance = m.getDataMatrix(this_row + i, this_col +j);
						this_row = this_row + i;
						this_col = this_col +j;
						m.setDataMatrix(get_row_start_index , get_col_start_index, path_cell);
					}
				}
			}
		}
	}
	m.setDataMatrix( get_row_goal_index , get_col_goal_index, goal_cell_color);
}

void drawNewMap( Mat <unsigned char> &m, Mat <int> &m1 )
{
	int r= m.getNumRows();
	int c= m.getNumCols();

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; i < c; j++)
		{
			if ( m1.getDataMatrix( i , j ) == path_cell ||
				 m1.getDataMatrix( i , j ) == start_cell ||
				 m1.getDataMatrix( i , j ) == goal_cell_color )
			{
				m.setDataMatrix( i , j ,  ( unsigned char )m1.getDataMatrix ( i , j ) );
			}
			else
				NULL;
		}
	}
	return;
}