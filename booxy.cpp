#include<iostream>
#include<vector>
#include<string>

struct Chapter {
    // std::string e;
    int num;
    // print is true by default
    // bool isPrintable;
};

int main() {

    // for all in this dir
    // create a chapter object 

    // Create a chapter object
    Chapter shell;

    // Set the object's properties
    // john.num = "John";
    shell.num = 22;
    // john.isMale = true;

    // don't use endl [Turner]
    // cout << "Name: " << john.name << endl;
    std::cout << "Chapter number: " << shell.num << std::endl;
    // cout << "Is Male: " << (john.isMale ? "Yes" : "No") << endl;

    return 0;
}
