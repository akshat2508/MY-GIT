#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

using namespace std;
namespace fs = filesystem;

#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define RESET   "\033[0m"

const string COMMIT_DIR = ".mygit/commits";

void handleCheckout(const string& commitFile, const string& fileName) {
    if (!fs::exists(commitFile)) {
        cout << RED << "❌ Error: Commit file not found!" << RESET << endl;
        return;
    }

    ifstream commit(commitFile);
    if (!commit.is_open()) {
        cout << RED << "❌ Error: Unable to open commit file!" << RESET << endl;
        return;
    }

    string line;
    bool fileFound = false;
    bool readingFile = false;
    vector<string> fileContent;

    while (getline(commit, line)) {
        if (line.find("📑 File: " + fileName) != string::npos) {
            fileFound = true;
            readingFile = true;
            continue;
        }

        if (readingFile) {
            if (line == "-------------------------") {
                break;
            }
            fileContent.push_back(line);
        }
    }

    commit.close();

    if (!fileFound) {
        cout << RED << "❌ Error: File not found in the specified commit!" << RESET << endl;
        return;
    }

    // Restore file content
    ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        cout << RED << "❌ Error: Unable to restore file!" << RESET << endl;
        return;
    }

    for (const string& content : fileContent) {
        outputFile << content << endl;
    }

    outputFile.close();
    cout << GREEN << "✅ File '" << fileName << "' has been restored from commit " << commitFile << RESET << endl;
}
