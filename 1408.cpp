// https://leetcode.com/contest/weekly-contest-184/problems/string-matching-in-an-array/

#include<bits/stdc++.h>
using namespace std;

bool checkIn(string small, string big) {
    for (int i = 0; i <= big.length() - small.length(); i++) {
        if (small[0] == big[i]) {
            int j;
            for (j = 1; j < small.length(); j++)
                if (small[j] != big[i + j])
                    break;
            if (j == small.length())
                return true;
        }
    }
    return false;
}

vector<string> stringMatching(vector<string>& words) {
    set<string> matchingWords;
    for (int i = 0; i < words.size() - 1; i++)
        for (int j = i + 1; j < words.size(); j++)
            if (words[i].length() < words[j].length() && checkIn(words[i], words[j])) {
                matchingWords.insert(words[i]);
            } else if (words[j].length() < words[i].length() && checkIn(words[j], words[i])) {
                matchingWords.insert(words[j]);
            }    
    vector<string> result;
    result.assign(matchingWords.begin(), matchingWords.end());
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    vector<string> matchingWords = stringMatching(words);
    for (string word : matchingWords) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}