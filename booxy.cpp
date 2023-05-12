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

void CopyTex(std::string path, std::string endPath, std::vector<std::string> files) {
    for (const auto & entry : fs::directory_iterator(path))
        files.push_back(entry.path());

    for (int i = 0; i < files.size(); i++) {
        if (files[i].substr(files[i].find_last_of(".") + 1) == "tex") {
            std::string cmd = "cp " + files[i] + " " + endPath; // relative paths still
            system(cmd.c_str());
            std::string latex_cmd = "pdflatex " + files[i] + '\n'; // relative paths still
            std::cout << latex_cmd;
            // system(cmd.c_str());
        }
    }
}

void PdfLatex(std::string path) {
    for (const auto & entry : fs::directory_iterator(path)) {
        const char *cstr = entry.path().c_str();
        std::cout << cstr << '\n';
        // std::string cmd = "pdflatex " + entry.path();
    }
}
    

std::string getParentDirectory(std::string path) {
    size_t found = path.find_last_of("/\\");
    if (found != std::string::npos) {
        return path.substr(0, found);
    }
    return "";
}

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

    // CopyTex(chapOnePath, latexPath, texFiles);
    // CopyTex(chapTwoPath, latexPath, texFiles);
    // CopyTex(chapThreePath, latexPath, texFiles);
    // CopyTex(chapFourPath, latexPath, texFiles);

    // for all files in latexPath 
    std::string latexCmd = "pdflatex";
    
    PdfLatex(latexPath);

    // for all files in latex directory, ox.execute(pdflatex $filename)




















    // Chapter shell;
    // shell.TexDocs = {"I'm", "in", "GetDocs", "Function"};

    // GetDocs(shell);

    // shell.num = 22;
    // std::cout << "Chapter number: " << shell.num << '\n';

    return 0;
}
