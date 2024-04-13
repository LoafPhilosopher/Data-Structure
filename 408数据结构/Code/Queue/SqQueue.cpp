#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
#define MaxSize 100 // 定义队列中元素的最大个数
typedef struct
{
    int data[MaxSize]; // 存放队列元素
    int front, rear;   // 队头指针和队尾指针
} SqQueue;
void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0; // 初始化队首,队尾指针
}
bool IsEmpty(SqQueue &Q)
{
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}
bool EnQueue(SqQueue &Q, int x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false; // 队满则报错
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize; // 队尾指针加1取模
    return true;
}
bool DeQueue(SqQueue &Q)
{
    if (Q.rear == Q.front)
        return false;                  // 队空则报错
    Q.front = (Q.front + 1) % MaxSize; // 队头指针加1取模
    return true;
}
int CountQueue(SqQueue &Q)
{
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    SqQueue q;
    InitQueue(q);
    cout << IsEmpty(q) << endl;
    for (int i = 0; i < 10; i++)
    {
        EnQueue(q, i);
        cout << q.data[q.rear - 1] << endl; // 依次输出队列中所有元素
    }
    cout << CountQueue(q) << endl;
    DeQueue(q);
    cout << CountQueue(q) << endl;
    for (int i = 0; i < 10; i++)
        cout << q.data[q.rear - 1] << endl; // 依次输出队列中所有元素
    cout << CountQueue(q) << endl;
    return 0;
}