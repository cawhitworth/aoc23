#include <span>
#include <string>
#include "day3.h"

bool operator==(const Part& lhs, const Part& rhs)
{
    return lhs.number == rhs.number &&
           lhs.x == rhs.x &&
           lhs.y == rhs.y;
}

bool operator==(const Symbol& lhs, const Symbol& rhs)
{
    return lhs.c == rhs.c &&
           lhs.x == rhs.x &&
           lhs.y == rhs.y;
}

Schematic parse_input(const std::span<std::string>& input)
{
    Schematic result;
    int y = 0;
    for(auto line: input)
    {
        bool parsing_part = false;
        std::string part = "";
        int part_start = -1;
        for(int x = 0; x < line.length(); x++)
        {
            char c = line[x];
            if (c >= '0' && c <= '9') {
                if (!parsing_part) {
                    part_start = x;
                }
                parsing_part = true;
                part += c;
            } else {
                if (parsing_part) {
                    parsing_part = false;
                    result.parts.emplace_back(std::stoi(part), part_start, y);
                    part = "";
                }
                if (c != '.') {
                    result.symbols.emplace_back(c, x, y);
                }
            }
        }
        if (parsing_part) {
            result.parts.emplace_back(std::stoi(part), part_start, y);
        }
        y++;
    }
    return result;
}