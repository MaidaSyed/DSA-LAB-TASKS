#include <iostream>
using namespace std;

#define PRIME 101
#define BASE 256

void rabinKarp(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    if (m == 0 || m > n)
    {
        cout << "No valid pattern to search." << endl;
        return;
    }

    int p = 0;
    int t = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * BASE) % PRIME;

    for (int i = 0; i < m; i++)
    {
        p = (BASE * p + pattern[i]) % PRIME;
        t = (BASE * t + text[i]) % PRIME;
    }

    int realMatches[1000], falseMatches[1000];
    int realCount = 0, falseCount = 0;

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            bool match = true;

            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                realMatches[realCount++] = i;
            }
            else
            {
                falseMatches[falseCount++] = i;
            }
        }
        if (i < n - m)
        {
            t = (BASE * (t - text[i] * h) + text[i + m]) % PRIME;

            if (t < 0)
                t += PRIME;
        }
    }
    cout << "Real Matches: [ ";
    for (int i = 0; i < realCount; i++)
        cout << realMatches[i] << " ";
    cout << "]\n";

    cout << "False Positives: [ ";
    for (int i = 0; i < falseCount; i++)
        cout << falseMatches[i] << " ";
    cout << "]\n";
}

int main()
{
    string text = "Data structures and Algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    rabinKarp(text, pattern);
    return 0;
}