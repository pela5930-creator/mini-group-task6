

#include <iostream>
#include <string>

std::string removeHtmlTags(const std::string& text) {
    std::string result = "";
    bool inTag = false;

    for (char c : text) {
        if (c == '<') {
            inTag = true;
        }
        else if (c == '>') {
            inTag = false;
        }
        else if (!inTag) {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string htmlText = "<h1>Hello, world!</h1><p>This is <b>bold</b> text.</p>";

    std::cout << "Original text:\n" << htmlText << "\n\n";
    std::cout << "Text without tags:\n" << removeHtmlTags(htmlText) << "\n";

    return 0;
}