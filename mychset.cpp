#include "mychset.h"
#include <iostream>

mychset::mychset(const mychset& mychset) { // Конструктор копирования
	value = new char[mychset.count]; // Выделяем память
	count = mychset.count;
	for (int i = 0; i < count; i++) // Заполняем 
		value[i] = mychset.value[i];
}

void mychset::input(int size) { // Ввод элементов
	char key;
	for (int k = 0; k < size; k++) {
		std::cout << "Enter element #" << k << ": ";
		std::cin >> key;
		this->push(key);
	}
}

void mychset::print() { // Вывод элементов
	for (int i = 0; i < count; i++)
		std::cout << value[i] << "\t";
	std::cout << "\nSize: " << count << "\n" << std::endl;
}

bool mychset::subset(const char item) { // Проверка на наличие элемента в множестве
	for (int i = 0; i < count; i++) {
		if (value[i] == item)
			return 1;
	}
	return 0;
}

bool mychset::subset(const mychset& mychset) { // Проверка на подмножество
	bool find = false;
	if (count >= mychset.count) { // Сверяем размеры множеств
		for (int i = 0; i < mychset.count; i++) { // Проходим все элементы множества
			for (int k = 0; k < count; k++) {
				if (value[k] == mychset.getChar(i)) {
					find = true;
				}
			}
			if (!find)
				return 0;
			find = false;
		}
		return 1;
	}
	else
		return 0;
}

void mychset::push(const char item) // Добавление элемента
{
	char* p2; // Выделяем память
	p2 = value;
	bool isFind = false;

	try {
		if (subset(item)) // Проверяем есть ли такой элемент
			return;
		value = new char[count + 1]; // Выделяем память
		for (int i = 0; i < count; i++) // Копируем
			value[i] = p2[i];
		for (int i = 0; i < count; i++) {
			if (item < value[i]) 
			{
				for (int k = count; k > i; k--) // Сдвигаем элементы для вставки нужного
				{
					value[k] = value[k - 1];
				}
				value[i] = item;
				isFind = true;
				break;
			}
		}
		if (!isFind)
			value[count] = item;
		count++;
		if (count > 0)
			delete[] p2; // Освобождаем память
	}
	catch (std::bad_alloc e) { 
		std::cout << e.what() << std::endl; // Если память не была выделена выводим причину
	}
}

mychset::~mychset() { // Деструктор
	if (count > 0)
		delete[] value;
}

mychset& mychset::operator=(const mychset& obj) { // Оператор присваивания
	char* val2;

	try {
		val2 = new char[obj.count]; // Выделяем память
		if (count > 0)
			delete[] value; // Освобождаем исхоную если была аллоцирована
		value = val2;
		count = obj.count;
		for (int i = 0; i < count; i++) // Копируем
			value[i] = obj.value[i];
	}
	catch (std::bad_alloc e)
	{
		std::cout << e.what() << std::endl;
	}
	return *this;
}

mychset& mychset::operator*=(const mychset& _mychset) { // Оператор пересечения 1
	mychset* buff = new mychset();
	for (int i = 0; i < _mychset.size(); i++) {
		if (subset(_mychset.value[i])) {
			buff->push(_mychset.value[i]);
		}
	}
	*this = *buff;
	return *this;
}

mychset operator*(const mychset& _mychset, const mychset& _mychset2) {  // Оператор пересечения 2
	mychset buff(_mychset);
	buff *= _mychset2;
	return buff;
}

bool mychset::operator<(const mychset& _mychset) { // Подмножество
	return subset(_mychset);
}

bool mychset::operator>(const char _item) { // Принадлежность
	return subset(_item);
}
