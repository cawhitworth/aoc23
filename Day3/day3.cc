#include <span>
#include <string>
#include "day3.h"

bool Part::in_expanded_bounds(int x, int y) {
    // Don't care if it's OOB
    int min_x = this->x - 1;
    // Zero-indexec
    int max_x = this->x + this->number.length();
    int min_y = this->y - 1;
    int max_y = this->y + 1;

    return (x >= min_x && x <= max_x && y >= min_y && y <= max_y);
}

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
                    result.parts.emplace_back(part, part_start, y);
                    part = "";
                }
                if (c != '.') {
                    result.symbols.emplace_back(c, x, y);
                }
            }
        }
        if (parsing_part) {
            result.parts.emplace_back(part, part_start, y);
        }
        y++;
    }
    return result;
}

std::vector<int> Schematic::gear_ratios() {
    std::vector<int> result;
    for(auto s: this->symbols) {
        if (s.c != '*') {
            continue;
        }

        std::vector<Part> adjacents;
        for(auto p: this->parts) {
            if (p.in_expanded_bounds(s.x, s.y)) {
                adjacents.push_back(p);
            }
        }
        if (adjacents.size() == 2) {
            int gear_1 = std::stoi(adjacents[0].number);
            int gear_2 = std::stoi(adjacents[1].number);
            result.push_back(gear_1 * gear_2);
        }
    }

    return result;
}

std::vector<Part> Schematic::actual_parts() {
    std::vector<Part> result;

    for(auto p: this->parts) {
        for(auto s: this->symbols) {
            if (p.in_expanded_bounds(s.x, s.y)) {
                result.push_back(p);
                break;
            }
        }
    }

    return result;
}

std::vector<Part> Schematic::not_parts() {
    std::vector<Part> result;

    for(auto p: this->parts) {
        bool has_symbol = false;
        for(auto s: this->symbols) {
            if (p.in_expanded_bounds(s.x, s.y)) {
                has_symbol = true;
                break;
            }
        }
        if (!has_symbol) {
            result.push_back(p);
        }
    }

    return result;
}