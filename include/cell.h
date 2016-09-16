#pragma once

/* La cella equivale ad un punto della mappa, ovvero della 
   matrice che la rappresenta, contraddistinta dai propri indici di riga e colonna
   e dal valore in essa contenuto*/

   class Cell
   {
   
   public:
   
   /* Costruttore, costruttore di opia e distruttore */
   
   Cell(){};
   Cell(int r, int c, int d);
  	Cell (const Cell &other);
	~Cell(){};

	// Stampa a video della cella
	void printCell() const;

	// Metodi per la restituzione dei parametri privati
	inline int getDistance() const { return dist_ ; };
	inline int getRow() const { return row_; };
   inline int getCol() const { return col_; };

   // Metodo per la modifica dei valori della cella
   void setCell(int r, int c, int d);

   private:

   	int row_, col_;
   	int dist_;
   };