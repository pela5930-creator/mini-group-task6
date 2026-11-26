#include <iostream>
#include <string>

std::string removeHtmlTags(const std::string& text) {
    std::string result = "";

    for (char c : text) {
        result += c;
    }
    return result;
}

int main() {
    std::string htmlText = "<h1>Hello, world!</h1><p>This is <b>bold</b> text.</p>";

    std::cout << "Original text:\n" << htmlText << "\n\n";
    std::cout << "Text without tags:\n" << removeHtmlTags(htmlText) << "\n";

    return 0;
}