#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "day8.h"

int main(int argc, char* argv[])
{
    std::ifstream input { argv[1] };
    
    std::string directions;
    std::getline(input, directions);
    
    std::vector<std::string> nodes;
    for(std::string line; std::getline(input, line); ) {
        nodes.push_back(line);
    }

    Map m(directions, nodes);

    std::cout << "Result: " << m.solve() << std::endl;
    return 0;
}

