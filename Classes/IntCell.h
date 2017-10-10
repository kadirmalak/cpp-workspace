#pragma once

class IntCell
{
	int _storedValue;

public:
	explicit IntCell(int initialValue = 0);
	int read() const;
	void write(int x);
};
