#pragma once
#include "cell.h"
#include <stdio.h>

class CellNode
{

public:
	CellNode( const Cell &c ) :
	cell_(c),
	prev_cell( NULL ),
	next_cell( NULL )
	{};

	~CellNode(){};

	Cell cell_;
	CellNode *prev_cell , *next_cell;
};

class List
{
public:

	List();
	~List();

	inline Cell getFirst() const { return firstp_ -> cell_; };
	void dequeue();
	
	void enqueue( const Cell &end_cell );

	void clear();

	bool checkNotEmpty() const;

	void printList() const;


private:
	CellNode *firstp_ , *lastp_;
};