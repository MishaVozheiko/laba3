#pragma once
class mychset { // Класс множества
private:
	char* value; // Массив char
	int count; // Количество элементов 
public: 
	mychset() : count(0), value(nullptr) { } // Конструктор без параметров
	mychset(const mychset&); // Констурктор копирования
	~mychset(); // Деструктор
	inline bool empty() const { return count == 0; } // Пустое ли множество
	inline char getChar(int position) const { return value[position]; } // Получить позицию элемента в множестве
	inline int size() const { return count; } // Размер множества
	void push(const char item); // Добавить элемент
	void print(); // Вывести множество в поток
	void input(int size); // Ввод множества
	bool subset(const char item); // Входит ли char в множество
	bool subset(const mychset&); // Является ли подмножеством

	mychset& operator=(const mychset&); // Оператор присваивания
	mychset& operator*=(const mychset&); // Пересечение
	bool operator<(const mychset&); // Проверка на подмножество
	bool operator>(const char item); // Принадлежность
	friend mychset operator*(const mychset&, const mychset&); // Пересечение
};
