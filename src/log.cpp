#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>

using namespace std;
namespace fs = filesystem;

#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define RESET   "\033[0m"

const string COMMIT_DIR = ".mygit/commits"; // Folder where commits are stored
void printCommitLog() {
    cout << YELLOW << "🌟 MyGit Log 🌟" << RESET << endl;

    if (!fs::exists(COMMIT_DIR)) {
        cout << "❌ No commits found!" << endl;
        return;
    }

    vector<string> commitFiles;
    for (const auto& entry : fs::directory_iterator(COMMIT_DIR)) {
        if (entry.is_regular_file()) {
            commitFiles.push_back(entry.path().string());
        }
    }

    if (commitFiles.empty()) {
        cout << "❌ No commits found!" << endl;
        return;
    }

    // Sorting commits in descending order (newest first)
    sort(commitFiles.rbegin(), commitFiles.rend());

    for (const string& file : commitFiles) {
        ifstream commitFile(file);
        if (commitFile.is_open()) {
            cout << GREEN << "📜 Commit: " << file << RESET << endl;
            string line;
            while (getline(commitFile, line)) {
                cout << "   " << line << endl;
            }
            commitFile.close();
            cout << "------------------------" << endl;
        } else {
            cout << RED << "❌ Error reading " << file << RESET << endl;
        }
    }
}

void handleLog() {
    printCommitLog();
}
