#include <iostream>
using namespace std;
string pi = "14159265358979";
string resu = "3,";
int main()
{
  int n = 0;
  cout << "Hello, world: ";
  cin>>n;
  cout<<endl;
  if(int(pi[n])-48 >= 5)
  {
    cout<<pi[n]<<endl;
    int a = (int(pi[n-1])+1)-48;
    pi[n-1] = a+'0';
  }
  for(int x = 0;x < n;x++)
  {
    resu += pi[x];
  }  
  cout<<"Pi: "<<resu<<endl;
  return 0;
}