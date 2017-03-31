#pragma once
#include <iostream>
namespace mtools {

#pragma region LinkedList

	/*
	* @brief basic single linked list node structure.
	*/
	template <class T>
	struct LinkedListNode_t {
		LinkedListNode_t* next;
		T data;

		LinkedListNode_t(T data_) {
			data = data_;
			next = NULL;
		}
	};

	/*
	* @brief LinkedList class to handle operations on a linkedlist.
	*/
	template <class T>
	class CLinkedList {
	public:
		CLinkedList() {
			m_head = NULL;
			m_size = 0;
		}

		CLinkedList(T data) {
			m_head = new LinkedListNode_t<T>(data);
			m_size = 1;
		}

		CLinkedList(const CLinkedList& list) {
			// To do : Implement deep copy of each node for the whole list.
		}

		~CLinkedList() {
			delete_linked_list();
		}

		void push_back(T data) {			
			if (m_head == NULL) {
				m_head = new LinkedListNode_t<T>(data);
			}
			else {
				LinkedListNode_t<T>* n = m_head;
				while (n->next != NULL) {
					n = n->next;
				}
				n->next = new LinkedListNode_t<T>(data);
			}
			++m_size;
		}

		LinkedListNode_t<T>* push_front(T data) {		
			LinkedListNode_t<T>* n = new LinkedListNode_t<T>(data);
			if (m_head != NULL) {
				n->next = m_head;
			}
			m_head = n;
			++m_size;
			return m_head;
		}

		void reverse() {
			LinkedListNode_t<T>* prev = NULL;
			LinkedListNode_t<T>* next = NULL;
			LinkedListNode_t<T>* current = m_head;
			while (current != NULL) {
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}
			m_head = prev;
		}

		void display() {
			std::cout << "Head -> ";
			LinkedListNode_t<T>* n = m_head;
			while (n != NULL) {
				std::cout << n->data << " ";
				n = n->next;
			}
			std::cout << "<- Tail\n";
		}

		void remove_node(T data) {		
			LinkedListNode_t<T>* prev = m_head;
			LinkedListNode_t<T>* n = prev;
			while (n->data != data) {
				prev = n;
				n = n->next;		
			}
			prev->next = n->next;
			delete n;
			n = NULL;
			--m_size;
		}

		void delete_linked_list() {
			LinkedListNode_t<T>* n = m_head;
			while (m_head != NULL) {
				n = m_head;
				m_head = n->next;
				delete n;
			}
			n = NULL;
			m_size = 0;
		}

		LinkedListNode_t<T>* find(T data) {

		}

		const int get_size() {
			return m_size;
		}

		// To do : Implement some operators ?

	private:
		LinkedListNode_t<T>* m_head;
		unsigned int m_size;
	};

	/*
	* @brief Given the head of a linked list, will add a new node at the head.
	*/
	template <class T>
	static LinkedListNode_t<T>* push_front_LinkedListNode_t(LinkedListNode_t<T>* head, T data) {
		LinkedListNode_t<T>* n = new LinkedListNode_t<T>(data);
		if (head != NULL) {
			n->next = head;
		}
		head = n;
		return head;
	}

	/*
	 * @brief Given the head of a linked list, will add a new node at the tail.
	 */
	template <class T>
	static void push_back_LinkedListNode_t(LinkedListNode_t<T> *head, int data)
	{
		if (head == NULL) {
			head = new LinkedListNode_t<T>(data);
		}
		else {
			LinkedListNode_t<T>* n = head;
			while (n->next != NULL) {
				n = n->next;
			}
			n->next = new LinkedListNode_t<T>(data);
		}
	}

	/*
	* @brief Display from head to tail the linked list datas.
	*/
	template <class T>
	static void display_linked_list(LinkedListNode_t<T> *head) {
		std::cout << "Head -> ";
		LinkedListNode_t<T> * n = head;
		while (n != NULL) {
			std::cout << n->data << " ";
			n = n->next;
		}
		std::cout << "<- Tail\n";
	}

	/*
	* @brief reverse a linked list using 3 pointers. O(N) we parse all the N elements of the list.
	*/
	template <class T>
	static void reverse_linked_list(LinkedListNode_t<T> *head) {
		LinkedListNode_t<T>* prev = NULL, next = NULL;
		LinkedListNode_t<T>* current = head;
		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	/*
	* @brief delete a linkedlist from head to tail.
	*/
	template <class T>
	static void delete_linked_list(LinkedListNode_t<T> *head) {
		LinkedListNode_t<T>* n = head;
		while (head != NULL) {
			n = head;
			head = n->next;
			delete n;		
		}
		n = NULL;
	}

#pragma endregion

#pragma region DoublyLinkedList
	/*
	* @brief basic doubly linked list node structure.
	*/
	template <class T>
	struct DoublyLinkedListNode_t {
		DoublyLinkedListNode_t* prev;
		DoublyLinkedListNode_t* next;
		T data;

		DoublyLinkedListNode_t(T data_) {
			data = data_;
			prev = NULL;
			next = NULL;
		}
	};

#pragma endregion
}