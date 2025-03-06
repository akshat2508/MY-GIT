#include<iostream>
#include<fstream>
#include<filesystem>
#include<ctime>
#include<set>

#include<string>
#include "../include/utils.h"
using namespace std;
namespace fs = filesystem;

#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define RESET   "\033[0m"

const string MYGIT_DIR = ".mygit";
const string COMMIT_DIR = ".mygit/commits";
const string INDEX_FILE = ".mygit/index";


void handleCommit(const string& message) {
    if (!fs::exists(MYGIT_DIR)) {
        cout << RED << "🚨 No repository found! Run 'mygit init' first." << RESET << endl;
        return;
    }

    fs::create_directories(COMMIT_DIR);

    string timestamp = getCurrentTimestamp();
    string commitFile = COMMIT_DIR + "/commit_" + to_string(time(0)) + ".txt";

    ofstream commit(commitFile);
    if (!commit.is_open()) {
        cout << RED << "❌ Error: Failed to create commit file!" << RESET << endl;
        return;
    }

    commit << "Commit Timestamp: " << timestamp << endl;
    commit << "Message: " << message << endl;
    commit << "Files and Contents:" << endl;

    ifstream indexFile(INDEX_FILE);
    string file;
    while (getline(indexFile, file)) {
        commit << "📑 File: " << file << endl;

        ifstream sourceFile(file);
        if (sourceFile.is_open()) {
            commit << "-------------------------" << endl;
            string line;
            while (getline(sourceFile, line)) {
                commit << line << endl;  // Store the actual file content
            }
            commit << "-------------------------" << endl;
            sourceFile.close();
        } else {
            commit << "❌ Error: Could not read file at commit time." << endl;
        }
    }

    indexFile.close();
    commit.close();
    cout << GREEN << " ✅ Commit Successful! Saved as " << commitFile << RESET << endl;
}
