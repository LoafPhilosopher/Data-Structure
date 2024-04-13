#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
#define MaxSize 100 // 定义栈中元素的最大个数
typedef struct
{
    int data[MaxSize]; // 存放栈中元素
    int top;           // 栈顶指针
} SqStack;
void InitStack(SqStack &S)
{
    S.top = -1; // 初始化栈顶指针
}
bool StackEmpty(SqStack &S)
{
    if (S.top == -1) // 栈空
        return true;
    else // 不空
        return false;
}
bool Push(SqStack &S, int x)
{
    if (S.top == MaxSize - 1) // 栈满
        return false;
    S.data[++S.top] = x; // 指针加一后入栈
    return true;
}
int Pop(SqStack &S, int x)
{
    if (S.top == -1)
        return false;    // 栈空
    x = S.data[S.top--]; // 先出栈,指针再减1
    return x;
}
int GetTop(SqStack &S, int x)
{
    if (S.top == -1) // 栈空,报错
        return false;
    x = S.data[S.top]; // x 记录栈顶元素
    return x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    SqStack S;
    InitStack(S);

    // 测试 Push()
    cout << "测试 Push():" << endl;
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    if (StackEmpty(S) == false)
        cout << "Push() 测试成功" << endl;
    else
        cout << "Push() 测试失败" << endl;
    cout << "栈顶元素为：" << S.data[S.top] << endl;

    // 测试 Pop()
    cout << "测试 Pop():" << endl;
    int x;
    cout << "出栈元素为：" << Pop(S, x) << endl;
    cout << "出栈元素为：" << Pop(S, x) << endl;

    // 测试 GetTop()
    cout << "测试 GetTop():" << endl;
    cout << "栈顶元素为：" << GetTop(S, x) << endl;
    return 0;
}