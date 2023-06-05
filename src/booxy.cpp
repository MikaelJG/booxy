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

void CopyTex(std::string path, std::string endPath, std::vector<std::string> files) {
    for (const auto & entry : fs::directory_iterator(path))
        files.push_back(entry.path());

    for (int i = 0; i < files.size(); i++) {
        if (files[i].substr(files[i].find_last_of(".") + 1) == "tex") {
            std::string cmd = "cp " + files[i] + " " + endPath; // relative paths still
            system(cmd.c_str());
        }
    }
}

void PdfLatex(std::string path) {
    for (const auto & entry : fs::directory_iterator(path)) {
        std::string cstr = entry.path().c_str();
        std::string latex_cmd = "pdflatex " + cstr;
        system(latex_cmd.c_str());
    }
}
    

std::string getParentDirectory(std::string path) {
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
    std::vector<std::string> arguments(argv + 1, argv + argc);

    for (int i = 0; i < arguments.size(); i++) {
        std::cout << arguments[i] << " ";
    }
    std::cout << std::endl;

    // if no arguments give help as default
    // if arguments.size = 0?

    if (hasFlag(arguments, "-o")) {
        std::cout << "Flag -o for -omit is present!" << std::endl;
    }

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

    CopyTex(chapOnePath, latexPath, texFiles);
    CopyTex(chapTwoPath, latexPath, texFiles);
    CopyTex(chapThreePath, latexPath, texFiles);
    CopyTex(chapFourPath, latexPath, texFiles);

    PdfLatex(latexPath);

    // next, remove or move .aux .pdf  .log files

    // if ext = .pdf // put in ./pdf
    // if ext = .aux // put in ./aux
    // if ext = .log // put in ./log

    // install dependencies, pdfunite?

    return 0;
}

// Bash Example 


// compile_latex() {
//     # .log in log ; .pdf in pdf
//     mv *.aux log ; mv *.log log ; mv *.pdf pdf
// 
//     pdf_files=$(ls ${pdf_path}) 
// 
//     cd $pdf_path && pdfunite ${pdf_files} workbook_$date.pdf
// 
//     mv workbook* ../$complete_path
// }
// 
// # loop over number of chapters
// for i in {1..5}; do
//   path="path_$i"
//   files=$(ls ${!path})
// 
//     for filename in ${files}; do
//         ext="${filename##*.}"
//         case $ext in
//         tex) 
//             filepath=${!path}/$filename
//             cp $filepath latex;;
//         esac
//     done
// done
