#include <bits/stdc++.h>
using namespace std;

void replace (string &txt, int index){
    txt[index] = txt[index + 1] = txt[index + 2] = '*';
}

int main(){
    
    string s, word;
    getline(cin, s);

    for (int i = 0; i < s.size(); ++i){

        word = "";
        for (; i < s.size(); ++i){
            if (s[i] == 32 || s[i] == 9) break;
            word += s[i];
        }
        if (word.size() == 3 && word[0] > 96 && word[0] < 123){
            if (word[1] > 47 && word[1] < 58 && word[2] > 47 && word[2] < 58) replace(s, i-3);
        }
    }

    cout << "\n" << s << "\n";

    return 0;
}
