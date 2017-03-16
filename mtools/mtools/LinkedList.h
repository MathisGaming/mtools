#pragma once

namespace mtools {

	/*
	* @brief basic single linked list node structure.
	*/
	template <class T>
	struct LinkedListNode {
		LinkedListNode* next;
		T data;

		LinkedListNode(T data_) {
			data = data_;
			next = NULL;
		}

	};

	/*
	* @brief Given the head of a linked list, will add a new node at the head.
	*/
	template <class T>
	static void insert_linkedlistnode_front(LinkedListNode<T>* head, T data) {
		LinkedListNode<T>* n = new LinkedListNode<T>(data);
		if (head != NULL) {
			n->next = head;
		}
		head = n;
	}

	/*
	 * @brief Given the head of a linked list, will add a new node at the tail.
	 */
	template <class T>
	static void insert_linkedlistnode_back(LinkedListNode<T> *head, int data)
	{
		if (head == NULL) {
			head = new LinkedListNode<T>(data);
		}
		else {
			LinkedListNode<T>* n = head;
			while (n->next != NULL) {
				n = n->next;
			}
			n->next = new LinkedListNode<T>(data);
		}
		return head;
	}

	/*
	* @brief basic doubly linked list node structure.
	*/
	template <class T>
	struct DoublyLinkedListNode {
		DoublyLinkedListNode* prev;
		DoublyLinkedListNode* next;
		T data;

		DoublyLinkedListNode(T data_) {
			data = data_;
			prev = NULL;
			next = NULL;
		}
	};
}