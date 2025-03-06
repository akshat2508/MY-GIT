#include <iostream>
#include <filesystem>
#include <fstream>
#include <ctime>
#include "../include/init.h"
#include "../include/utils.h"
using namespace std;
namespace fs = filesystem;

// ANSI color codes
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define BLUE    "\033[1;34m"

// Function to get the current timestamp


void initializeRepository() {
    string mygitPath = ".mygit";

    if (fs::exists(mygitPath)) {
        cout << YELLOW << "[" << getCurrentTimestamp() << "] ⚠️  Repository already initialized!" << RESET << endl;
        return;
    }

    fs::create_directory(mygitPath);
    fs::create_directory(mygitPath + "/objects");
    fs::create_directory(mygitPath + "/refs");
    fs::create_directory(mygitPath + "/refs/heads");
    fs::create_directory(mygitPath + "/refs/tags");

    ofstream headFile(mygitPath + "/HEAD");
    if (headFile) {
        headFile << "ref: refs/heads/main\n";
        headFile.close();
    } else {
        cout << RED << "[" << getCurrentTimestamp() << "] ❌ Error creating HEAD file!" << RESET << endl;
        return;
    }

    ofstream indexFile(mygitPath + "/index");
    if (!indexFile) {
        cout << RED << "[" << getCurrentTimestamp() << "] ❌ Error creating index file!" << RESET << endl;
        return;
    }
    indexFile.close();

    cout << GREEN << "[" << getCurrentTimestamp() << "] ✅ Initialized empty MyGit repository in " 
         << BLUE << fs::absolute(mygitPath) << RESET << endl;
}
