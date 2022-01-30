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
		// Make a new node for the head
		m_head = new Node<T>;

		// The last node becomes the head
		m_lastNode = m_head;

		// We don't have data for the head
		// So it hasn't been initialised yet
		isHeadInitialised = false;
	}

	LinkedList(unsigned int size)
	{
		// Make a new node for the head
		m_head = new Node<T>;
			
		// The last node becomes the head
		m_lastNode = m_head;

		// If the size of the list is 1 or more
		// Then we have a head
		if (size > 0)
		{
			isHeadInitialised = true;
		}

		// The list will be empty
		else
		{
			isHeadInitialised = false;
		}

		if (size >= 2)
		{
			for (unsigned int i = 1; i < size; i++)
			{
				Node<T>* newNode = new Node<T>(NULL, m_lastNode, NULL);

				m_lastNode->m_nextNode = newNode;

				m_lastNode = newNode;
			}
		}
	}

	LinkedList(const std::vector<T>& values)
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

	~LinkedList()
	{
		Node<T>* temp = m_lastNode;

		while (temp->m_previousNode != NULL)
		{
			temp = temp->m_previousNode;

			delete temp->m_nextNode;
		}
		delete temp;
	}

	T& operator[](unsigned int index)
	{
		// If the index is out of range
		if (index >= size())
		{
			throw new std::exception("Index out of bound");
		}

		return getElementAtIndex(index);
	}

	void push_back(const std::vector<T>& values)
	{
		for (unsigned int i = 0; i < values.size(); i++)
		{
			push_back(values[i]);
		}
	}

	void push_back(const T& data)
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

	void pop_back()
	{	
		// If the list is empty
		if (empty())
		{
			// Don't do anything
			return;
		}
		// If the only initialised node is the head
		else if (m_lastNode == m_head)
		{
			// Just remove the data from the head
			m_head->m_data = NULL;

			isHeadInitialised = false;
		}
		// There are more than one initialised nodes
		else
		{
			// The last initialised node becomes the one thats previous to it
			m_lastNode = m_lastNode->m_previousNode;

			m_lastNode->m_nextNode = NULL;
		}
	}

	unsigned int size() const 
	{
		// If the list has a head, then size >= 1
		if (isHeadInitialised)
		{
			// If the last node is the head, then the head is the only element in the list
			if (m_lastNode == m_head)
			{
				return 1;
			}

			unsigned int listSize = 1;

			Node<T>* temp = m_head;
			
			// Traverse the list until we find the end of the list
			while (temp->m_nextNode != NULL)
			{
				listSize++;
				temp = temp->m_nextNode;
			}
			
			return listSize;
		}
		// If the list doesn't have a head, then it's empty
		return 0;
	}

	bool empty() const
	{
		return size() == 0;
	}

	void printList() const
	{
		Node<T>* temp = m_head;

		std::cout << temp->m_data<<std::endl;

		while (temp->m_nextNode != NULL)
		{
			temp = temp->m_nextNode;
			std::cout << temp->m_data << std::endl;
			
		}
	}

private:
	T& getElementAtIndex(unsigned int index)
	{
		Node<T>* temp = m_head;

		unsigned int counter = 0;

		// Traverse the list until the index is reached
		while (counter != index)
		{
			temp = temp->m_nextNode;
			counter++;
		}
		// Return the item at the reached index
		return temp->m_data;
	}

private:
	Node<T>* m_head = NULL;
	Node<T>* m_lastNode = NULL;

	bool isHeadInitialised;
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
		m_data = NULL;
		m_previousNode = NULL;
		m_nextNode = NULL;
	}

private:
	T m_data;
	Node<T>* m_previousNode = NULL;
	Node<T>* m_nextNode = NULL;

	friend class LinkedList<T>;
};