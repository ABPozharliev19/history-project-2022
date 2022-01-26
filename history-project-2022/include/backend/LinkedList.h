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

				delete newNode;
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

		delete m_head;
		delete temp;

		delete m_head;
	}

	T& operator[](unsigned int index)
	{
		if (index >= size())
		{
			throw new std::exception("Index out of bound");
		}

		return getElementAtIndex(index);
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

			delete newNode;
		}
	}

	void pop_back()
	{
		if (empty())
		{
			return;
		}
		else if (m_lastNode == m_head)
		{
			m_head->m_data = NULL;

			isHeadInitialised = false;
		}
		else
		{
			m_lastNode = m_lastNode->m_previousNode;
			m_lastNode->m_nextNode = NULL;
		}
	}

	unsigned int size() const 
	{
		if (isHeadInitialised)
		{
			if (m_lastNode == m_head)
			{
				return 1;
			}

			unsigned int listSize = 1;

			Node<T>* temp = m_head;

			while (temp->m_nextNode != NULL)
			{
				listSize++;
				temp = temp->m_nextNode;
			}
			
			return listSize;
		}

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
			std::cout << temp->m_data<<std::endl;
		} 
	}

private:
	T& getElementAtIndex(unsigned int index)
	{
		Node<T>* temp = m_head;

		unsigned int counter = 0;

		while (counter != index)
		{
			temp = temp->m_nextNode;
		}

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