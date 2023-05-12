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

std::vector<std::string> FindTex(std::string path, std::vector<std::string> files) {
    for (const auto & entry : fs::directory_iterator(path))
        files.push_back(entry.path());

    for (int i = 0; i < files.size(); i++) {
        if (files[i].substr(files[i].find_last_of(".") + 1) == "tex") {
            std::cout << "In path: " << path << '\n';
            std::cout << files[i] << " is a .tex" << '\n';
        }
    }

    return files;
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

    std::vector<std::string> texFiles = {};

    FindTex(chapOnePath, texFiles);
    // FindTex(chapTwoPath);
    // FindTex(chapThreePath);
    // FindTex(chapFourPath);

    // Chapter shell;
    // shell.TexDocs = {"I'm", "in", "GetDocs", "Function"};

    // GetDocs(shell);

    // shell.num = 22;
    // std::cout << "Chapter number: " << shell.num << '\n';

    return 0;
}
