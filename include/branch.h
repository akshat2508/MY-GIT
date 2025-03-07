#ifndef BRANCH_H
#define BRANCH_H

#include <string>

// Function to create a new branch
void createBranch(const std::string& branchName);

// Function to switch to a specific branch
void switchBranch(const std::string& branchName);

// Function to get the current branch name
std::string getCurrentBranch();

#endif // BRANCH_H
