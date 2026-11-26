#include <iostream>
#include <string>
#include <vector>
#include <stack>
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

string vigenereCipher(string text, string key, bool encrypt) {
    string result = "";
    int keyIndex = 0;

    for (char& c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char keyChar = tolower(key[keyIndex % key.length()]);
            int shift = keyChar - 'a';

            if (encrypt) {
                c = (c - base + shift) % 26 + base;
            }
            else {
                c = (c - base - shift + 26) % 26 + base;
            }
            keyIndex++;
        }
        result += c;
    }
    return result;
}

void task3_vigenere() {
    cout << "\n--- Task 3: Vigenere Cipher ---\n";

    string text = "HELLO WORLD";
    string key = "KEY";

    string encrypted = vigenereCipher(text, key, true);
    string decrypted = vigenereCipher(encrypted, key, false);

    cout << "Original:  " << text << "\n";
    cout << "Key:       " << key << "\n";
    cout << "Encrypted: " << encrypted << "\n";
    cout << "Decrypted: " << decrypted << "\n";
}

bool isValidJSON(const string& json) {
    stack<char> brackets;
    bool inQuotes = false;
    bool escaped = false;

    for (char c : json) {
        if (inQuotes) {
            if (escaped) {
                escaped = false;
            }
            else if (c == '\\') {
                escaped = true;
            }
            else if (c == '"') {
                inQuotes = false;
            }
            continue;
        }

        if (c == '"') {
            inQuotes = true;
        }
        else if (c == '{' || c == '[') {
            brackets.push(c);
        }
        else if (c == '}' || c == ']') {
            if (brackets.empty()) return false;
            char open = brackets.top();
            brackets.pop();
            if ((c == '}' && open != '{') || (c == ']' && open != '[')) {
                return false;
            }
        }
    }
    return !inQuotes && brackets.empty();
}

void task4_jsonValidation() {
    cout << "\n--- Task 4: JSON Validation ---\n";
    cout << boolalpha;

    string test1 = R"({"name": "Ivan", "age": 25, "skills": ["C++", "Python"]})";
    string test2 = R"({"name": "Ivan", "age": 25])";
    string test3 = R"({"text": "He said: \"Hello!\"", "valid": true})";

    cout << "Test 1 (valid):     " << isValidJSON(test1) << "\n";
    cout << "Test 2 (invalid):   " << isValidJSON(test2) << "\n";
    cout << "Test 3 (escaped):   " << isValidJSON(test3) << "\n";
}

int main() {
    task1_logParser();
    task2_wordFrequency();
    task3_vigenere();
    task4_jsonValidation();

    return 0;
}