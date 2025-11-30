#include <iostream>
using namespace std;

void bruteForceAlgo(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int comparision = 0;

    cout << "Output: [ ";
    for (int i = 0; i < n - m; i++)
    {
        bool found = true;

        for (int j = 0; j < m; j++)
        {
            comparision++;
            if (text[i + j] != pattern[j]){
                found = false;
                break;
            }
        }
        if (found)
            cout << i << ", ";
    }
    cout << "]" << endl;
    cout<<"Total comparision: "<<comparision<<endl;
}

int main()
{
    string Text = "the quick brown fox jumps over the lazy dog";
    string Pattern = "the";

    bruteForceAlgo(Text, Pattern);
}