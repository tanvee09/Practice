// List of strings of the form "<user> message"
// Find top n names with word count

#include<bits/stdc++.h>
using namespace std;

bool checkValidWord(string sentence, int start, int end) {
    for (int i = start; i <= end; i++) {
        char ch = sentence[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') && (ch >= '0' && ch <= '9'))
            return true;
    }
    return false;
}

pair<string, int> findUser(string message) {
    pair<string, int> user = {"", 0};
    for (int i = 1; i < message.length(); i++) {
        if (message[i] == '>') {
            user.second = i;
            user.first = message.substr(1, i - 1);
            break;
        }
    }
    return user;
}

int countWords(string message) {
    int start = 0;
    int wordcount = 0;
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == ' ' && checkValidWord(message, start, i - 1)) {
            wordcount++;
            start = i + 1;
        }
    }
    if (start != message.length())
        wordcount++;
    return wordcount;
}

struct cmp {
    bool operator()(pair<string, int> p1, pair<string, int> p2) {
        return p1.second > p2.second;
    }
};

vector<string> topN(vector<string> messages, int n) {
    unordered_map<string, int> wordFreq;
    for (string message : messages) {
        pair<string, int> user = findUser(message);
        wordFreq[user.first] += countWords(message.substr(user.second + 1));
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> name_word_freq;
    for (auto name_freq : wordFreq) {
        if (name_word_freq.size() < n) {
            name_word_freq.push(name_freq);
        } else {
            pair<string, int> leastFreqUser = name_word_freq.top();
            if (leastFreqUser.second < name_freq.second) {
                name_word_freq.pop();
                name_word_freq.push(name_freq);
            }
        }
    }
    vector<string> users;
    while (name_word_freq.size() > 0) {
        pair<string, int> user = name_word_freq.top();
        users.push_back(user.first);
        name_word_freq.pop();
    }
    return users;
}

int main()
{
    vector<string> messages = {"<Tanvee> Hey! I am Tanvee", "<Anon> Hey Tanvee!", "<Mike> Hey Tanvee", "<Tanvee> Hey Mike", "<Mike> Hey Tanvee"};
    for (string user : topN(messages, 2))
        cout << user << endl;
    return 0;
}