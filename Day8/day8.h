#pragma once
#include <string>
#include <span>
#include <map>

struct Map
{
    Map(std::string directions, std::span<std::string> nodes);
    int solve();

    std::string directions_;
    std::map<std::string, std::pair<std::string, std::string> > node_map_;
};