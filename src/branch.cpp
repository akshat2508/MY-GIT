#include <iostream>
#include <fstream>
#include <string>
#include "../include/branch.h"
#include "../include/utils.h"

using namespace std;

// Function to create a new branch
void createBranch(const std::string& branchName) {
    string branchDir = ".mygit/branches/" + branchName;
    
    // Check if branch already exists
    ifstream branchCheck(branchDir);
    if (branchCheck.good()) {
        cout << "❌ Error: Branch '" << branchName << "' already exists!" << endl;
        return;
    }

    // Create a new branch by pointing to the current HEAD commit
    ofstream newBranch(branchDir);
    if (!newBranch) {
        cout << "❌ Error: Failed to create the branch!" << endl;
        return;
    }

    // Get the current commit ID from HEAD and write it to the branch file
    ifstream headFile(".mygit/HEAD");
    string currentCommit;
    getline(headFile, currentCommit);
    newBranch << currentCommit;
    cout << "🌱 Branch '" << branchName << "' created successfully!" << endl;
}

// Function to switch to a specific branch
void switchBranch(const std::string& branchName) {
    string branchDir = ".mygit/branches/" + branchName;
    
    // Check if the branch exists
    ifstream branchFile(branchDir);
    if (!branchFile.good()) {
        cout << "❌ Error: Branch '" << branchName << "' does not exist!" << endl;
        return;
    }

    // Get the commit ID associated with the branch
    string branchCommit;
    getline(branchFile, branchCommit);

    // Update HEAD to point to the new branch's commit
    ofstream headFile(".mygit/HEAD");
    headFile << branchCommit;

    cout << "🔄 Switched to branch '" << branchName << "'." << endl;
}

// Function to get the current branch
std::string getCurrentBranch() {
    ifstream headFile(".mygit/HEAD");
    string currentCommit;
    getline(headFile, currentCommit);

    // Find the branch that corresponds to the current commit
    for (const auto& entry : std::filesystem::directory_iterator(".mygit/branches")) {
        ifstream branchFile(entry.path());
        string branchCommit;
        getline(branchFile, branchCommit);
        if (branchCommit == currentCommit) {
            return entry.path().filename().string();
        }
    }
    return "No branch";  // In case of a detached HEAD state
}
