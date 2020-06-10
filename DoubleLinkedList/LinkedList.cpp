#include <iostream>
using namespace std;

#include "Cell.h"
#include "Iterator.h"
#include "LinkedList.h"

LinkedList::LinkedList()
	: m_size(0),
	m_firstCellPtr(nullptr),
	m_lastCellPtr(nullptr)
{
	//Empty
}

LinkedList::LinkedList(const LinkedList& list)
{
	assign(list);
}

void LinkedList::assign(const LinkedList& list)
{
	m_size = list.m_size;
	m_firstCellPtr = list.m_firstCellPtr;
	m_lastCellPtr = list.m_lastCellPtr;
	add(list);
}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::clear()
{
	Cell* currentCellPtr = m_firstCellPtr;
	while (currentCellPtr != nullptr)
	{
		Cell* deleteCellPtr = currentCellPtr;
		currentCellPtr = currentCellPtr->getNext();
		delete deleteCellPtr;
	}

	m_firstCellPtr = nullptr;	
	m_lastCellPtr = nullptr;
	m_size = 0;
}

bool LinkedList::find(double value, Iterator& findIterator)
{
	Iterator iterator = first();
	
	//TRY DO WHILE HERE
	while(iterator.hasNext())
	{
		if (value == iterator.getValue())
		{
			findIterator = iterator;
			return true;
		}

		iterator.next();
	}

	return false;
}

bool LinkedList::equal(const LinkedList& list) const
{
	if (m_size != list.m_size)
	{
		return false;
	}

	Iterator thisIterator = first(), listIterator = list.first();
	while (thisIterator.hasNext())
	{
		if (thisIterator.getValue() != listIterator.getValue())
		{
			return false;
		}

		thisIterator.next();
		listIterator.next();
	}

	return true;
}

bool LinkedList::notEqual(const LinkedList& list) const
{
	return !equal(list);
}

void LinkedList::add(double value)
{
	Cell* newCellPtr = new Cell(value, m_lastCellPtr, nullptr);

	if (m_firstCellPtr == nullptr)
	{
		m_firstCellPtr = newCellPtr;
	}
	else
	{
		m_lastCellPtr->setNext(newCellPtr);
	}

	m_lastCellPtr = newCellPtr;
	++m_size;
}

void LinkedList::add(const LinkedList& list)
{
	Cell* listCellPtr = list.m_firstCellPtr;

	while (listCellPtr != nullptr)
	{
		double value = listCellPtr->getValue();
		Cell* newCellPtr = new Cell(value, m_lastCellPtr, nullptr);

		if (m_firstCellPtr == nullptr)
		{
			m_firstCellPtr = newCellPtr;
		}
		else
		{
			m_lastCellPtr->setNext(newCellPtr);
		}
		m_lastCellPtr = newCellPtr;
		listCellPtr = listCellPtr->getNext();
	}

	m_size += list.m_size;
}