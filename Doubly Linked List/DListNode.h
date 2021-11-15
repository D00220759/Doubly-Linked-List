#pragma once

template <class T>
class DListNode
{
public:
	T data;
	DListNode<T> *next;
	DListNode<T> *previous;

	DListNode(T item);
	DListNode(DListNode<T> &item);
	void insertBefore(T item);
	void insertAfter(T item);

	~DListNode()
	{
		//next = nullptr;
		//previous = nullptr;
	}
};


template <class T>
DListNode<T>::DListNode(DListNode<T> &node)
{
	this->data = new DListNode(node->data);
}
template <class T>
DListNode<T>::DListNode(T item)
{
	data = item;
	next = previous = nullptr;
}

template <class T>
void DListNode<T>::insertAfter(T item)
{
	DListNode<T> *newNode = new DListNode<T>(item);
	newNode->previous = this;
	newNode->next = next;
	if (this->next != nullptr)
	{
		this->next->previous = newNode;
	}
	this->next = newNode;
}

template <class T>
void DListNode<T>::insertBefore(T item)
{
	DListNode<T> *newNode = new DListNode<T>(item);
	newNode->previous = previous;
	newNode->next = this;
	if (this->previous != nullptr)
	{
		this->previous->next = newNode;
	}
	this->previous = newNode;
}
