#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

class List
{
private:
	Node* head; //"голова" связанного списка
public:
	List() //конструктор класса без параметров
	{
		head = NULL; //первого элемента пока нет
	}
	//метод, добавляющий новый узел в список
	void operator+=(int d)
	{
		Node* nd = new Node; //динамически создаем новый узел
		nd->data = d;        //задаем узлу данные
		nd->next = NULL;     //новый узел в конце, поэтому NULL
		if (head == NULL)     //если создаем первый узел
			head = nd;
		else                 //если узел уже не первый
		{
			Node* current = head;
			//ищем в цикле предшествующий последнему узел
			while (current->next != NULL)
				current = current->next;
			//предшествующий указывает на последний
			current->next = nd;
		}
	}
	//метод, выводящий связанный список на экран
	/*void printList()
	{
		Node* current = head;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}*/

	std::ostream& operator<<(std::ostream& out)
	{
		Node* current = head;
		while (current != nullptr)
		{
			out << current->data << endl;
			current = current->next;
		}
		return out;
	}
};
int main()
{
	List myList;
	myList.operator+=(5);
	myList += 11;
	myList += 27;
	myList += 35;
	myList += 50;
	std:cout << myList;
	return 0;
}