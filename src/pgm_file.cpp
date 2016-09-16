#include <stdio.h>
#include "pgm_file.h"
#include "get_line.h"

/* Costruttore e distruttore della classe */

PgmFile::PgmFile()
{
	_row = _col = 0;
	_data = NULL;
}
PgmFile::~PgmFile()
{
	if ( _data != NULL)
	{
		delete [] _data;
	}
	return;
}

/*Funzione per la stampa del file di tipo PGM. */

void PgmFile::print() const
{
	printf("I'm printing a PGM file\n");
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			printf("%.3d\n",_data[ i*_col + j] );		
		}
	}

}

/* Funzione booleana per controllare il caricamento del file*/

bool PgmFile::load( const char *filename )
{
	FILE *fp  = fopen(filename, "r");
	if (fp == NULL)
	{
		/*Verifica apertura di un file non vuoto*/
		
		printf("Empty file!\n");
		return false;
	}
	
	/* Il file non è vuoto, si procede con la lettura delle
	  dimensioni della matrice*/

	char *line;
	line = getLine(fp);
	if ( line == NULL)
	{
		/*Verifica acquisizione della prima riga*/

		printf("Error! The first row is empty!\n");
		fclose(fp);
		return false;
	}
	else if ( line[0] != 'P' || line[1] != '2')
	{
		/*Verifica che il codice inizi con il magic number dei file PGM */

		printf("Error! The selected file is not a PGM file!\n");
		free(line);
		fclose(fp);
		return false;
	}
	/*Estazione delle dimensioni della matrice necessaria al
	  salvataggio del dato riguardante l'intensità di grigio
	   e del massimo valore di luminosità*/

	_row = _col = -1;

	while(( line = getLine(fp)) != NULL)
	{
		if ( line[0] != '#')
		{
			if ( sscanf( line, "%d %d", &_col, &_row) != 2)
			{
				printf("Error index!\n");
				free(line);
				fclose(fp);
				return false;
			}

			/*Estrazione del valore massimo di luminosità*/

			int max_value;
			free ( line );
			line = getLine(fp);
			if(sscanf(line,"%d", &max_value) != 1)
			{
				printf("Error! There are more than one maximum value of grey intensity.\n");
				free ( line );
				fclose( fp );
				return false;
			}
			else
			{
				/*Ok! Si è copiato il valore della luminosità massima*/

				free ( line );
				break;
			}
		}
		free( line );
 	}
 	/*Immagazzinamento dei dati
 	  
 	Per prima cosa si verifica la corretta dimensione di righe e colonne, */

 	if ( _col == -1 || _row == -1)
 	{
 		/*I valori di riga e colonna acquisiti non sono
 		  validi*/

 		printf("Error! The dimension are not greater than zero. \n");
 		fclose(fp);
 		return false;
 	}
 	/* Si procede con il salvataggio del valore della dimensione totale
 	  dell'array e con l'allocazione di data*/

 	unsigned int data_dim= _row * _col;
 	_data = new unsigned char[data_dim];
 	if ( _data == NULL)
 	{
 		printf("Error during _data allocation.\n");
 		return false;
 	}
 	
 	/* si procede con la lettura del file si dichiara una variabile temporanea
 	  per evitare di scrivere su _data per pià di una volta. */

 	int temp;
 	for (int i = 0; i < data_dim; i++)
 	{
 		if (fscanf(fp, "%d", &temp) != 1)
 		{
 			/*Non si è riusciti a leggere i dati*/
 			delete [] _data;
 			fclose(fp);
 			return false;
 		}
 		_data[i] = (unsigned char) temp;
 	}
 	fclose(fp);
 	return true;
 }


/* Funzione booleana per controllare il salvataggio del file*/

bool PgmFile::save( const char *filename )
{
	FILE *fs = fopen( filename, "w");
	
	/* Si controlla che l'apertura del file sia avvenuta correttamente*/

	if ( fs == NULL)
	{
		printf("Error! Empty file.\n");
		fclose(fs);
		return false;
	}
	
	/* Si procede con la scrittura del file. */

	fprintf( fs , "P");
	fprintf( fs , "2\n");
	fprintf( fs, "#This is a comment\n");
	fprintf( fs, "%d %d\n",_col,_row );
	fprintf( fs, "255\n" );
	int data_dim = _col * _row;
	for (int i = 0; i < data_dim; i++)
	{
		fprintf(fs, "%d\n", _data[i] );
	}
	fclose( fs );
	return true;
}

/* Funzioni utilizzate per la lettura degli attributi privati del file. */
int PgmFile::getRow() const
{
	return _row;
}


int PgmFile::getCol() const
{
	return _col;
}

void PgmFile::setData( unsigned char data, int r, int c)
{
	if ( r < 0 || r >= _row || c < 0 || c >= _col ) 
	{
		printf("ERROR_Index overdrive set data pagm\n");
		return;
	}

	_data[r*_col + c] = data;
}

unsigned char PgmFile::getData( int r, int c)
{
	unsigned char data;
	if ( r < 0 || r >= _row || c < 0 || c >= _col )
	{
		printf("ERROR_Index overdrive get data pgm\n");
		return 0;
	}
	data = _data[r*_col +c];
	return data;
}