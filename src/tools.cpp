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
#define color_cell 70


void getPosition( Mat <int> &m, int &get_row_start_index , int &get_col_start_index, int &get_row_goal_index , int &get_col_goal_index)
{
	double grs, gcs, grg, gcg;
	// int *start, *goal;
	int r= m.getNumRows();
	int c= m.getNumCols();

	cout << "Please insert the robot start position and the robot goal position.\n" << endl;
	cout << "Insert the start column: " << endl;
	cin >> grs;
	cout << "Insert the start row: " << endl;
	cin >> gcs;
	cout << "Insert the goal column: " << endl;
	cin >> grg;
	cout << "Insert the goal row: " << endl;
	cin >> gcg;
	
	/*grs = 23.3;
	gcs = 9.9;
	grg = 29.1;
	gcg = 12.6;*/

	get_row_start_index = (int)round(grs * 10);
	get_col_start_index = (int)round(gcs * 10);
	get_row_goal_index = (int)round(grg * 10);
	get_col_goal_index = (int)round(gcg * 10);
	
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
	
	if (start == occupied_cell || get_row_start_index >= r || get_col_start_index >= c 
		|| get_row_start_index < 0 || get_col_start_index < 0)
	{
		cout << "Error the start position is invalid!" << endl;
		get_row_start_index = -1;
		get_col_start_index = -1;
		return;
	}
	else if( goal == occupied_cell || get_row_goal_index >= r || get_col_goal_index >= c 
		|| get_row_goal_index < 0 || get_col_goal_index < 0)
	
	{
		cout << "Error the goal position is invalid!" << endl;
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
	int b = m.getNumCols() ;
	//cout << "righe vale: " << a << " colonne vale: " << b << " invece r e c valgono rispettivamente: "<< r << " " << c << endl;
	/*Si verifica dapprima l'appartenenza della cella alla matrice*/
	if ( r < 0 && r > a -1 )
		return false;

	if ( c < 0 && c < b -1)
		return false;
	
	int available = m(r,c);
	// cout << available << endl;
	if ( available == occupied_cell)
		return false;
	else
		return true;
}

void setPathDistance(Mat <int> &m, int &get_row_start_index , int &get_col_start_index, int &get_row_goal_index , int &get_col_goal_index)
{
	List pt;
	int r= m.getNumRows();
	int c= m.getNumCols();
	int dist = 0;
	int data;

	//cout << "Sono nella funzione, ancora nessun errore"<< endl;


	if ( m( get_row_goal_index , get_col_goal_index ) != goal_cell )
	{ 
		/*Si effettua la ricerca della goal position e si inserisce la cella 
		  corrispondente ad essa all'interno della lista; inoltre si inizializza
		  a zero la variabile distance*/
		cout << "Error! There is not a goal position.\n" << endl;
		return;
	}
		
	pt.enqueue(Cell(get_row_goal_index , get_col_goal_index, m(get_row_goal_index,  get_col_goal_index) ) );

	//cout << "Sono nella funzione, ed ho trovato lo 0 nella goal cell"<< endl;
		
	/* Si inizializzano le variabili riguardanti la cella che si sta analizzando*/
	Cell this_cell;
	int this_row, this_col;
	this_row = get_row_goal_index;
	this_col = get_col_goal_index;
	dist = m(get_row_goal_index,  get_col_goal_index);

	//cout << "Sono nella funzione, ancora nessun errore_2"<< endl;
		
	/* Effettuo il ciclo di "esplorazione" fino a quando la lista non risulta vuota*/
	while(pt.checkNotEmpty())
	{
		// cout << "Eseguo il check su lista vuota"<< endl;
		/* Leggo il primo elemento (che nel primo giro corrisponde alla 
		   goal position) e ne salvo la posizione all'interno della matrice
		   e la distanza in esso riportata*/
		this_cell = pt.getFirst();
		//cout << "Qui"<< endl;
		this_row = this_cell.getRow();
		// cout << "riga "<< this_row << endl;
		this_col = this_cell.getCol();
		// cout << "colonna "<< this_col << endl;
		dist = this_cell.getDistance();
		// cout << "dist: "<< dist << "\n" << endl;
		pt.dequeue();
		//cout << "Sono nella funzione, ancora nessun errore_4"<< endl;

		/*Passo ad esplorare le celle adiacenti la cella in esame*/

		for ( int i = -1 ; i < 2 ; i++)
		{
			// cout << "sì sono nel primo for " << i << endl; 
			for ( int j = -1 ; j < 2; j++)
			{
				//cout << "Sono nella funzione, ancora nessun errore_5"<< endl;
				/* Si assicura che si stanno esplorando le quattro celle
				   adiacenti a quella in esame, ovvero quelle corrispondenti alla stessa riga
				   (i=0) e alle colonne adiacenti (j= -1 e j= 1) e quelle corrispondenti alla 
				   stessa colonna ( j= 0) e righe adiacenti ( i= -1 e i= 1)*/
				// cout << "sì sono nel secondo for " << j << endl;
				if ( i*j == 0 && i != j)
				{
					// cout << "sono nei for annidati" << endl;
					int q = m( this_row +i, this_col +j );
					// cout << "Il valore della cella in analisi è: " << q << endl;
					/* Verifico che la cella sia libera ed interna alla mappa*/
					if ( checkAvailable (m, this_row + i, this_col +j ) 
						&& m( this_row + i  ,  this_col +j ) == free_cell )
					{
						// cout << "la cella è risultata accessibile\n" << endl;
						// cout << "Sono nella funzione, ancora nessun errore_7"<< endl;
						/* Si setta la distanza della cella che si sta esplorando
						   pari al valore della distanza della cella precedente più uno*/
						m.setDataMatrix( this_row + i , this_col + j , dist +1 );

						int data5 = m( this_row +i , this_col +j );

						// cout << "data5 vale: " << data5 << endl;

						/* Inserisco la cella appena in)izializzata nella lista per
						   l'iterazione sucessiva*/
						
						pt.enqueue(Cell(this_row + i, this_col+j , dist +1 ));
					}
				}
			}
		}
	}

	/*int data3 = m(get_row_start_index , get_col_start_index);

	cout << "data3 vale: " << data3 << endl;

	int data4 = m(get_row_goal_index , get_col_goal_index + 1);
	cout << "data4 vale: " << data4 << endl; */

	/*Per completezza verifico di aver aggiornato il valore della distanza 
	della start position*/
	int start_cell_available = m(get_row_start_index , get_col_start_index);
	if ( start_cell_available == free_cell)
	{
		cout << "Error! Something went wrong, the start position result unexplored" << endl;
		return;
	}
	return;
}

void drawPath(Mat <int> &m, Mat <int> &m1, int &get_row_start_index , int &get_col_start_index, int &get_row_goal_index , int &get_col_goal_index)
{
	int path_distance, this_row, this_col;
	this_row = get_row_start_index;
	this_col = get_col_start_index;

	path_distance = m.getDataMatrix(get_row_start_index , get_col_start_index);
	m1.setDataMatrix( get_row_start_index , get_col_start_index, color_cell);
	drawRectStart( m1, get_row_start_index, get_col_start_index);

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
						m1.setDataMatrix(this_row +i , this_col +j , path_cell);
						this_row = this_row + i;
						this_col = this_col +j;
						
					}
				}
			}
		}
	}
	m1.setDataMatrix( get_row_goal_index , get_col_goal_index, color_cell);
	drawRectGoal( m1, get_row_goal_index , get_col_goal_index);
}

void drawRectStart(Mat <int> &m, int &get_row_start_index , int &get_col_start_index)
{
	for (int i = -2 ; i <= 2; i++)
	{
		m.setDataMatrix( get_row_start_index -4 , get_col_start_index +i ,  color_cell);
		m.setDataMatrix( get_row_start_index +4 , get_col_start_index +i ,  color_cell);
	}
	for (int i = -4 ; i <= 4; i++)
	{
		m.setDataMatrix( get_row_start_index + i , get_col_start_index + 2 , color_cell);
		m.setDataMatrix( get_row_start_index + i , get_col_start_index - 2 , color_cell);
	}
} 

void drawRectGoal(Mat <int> &m, int &get_row_goal_index , int &get_col_goal_index)
{
	for (int i = -3 ; i <= 3; i++)
	{
		m.setDataMatrix( get_row_goal_index -6 , get_col_goal_index +i ,  color_cell);
		m.setDataMatrix( get_row_goal_index +6 , get_col_goal_index +i ,  color_cell);
	}
	for (int i = -6 ; i <= 6; i++)
	{
		m.setDataMatrix( get_row_goal_index + i , get_col_goal_index + 3 , color_cell);
		m.setDataMatrix( get_row_goal_index + i , get_col_goal_index - 3 , color_cell);
	}
}