#include <bits/stdc++.h>
using namespace std;

string clear_string(string ec){
    string new_ec = "";
    for (int i = 0; i < ec.size(); ++i){
        if (ec[i] == 32 || ec[i] == 9) continue;
        new_ec += ec[i];
    }
    return new_ec;
}

string add_brackets(string ec){
    string new_ec = "";
    for (int i = 0; i < ec.size(); ++i){
        if ((ec[i] == '*' || ec[i] == '/') && ec[i+1] == '-' ){
            new_ec += ec[i++];
            new_ec +=  "(-";
            while (++i < ec.size() && ec[i] > 47 && ec[i] < 58) new_ec += ec[i];
            new_ec += ')';
            if (i >= ec.size()) break;
        }
        new_ec += ec[i];
    }
    return new_ec;
}

int solve_ecuation(string &ec, int start, int end){

    // cout << "Solve: " <<  ec.substr(start, end-start) << "\t" << (end-start) << endl;

    int parentesis, i, factor = 1;

    // Ignore sign + at start of the ecuation
    // Sign - at start is important
    if (ec[start] == '+') ++start;
    else if (ec[start] == '-'){
        factor = -1;
        ++start;
    }

    // Look for addition and subtraccion
    for (i = start; i < end; ++i){

        // ignore things inside parentesis
        if (ec[i] == '('){
            parentesis = 1;
            for (i = i+1; parentesis && i < end; ++i){
                if (ec[i] == '(') ++parentesis;
                else if (ec[i] == ')') --parentesis;
            }
        }

        if (i >= end) break;

        if (ec[i] == '+') return factor*solve_ecuation(ec, start, i) + solve_ecuation(ec, i+1, end);
        if (ec[i] == '-') return factor*solve_ecuation(ec, start, i) + solve_ecuation(ec, i, end); // include - at start
    }

    // Look for mult and div (Invert)
    for (i = end-1; i >= start; --i){

        // ignore things inside parentesis
        if (ec[i] == ')'){
            parentesis = 1;
            for (i = i-1; parentesis && i >= start; --i){
                if (ec[i] == ')') ++parentesis;
                else if (ec[i] == '(') --parentesis;
            }
        }

        if (i < start) break;

        if (ec[i] == '*') return solve_ecuation(ec, start, i) * solve_ecuation(ec, i+1, end) * factor;
        if (ec[i] == '/') return solve_ecuation(ec, start, i) / solve_ecuation(ec, i+1, end) * factor;
    }

    // if there is no operators outside parentesis:

    // Opc 1: All the expression is rounded in parentesiss
    if (ec[start] == '(' && ec[end-1] == ')') return solve_ecuation(ec, start+1, end-1) * factor;

    // Opc 2: All the expresion is a number
    return stoi(ec.substr(start, end-start)) * factor;
}

int main(){

    string ec;
    getline(cin, ec);
    ec = clear_string(ec);
    ec = add_brackets(ec);

    // cout << ec << endl;

    cout << solve_ecuation(ec, 0, ec.size()) << endl;

    return 0;

}
