// CustomContainer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>

template<typename T>
class MyContainer {
public:

	class iterator {
	public:
		typedef typename std::ptrdiff_t difference_type;
		typedef typename T value_type;
		typedef typename T & reference;
		typedef typename T * pointer;
		typedef std::forward_iterator_tag iterator_category; //or another tag

		iterator(const iterator & rhs) {
			_ptr = rhs._ptr;
		}
		iterator(pointer ptr) : _ptr(ptr){}
		bool operator == (const iterator & rhs) {
			return _ptr == rhs._ptr;
		}
		bool operator != (const iterator & rhs) {
			return _ptr != rhs._ptr;
		}
		iterator & operator ++ () {
			_ptr++;
			return *this;
		}
		iterator & operator ++ (int) {
			operator++();
			return *this;
		}
		reference operator * () {
			return *_ptr;
		}
	private:
		pointer _ptr;
	};

	MyContainer<T>(size_t initialSize) : _size(initialSize) {
		_data = new T[_size];
	}
	~MyContainer() {
		delete[] _data;
	}
	void insert(const T & val) {
		if (_lastIndex >= _size) {
			throw std::exception("growing size not implemented");
		}
		_data[_lastIndex] = val;
		_lastIndex++;
	}

	iterator begin() {
		return iterator(_data);
	}

	iterator end() {
		return iterator(_data + _lastIndex);
	}

private:
	size_t _lastIndex = 0;
	size_t _size;
	T* _data;
};


int main()
{
	auto cont = MyContainer<std::string>(3);
	cont.insert("value");
	cont.insert("some other value");
	cont.insert("yet another value");
	//cont.insert("should throw an exception");

	auto cont2 = MyContainer<int>(3);
	cont2.insert(1);
	cont2.insert(2);
	cont2.insert(3);

	auto it = cont.begin();
	std::cout << "*it: " << *it << std::endl;
	it++;
	std::cout << "*it: " << *it << std::endl;

	for (auto & val : cont) {
		std::cout << "val: " << val << std::endl;
	}

	for (auto val : cont2) {
		std::cout << "val: " << val << std::endl;
	}

	for (auto it = cont.begin(); it != cont.end(); it++) {
		std::cout << *it << std::endl;
	}

	std::for_each(cont.begin(), cont.end(), [](const auto & val) {
		std::cout << "val from for_each: " << val << std::endl;
	});

	//std::vector<int> v = { 1,2,3,4,5 };
	//auto ret = v.begin();

    return 0;
}

