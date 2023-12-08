#include <string>
#include <algorithm>

int process_line(std::string line) {

    auto first { std::find_if(line.begin(), line.end(), [](const char& c) { return c >= '0' && c <= '9'; }) };
    auto last { std::find_if(line.rbegin(), line.rend(), [](const char& c) { return c >= '0' && c <= '9'; }) };

    if (first == line.end()) {
        return 0;
    }

    std::string digits;
    digits += *first;
    digits += *last;

    return atoi(digits.c_str());
}