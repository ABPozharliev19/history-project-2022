#pragma once

#include <vector>

template <typename T>
class Node;

template <typename T>
class LinkedList
{
public:
	LinkedList()
	{
		m_head = new Node<T>;

		m_lastNode = m_head;

		isHeadInitialised = false;
	}

	LinkedList(std::vector<T> values)
	{
		m_head = new Node<T>(values[0], NULL, NULL);

		m_lastNode = m_head;

		isHeadInitialised = true;

		if(values.size() >= 2)
		{
			for (unsigned int i = 1; i < values.size(); i++)
			{
				Node<T>* newNode = new Node<T>(values[i], m_lastNode, NULL);

				// Make the connection between the previous and next nodes
				m_lastNode->m_nextNode = newNode;

				m_lastNode = newNode;
			}
		}
	}

	void push_back(T data)
	{
		// If the head hasn't been initialized
		if (!isHeadInitialised)
		{
			m_head->m_data = data;

			isHeadInitialised = true;
		}

		else
		{
			Node<T>* newNode = new Node<T>(data, m_lastNode, NULL);
			m_lastNode->m_nextNode = newNode;
			m_lastNode = newNode;
		}
	}

	void printList()
	{
		Node<T>* temp = m_head;

		std::cout << temp->m_data;

		while (temp->m_nextNode != NULL)
		{
			temp = temp->m_nextNode;
			std::cout << temp->m_data;
		} 
	}

private:
	Node<T>* m_head = NULL;
	Node<T>* m_lastNode = NULL;

	bool isHeadInitialised;

private:

};

template <typename T>
class Node
{
public:
	Node(T data, Node* prevNode, Node* nextNode)
	{
		m_data = data;
		m_previousNode = prevNode;
		m_nextNode = nextNode;
	}

	Node()
	{
		m_data = 0;
		m_previousNode = 0;
		m_nextNode = 0;
	}

private:
	T m_data;
	Node<T>* m_previousNode = NULL;
	Node<T>* m_nextNode = NULL;

	friend class LinkedList<T>;
};