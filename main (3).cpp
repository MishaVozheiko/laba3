#include <iostream>
#include "mychset.h"

int main()
{
	mychset set1; // Множество 1
	mychset set2; // Множество 2
	mychset set3; // Множество 3
	set1.input(3); // Ввод
	set2.input(3);
	set3 = set1 * set2; // Пересечение
	std::cout << "SET 1:\n";
	set1.print();
	std::cout << "SET 2:\n";
	set2.print();
	std::cout << "SET 3(Subset of 1 & 2 :\n";
	set3.print();
	std::cout << std::endl;
	if (set1 < set2)
		std::cout << "Set1 is subset of set2" << std::endl;
	else
		std::cout << "Set1 is not subset of set2" << std::endl;

	char isPresent = 'A'; // Символ для проверки
	if (set1 > isPresent)
		std::cout << isPresent << " present in set1" << std::endl;
	else
		std::cout << isPresent << " not present in set2" << std::endl;
	return 0;
}