#include <iostream>

using namespace std;

class Node {
public:
	string data;
	Node* next;
	Node(const string& data) : data(data), next(nullptr) {}
};

class SinglyList {
	Node* head = nullptr;
public:



	void AddFront(const string& value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}

	void AddEnd(const string& value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* temp = head;

		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = newNode;
		temp = nullptr;
	}

	void insertAfterNode(Node* givenNode, const string& value)
	{
		Node* newNode = new Node(value);

		newNode->next = givenNode->next;
		givenNode->next = newNode;
	}


	void insertNth(const string& value, int position) {
		Node* node = new Node(value);
		node->data = value;
		if (this->head == NULL) {
			if (position != 0) {
				return;
			}
			else { 
				this->head = node;
			}
		}

		if (head != NULL && position == 0) {
			node->next = this->head;
			this->head = node;
			return;
		}
		Node* current = this->head;
		Node *previous = NULL;

		int i = 0;

		while (i < position) {
			previous = current;
			current = current->next;

			if (current == NULL) {
				break;
			}

			i++;
		}

		node->next = current;
		previous->next = node;
	}


	void search(const string & value)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == value)
			{
				cout << value << " was founded"<<endl;
				temp = temp->next;
				break;
			}

			else
			{
				cout << value << " was not founded" << endl;;
				break;
			}

		}

	}
	
	

	void DeleteFront() {
		if (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void DeleteEnd() {
		if (head != nullptr) {
			Node* temp = head;
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}
	}

	void Print() {

		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	

};

void main() {
	string value;
	string data;
	SinglyList sl;
	cout << "Add front method : " ;
	sl.AddFront("Islam");
	sl.AddFront("Ayshan");
	sl.Print();
	cout << endl;
	cout << "Add end method :" ;
	sl.AddEnd("Nigar");
	sl.AddEnd("Bahruz");
	sl.Print();
	cout << endl;
	cout << "Insert new string to anywhere you want : ";
	sl.insertNth("New string", 2);
	sl.Print();
	cout << endl;

	cout << "After delete  front and end  method : ";
	sl.DeleteFront();
	sl.DeleteEnd();
	sl.Print();
	cout << endl;
	cout << "Search method : " ;
	sl.search("Islam");
	cout << "Search method : ";
	sl.search("Aygun");
	

	
	

}