//#include <iostream>
//using namespace std;
//class Node        //один узел, представленный в виде структуры
//{
//	friend class List;//объявляем класс Список дружественным, чтобы он имел доступ к закрытым полям
//private:
//	int key;       //номер узла в списке
//	int data;      //данные, содержащиеся в узле
//	Node* next;    //указатель на следующую структуру
//	Node* last;    //указатель на предыдущую структуру
//public:
//	Node(int data, Node* next, Node* last)
//	{
//		this->data = data;
//		this->next = next;
//		this->last = last;
//	}
//	Node(int data)
//	{
//		this->data = data;
//	}
//};
//class List        //класс, описывающий объект "список"
//{
//private:
//	Node* head;   //голова списка (указатель на первый узел в списке)
//	Node* temp;   //указатель на последний узел в списке
//public:
//	List() : head(NULL), temp(NULL) //в первом созданном объекта указатель равен нулю, т.к. следующего объекта еще нет и указывать не на что
//	{
//	}
//	void addNodeEnd(int data)     //метод, добавляющий узел в конец списка
//	{
//		Node* nd = new Node(data, NULL, temp); //создаем новый узел, добавляем в него данные и делаем его последним, присваивая NULL
//		temp = nd;
//		if (head)
//		{
//			Node* current = head;  //указывает на начало списка, на первый узел; и используется в цикле для нахождения предыдущего узла
//			while (current->next)   //прокручиваем в цикле наш список, пока не дойдем до последнего узла, остановившись на предыдущем
//				current = current->next; //переходим на следующий узел
//			current->next = nd;    //предыдущий указывает на следующий узел
//		}
//		else                       //если список был пуст и создается первый узел, то голова указывает на него
//			head = nd;             //у головы бывает два состояния: она либо NULL, либо указывает на первый узел в списке
//		numNode(); //нумеруем узлы списка
//	}
//	void addNodeBeginning(int data)   //метод, добавляющий узел в начало списка
//	{
//		Node* nd = new Node(data);
//		if (head) //если уже есть узлы в списке
//		{
//			Node* tmp = head;
//			head = nd;
//			nd->next = tmp;
//		}
//		else    //если список пуст
//		{
//			head = nd;
//			nd->next = NULL;
//		}
//		numNode();
//	}
//	void deleteNodeEnd() //удаление узла в конце списка
//	{
//		if (temp)
//		{
//			Node* current = temp;
//			current = current->last;
//			delete current->next;
//			current->next = NULL;
//		}
//		else
//			cout << "The list is empty!" << endl;
//	}
//	void deleteNodeBeginning() //удаление узла в начале списка
//	{
//		if (head)
//		{
//			Node* tmp = head;
//			tmp = tmp->next;
//			delete head;     //освобождаем память по этому адресу
//			head = tmp;      //и задаем новое значение
//		}
//		else
//			cout << "The list is empty!" << endl;
//		numNode();
//	}
//	int find(int k) //поиск по ключу в списке
//	{
//		Node* counter = head;
//		while (counter)
//		{
//			if (counter->key == k)
//				return counter->data;
//			counter = counter->next;
//		}
//	}
//	void printListForward() const //выводим на печать наш список в прямом порядке
//	{
//		Node* current = head;
//		while (current)             //пока не дойдем до последнего узла
//		{
//			cout << current->key << " - " << current->data << endl;   //выводим данные на экран
//			current = current->next;         //переходим к следующему узлу
//		}
//	}
//	void printListBack() const     //выводим на печать наш список в обратном порядке
//	{
//		Node* current = temp;
//		while (current)
//		{
//			cout << current->key << " - " << current->data << endl;
//			current = current->last;
//		}
//	}
//	void numNode() //внутренняя функция-утилита, нумерует узлы списка
//	{
//		Node* counter = head;
//		int i = 0;
//		while (counter)
//		{
//			counter->key = ++i;
//			counter = counter->next;
//		}
//	}
//};
//int main()
//{
//	List n; //создаем экземпляр класса List
//	int key;
//	n.addNodeEnd(21);  //вызываем метод addNode класса List (добавление узла)
//	n.addNodeEnd(32);
//	n.addNodeEnd(47);
//	n.addNodeEnd(63);
//	n.addNodeEnd(78);
//	n.addNodeEnd(83);
//	n.addNodeEnd(97);
//	n.addNodeEnd(98);
//	n.printListForward();
//	cout << endl;
//	n.printListBack();
//	n.addNodeBeginning(17);
//	n.addNodeBeginning(15);
//	n.addNodeBeginning(10);
//	n.addNodeBeginning(3);
//	cout << endl;
//	n.printListForward();
//	n.deleteNodeEnd();
//	cout << endl;
//	n.printListForward();
//	n.deleteNodeBeginning();
//	cout << endl;
//	n.printListForward();
//	cout << "Enter a number of node: ";
//	cin >> key;
//	cout << "Data node " << key << " = " << n.find(key) << endl;
//}