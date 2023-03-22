#include <bits/stdc++.h>
using namespace std;

// Problem 5

struct Date{
	int dd, mm, yy;
	Date(int d, int m, int y){
		dd = d;
		mm = m;
		yy = y;		
	}
		
	void print(){
		cout << dd << "/" << mm<<"/" << yy << endl;
	}
};

struct sortDia{
	bool operator() (Date a, Date b){ return a.dd < b.dd; }
};

struct sortMes{
	bool operator() (Date a, Date b){ return a.mm < b.mm;}
};

struct sortYear{
	bool operator() (Date a, Date b){ return a.yy < b.yy; }
};

int main(){

	int n, d,m,y;
	vector<Date> v;
	cin >> n;
	
	for (int i = 0; i < n ;++i){
		cout << "Insertar fecha: "; cin >> d >> m >> y;
		v.push_back(Date(d,m,y));
	}
	
	cout <<endl<< "Por dia:" << endl;
	sort(v.begin(), v.end(), sortDia());
	
	for (int i = 0 ; i < n; ++i) v[i].print();
	
	cout <<endl<< "Por mes:" << endl;
	sort(v.begin(), v.end(), sortMes());
	for (int i = 0 ; i < n; ++i) v[i].print();
	
	
	cout <<endl<< "Por year:" << endl;
	sort(v.begin(), v.end(), sortYear());
	for (int i = 0 ; i < n; ++i) v[i].print();
	
	

    return 0;
}
