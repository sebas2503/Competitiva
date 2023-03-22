#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

int daysTilNow(int y, int m, int d) { 
	if (m < 3) y--, m += 12;
	return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}


int main(int argc, char **argv){
	int dd, mm, yy, d_week;
	cout << "Insertar día, mes y año: "; cin >> dd >> mm >> yy;
	int days = abs(daysTilNow(2023, 3, 22) - daysTilNow(yy, mm, dd)); //Fecha de hoy 
	mm = (mm+9) % 12;
	yy -= mm/10;
	d_week = 365*yy + yy/4 - yy/100 + yy/400 + (mm*306 + 5)/10 + (dd-1);
	
	string day[] = {"Miercoles", "Jueves", "Viernes", "Sábado", "Domingo", "Lunes", "Martes"};
	
	cout << "Día de la semana es: " << day[d_week % 7] << "\n";
	cout << "Cantidad de días: " << days << "\n";
	
	return 0;
}
