#pragma once

void DoLinkedList();
void Print();

class LinkedListNode
{
public:
	static LinkedListNode* Create(DataType data);

	static void Insert(LinkedListNode* cur, LinkedListNode* newNode);

	void InsertHead();
	void Push();

	void Remove();
	static void RemoveAll();

	static LinkedListNode* GetNode(int index);
	const DataType GetData() { return Data; }

	static const int GetLength() { return Length; }

	static int GetNodeCount(int index);

	static const LinkedListNode* GetHead() { return Head; }
	static const LinkedListNode* GetTail() { return Tail; }

private:
	static void RemoveAll(const LinkedListNode* head);

private:
	DataType Data;
	LinkedListNode* Next;

	static int Length;
	static LinkedListNode* Head;
	static LinkedListNode* Tail;

};
