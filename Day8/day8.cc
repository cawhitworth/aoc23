#include <regex>
#include <algorithm>
#include <numeric>
#include "day8.h"

Map::Map(std::string directions, std::span<std::string> nodes)
{
    directions_ = directions;
    
    static std::regex re_node("(\\w\\w\\w) = \\((\\w\\w\\w), (\\w\\w\\w)\\)");

    for(auto l: nodes)
    {
        std::smatch match;
        if (!std::regex_match(l, match, re_node)) {
            continue;
        }

        node_map_[match[1]] = std::pair { match[2], match[3] };
    }
}

std::string Map::next_step(char step, std::string node)
{
    return step == 'L' ? node_map_[node].first : node_map_[node].second;
}

int Map::solve()
{
    auto step = directions_.begin();

    std::string node { "AAA" };
    int count = 0;
    while (node != "ZZZ") {
        node = next_step(*step, node);
        step++;
        if (step == directions_.end()) { 
            step = directions_.begin();
        }
        count ++;
    }

    return count;
}

uint64_t Map::solve2()
{
    auto step = directions_.begin();

    std::vector<std::string> start_nodes;
    for(auto n: node_map_)
    {
        if (n.first.ends_with('A')) {
            start_nodes.push_back(n.first);
        }
    }

    uint64_t total = 1;
    for(auto n : start_nodes)
    {
        int count = 0;
        while (!n.ends_with('Z')) {
            n = next_step(*step, n);
            step++;
            if (step == directions_.end()) { 
                step = directions_.begin();
            }
            count ++;
        }
        total *= count;
    }

    return total;
}