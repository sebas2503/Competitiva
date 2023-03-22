#include <iostream>
#include <set>
#include <random>
using namespace std;

int get_random(int low, int high) { // Funcion que genera numeros aleatorios 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(low, high);
    return distribution(gen);
}

void aleatorio()
{
  set<int> numeros;
  int n;
  cout<<"n: "; cin>>n;
  for(int i=0;i<n;i++)
    {
      numeros.insert(get_random(0,n*1000));
    }

  
  set<int>::iterator itr;
 
  for (itr = numeros.begin();itr != numeros.end(); itr++)
  {
    cout << *itr << " ";
  }
}

int main() {
    aleatorio();
    return 0;
}