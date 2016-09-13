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
  	
  virtual int getRow() const;
  virtual int getCol() const;
  virtual void setData( unsigned char data, int r, int c);
  virtual unsigned char getData( int r, int c);
 
 private:
 	int _row, _col;
 	unsigned char *_data;
};