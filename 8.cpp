#include <bits/stdc++.h>
using namespace std;

void power_set(string cad = "", int count = 0){
    if (count == 20){
        cout << cad << "\n";
        return;
    }

    power_set(cad, count+1);
    power_set(cad + to_string(count+1), count+1);

}

int main(){

    power_set();

    return 0;
}
