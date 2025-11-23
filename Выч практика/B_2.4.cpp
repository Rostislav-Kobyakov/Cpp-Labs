#include <iostream>
using namespace std; // не хочу думать и придумывать свой кривой код(для создания списка), когда в туторе нормально расписано и понятно(вообще можно было бы с кайфом сделать..... для всех типов переменных при помощи typename но камон, это слишком далеко и не хочу и не буду ;)))) привет если читаешь это

class Node // я использую классы потому что я классный :)
{
public: // вижла это делает по умолчанию, но в туторе пишут, поэтому че бы не написать ;)
	char data;
	Node* next{};
public:
	Node(char data) // это конструктор ребята
	{
		this->data = data;
		this->next = NULL;
	}
};
class List // запрети мне писать на классах (можно описать все методы в классе, вместо того, чтобы выписывать как отдельные функции, зачем париться¿)
{
public: 
	Node* head, *tail;
public:
	List()
	{
		this->head = this->tail = NULL;
	}
	~List()
	{
		while (head != NULL) pop_front();
	}
	void pop_front() //удаление ноды с начала
	{
		if (head == NULL) return;
		if (head == tail) 
		{
			delete tail;
			head = tail = NULL;
			return;
		}
		Node* node = head;
		head = node->next;
		delete node;
	}
	void push_back(char data) //создание ноды в конец(tail)
	{
		Node* node = new Node(data);
		if (head == NULL) head = node;
		if (tail != NULL) tail->next = node;
		tail = node;
	}
	void push_front(char data) //создание ноды в начало(head)
	{
		Node* node = new Node(data);
		node->next = head;
		head = node;
		if (tail == NULL) tail = node;
	}
	void pop_back() //удаление ноды с конца
	{
		if (tail == NULL) return;
		if (head == tail)
		{
			delete tail;
			head = tail = NULL;
			return;
		}

		Node* node = head;
		for (; node->next != tail; node->next);
		node->next = NULL;
		delete tail;
		tail = node;
	}
	Node* getAt(int k) //адрес нужного элемента
	{
		if (k < 0) return NULL;
		Node* node = head;
		int n = 0;
		while (node && n != k && node->next)
		{
			node = node->next;
			n++;
		}
		return (n == k) ? node : NULL;
	}
	void insert(int k, char data) //вставка между нодами
	{
		Node* left = getAt(k);
		if (left == NULL) return;
		Node* right = left->next;
		Node* node = new Node(data);

		left->next = node;
		node->next = right;
		if (right == NULL) tail = node;	
	}
	void erase(int k) //вырезаю семью ноды
	{
		if (k < 0) return;
		if (k == 0)
		{
			pop_front();
			return;
		}

		Node* left = getAt(k - 1);
		Node* node = left->next;
		if (node == NULL) return;
		Node* right = node->next;
		left->next = right;
		if (node == tail) tail = left;
		delete node;
	}
};
void ListFilling(List L, int &size) // заполнение списка
{
	for (int i = 0, char k; i < size; i++)
	{
		cout << "Enter " << i + 1 << "node: " << endl;
		cin >> k;
		L.push_back(k);
	}
}
void Sortir(Node* head) // сортировка вставкой O(n^2)
	{
	if (head == NULL || head->next == NULL) 
	{
		return;
	}
	Node* sorted = NULL, * current = head;
	while (current != NULL) 
		{
		Node* nextNode = current->next;
		if (sorted == NULL || sorted->data > current->data) 
		{
			current->next = sorted;
			sorted = current;
		}
		else 
			{
			Node* temp = sorted;
			while (temp->next != NULL && temp->next->data < current->data) 
			{
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}
		current = nextNode;
	}
	head = sorted;
}

void list_print(const Node* head) {
	while (head) {
		cout << dec << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

//void Solution(List L, List L1, int size1, List L2, int size2) // XOR
//{
//	for (int i = 0, k = 0; i < size1 && k < size2; i++, k++)
//	{
//		Node* current = 
//	}
//}
int main()
{
	List L, L1, L2;
	int size1, size2;
	cout << "Enter number of nodes for L1" << endl;
	cin >> size1;
	ListFilling(L1, size1);
	list_print(L1.getAt(0));
	Sortir(L1.getAt(0));
	cout << "Enter number of nodes for L2" << endl;
	cin >> size2;
	ListFilling(L2, size2);
	Sortir(L2.getAt(0));

}