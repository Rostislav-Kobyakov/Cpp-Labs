#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
	double data;
	Node* next;
	Node* prev;
};
struct List
{
	Node* head;
	Node* tail;
	List()
	{
		head = NULL;
		tail = NULL;
	}
	void addNode(double value)
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = NULL;
		newNode->prev = tail;
		if (tail != NULL)
		{
			tail->next = newNode;
		}
		tail = newNode;
		if (head == NULL)
		{
			head = newNode;
		}
	}
	void deleteNode()
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
	void ListFilling(int& size) // заполнение списка
	{
		double k;
		for (int i = 0; i < size; i++)
		{
			cout << "Enter a" << i + 1 << " node: " << endl;
			cin >> k;
			addNode(k);
		}
	}
	void printList() {
		Node* current = head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	void Solution(double &sum)
	{
		Node* current = head;
		Node* last = tail;
		sum = current->data * last->data;
		current = current->next;
		for(;current != last;)
		{
			last = last->prev;
			sum += current->data * last->data;
			current = current->next;
		}
	}
};
int main()
{
	List L;
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	n *= 2;
	L.ListFilling(n);
	cout << "All a: ";
	L.printList();
	double sum = 0;
	L.Solution(sum);
	cout << "Sum: " << sum << endl;
	for (int i = 0; i < n; i++)
	{
		L.deleteNode();
	}
}
