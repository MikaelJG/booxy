#include<iostream>
#include<vector>
#include<string>

struct Chapter {
    // std::string e;
    int num;
    // possibly many .tex for one chapter 
    std::vector<std::string> TexDocs;

    bool isPrintable; // true by default
};

// give it std::string directory as well.
std::vector<std::string> GetDocs(std::vector<std::string> docs) {
    // look in the dir
    // for found .tex, 
    // append in the chapter's vector

    for (int integer = 0; integer < docs.size(); integer++) {
        std::cout << docs[integer] << " ";
    }
    std::cout << std::endl;
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

    GetDocs(shell.TexDocs);

    shell.num = 22;
    std::cout << "Chapter number: " << shell.num << '\n';

    return 0;
}
