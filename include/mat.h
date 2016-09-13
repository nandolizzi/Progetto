#pragma once
#include <vector>
#include <iostream>
#include <stdlib.h>

template <typename T> class Mat
{
public:
  Mat( int r, int c )
  {
    rows_ = r;
    cols_ = c;; 
    data_.resize(r*c);
  };

  int getNumRows() const{ return rows_; };
  int getNumCols() const{ return cols_; };
  T &operator()( int r, int c )  { return data_[r*cols_ + c]; };
 
  void fillRand()
  {
    for( int r = 0; r < rows_; r++)
    {
      for( int c = 0; c < cols_; c++)
        data_[r*cols_ + c] = (T)(1000.0*drand48());
    }
  };
  void scale( T s )
  {
    for( int r = 0; r < rows_; r++)
    {
      for( int c = 0; c < cols_; c++)
        data_[r*cols_ + c] *= s;
    }
  };
  void print()
  {
    for( int r = 0; r < rows_; r++)
    {
      for( int c = 0; c < cols_; c++)
      std::cout<<data_[r*cols_ + c]<<" ";
      std::cout<<std::endl;
    }
  };

  void setDataMatrix( int r, int c, int value )
  {
    if ( r < 0 || r >= rows_ || c < 0 || c >= cols_ ) 
    {
      printf("ERROR_Index overdrive 1\n");
      return;
    }
    data_[r*cols_ + c] = value;
  }
  
  T getDataMatrix ( int r, int c) const
  {
    if ( r < 0 || r >= rows_ || c < 0 || c >= cols_ ) {
    //printf("ERROR_Index overdrive 2\n");
    return 0;
  }
    return data_[r * cols_ + c];
  }
  
private:
    
  int rows_, cols_;
  std::vector<T> data_;
};
