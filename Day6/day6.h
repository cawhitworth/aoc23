#pragma once

#include <vector>
#include <string>
#include <cstdint>

std::vector<int> parse_times(std::string line);
std::vector<int> parse_distances(std::string line);

std::vector<int> possibilities(int time);

int winning_ways(int time, int distance);

uint64_t parse_times_bignum(std::string line);
uint64_t parse_distances_bignum(std::string line);
uint64_t winning_ways_quadratic(uint64_t time, uint64_t distance);