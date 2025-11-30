#include <iostream>
using namespace std;

void buildLPS(string pattern, int lps[]) {
    int m = pattern.length();
    lps[0] = 0;
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int lps[m];
    buildLPS(pattern, lps);

    cout << "LPS Array: [ ";
    for (int i = 0; i < m; i++)
        cout << lps[i] << " ";
    cout << "]" << endl;

    cout << "Positions: [ ";
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }
        if (j == m) {
            cout << (i - j) << " ";
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    cout << "]" << endl;
}

int main() {
    string text = "ababababc";
    string pattern = "abab";
    KMP(text, pattern);
}
