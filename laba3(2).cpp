#include "mqueue.h"
#include <iostream>

void mqueue::input(int size) {
	int key;
	for (int k = 0; k < size; k++) {
		std::cout << "Enter element #" << k << ": ";
		std::cin >> key;
		this->push(key);
	}
}

void mqueue::print() {
	for (int i = 0; i < count; i++)
		std::cout << p[i] << "\t";
	std::cout << std::endl;
	std::cout << "Print Done.\n" << std::endl;
}

void mqueue::push(int item)
{
	int* p2;
	p2 = p;

	try {
		p = new int[count + 1];
		for (int i = 0; i < count; i++)
			p[i] = p2[i];
		p[count] = item;
		count++;
		if (count > 1)
			delete[] p2;
	}
	catch (std::bad_alloc e) {
		std::cout << e.what() << std::endl;
		p = p2;
	}
}

void mqueue::pop() {
	if (count == 0)
		return;
	try {
		int* p2;
		p2 = new int[--count];
		for (int i = 0; i < count; i++)
			p2[i] = p[i + 1]; // Копируется всё, кроме первого элемента
		if (count > 0)
			delete[] p;
		p = p2;
	}
	catch (std::bad_alloc e)
	{
		std::cout << e.what() << std::endl;
	}
}

mqueue::~mqueue() {
	if (count > 0)
		delete[] p;
}

mqueue& mqueue::operator=(const mqueue& obj) {
	int* p2;

	try {
		p2 = new int[obj.count];
		if (count > 0)
			delete[] p;
		p = p2;
		count = obj.count;
		for (int i = 0; i < count; i++)
			p[i] = obj.p[i];
	}
	catch (std::bad_alloc e)
	{
		std::cout << e.what() << std::endl;
	}
	return *this;
}

mqueue& mqueue::operator+=(int item) {
	this->push(item);
	return *this;
}
mqueue& mqueue::operator-=(int count) {
	for (int k = 0; k < count; k++)
		this->pop();
	return *this;
}
mqueue operator+(const mqueue& lhs, int item) {
	mqueue bufferq = lhs;
	bufferq += item;
	return bufferq;
}
mqueue operator-(const mqueue& lhs, int count) {
	mqueue bufferq = lhs;
	bufferq -= count;
	return bufferq;
}
