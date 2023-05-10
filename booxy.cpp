#include<iostream>
#include<vector>
#include<string>

struct Chapter {
    int num;
    std::string directory;
    std::vector<std::string> TexDocs;
    bool isToPrint = true;
};

// give it std::string directory as well.
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

int main() {

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
