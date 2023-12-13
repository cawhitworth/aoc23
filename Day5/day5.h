#pragma once

#include <vector>
#include <string>

typedef long long Identifier;

struct Range
{
    Range(Identifier dst_start, Identifier src_start, Identifier len)
        : destination_start(dst_start), source_start(src_start), length(len)
    {}
    Identifier destination_start;
    Identifier source_start;
    Identifier length;
};

bool operator==(const Range& lhs, const Range& rhs);

struct Map
{
    Map() {}
    Map(std::string from, std::string to)
        : from(from), to(to)
    {}

    Identifier map(Identifier from) const;

    std::string from;
    std::string to;
    std::vector<Range> ranges;
};

struct Almanac
{
    Almanac(std::vector<std::string> lines);

    Identifier map_through(Identifier seed) const;

    std::vector<Identifier> seeds;
    std::vector<Map> maps;
};