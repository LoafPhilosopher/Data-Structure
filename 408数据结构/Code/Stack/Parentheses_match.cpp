#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 10;
char s[N];
int top = 0;
void Push(char x)
{
    s[++top] = x;
}
void Pop()
{
    if (top == 0)
        return;
    --top;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str = "))))))))()()()()()";
    Push(str[0]);
    for (int i = 1; i < str.size(); i++)
        if (str[i] == ')' && s[top] == '(')
            Pop();
        else
            Push(str[i]);
    cout<<"栈的逆序输出为:";
    for (int i = top; i >= 1; i--)
        cout << s[i] << ' ';
    cout << endl;
    return 0;
}