#include<iostream>
#include<vector>
#include<string>

struct Chapter {
    int num;
    std::vector<std::string> TexDocs;
    bool isToPrint = true;
};

// give it std::string directory as well.
std::vector<std::string> GetDocs(std::vector<std::string> docs, bool print) {
    // look in the dir
    // for found .tex, 
    // append in the chapter's vector

    for (int integer = 0; integer < docs.size(); integer++) {
        std::cout << docs[integer] << " ";
    }
    std::cout << std::endl;
    std::cout << (print ? "true" : "false") << '\n'; 
    return docs;
}

// function,
// find .tex docs.

// sort chapters.num 
// to print in the right order

int main() {

    // for all .tex in directory latex
    // create a chapter object 
    Chapter shell;
    shell.TexDocs = {"I'm", "in", "GetDocs", "Function"};

    GetDocs(shell.TexDocs, shell.isToPrint);

    shell.num = 22;
    std::cout << "Chapter number: " << shell.num << '\n';

    return 0;
}
