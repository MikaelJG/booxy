//  c++17 standard.
//  g++ -std=c++17 myfile.cpp -o output-name


// readflag stategy
// if -o or -omit flag
// prompt user with std::cin >> omit_chapter  
// prompt user for more chapters // chap_two
// omit path search for them specifically

// feature probing
// verify that latex and pdfunite are installed
// either by which, or cpp own means 

// Test relative paths 
// With .bashrc shortcut
// Could I do it with $PATH? 

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cstring>
#include <algorithm>
#include <filesystem>
namespace fs = std::filesystem;

const bool is_tex(const std::string file) {
    return (file.substr(file.find_last_of(".") + 1) == "tex" ? true : false);
}

const std::string create_tex_cmd(const std::string file, const std::string endPath) {
    std::string cmd = "cp " + file + " " + endPath; // relative paths still
    return cmd;
}

const void copy_tex(std::string path, std::string endPath, std::vector<std::string> files) {
    for (const auto & entry : fs::directory_iterator(path))
        files.push_back(entry.path());

    for (const auto file : files) {
        if (is_tex(file)) {
            system(create_tex_cmd(file, endPath).c_str());
        }
    }
}

void pdf_latex(std::string path) {
    for (const auto & entry : fs::directory_iterator(path)) {
        const std::string cstr = entry.path().c_str();
        const std::string latex_cmd = "pdflatex " + cstr;
        system(latex_cmd.c_str());
    }
}

const std::string getParentDirectory(std::string path) {
    size_t found = path.find_last_of("/\\");
    if (found != std::string::npos) {
        return path.substr(0, found);
    }
    return "";
}

bool hasFlag(const std::vector<std::string>& arguments, const std::string& flag) {
    return std::find(arguments.begin(), arguments.end(), flag) != arguments.end();
}

int main(int argc, char* argv[]) {
    const std::vector<std::string> arguments(argv + 1, argv + argc);

    // if (hasFlag(arguments, "-o")) {
    //     std::cout << "Flag -o for -omit is present!" << std::endl;
    // }

    // relative paths
    const std::string programPath = argv[0];
    const std::string parentDirectory = getParentDirectory(programPath);
    const std::string chapOnePath = parentDirectory + "/chap_1";
    const std::string chapTwoPath = parentDirectory + "/chap_2";
    const std::string chapThreePath = parentDirectory + "/chap_3";
    const std::string chapFourPath = parentDirectory + "/chap_4";
    const std::string latexPath = parentDirectory + "/latex";
    const std::string pdfPath = parentDirectory + "/pdf";
    const std::string completePath = parentDirectory + "/complete";

    std::vector<std::string> texFiles = {};

    copy_tex(chapOnePath, latexPath, texFiles);
    copy_tex(chapTwoPath, latexPath, texFiles);
    copy_tex(chapThreePath, latexPath, texFiles);
    copy_tex(chapFourPath, latexPath, texFiles);

    pdf_latex(latexPath);

    // next, remove or move .aux .pdf  .log files

    // if ext = .pdf // put in ./pdf
    // if ext = .aux // put in ./aux
    // if ext = .log // put in ./log

    // install dependencies, pdfunite?

    return 0;
}

