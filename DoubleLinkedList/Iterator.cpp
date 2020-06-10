#include "Cell.h"
#include "Iterator.h"

Iterator::Iterator(Cell* cellPtr)
	: m_cellPtr(cellPtr)
{

}

Iterator::Iterator()
	: m_cellPtr(nullptr)
{

}

Iterator::Iterator(const Iterator& iterator)
	: m_cellPtr(iterator.m_cellPtr)
{

}
