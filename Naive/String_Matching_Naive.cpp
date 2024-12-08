#include<bits/stdc++.h>
using namespace std;

void naiveStringMatch(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    // Loop through the text to check for possible starting positions
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;

        // Check if the substring of text starting from i matches the pattern
        while (j < m && text[i + j] == pattern[j])
        {
            j++; // Compare character by character
        }

        // If all characters of the pattern matched
        if (j == m)
        {
            cout << "Pattern found at index " << i << endl;  // Print the starting index
        }
    }
}

int main()
{
    string text, pattern;

    // Input text and pattern from the user
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    // Call the naive string matching function
    naiveStringMatch(text, pattern);

    return 0;
}

