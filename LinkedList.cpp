#include <iostream>
class LinkedList {
public:
	LinkedList() {
		this-> val = 0;
		this->next = nullptr;

	}

	LinkedList(int val) {
		this->val = val;
		this->next = nullptr;
	}
	LinkedList(int val, LinkedList* next) {
		this->val = val;
		this->next = next;
	}

	~LinkedList() {
		LinkedList* current = this;
		while (current != nullptr) {
			LinkedList* next = current->next;
			delete current;
			current = next;
		}
	}

	void setVal(int val) {
		this->val = val;
	}
	int getVal() {
		return val;
	}

	LinkedList* getNext() {
		return this->next;
	}
	void setNext(LinkedList* next) {
		this->next = next;
	}
private:
	int val;
	LinkedList *next;
};
void reversingLinkedList(LinkedList** root);
void deleteNode(LinkedList** root, int val);
bool hasCycle(LinkedList* head);

int main() {
	LinkedList n1;
	n1.setVal(1);
	LinkedList n2;
	n2.setVal(2);
	LinkedList n3;
	n3.setVal(2);
	LinkedList n4;
	n4.setVal(3);

	n1.setNext(&n2);
	n2.setNext(&n3);
	n3.setNext(&n1);

	LinkedList* root = &n1;
	LinkedList* aux = &n1;
	//std::cout << hasCycle(root);
	//while (root != nullptr) {
	//	std::cout << root->getVal()<<std::endl;
	//	root = root->getNext();
	//}
	//root = aux;
	//std::cout << "\n";
	//deleteNode(&root, 1);
	//deleteNode(&root, 2);
	//while (root != nullptr) {
	//	std::cout << root->getVal()<<std::endl;
	//	root = root->getNext();
	//}
	//reversingLinkedList(&root);
	//while (root != nullptr) {
	//	std::cout << root->getVal()<<std::endl;
	//	root = root->getNext();
	//}
	//deleteNode();
	//while (root != nullptr) {
	//	std::cout << root->getVal()<<std::endl;
	//	root = root->getNext();
	//}
	return 0;
}

//A Reversing a linked list
void reversingLinkedList(LinkedList** root) {
	LinkedList* curr = *root;
	LinkedList* prev = nullptr;
	LinkedList* next = nullptr;
	while (curr != nullptr) {
		next = curr->getNext();
		curr->setNext(prev);
		prev = curr;
		curr = next;
	}
	*root = prev;
}

// D Deleting a node from a linked list
void deleteNode(LinkedList** root, int val) {
	LinkedList* curr = *root;
	LinkedList* prev = nullptr;
	while (curr != nullptr) {
		if (curr->getVal() == val) {
			if (prev != nullptr) {
				prev->setNext(curr->getNext());
				curr->setNext(nullptr);
				curr->setVal(-1);
				curr = prev->getNext();
			}
			else {
				LinkedList* aux = curr;
				curr = curr->getNext();
				aux->setNext(nullptr);
				aux->setVal(-1);
				*root = curr;
			}
		}
		else {
			prev = curr;
			curr = curr->getNext();
		}
	}
}

bool hasCycle(LinkedList* head) {
	if (head == nullptr || head->getNext() == nullptr)
		return false;

	LinkedList* slow = head;
	LinkedList* fast = head->getNext();

	while (fast != slow) {
		if (fast == nullptr || fast->getNext() == nullptr)
			return false;

		slow = slow->getNext();
		fast = fast->getNext()->getNext();
	}

	return true;
}
