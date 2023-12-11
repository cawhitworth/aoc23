#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    std::ifstream input { argv[1] };
    
    for(std::string line; std::getline(input, line); ) {
    }

    std::cout << "Result: " << std::endl;
    return 0;
}

