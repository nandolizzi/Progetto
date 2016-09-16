#include "cell.h"
#include <iostream>

using namespace std;

/* Costruttore, costruttore di copia e distruttore*/
Cell::Cell(int r, int c, int d)
{
	row_ = r;
	col_ = c;
	dist_ = d;
}


Cell::Cell(const Cell &other)
{
	row_ = other.row_;
  	col_ = other.col_;
  	dist_ = other.dist_;
}

// Stampa a video della cella
void Cell::printCell() const
{
	cout << dist_ << "\n" << endl;
}

// Metodo per la modifica dei valori della cella
void Cell::setCell(int r, int c, int d)
{
	row_ = r;
	col_ = c;
	dist_ = d;
}