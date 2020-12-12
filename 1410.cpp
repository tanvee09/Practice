// https://leetcode.com/contest/weekly-contest-184/problems/html-entity-parser/

#include<bits/stdc++.h>
using namespace std;

string parseHTML(string text) {
    vector<string> entities = {"&gt;", "&lt;", "&quot;", "&apos;", "&frasl;", "&amp;"};
    vector<string> values = {">", "<", "\"", "'", "/", "&"};
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        bool isEntity = false;
        if (text[i] == '&') {
            for (int idx = 0; idx < entities.size(); idx++) {
                string entity = entities[idx];
                int j;
                for (j = 1; j < entity.length() && i + j < text.length(); j++)
                    if (text[i + j] != entity[j]) 
                        break;
                if (j == entity.length()) {
                    isEntity = true;
                    result += values[idx];
                    i += entity.length() - 1;
                    break;
                }
            }
        } 
        if (!isEntity) {
            result.push_back(text[i]);
        }
    }
    return result;
}

int main()
{
    string text;
    getline(cin, text);
    cout << parseHTML(text) << endl;
    return 0;
}