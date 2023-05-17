//  c++17 standard.
//  g++ -std=c++17 myfile.cpp -o output-name


// readflag stategy
// if -o or -omit flag
// prompt user with std::cin >> omit_chapter  
// prompt user for more chapters // chap_two
// omit path search for them specifically

// have flags and options strategy

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
