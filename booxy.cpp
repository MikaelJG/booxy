// You need the 17 standard.
//  g++ -std=c++17 myfile.cpp -o output-name

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cstring>
#include <filesystem>
namespace fs = std::filesystem;

struct Chapter {
    int num;
    std::string directory;
    std::vector<std::string> TexDocs;
    bool isToPrint = true;
};

std::string FindTex(std::string path) {
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;

    std::cout << "in fun, for path:  " << path << '\n';
    return path;
}

std::string getParentDirectory(std::string path) {
    size_t found = path.find_last_of("/\\");
    if (found != std::string::npos) {
        return path.substr(0, found);
    }
    return "";
}
// sort chapters.num 
// to print in the right order

int main(int argc, char* argv[]) {

    // relative paths
    std::string programPath = argv[0];
    std::string parentDirectory = getParentDirectory(programPath);
    std::string chapOnePath = parentDirectory + "/chap_1";
    std::string chapTwoPath = parentDirectory + "/chap_2";
    std::string chapThreePath = parentDirectory + "/chap_3";
    std::string chapFourPath = parentDirectory + "/chap_4";
    std::string latexPath = parentDirectory + "/latex";
    std::string pdfPath = parentDirectory + "/pdf";
    std::string completePath = parentDirectory + "/complete";

    FindTex(chapOnePath);
    FindTex(chapTwoPath);
    FindTex(chapThreePath);
    FindTex(chapFourPath);

    // Chapter shell;
    // shell.TexDocs = {"I'm", "in", "GetDocs", "Function"};

    // GetDocs(shell);

    // shell.num = 22;
    // std::cout << "Chapter number: " << shell.num << '\n';

    return 0;
}
