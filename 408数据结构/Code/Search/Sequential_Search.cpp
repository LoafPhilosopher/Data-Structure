#include <iostream>
#define endl "\n"
using namespace std;
int Search(int arr[], int key)
{
    int tmp = sizeof(arr);
    for (int i = 0; i < tmp; i++)
        if (arr[i] == key)
            return i;
    return -1;
}
int main()
{
    int arr[] = {1, 12, 123, 131, 23412, 41241, 41, 41};
    int ans = Search(arr, 123);
    cout << ans << endl;
    return 0;
}