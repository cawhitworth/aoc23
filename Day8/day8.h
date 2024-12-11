#pragma once
#include <string>
#include <span>
#include <map>
#include <stdint.h>

struct Map
{
    Map(std::string directions, std::span<std::string> nodes);
    int solve();
    long long solve2();
    std::string next_step(char step, std::string node);

    std::string directions_;
    std::map<std::string, std::pair<std::string, std::string> > node_map_;
};