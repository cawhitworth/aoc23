#include <string>
#include <map>
#include <algorithm>

int process_line_part1(std::string line) {

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

int process_line_part2(std::string line)
{
    std::map<std::string, int> tokens = {
        { "1", 1 }, { "one", 1 },
        { "2", 2 }, { "two", 2 },
        { "3", 3 }, { "three", 3 },
        { "4", 4 }, { "four", 4 },
        { "5", 5 }, { "five", 5 },
        { "6", 6 }, { "six", 6 },
        { "7", 7 }, { "seven", 7 },
        { "8", 8 }, { "eight", 8 },
        { "9", 9 }, { "nine", 9 },
        { "0", 0 }, { "zero", 0 }
    };

    int first_pos=line.length()+1, first_digit;
    int last_pos=-1, last_digit;

    for(auto const& t: tokens) {
        int pos = -1;
        do {
            pos = line.find(t.first, pos+1);
            if (pos != std::string::npos) {
                if (pos < first_pos) {
                    first_pos = pos; first_digit = t.second;
                }
                if (pos > last_pos) {
                    last_pos = pos; last_digit = t.second;
                }
            }
        }
        while (pos != std::string::npos);
    }

    if (first_pos == line.length() + 1 || last_pos == -1) {
        return 0;
    }

    return first_digit * 10 + last_digit;
}