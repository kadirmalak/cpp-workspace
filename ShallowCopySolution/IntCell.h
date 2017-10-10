#pragma once

class IntCell
{
	int* m_storedValue;

public:
	explicit IntCell(int initialValue = 0);
	IntCell(const IntCell & rhs);
	~IntCell();
	const IntCell & operator=(const IntCell & rhs);
	int read() const;
	void write(int x);
};
