#include <regex>
#include <iostream>
#include <exception>

#include "utils.h"
#include "day5.h"

bool operator==(const Range& lhs, const Range& rhs)
{
    return lhs.destination_start == rhs.destination_start &&
           lhs.source_start == rhs.source_start &&
           lhs.length == rhs.length;
}

Identifier Map::map(Identifier from) const 
{
    for(auto r: ranges)
    {
        if (from >= r.source_start && from < r.source_start + r.length)
        {
            Identifier offset = from - r.source_start;
            return r.destination_start + offset;
        }
    }

    return from;
}

Almanac::Almanac(std::vector<std::string> lines)
{
    static std::regex re_map("(.+)-to-(.+) map:");

    bool reading_map = false;
    Map current_map;
    for(auto l: lines) {
        // Assume first line is seeds
        if (seeds.size() == 0) {
            auto split = split_string(l, ':');
            if (split[0] != "seeds") {
                return;
            }
            seeds = ll_numbers_from(split[1]);
            continue;
        }

        std::smatch sr;
        if (std::regex_match(l, sr, re_map)) {
            if (reading_map) {
                throw std::exception("Malformed data");
            }
            current_map = Map(sr[1], sr[2]);
            reading_map = true;
            continue;
        }

        if (reading_map) {
            if (l == "") {
                maps.push_back(current_map);
                reading_map = false;
            } else {
                auto numbers = ll_numbers_from(l);
                if (numbers.size() != 3) {
                    throw std::exception("Malformed data");
                }
                current_map.ranges.emplace_back(numbers[0], numbers[1], numbers[2]);
            }
            continue;
        }
    }

    if (reading_map) {
        maps.push_back(current_map);
    }
}

Identifier Almanac::map_through(Identifier seed) const
{
    std::string map_from = "seed";
    Identifier value = seed;
    do {
        auto map = std::find_if(maps.cbegin(), maps.cend(), [&map_from](const Map& map) { return map.from == map_from; });
        if (map != maps.end()) {
            map_from = map->to;
            value = map->map(value);
        } else {
            map_from = "";
        }
    } while (map_from != "");

    return value;
}