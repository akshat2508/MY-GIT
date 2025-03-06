#include <iostream>
#include <fstream>
#include <filesystem>
#include "../include/add.h"

using namespace std;
namespace fs = filesystem;

#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define RESET   "\033[0m"

void addFile(const string& filename) {
    string repoPath = ".mygit";
    string indexFile = repoPath + "/index";

    // ❌ Do NOT initialize the repo again inside addFile()!
    if (!fs::exists(repoPath)) {
        cout << RED << "❌ Error: Repository not initialized. Run 'mygit init' first." << RESET << endl;
        return;
    }

    if (!fs::exists(filename)) {
        cout << RED << "❌ Error: File '" << filename << "' does not exist!" << RESET << endl;
        return;
    }

    // ✅ Append filename to staging area
    ofstream index(indexFile, ios::app);
    if (index.is_open()) {
        index << filename << endl;
        cout << GREEN << "✅ File '" << filename << "' added to staging area." << RESET << endl;
        index.close();
    } else {
        cout << RED << "❌ Error: Could not update index." << RESET << endl;
    }
}
