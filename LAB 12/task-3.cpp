#include <iostream>
using namespace std;

#define noOfChars 256

void buildBadChar(string s, int arr[]){
    for(int i=0; i<noOfChars; i++) arr[i] = -1;

    for(int i=0; i<s.length(); i++) arr[(int)s[i]] = i;
}

void BoyersMoore(string str, string p){
    int n = str.length();
    int m = p.length();

    int badChar[noOfChars];
    buildBadChar(p, badChar);

    int s = 0;
    cout<<"[";
    while (s <= n-m){
        int j = m-1;
        while(j >= 0 && p[j] == str[s+j]) j--;

        if(j<0){
            cout << " " << s;
            s += (s+m < n) ? m-badChar[str[s+m]] : 1;
        }
        else{
            int shift = max(1, j-badChar[str[s+j]]);
            s += shift;
        }
    }
    cout<<"]"<<endl;
}

int main(){
    string text = "ACGTACGTGACG";
    string pattern = "ACG";

    BoyersMoore(text, pattern);
};