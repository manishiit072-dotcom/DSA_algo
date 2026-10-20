
#include <bits/stdc++.h>
using namespace std;

// Build the LPS (Longest Proper Prefix which is also Suffix) array
vector<int> computeLPS(string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len > 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Search pattern in text
int KMP(string& text, string& pattern) {
    int n = text.size();
    int m = pattern.size();

    if (m == 0) return 0;

    vector<int> lps = computeLPS(pattern);

    int i = 0; // Text pointer
    int j = 0; // Pattern pointer

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;

            if (j == m) {
                return i - m; // First occurrence
            }
        }
        else {
            if (j > 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return -1; // Pattern not found
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";

    cout << KMP(text, pattern) << '\n'; // Output: 10
}
