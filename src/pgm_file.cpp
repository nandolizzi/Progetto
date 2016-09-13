#include <stdio.h>
#include "pgm_file.h"
#include "get_line.h"


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
	
void PgmFile::print() const
{
	printf("Sto per stampare un immagine PGM\n");
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			printf("%.3d\n",_data[ i*_col + j] );		
		}
	}

}

bool PgmFile::load( const char *filename )
{
	FILE *fp  = fopen(filename, "r");
	if (fp == NULL)
	{
		/*Verifica apertura di un file non vuoto*/
		printf("FILE vuoto\n");
		return false;
	}
	/*il file non è vuoto, si procede con la lettura delle
	  dimenbsioni della matrice*/
	char *line;
	line = getLine(fp);
	if ( line == NULL)
	{
		/*Verifica acquisizione della prima riga*/
		printf("Errore, riga vuota\n");
		fclose(fp);
		return false;
	}
	else if ( line[0] != 'P' || line[1] != '2')
	{
		/*Verifica che il codice inizi per il magic number dei file pgm*/
		printf("Il file selezionato non è un PgmFile\n");
		free(line);
		fclose(fp);
		return false;
	}
	/*Estazione delle dimensioni della matrice necessaria al
	  salvataggio del dato e del massimo valore di luminosità*/
	_row = _col = -1;
	while(( line = getLine(fp)) != NULL)
	{
		if ( line[0] != '#')
		{
			if ( sscanf( line, "%d %d", &_col, &_row) != 2)
			{
				printf("Errore nel dimensionamento della matrice\n");
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
				printf("Errore, sono inseriti più di un valore di luminosità massima\n");
				free ( line );
				fclose( fp );
				return false;
			}
			else
			{
				/*Ok! Ho copiato il valore della luminosità massima*/
				free ( line );
				break;
			}
		}
		free( line );
 	}
 	/*Immagazzinamento dei dati
 	  Per prima cosa verifico la corretta dimensione di righe e colonne*/
 	if ( _col == -1 || _row == -1)
 	{
 		/*I valori di riga e colonna acquisiti non sono
 		  validi*/
 		printf("Errore nel passaggio dei valori delle dimensioni\n");
 		fclose(fp);
 		return false;
 	}
 	/*Procedo con il salvataggio del valore della dimensione totale
 	  dell'array e con l'allocazione di data*/
 	unsigned int data_dim= _row * _col;
 	_data = new unsigned char[data_dim];
 	if ( _data == NULL)
 	{
 		printf("Errore nell'allocazione di _data\n");
 		return false;
 	}
 	/*Procedo con la lettura del file e dichiaro una variabile temporanea
 	  per non scrivere più volte su _data*/
 	int temp;
 	for (int i = 0; i < data_dim; i++)
 	{
 		if (fscanf(fp, "%d", &temp) != 1)
 		{
 			/*Non riesco a leggere i dati*/
 			delete [] _data;
 			fclose(fp);
 			return false;
 		}
 		_data[i] = (unsigned char) temp;
 	}
 	fclose(fp);
 	return true;
 }

bool PgmFile::save( const char *filename )
{
	FILE *fs = fopen( filename, "w");
	/*Controllo che l'apertura del file sia avvenuta correttamente*/
	if ( fs == NULL)
	{
		printf("Errore! Il file è vuoto\n");
		fclose(fs);
		return false;
	}
	/*Passo alla scrittura del file
	  Per prima cosa scrivo l'header, si noti come per adesso
	  debba settare il max_value e devo ricalcolare il valore massimo*/
	fprintf( fs , "P");
	fprintf( fs , "2\n");
	fprintf( fs, "#Questo è un commento\n");
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
		printf("ERROR_Index overdrive\n");
		return;
	}

	_data[r*_col + c] = data;
}

unsigned char PgmFile::getData( int r, int c)
{
	unsigned char data;
	if ( r < 0 || r >= _row || c < 0 || c >= _col )
	{
		printf("ERROR_Index overdrive\n");
		return 0;
	}
	data = _data[r*_col +c];
	return data;
}