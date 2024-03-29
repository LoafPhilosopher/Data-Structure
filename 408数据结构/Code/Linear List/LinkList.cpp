#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode, *LinkList;
LinkList initList()
{
	LNode *p = (LNode *)malloc(sizeof(LNode));
	p->next = NULL;
	p->data = 0;
	return p;
}
LNode *GetElem(LinkList &L, int idx)
{
	if (idx < 1)
		return NULL;
	LNode *p = L->next;
	for (int i = 0; i < idx; i++)
		p = p->next;
	return p;
}
LNode *LocateElem(LinkList &L, int tmp)
{
	LNode *p = L->next;
	while (p != NULL && p->data != tmp)
		p = p->next;
	return p;
}
bool listInsert(LinkList &L, int idx, int tmp)
{
	LNode *p = L;
	for (int i = 0; i < idx; i++)
	{
		p = p->next;
		if (p == NULL)
			return false;
	}
	LNode *q = (LNode *)malloc(sizeof(LNode));
	q->data = tmp;
	q->next = p->next;
	p->next = q;
	return true;
}
void listVisit(LinkList &L)
{
	// LNode *p=L; 无头结点的情况
	LNode *p = L->next; // 有头结点的情况
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
bool listDelte(LinkList &L, int idx)
{
	LNode *p = L;
	for (int i = 0; i < idx; i++)
	{
		p = p->next;
		if (p == NULL)
			return false;
	}
	if (p->next == NULL)
		return false;
	LNode *q = p->next;
	p->next = q->next;
	free(q);
	return true;
}
int listLength(LinkList &L)
{
	// LNode *p=L; 无头结点
	LNode *p = L->next; // 有头结点的
	int count;
	for (count = 0; p != NULL; count++)
		p = p->next;
	return count;
}
void clearList(LinkList &L)
{
	// LNode *p = *L; 无头结点
	LNode *p = L->next;
	while (p != NULL)
	{
		LNode *tmp = p->next;
		free(p);
		p = tmp;
	}
	L->next = NULL; // 有头结点
					// L=NULL; 无头结点
}
bool listEmpty(LinkList L)
{
	// LNode *p = L; 无头结点
	LNode *p = L->next; // 有头结点
	if (p == NULL)
		return true;
	return false;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LinkList L = initList();
	// 测试插入函数
	listInsert(L, 0, 10);
	listInsert(L, 0, 20);
	listInsert(L, 0, 30);
	listVisit(L);
	int length = listLength(L);
	cout << "List length: " << length << endl;
	// 测试获取元素函数
	LNode *node = GetElem(L, 2);
	if (node)
		cout << "Node at index 2: " << node->data << endl;
	else
		cout << "Node not found at index 2" << endl;
	// 测试查找元素函数
	node = LocateElem(L, 20);
	if (node)
		cout << "Found node with data 20" << endl;
	else
		cout << "Node with data 20 not found" << endl;
	// 测试删除元素函数
	listDelte(L, 2);
	// 测试链表长度函数
	length = listLength(L);
	cout << "List length: " << length << endl;
	// 测试清空链表函数
	clearList(L);
	// 测试空链表函数
	if (listEmpty(L))
		cout << "List is empty" << endl;
	else
		cout << "List is not empty" << endl;
	return 0;
}