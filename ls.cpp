// You need the 17 standard.
//  g++ -std=c++17 myfile.cpp -o output-name

#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    std::string path = "./foo";
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}
