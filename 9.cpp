#include <bits/stdc++.h>
#include <string>
using std::string;
using namespace std;

// Ejercicio 9

long long ConvertTo10(const string& input, int base){
	if(base < 2 || base > 36) return 0;
	
	bool isNegative = (input[0] == '-');    
	
	int startIndex = input.length()-1;
	int endIndex   = isNegative ? 1 : 0;
	
	long value = 0;
	int digitValue = 1;
	
	for(int i = startIndex; i >= endIndex; --i){
		char c = input[i];
		
		// Uppercase it - NOTE: could be done with std::toupper
		if(c >= 'a' && c <= 'z') c -= ('a' - 'A');
		
		// Convert char to int value - NOTE: could be done with std::atoi
		// 0-9
		if(c >= '0' && c <= '9') c -= '0';
		// A-Z
		else c = c - 'A' + 10;
		
		if(c >= base) return 0;
		
		// Get the base 10 value of this digit    
		value += c * digitValue;
		
		// Each digit has value base^digit position - NOTE: this avoids pow
		digitValue *= base;
	}
	
	if(isNegative) value *= -1;
	
	return value;
}

string ConvertFrom10(long value, int base){
	if(base < 2 || base > 36) return "0";
	
	bool isNegative = (value < 0);
	if(isNegative) value *= -1;
	
	// NOTE: it's probably possible to reserve string based on value
	string output;
	
	do{
		char digit = value % base;
		
		// Convert to appropriate base character
		// 0-9
		if(digit < 10) digit += '0';
		// A-Z
		else digit = digit + 'A' - 10;
		
		// Append digit to string (in reverse order)
		output += digit;
		
		value /= base;
		
	} while (value > 0);
	
	if(isNegative) output += '-';
	
	// Reverse the string - NOTE: could be done with std::reverse
	int len = output.size() - 1;
	for(int i = 0; i < len; ++i){
		// Swap characters - NOTE: Could be done with std::swap
		char temp = output[i];
		output[i] = output[len-i];
		output[len-i] = temp;
	}
	
	return output;
}

// Convert from one base to another
string ConvertBase(const string& input, int baseFrom, int baseTo)
{
	// NOTE: There is probably a more efficient way to convert between two bases.
	//       This however is easy to understand and debug.
	return ConvertFrom10(ConvertTo10(input, baseFrom), baseTo);
}


int main(){
	
	string X;
	int base1, base2;
	
	cout << "Ingrese X: "; cin >> X;
	cout << "Ingrese Base del numero: "; cin >> base1;
	cout << "Ingrese Base a convertir: "; cin >> base2;
	
	cout << ConvertBase(X,   base1, base2) << endl;
	return 0;
}
