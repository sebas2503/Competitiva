#include <bits/stdc++.h>
using namespace std;

int binarySearch(int* arr, int start, int end, int val){
    if (end >= start) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == val) return mid;
        if (arr[mid] > val) return binarySearch(arr, start, mid - 1, val);
        return binarySearch(arr, mid + 1, end, val);
    }
    return -1;
}

int main(){

    int *arr = new int[1000000];

    for (int i = 0; i < 1000000; ++i) arr[i] = i*2;

    cout << binarySearch(arr, 0, 1000000, 257798) << endl;
    cout << binarySearch(arr, 0, 1000000, 798799) << endl;

    delete [] arr;
    return 0;
}
