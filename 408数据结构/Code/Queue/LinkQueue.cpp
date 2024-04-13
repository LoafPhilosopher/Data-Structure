#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef struct LinkNode // 链队列的结点
{
	int data;
	struct LinkNode *next;
} LinkNode;
typedef struct // 链式队列
{
	LinkNode *front, *rear; // 头尾指针
} LinkQueue;
void InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode)); // 建立头结点
	Q.front->next = NULL;									 // 初始为空
}
bool IsEmpty(LinkQueue &Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
void EnQueue(LinkQueue &Q, int x)
{
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = x, s->next = NULL; // 创建新结点,插入到链尾
	Q.rear->next = s;
	Q.rear = s;
}
bool DeQueue(LinkQueue &Q)
{
	if (Q.front == Q.rear)
		return false; // 空队
	LinkNode *p = Q.front->next;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front; // 若原队列中只有以歌结点，删除后变空
	free(p);
	return true;
}
void VisitQueue(LinkQueue &Q)
{
	LinkNode *p = Q.front;
	while (p != Q.rear)
	{
		p = p->next;
		cout << p->data << ' ';
	}
	cout << endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LinkQueue q;
	InitQueue(q);
	cout << IsEmpty(q) << endl;
	for (int i = 0; i <= 10; i++)
		EnQueue(q, i);
	VisitQueue(q);
	cout << IsEmpty(q) << endl;
	DeQueue(q), VisitQueue(q);
	DeQueue(q), VisitQueue(q);
	DeQueue(q), VisitQueue(q);
	DeQueue(q), VisitQueue(q);
	return 0;
}