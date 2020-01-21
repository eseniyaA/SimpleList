#include<iostream>
#include"List.h"

int main()
{
	List list1;
	for (int i = 0; i < 10; i++)
	{
		int a;
		std::cin >> a;
		list1 += a;
	}

	std::cout << list1;
	return 0;
}
