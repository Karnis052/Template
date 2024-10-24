#include<bits/stdc++.h>
#define MOD ((int)998244353 + 0)
#define N ((int)2e6 + 7)
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long


using namespace std;

int lef[N] , rig[N] , arr[N];
void merg(int arr[] , int l , int r)
{
    int mid = (l + r) >> 1;
    for (int i = l ; i <= mid ; i++) lef[i] = arr[i];
    for (int i = mid + 1 ; i <= r ; i++) rig[i] = arr[i];
    int i = l , j = mid + 1 , k = l;
    while (i <= mid && j <= r) {
        if (lef[i] < rig[j]) {
            arr[k] = lef[i];
            i++;
        }
        else
        {
            arr[k] = rig[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        arr[k] = lef[i];
        k++;
        i++;
    }
    while (j <= r) {
        arr[k++] = rig[j++];
    }
}

void mergesort(int arr[] , int l , int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);
    merg(arr, l, r);
}

int main()
{
    int n = 10;
    for (int i = 1 ; i <= 10 ; i++) arr[i] = 10 - i + 1;
    cout << "before\n";
    for (int i = 1 ; i <= 10 ; i++) cout << arr[i] << " ";
    cout << endl << "after\n";
    mergesort(arr, 1, n);
    for (int i = 1 ; i <= 10 ; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}