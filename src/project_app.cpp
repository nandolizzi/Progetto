#include "pgm_file.h"
#include "mat.h"
#include "tools.h"
#include <iostream>
#include <string.h>

using namespace std;

#define Black 255
#define White 0


// Il robot si muove su di una cella di 60*80 metri


int main()
{
	PrintableFile *file;

	file = new PgmFile();
	file -> load("map.pgm");

	int r = file -> getRow();
	int c = file -> getCol();
	int data1;

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

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			data1 = (int) file -> getData(i, j);;

			if ( data1 > 127 )
			{
				copia.setDataMatrix(i,j, Black);
			}
			else
			{
				copia.setDataMatrix( i , j , White );
			}
		}
	}

	// cout << "Ancora nessun errore_2" << endl;

	//copia.print();

	putDistance( distance );

	// cout << "Ancora nessun errore_3" << endl;



	int get_row_start_index = 0;
	int get_col_start_index = 0;
	int get_row_goal_index = 0;
	int get_col_goal_index = 0;
	getPosition( distance, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);

	//cout << "Ancora nessun errore_4" << endl;

	if ( get_row_start_index == -1 || get_col_start_index == -1 || get_row_goal_index == -1 || get_col_goal_index == -1 )
	{
		getPosition( distance, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);
	}
	else 
		NULL;

	// cout << "Ancora nessun errore_5" << endl;

	//distance.print();

	
	
	setPathDistance ( distance, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);
	
	/*cout << "Ancora nessun errore_6" << endl; */

	drawPath( distance, copia, get_row_start_index ,get_col_start_index, get_row_goal_index, get_col_goal_index);


 	/*string filename;
	
	cout << "Please insert the name of the new map file" << endl;
	getline ( cin, filename);

	char *name;

	name = new char [ filename.size() + 1 ];
    memcpy( name , filename.c_str(), filename.size() + 1);*/

	for (int i = 0; i < r*c ; i ++)
	 {
	 	data [i] = 0;
	 } 

	for (int i = 0; i < r ; i++)
	{
		for (int j = 0; j < c; j++)
		{
			data[i*c + j] = copia.getDataMatrix( i , j );
			file -> setData( data[i*c + j], i , j);
		}
	}

	file -> save("Ci_siamo_1.pgm");


	delete file;

	return 0;
}
