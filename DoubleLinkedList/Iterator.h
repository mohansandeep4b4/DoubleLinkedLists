#pragma once
class Iterator
{
private:
	Iterator(Cell* cellPtr);
	friend class LinkedList;

public:
	Iterator();
	
	Iterator(const Iterator& iterator);

	double getValue() { return m_cellPtr->getValue(); }
	void setValue(double value) { m_cellPtr->setValue(value); }

	bool hasNext() { return m_cellPtr->getNext() != nullptr; }
	void next() { m_cellPtr = m_cellPtr->getNext(); }

	bool hasPrevious() { return m_cellPtr->getPrevious() != nullptr; }
	void previous() { m_cellPtr = m_cellPtr->getPrevious(); }

private:
	Cell* m_cellPtr;

};

