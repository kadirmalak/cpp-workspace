#include "stdafx.h"
#include "IntCell.h"

IntCell::IntCell(int initialValue) : _storedValue(initialValue) {

}

int IntCell::read() const {
	return _storedValue;
}

void IntCell::write(int x) {
	_storedValue = x;
}
