#include "stdafx.h"
#include "Cell.h"

Cell::Cell(int row, int col, int peice, int priority) {
	this->row = row;
	this->col = col;
	this->peice = peice;
	this->priority = priority;
}