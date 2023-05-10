#include <iostream>
#include <cstring>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(".")) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
        std::cout << entry->d_name << std::endl;
        }
        closedir(dir);
    } else {
        perror("opendir() error");
    }

    return 0;
}

