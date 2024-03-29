#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define MAX_SIZE 100
using namespace std;
typedef struct
{
    int data[MAX_SIZE];
    int length;
    int size;
} SqList;
SqList *initList()
{
    SqList *L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
    L->size = MAX_SIZE;
    return L;
}
int listLength(SqList &L)
{
    return L.length;
}
void listVisit(SqList &L)
{
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << endl;
}
bool listInsert(SqList &L, int tmp, int idx)
{
    if (idx < 1 || idx > L.length + 1 || L.length >= MAX_SIZE)
        return false;
    for (int i = idx - 1; i > L.length; i--)
        L.data[i] = L.data[i - 1];
    L.data[idx - 1] = tmp;
    L.length++;
    return true;
}
bool ListDelete(SqList &L, int idx, int &tmp)
{
    if (idx < 1 || idx > L.length)
        return false;
    tmp = L.data[idx - 1];
    for (int i = idx; i < L.length; i++)
        L.data[i - 1] = L.data[i];
    L.length--;
    return true;
}
void clearList(SqList &L)
{
    L.length = 0;
}
bool listEmpty(SqList &L)
{
    if (L.length == 0)
        return true;
    return false;
}
int getElem(SqList &L, int idx)
{
    if (idx >= 0 && idx < L.length)
        return L.data[idx];
    else
        return false;
}
int locateELem(SqList &L, int tmp)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == tmp)
            return i + 1;
    return -1;
}
signed main()
{
    SqList *L = initList();
    // Check initial length and emptiness
    cout << "Length: " << listLength(*L) << endl;
    cout << "Empty? " << (listEmpty(*L) ? "Yes" : "No") << endl;
    // Insert elements
    listInsert(*L, 0, 0);  // 非法操作,插入失败
    listInsert(*L, 10, 1); // Insert 10 at position 1
    listInsert(*L, 20, 2); // Insert 20 at position 2
    listInsert(*L, 30, 3); // Insert 30 at position 3
    listInsert(*L, 40, 4); // Insert 40 at position 4
    listInsert(*L, 50, 5); // Insert 50 at position 5
    // Check current length
    cout << "Length after insertion: " << listLength(*L) << endl;
    // Print the list
    cout << "List content:" << endl;
    listVisit(*L);
    // Delete elements
    int deletedElem;
    ListDelete(*L, 2, deletedElem); // Delete at position 2
    cout << "Deleted element: " << deletedElem << endl;
    // Access element
    listVisit(*L);
    cout << "Element at position 1: " << getElem(*L, 1) << endl;
    // Locate element
    cout << "Position of element 20: " << locateELem(*L, 20) << endl;
    cout << "Position of element 40: " << locateELem(*L, 40) << endl;
    cout << "Empty? " << (listEmpty(*L) ? "Yes" : "No") << endl;
    // Clear the list
    clearList(*L);
    // Check length and emptiness after clearing
    cout << "Length after clearing: " << listLength(*L) << endl;
    cout << "Empty after clearing? " << (listEmpty(*L) ? "Yes" : "No") << endl;
    return 0;
}