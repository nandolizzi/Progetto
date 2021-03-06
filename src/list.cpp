#include "list.h"
#include "cell.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Costruttore e distruttore di copia. 
List::List()
{
	firstp_ = lastp_ = NULL;
}

List::~List()
{
	clear();
}

/* Metodo per eliminare il primo elemento della lista. */
void List::dequeue()
{
	/* Si verifica se la lista è vuota */
	
	if ( firstp_ == NULL )
	return;
	
	// Qualora la lista abbia un solo nodo la "pulisco".
	
	if(firstp_ == lastp_)
		clear();
	else
	{
		/* Altrimenti inizializzo un nuovo nodo di appoggio. */

		CellNode *next_pn = firstp_ -> next_cell;
		delete firstp_;
		firstp_ = next_pn;
		firstp_ -> prev_cell = NULL;
	}
	
}
	
void List::enqueue( const Cell &end_cell )
{
	/* Si inizializza un nuovo nodo-cella */
	
	CellNode *new_n = new CellNode (end_cell);

	/* Si verifica se la lista è vuota */
	
	if( lastp_== NULL )
	{
		firstp_ = lastp_ = new_n;
	}
	else
	{
		lastp_->next_cell = new_n;
		new_n->prev_cell = lastp_;
		lastp_ = new_n;
	}
	
}

void List::clear()
{
	if ( firstp_ != NULL )
	{
		/* Si utilizza un puntatore temporaneo per evitare di accedere 
		   a firstp_->next dopo aver cancellato firstp_. */
		
		CellNode *next_n;

		/* Si eseguono le operazioni fino a quando la lista non risulta
		   completamente cancellata. */

		for ( ; firstp_ != NULL; firstp_ = next_n )
		{
			next_n = firstp_ -> next_cell ;
			delete firstp_ ;
		}
		
		/*Quando la lista risulta essere vuota si inizializzano
		  nuovamnente il primo nodo e l'ultimo nodo a 0. */
		
		lastp_ = firstp_ = NULL;
	}
	else
		return;
	return;
}

/* Funzione per verificare se la lista è vuota o meno. */
bool List::checkNotEmpty() const
{
	if ( firstp_ == NULL || lastp_ == NULL)
	 return false;
	return true;
}

// Stampa a video dell'intera lista.
void List::printList() const
{
	cout << "List:\n" << endl;
	
	/* Si verifica se la lista è vuota o meno. */

	if ( firstp_ != NULL )
	{
		CellNode *temp = firstp_;
		for ( ; temp != NULL; temp = temp -> next_cell )
		{
			temp -> cell_.printCell();
			cout << "\n" << endl;
		}

	}
	else
		cout << "The List is empty" << endl;
}
