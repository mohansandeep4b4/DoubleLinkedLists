#include <iostream>
#include "Cell.h"
using namespace std;

Cell::Cell(double value, Cell* previous, Cell* next)
	:m_value(value),
	 m_previous(previous),
	 m_next(next)
{
	//Empty
}

Cell::~Cell()
{
}