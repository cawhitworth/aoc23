#pragma once

#include <vector>
#include <string>
#include <span>

struct Part
{
    Part() {}
    Part(std::string number, int x, int y) : number(number), x(x), y(y) {}

    bool in_expanded_bounds(int x, int y);

    std::string number;
    int x;
    int y;
};

bool operator==(const Part& lhs, const Part& rhs);

struct Symbol
{
    Symbol() {}
    Symbol(char c, int x, int y) : c(c), x(x), y(y) {}

    char c;
    int x;
    int y;
};

bool operator==(const Symbol& lhs, const Symbol& rhs);

struct Schematic
{
    Schematic() {}

    std::vector<Part> actual_parts();
    std::vector<Part> not_parts();

    std::vector<Part> parts;
    std::vector<Symbol> symbols;
};

Schematic parse_input(const std::span<std::string>& input);