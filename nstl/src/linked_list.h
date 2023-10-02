#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
class LinkedList
{
private:
	Node<T>* m_HeadNode;
	int m_Size;
            
public:
	LinkedList(): m_HeadNode(NULL), m_Size(0) {
		
	}
	~LinkedList() {
		Node<T>* another = NULL;
		Node<T>* temp = m_HeadNode;
		while (temp != NULL) {
			another = temp;
			temp = temp->next;

			std::cout << "Deleted: " << another->data << std::endl;
			delete another;
		}
	}

	void PushBack(T data) {
		m_Size++;
		if (m_HeadNode == NULL) {
			Node<T>* newNode = new Node<T>;
			newNode->data = data;
			newNode->next = NULL;
			
			m_HeadNode = newNode;
		}
		else {
			Node<T>* temp = m_HeadNode;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			Node<T>* newNode = new Node<T>;
			newNode->data = data;
			newNode->next = NULL;
			
			temp->next = newNode;
		}
	}
	void PushFront(T data) {
		m_Size++;
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->next = m_HeadNode;

		m_HeadNode = newNode;
		
	}
	void Insert(int index, T data) {
		// TODO: OPTIMIZATION
		m_Size++;
		if (index > m_Size)
			PushBack(data);
		else if (index == 0)
			PushFront(data);
		else {
			Node<T>* temp = m_HeadNode;

			while (temp != NULL) {
				index--;
				if (index == 0) {
					Node<T>* newNode = new Node<T>;
					newNode->data = data;
					newNode->next = temp->next;

					temp->next = newNode;
				}
				else {
					temp = temp->next;
				}
			}
		}
	}
	void Delete(int index) {
		// TODO: OPTIMIZATION
		// This is probably not the best way to delete elements/nodes from a linked list. Not bad for my first ever implementation after just learning the theory
		// of linked lists but definitely needs some work if I want to make it "production" ready.
		m_Size--;
		if (index == 0) {
			Node<T>* temp = m_HeadNode;
			m_HeadNode = m_HeadNode->next;

			delete temp;
		}
		else if(index == m_Size-1) {
			int counter = 0;
			Node<T>* temp = m_HeadNode;

			while (temp != NULL) {
				if (counter == m_Size - 2) {
					delete temp->next;
					temp->next = nullptr;
				}
				temp = temp->next;
				counter++;
			}
		}
		else if (index > m_Size - 1) {
			return;
		}
		else {
			Node<T>* temp = m_HeadNode;

			Node<T>* before = nullptr, *data = nullptr, * after = nullptr;
			int counter = 0;
			while (temp != NULL) {
				if (counter == index - 1) 
					before = temp;
				else if (counter == index)
					data = temp;
				else if (counter == index + 1)
					after = temp;

				temp = temp->next;
				counter++;
			}

			before->next = after;
			delete data;
		}
	}

	void PrintData() {
		Node<T>* temp = m_HeadNode;
		while (temp != NULL) {
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
};
