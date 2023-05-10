#include<iostream>
#include<vector>
#include<string>

struct Chapter {
    int num;
    std::string directory;
    std::vector<std::string> TexDocs;
    bool isToPrint = true;
};

std::vector<std::string> GetDocs(Chapter ch) {
    // look in the dir
    // for found .tex, 
    // append in the chapter's vector

    for (int integer = 0; integer < ch.TexDocs.size(); integer++) {
        std::cout << ch.TexDocs[integer] << " ";
    }
    std::cout << '\n';
    std::cout << (ch.isToPrint ? "true" : "false") << '\n'; 
    return ch.TexDocs;
}

std::string getParentDirectory(const std::string& path) {
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
    
    std::cout << completePath << '\n';
    std::cout << pdfPath << '\n';
    std::cout << latexPath << '\n';

    // for all .tex in directory latex
    // create a chapter object 
    // look at directory
    // get all .tex docs

    Chapter shell;
    shell.TexDocs = {"I'm", "in", "GetDocs", "Function"};

    GetDocs(shell);

    shell.num = 22;
    std::cout << "Chapter number: " << shell.num << '\n';

    return 0;
}
