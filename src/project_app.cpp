#include "pgm_file.h"
#include "mat.h"
#include "tools.h"
#include <iostream>
#include <string.h>

using namespace std;

// Il robot si muove su di una cella di 60*80 metri


int main()
{
	PrintableFile *file;

	file = new PgmFile();
	file -> load("map.pgm");

	int r = file -> getRow();
	int c = file -> getCol();

	cout << "Sto per stampare le dimensioni della matrice del file:\n" <<  r << "\n" << c << endl;

	Mat <int> distance(r,c);
	int data[r*c];

	for (int i = 0; i < r ; i++)
	{
		for (int j = 0; j < c; j++)
		{
			data[i*c + j] = (int) file -> getData(i, j);
			distance.setDataMatrix( i, j, data[i*c + j]);
		}
	}

	cout << "Ancora nessun errore" << endl;

	//distance.print();

	

	Mat < int > copia ( r , c );

	cout << "Ancora nessun errore_1" << endl;

	for (int i = 0; i < r ; i++)
	{
		for (int j = 0; j < c; j++)
		{
			data[i*c + j] = (int)file->getData(i, j);
			copia.setDataMatrix( i, j, data[i*c + j]);
		}
	}

	cout << "Ancora nessun errore_2" << endl;

	//copia.print();

	putDistance( distance );

	cout << "Ancora nessun errore_3" << endl;



	int get_row_start_index = 0;
	int get_col_start_index = 0;
	int get_row_goal_index = 0;
	int get_col_goal_index = 0;
	getPosition( distance, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);

	cout << "Ancora nessun errore_4" << endl;

	if ( get_row_start_index == -1 || get_col_start_index == -1 || get_row_goal_index == -1 || get_col_goal_index == -1 )
	{
		getPosition( distance, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);
	}
	else 
		NULL;

	cout << "Ancora nessun errore_5" << endl;

	//distance.print();

		for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (distance(i,j) == -1 || distance(i,j) == -2)
			{
				continue;			
			}
			else
			{
				cout << distance(i,j) << endl;
				cout << " Mannaggia al diavoletto di Mircolosi" << endl;
			}
		}
	}

	
	
	/*setPathDistance ( distance, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);
	
	cout << "Ancora nessun errore_6" << endl;

	drawPath( distance, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);
	
	cout << "Ancora nessun errore_7" << endl;
	
	drawNewMap( copia , distance );

	cout << "Ancora nessun errore_8" << endl;

 	string filename;
	
	cout << "Please insert the name of the new map file" << endl;
	getline ( cin, filename);

	char *name;

	name = new char [ filename.size() + 1 ];
    memcpy( name , filename.c_str(), filename.size() + 1);

	for (int i = 0; i < r*c ; i ++)
	 {
	 	data [i] = 0;
	 } 

	for (int i = 0; i < r ; i++)
	{
		for (int j = 0; j < c; j++)
		{
			data[i*c + j] = copia.getDataMatrix( i , j );
			file -> setData( i , j, data[i*c + j] );
		}
	}

	file -> save(name); */


	delete file;

	return 0;
}
