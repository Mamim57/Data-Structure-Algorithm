#include <bits/stdc++.h>
using namespace std;

void rabinKarp(string text, string pattern, int prime = 101)
{
    int n = text.length();
    int m = pattern.length();
    int d = 256;  // Total characters in ASCII
    int patternHash = 0, textHash = 0, h = 1;

    // Calculate the value of h = (d^(m-1)) % prime
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % prime;
    }

    // Compute the initial hash values for the pattern and the first window of the text
    for (int i = 0; i < m; i++)
    {
        patternHash = (d * patternHash + pattern[i]) % prime;
        textHash = (d * textHash + text[i]) % prime;
    }

    // Slide the pattern over the text one by one
    for (int i = 0; i <= n - m; i++)
    {
        // If the hash values match, check for the exact match
        if (patternHash == textHash)
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
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Compute the hash for the next window of the text
        if (i < n - m)
        {
            textHash = (d * (textHash - text[i] * h) + text[i + m]) % prime;

            // Make sure the hash value is positive
            if (textHash < 0)
            {
                textHash += prime;
            }
        }
    }
}

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    rabinKarp(text, pattern);

    return 0;
}

