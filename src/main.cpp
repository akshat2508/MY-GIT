#include <iostream>
#include <string>
#include "../include/init.h"
#include "../include/add.h"
#include "../include/status.h"
#include "../include/commit.h"
#include "../include/log.h"
#include "../include/utils.h"
#include "../include/checkout.h"
using namespace std;

#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"


int main(int argc, char* argv[]) {
    cout << YELLOW << "🌟 Welcome to MyGit!" << RESET << endl;

    if (argc < 2) {
        cout << "❌ Error: No command provided!" << endl;
        return 1;
    }

    string command = argv[1];

    if (command == "init") {
        cout << getCurrentTimestamp() << " Initializing repository..." << endl;
        initializeRepository();
    } 
    else if (command == "add") {
        if (argc < 3) {
            cout << "❌ Error: No file specified for adding!" << endl;
            return 1;
        }
        string filename = argv[2];
        addFile(filename);
    } 
    else if (command == "status") {
        handleStatus();
    }
    else if (command == "commit") {
        if (argc < 3) {
            cout << "❌ Error: No commit message provided!" << endl;
            return 1;
        }
        string commitMessage = argv[2];
        handleCommit(commitMessage);
    }
    else if (command == "log") {
        handleLog(); // Handling the git log feature
    }

    else if (command == "checkout" && argc == 4)
    {
        handleCheckout(argv[2],argv[3]);
    }
    else {
        cout << RED<<"❌ Error: Unknown command '" << command << "'!" <<RESET<< endl;
    }

    return 0;
}
