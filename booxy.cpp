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

// sort chapters.num 
// to print in the right order

int main(int argc, char* argv[]) {
    std::cout << "Number of arguments: " << argc << '\n';
    std::cout << "Arguments:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << " " << argv[i] << '\n';
    }
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
