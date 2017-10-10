#include "IntCell.h"

IntCell::IntCell(int initialValue)
{
	m_storedValue = new int(initialValue);
}

IntCell::IntCell(const IntCell & rhs)
{
	m_storedValue = new int(*rhs.m_storedValue);
}

IntCell::~IntCell()
{
	delete m_storedValue;
}

const IntCell & IntCell::operator=(const IntCell & rhs)
{
	if (this != &rhs) {
		*m_storedValue = *rhs.m_storedValue;
	}
	return *this;
}

int IntCell::read() const
{
	return *m_storedValue;
}

void IntCell::write(int x)
{
	*m_storedValue = x;
}
