#include <regex>
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

int Map::solve()
{
    auto step = directions_.begin();

    std::string node { "AAA" };
    int count = 0;
    while (node != "ZZZ") {
        node = *step == 'L' ? node_map_[node].first : node_map_[node].second;
        step++;
        if (step == directions_.end()) { 
            step = directions_.begin();
        }
        count ++;
    }

    return count;
}