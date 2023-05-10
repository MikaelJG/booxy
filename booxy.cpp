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

    std::string programPath = argv[0];
    std::string parentDirectory = getParentDirectory(programPath);
    std::cout << "Parent Directory: " << parentDirectory << '\n';
    std::cout << parentDirectory << "outside of if";


    // std::string chap_one_path = parentDirectory + "/chap_1";
    // std::string chap_two_path = script_path/chap_2";
    // std::string chap_three_path = script_path/argv[0];
    // std::string chap_four_path = argv[0];

    // std::cout << script_path << '\n';
    // std::cout << chap_one_path << '\n';

    // std::cout << "Number of arguments: " << argc << '\n';
    // std::cout << "Arguments:" << '\n';
    // for (int i = 0; i < argc; i++) {
    //     std::cout << " " << argv[i] << '\n';
    // }
    // get relative path
    // where this program is.



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
