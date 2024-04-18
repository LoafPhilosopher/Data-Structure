#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef struct ThreadNode
{
    int data;                           // 数据元素
    struct ThreadNode *lchild, *rchild; // 左,右孩子指针
    int lTag, rTag;                     // 左右线索标记
} ThreadNode, *ThreadTree;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}