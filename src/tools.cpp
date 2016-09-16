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

/* Funzione che cattura i valori degli indici di riga e colonna delle celle di start e goal e che setta a "0" la distanza di quest'ultima. */

void getPosition( Mat <int> &m, int &get_row_start_index , int &get_col_start_index, 
	              int &get_row_goal_index , int &get_col_goal_index, int r , int c )
{
	/* Si inizializzano le variabili relative agli indici di righe e colonne delle celle start e goal. */

	double grs, gcs, grg, gcg;

	/* Si catturano da tastiera i valori delle posizioni delle celle espresse in metri. */
	
	cout << "Please insert the coordinates of the robot start position and the robot goal position expressed in metres." << endl;
	cout << "Remember it is possible choose inside 60 metres by 80 metres" << endl;
	cout << "Insert the vertical start position coordinate: " << endl;
	cin >> grs;
	cout << "Insert the horizontal start position coordinate: " << endl;
	cin >> gcs;
	cout << "Insert the vertical goal positionvcoordinate: " << endl;
	cin >> grg;
	cout << "Insert the horizontal goal position coordinate: " << endl;
	cin >> gcg;
	
	/* Si convertono i valori acquisiti in metri nei valori utilizzati all'interno delle funzioni ovvero di righe e colonne. */
	
	get_row_start_index = (int)round(grs * 10);
	get_col_start_index = (int)round(gcs * 10);
	get_row_goal_index = (int)round(grg * 10);
	get_col_goal_index = (int)round(gcg * 10);

	/* Si effettuano controlli relativi alla validità delle posizioni inserite; per prima cosa si verifica che la posizione
	   di start non corrisponda alla posizione goal. Nel caso in cui sia stato commesso qualche errore il valore della colonna e della 
	   riga vengono impostati a distanza -1, ovvero una distanza che non si presenterebbe mai. */

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

	/* Per facilitare la lettura del codice si inizializzano due variabili intere atte a contenere il valore della distanza
	   della cella, il quale, in questo punto del programma, corrisponde a free o occupied cell. */
	
	int start, goal;
	start = m( get_row_start_index , get_col_start_index );
	goal= m(get_row_goal_index, get_col_goal_index);
	
	/* Si verifica che le celle start e goal non siano occupate e non siano esterne alla mappa. */
	
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
		/* Nel caso in cui non si sia verificato alcun errore si inizializza a "0" la distanza della cella goal. */

		m(get_row_goal_index, get_col_goal_index ) = goal_cell;
	}
	return;

}

/* Funzione per la verifica della possibilità di esplorazione della cella. */

bool checkAvailable(Mat <int> &m, int r, int c)
{
	int a =  m.getNumRows() ;
	int b = m.getNumCols() ;

	/* Si verifica dapprima l'appartenenza della cella alla matrice. */
	
	if ( r < 0 && r > a -1 )
		return false;

	if ( c < 0 && c < b -1)
		return false;
	
	/* Se la cella appartiene alla mappa si verifica che essa non sia occupata da un ostacolo. */

	if ( m(r,c) == occupied_cell)
		return false;
	else
		return true;
}

/* Funzione che implementa l'algoritmo di Path Planning Grassfire che viene utilizzato per settare le distanze
   di ogni cella contenuta nella mappa rispetto alla cella goal. */

void setPathDistance( Mat <int> &m, int &get_row_start_index , int &get_col_start_index, 
					  int &get_row_goal_index , int &get_col_goal_index, int r, int c )
{
	cout << "The system is calculating the robot path." << endl;
	/* Si dichiarano una variabile appartenente alla classe List ed una variabile
	   intera che verrà utilizzata per indicare la distanza di ogni cella dalla cella goal. */
	
	List pt;
	int dist = 0;

	if ( m( get_row_goal_index , get_col_goal_index ) != goal_cell )
	{ 
		/*Si effettua la ricerca della goal position e si inserisce la cella 
		  corrispondente ad essa all'interno della lista; inoltre si inizializza
		  a zero la variabile distance. */
		
		cout << "Error! There is not a goal position.\n" << endl;
		return;
	}
		
	pt.enqueue(Cell(get_row_goal_index , get_col_goal_index, m(get_row_goal_index,  get_col_goal_index) ) );

	
		
	/* Si inizializzano le variabili riguardanti la cella che si sta analizzando. */
	
	Cell this_cell;
	int this_row, this_col;
	this_row = get_row_goal_index;
	this_col = get_col_goal_index;
	dist = m(get_row_goal_index,  get_col_goal_index);
		
	/* Si effettua il ciclo di "esplorazione" fino a quando la lista non risulta vuota. */
	
	while(pt.checkNotEmpty())
	{
		/* Si legge il primo elemento della lista (che inizialmente corrisponde alla cella
		   goal, che sarà anche l'unico elemento della stessa) e ne salvo la posizione all'interno della matrice,
		   ovvero la riga e la colonna corrispondente, e la distanza in esso riportata*/
		
		this_cell = pt.getFirst();
		
		this_row = this_cell.getRow();
		
		this_col = this_cell.getCol();
		
		dist = this_cell.getDistance();

		/* Dopo aver passato i valori relativi alla cella in esame sulle variabili adibite a tale compito si elimina 
		   la prima cella dalla lista. */
		
		pt.dequeue();

		/* Si passa ad esplorare le celle adiacenti la cella in esame .*/

		for ( int i = -1 ; i <= 1 ; i++)
		{
			for ( int j = -1 ; j <= 1; j++)
			{
				/* Si assicura che si stanno esplorando le quattro celle
				   adiacenti a quella in esame, ovvero quelle corrispondenti alla stessa riga
				   (i=0) e alle colonne adiacenti (j= -1 e j= 1) e quelle corrispondenti alla 
				   stessa colonna ( j= 0) e righe adiacenti ( i= -1 e i= 1)*/
				
				if ( i*j == 0 && i != j)
				{					
					/* Si verifica che la cella sia libera ed interna alla mappa*/
					
					if ( checkAvailable (m, this_row + i, this_col +j ) 
						&& m( this_row + i  ,  this_col +j ) == free_cell )
					{
						/* Si setta la distanza della cella che si sta esplorando
						   pari al valore della distanza della cella precedente più uno*/
						
						m( this_row + i , this_col + j ) = dist +1;

						/* Si inserisce la cella appena esplorata nella lista per
						   l'iterazione sucessiva*/
						
						pt.enqueue(Cell(this_row + i, this_col+j , dist +1 ));
					}
				}
			}
		}
	}

	/*Per completezza si verifica di aver aggiornato il valore della distanza della start position che potrebbe non essere stata esplorata. 
	In caso di utilizzo di questa funzione in un altro programma potrebbe inoltre esserci la possibilità di percorsi chiusi, 
	quindi l'impossibilità di traccciare un percorso dall cella start alla cella goal. */
	
	if ( m(get_row_start_index , get_col_start_index) == free_cell)
	{
		cout << "Error! Something went wrong, the start position result unexplored" << endl;
		return;
	}
	return;
}

/* Funzione che traccia il percorso richiesto sulla matrice copia della matrice rappresentante il file. */

void drawPath(Mat <int> &m, Mat <int> &m1, int &get_row_start_index , 
			  int &get_col_start_index, int &get_row_goal_index , int &get_col_goal_index)
{
	cout << "The system is drawing the robot path on a new map." << endl;
	/* Si inizializzano le variabili riguardanti quello che sarà il percorso e la riga e colonna con le quali si "scorrerà
	   la matrice. */

	int path_distance, this_row, this_col;
	this_row = get_row_start_index;
	this_col = get_col_start_index;

	/* Si inizia a tracciare il percorso a partire dalla cella start con un'intensità di grigio pari alla metà di quanto possibile.
	   Si evidenzia la cella di start con un grigio più intenso rispetto a quello del percorso e con un rettangolo 12x6 dello stesso grigio 
	   della cella di start */

	path_distance = m(get_row_start_index , get_col_start_index);
	m1( get_row_start_index , get_col_start_index ) = color_cell;
	drawRectStart( m1, get_row_start_index, get_col_start_index);

	/* Si effettua il ciclo di tracciamento del path partendo dalla cella start fino a risalire alla cella goal per la quale, ovviamente, 
	   la distanza sarà nulla */
	while( path_distance > 0 )
	{
		for ( int i = -1 ; i <= 1 ; i++)
		{
			for ( int j = -1 ; j <= 1; j++)
			{
				/* Prima di accedere alla cella adiacente a quella in esame
				   e valutarne la distanza si verifica che la cella sia libera. */
				
				if ( checkAvailable (m, this_row + i, this_col +j ) )
				{
					if (m(this_row + i, this_col +j) < path_distance)
					{
						/* Si verifica che la distanza rispetto alla cella goal sia inferiore 
						   rispetto alla cella fino alla quale si è tracciato il percorso. 
						   In caso positivo si aggiorna il valore della ditanza, si traccia il percorso all'interno di essa
						   e si aggiorna il valore della riga e della colonna. */

						path_distance = m(this_row + i, this_col +j);
						m1(this_row +i , this_col +j ) = path_cell;
						this_row = this_row + i;
						this_col = this_col +j;
						
					}
				}
			}
		}
	}

	/* Terminato il tracciamento del percorso si passa ad evidenziare la cella goal. In questo caso si utilizza
	   la stessa tonalità di grigio della cella start ma un rettangolo di dimensioni 6x12. */

	m1( get_row_goal_index , get_col_goal_index ) = color_cell;
	drawRectGoal( m1, get_row_goal_index , get_col_goal_index);
}

/* Funzione utilizzata per tracciare il rettangolo che evidenzia la cella di start*/

void drawRectStart(Mat <int> &m, int &get_row_start_index , int &get_col_start_index)
{
	for (int i = -6 ; i <= 6; i++)
	{
		m( get_row_start_index -3 , get_col_start_index +i ) =  color_cell;
		m( get_row_start_index +3 , get_col_start_index +i ) =  color_cell;
	}
	for (int i = -3 ; i <= 3; i++)
	{
		m( get_row_start_index + i , get_col_start_index + 6 ) = color_cell;
		m( get_row_start_index + i , get_col_start_index - 6 ) = color_cell;
	}
} 

/* Funzione utilizzata per tracciare il rettangolo che evidenzia la cella goal. */

void drawRectGoal(Mat <int> &m, int &get_row_goal_index , int &get_col_goal_index)
{
	for (int i = -3 ; i <= 3; i++)
	{
		m( get_row_goal_index -6 , get_col_goal_index +i ) = color_cell;
		m( get_row_goal_index +6 , get_col_goal_index +i ) = color_cell;
	}
	for (int i = -6 ; i <= 6; i++)
	{
		m( get_row_goal_index + i , get_col_goal_index + 3 ) = color_cell;
		m( get_row_goal_index + i , get_col_goal_index - 3 ) = color_cell;
	}
}