#include <bits/stdc++.h>
using namespace std;

//? Build LPS Array - (Longest Prefix Suffix)
void computeLPS(string pattern, vector<int>& lps) {

    int len = 0;
    int i = 1;

    lps[0] = 0;

    while (i < pattern.length()) {

        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {

            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search
void KMPSearch(string text, string pattern) {

    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m);

    computeLPS(pattern, lps);

    int i = 0; // text index
    int j = 0; // pattern index

    while (i < n) {

        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        // pattern found
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;

            j = lps[j - 1];
        }

        else if (i < n && text[i] != pattern[j]) {

            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
}

int main() {

    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    KMPSearch(text, pattern);

    return 0;
}