#include<iostream>
#include"List.h"

int main()
{
	List list1;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		list1 += a;
	}

	std::cout << list1 << std::endl;
	list1.removeMinimal();
	std::cout << list1 << std::endl;

	list1.removeMinimal();
	std::cout << list1 << std::endl;

	list1.removeMinimal();
	std::cout << list1 << std::endl;

	

	return 0;
}
