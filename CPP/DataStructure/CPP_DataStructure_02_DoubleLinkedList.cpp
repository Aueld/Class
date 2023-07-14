#include "stdafx.h"
#include "CPP_DataStructure_02_DoubleLinkedList.h"

int DoubleLinkedList::Length = 0;
DoubleLinkedList* DoubleLinkedList::Head = nullptr;
DoubleLinkedList* DoubleLinkedList::Tail = nullptr;

void Print()
{
    if (DoubleLinkedList::GetLength() <= 0)
    {
        cout << "List is NULL" << endl;
        return;
    }

    for (int i = 0; i < DoubleLinkedList::GetLength(); i++)
    {
        cout << "index [ " << i << " ] " << DoubleLinkedList::GetNode(i)->GetData() << endl;
    }
}


DoubleLinkedList* DoubleLinkedList::DoubleLinkedListCreate(DataType data)
{
    DoubleLinkedList* node = new DoubleLinkedList;

    node->SetData(data);
    node->SetNext(nullptr);
    node->SetPrev(nullptr);

    return node;
}

void DoubleLinkedList::Insert(DoubleLinkedList* cur, DoubleLinkedList* newNode)
{
    newNode->Next = cur->Next;  // newNode의 다음은 cur의 다음을
    newNode->Prev = cur;        // newNode의 이전은 cur을
    cur->Next->Prev = newNode;  // cur의 다음 노드의 이전 노드에 newNode의 주소를 대입
    cur->Next = newNode;        // cur의 다음 노드에 newNode을 대입

    ++Length;                   // 리스트 길이 증가
}

void DoubleLinkedList::InsertHead(DoubleLinkedList* newNode)
{
    newNode->Next = Head;   // 삽입된 newNode의 다음은 Head
    newNode->Prev = nullptr;// newNode의 이전은 NULL
    Head->Prev = newNode;   // Head의 이전은 newNode
    Head = newNode;         // Head는 newNode로 변경

    ++Length;
}

void DoubleLinkedList::Push(DoubleLinkedList* newNode)
{
    if (Head == nullptr)        // 리스트 헤드가 없다면
    {
        Head = newNode;         // 생성
        Tail = newNode;         // 
    }
    else
    {
        Tail->Next = newNode;   // Tail의 다음은 newNode
        newNode->Prev = Tail;   // newNode의 이전은 Tail
        Tail = newNode;         // Tail은 newNode
    }

    ++Length;
}

void DoubleLinkedList::Remove()
{
    if (this == Head)               // 헤드 라면
    {
        if (this->Next)             // 헤드의 다음이 있을때
        {
            Head = this->Next;      // 헤드를 다음 노드로 변경
            Head->Prev = nullptr;   // 헤드의 이전을 NULL로
        }

        delete this;                // 노드 delete

        return;
    }
    else if (this == Tail)
    {
        Tail->Prev->Next = nullptr;
        Tail = Tail->Prev;
    }
    else
    {
        this->Prev->Next = this->Next;  // 현재 노드의 이전노드의 앞을 가르키는 Next에 현재 노드의 Next 대입
        this->Next->Prev = this->Prev;  // 현재 노드의 앞노드의 이전을 가르키는 Prev에 현재 노드의 Prev 대입
    }

    delete this;                    // 노드 delete

    --Length;                       // -- 리스트 길이
}

void DoubleLinkedList::RemoveAll()
{
    Length = 0;

    if (Head == nullptr)
    {
        cout << "List is NULL" << endl;
        return;
    }

    if (Head->Next != nullptr)      // 헤드 다음을 가르키는 Next가 있을때 
        RemoveAll(Head->Next);      // RemoveAll(DobleLinkedList*) 실행

    delete Head;                    // Head delete

    Head = nullptr;
    Tail = nullptr;
}

void DoubleLinkedList::RemoveAll(const DoubleLinkedList* head)
{
    if (head == nullptr)
    {
        cout << "Empty" << endl;
        return;
    }

    if (head->Next != nullptr)
        RemoveAll(head->Next);

    delete Head;                    // Head delete

    Length = 0;

    return;
}

void DoubleLinkedList::SetHead(DoubleLinkedList* node)
{
    if (Head == nullptr)    // Head가 NULL일때
    {
        Head = node;
    }
    else if (node != Tail)   // node가 Tail이 아닐때
    {
        node->Next->Prev = node->Prev;  // node의 다음노드의 이전에 node의 이전 대입
        node->Prev->Next = node->Next;  // node의 이전노드의 다음에 node의 다음 대입
    }

    node->Prev = nullptr;               // node의 이전 NULL
    node->Next = Head;                  // node의 다음은 Head
    Head->Prev = node;                  // Head의 이전은 node

    Head = node;                        // Head는 node
}

void DoubleLinkedList::SetTail(DoubleLinkedList* node)
{
    if (node == Head)
    {
        Head = Head->Next;              // Head는 Head의 다음 노드
        Head->Prev = nullptr;           // Head의 Prev는 NULL
    }
    else if (node != Head)
    {
        node->Next->Prev = node->Prev;  // node의 다음 노드의 이전에 노드의 이전 대입
        node->Prev->Next = node->Next;  // node의 이전 노드의 다음에 노드의 다음 대입
    }

    node->Prev = Tail;                  // node의 이전은 Tail
    node->Next = nullptr;               // node의 다음은 Next
    Tail->Next = node;                  // Tail의 다음은 node

    Tail = node;                        // Tail은 node
}

DoubleLinkedList* DoubleLinkedList::GetNode(int index)
{
    if (Head == nullptr)                // 헤드가 없다면
        return nullptr;                 // 반환

    DoubleLinkedList* find = Head;

    while (find != nullptr && --index >= 0) // Head부터 index의 값이 0이 될때까지 다음 노드로 이동 후
    {
        find = find->Next;
    }

    return find;            // 반환
}

int DoubleLinkedList::GetNodeCount(int index)
{
    DoubleLinkedList* cur = GetNode(index);

    if (cur == nullptr)
        return -1;

    int count = 1;

    while (cur->Next != nullptr)
    {
        cur = cur->Next;
        ++count;
    }

    return count;   // 해당 인덱스의 노드부터 뒤로 몇개가 있는지 반환
}

int DoubleLinkedList::GetNodeReverseCount(int index)
{
    DoubleLinkedList* cur = GetNode(index);

    if (cur == nullptr)
        return -1;

    int count = 1;

    while (cur->Prev != nullptr)
    {
        cur = cur->Prev;
        ++count;
    }

    return count;   // 해당 인덱스의 노드부터 앞으로 몇개가 있는지 반환
}

