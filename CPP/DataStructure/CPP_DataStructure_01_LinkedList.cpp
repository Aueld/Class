#include "stdafx.h" // ../ 로 상대 경로
#include "CPP_DataStructure_01_LinkedList.h"

int LinkedListNode::Length = 0;
LinkedListNode* LinkedListNode::Head = nullptr;
LinkedListNode* LinkedListNode::Tail = nullptr;

void DoLinkedList()
{
	LinkedListNode::Create(16)->Push();

	for (int i = 0; i < 5; i++)
	{
		LinkedListNode::Create(i)->Push();
	}

	Print();
}

void Print()
{
	if (LinkedListNode::GetLength() <= 0)
	{
		cout << "List is NULL" << endl;
	}
	else
	{
		for (int i = 0; i < LinkedListNode::GetLength(); i++)
			cout << "index [ " << i << " ] " <<
			LinkedListNode::GetNode(i)->GetData() << endl;
	}
}

LinkedListNode* LinkedListNode::Create(DataType data)
{
	LinkedListNode* node = new LinkedListNode;

	node->Data = data;
	node->Next = nullptr;

	return node;
}

void LinkedListNode::Insert(LinkedListNode* cur, LinkedListNode* newNode)
{
	newNode->Next = cur->Next;
	cur->Next = newNode;
	
	++Length;
}

void LinkedListNode::InsertHead()
{
	this->Next = Head;
	Head = this;

	++Length;
}

void LinkedListNode::Push()
{
	if (Head == nullptr)
	{
		Head = this;
		Tail = this;
	}
	else
	{
		Tail->Next = this;
		Tail = this;
	}
	
	++Length;
}

void LinkedListNode::Remove()
{
	if (this == Head)
	{
		if (this->Next)
			Head = this->Next;

		delete this;
		return;
	}

	LinkedListNode* checker = Head;

	while (true)
	{
		if (checker->Next == this)
		{
			checker->Next = this->Next;

			delete this;
			break;
		}
		else
			checker = checker->Next;
	}

	--Length;
}

void LinkedListNode::RemoveAll()
{
	Length = 0;

	if (Head == nullptr)
	{
		cout << "List is already NULL" << endl;
		return;
	}
	if (Head->Next != nullptr)
		RemoveAll(Head->Next);

	cout << Head->Data << "\tData Remove Completed" << endl;

	delete Head;

	Head = nullptr;
	Tail = nullptr;
}

void LinkedListNode::RemoveAll(const LinkedListNode* head)
{
	if (head->Next != nullptr)
		RemoveAll(head->Next);

	cout << head->Data << "\tData Remove Completed" << endl;

	delete head;
}

LinkedListNode* LinkedListNode::GetNode(int index)
{
	if (Head == nullptr)
		return nullptr;

	LinkedListNode* find = Head;

	while (find != nullptr && --index >= 0)
	{
		find = find->Next;
	}

	return find;
}

int LinkedListNode::GetNodeCount(int index)
{
	LinkedListNode* cur = GetNode(index);
	
	if (cur == nullptr)
		return -1;

	int count = 1;
	while (cur->Next != nullptr)
	{
		cur = cur->Next;
		++count;
	}

	return count;
}
