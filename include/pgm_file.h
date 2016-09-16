#pragma once
#include "printable_file.h"

class PgmFile : public PrintableFile
{
public:
	PgmFile();
	virtual ~PgmFile();
	
	virtual void print() const;
 	virtual bool load( const char *filename );
  virtual bool save( const char *filename );
  
  /* Metodi introdotti per lo sviluppo del progetto; sono funzioni con le quali si possono
     leggere gli attributi privati della classe e si possono settare i valori da scrivere
     nella matrice rappresentante l'immagine. */

  virtual int getRow() const;
  virtual int getCol() const;
  virtual void setData( unsigned char data, int r, int c);
  virtual unsigned char getData( int r, int c);
 
 private:
 	int _row, _col;
 	unsigned char *_data;
};