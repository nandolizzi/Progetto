#pragma once

class PrintableFile
{
public:

  virtual ~PrintableFile(){};

  /* Print the file to stdout in a readable format */
  virtual void print() const = 0;
  /* Load to memory a file
   * Return true on success, false otherwise */
  virtual bool load( const char *filename ) = 0;
  /* Save to disk a file
   * Return true on success, false otherwise */
  virtual bool save( const char *filename ) = 0;

  virtual int getRow() const = 0;
  virtual int getCol() const = 0;
  virtual void setData( unsigned char data, int r, int c) = 0;
  virtual unsigned char getData( int r, int c) = 0;
};