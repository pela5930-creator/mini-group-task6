#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

void task1_logParser() {
    cout << "\n--- Task 1: Log Parser ---\n";

    vector<string> logs = {
        "2023-10-25 10:15:30 INFO User logged in",
        "2023-10-25 10:16:45 ERROR Database connection failed",
        "2023-10-25 10:17:00 WARNING Disk space low",
        "2023-10-25 10:18:12 ERROR Timeout occurred",
        "2023-10-25 10:19:50 INFO User logged out"
    };

    cout << "Found ERROR entries:\n";
    for (const string& line : logs) {
        size_t pos = line.find("ERROR");
        if (pos != string::npos) {
            string timestamp = line.substr(0, 19);
            string message = line.substr(pos + 6);

            cout << "Time: [" << timestamp << "] | Message: " << message << "\n";
        }
    }
}

void task2_wordFrequency() {
    cout << "\n--- Task 2: Word Frequency (Top-10) ---\n";

    string text = "C++ is a powerful language. C++ is fast. "
        "Python is easy. Python is popular. "
        "I love coding in C++ and Python.";

    transform(text.begin(), text.end(), text.begin(), ::tolower);

    for (char& c : text) {
        if (ispunct(c)) c = ' ';
    }

    map<string, int> wordCount;
    stringstream ss(text);
    string word;
    while (ss >> word) {
        wordCount[word]++;
    }

    vector<pair<string, int>> sortedWords(wordCount.begin(), wordCount.end());

    sort(sortedWords.begin(), sortedWords.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
        });

    cout << "Top words by frequency:\n";
    int count = 0;
    for (const auto& pair : sortedWords) {
        if (count >= 10) break;
        cout << count + 1 << ". " << pair.first << " (occurs " << pair.second << " times)\n";
        count++;
    }
}

int main() {
    task1_logParser();
    task2_wordFrequency();

    return 0;
}