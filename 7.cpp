#include <bits/stdc++.h>
using namespace std;

// ejercicio 7

int main(){

	char arr[10] = {'A','B','C','D','E','F','G','H','I','J'};
	
	do{
		for (int i = 0; i < 10; ++i) cout << arr[i];
		cout << endl;
	} while(next_permutation(arr, arr+10));
	
    return 0;
}
