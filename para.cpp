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
    std::string htmlText1 = "<h1>Hello, world!</h1><p>This is <b>bold</b> text.</p>";
    std::cout << "Original text:\n" << htmlText1 << "\n\n";
    std::cout << "Text without tags:\n" << removeHtmlTags(htmlText1) << "\n\n";

    std::string htmlText2 = "<div><a href='#'>Link</a></div>";
    std::cout << "Original text:\n" << htmlText2 << "\n\n";
    std::cout << "Text without tags:\n" << removeHtmlTags(htmlText2) << "\n";

    return 0;
}