#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

//Ejercicio 11

int main(int argc, char **argv){
    long long int n;
    cout << "Number: "; cin >> n;

    long long int top = sqrt(n);
    
    if (n % 2 == 0 || n % 3 == 0) {
			cout << "Compuesto\n"; 
			return 0;}
	
    for(int i = 5; i <= top; i++){
			if( n % i == 0 ) {
				cout << "Compuesto\n"; 
				return 0 ;}
    }

    cout << "Primo\n";

	return 0;
}
