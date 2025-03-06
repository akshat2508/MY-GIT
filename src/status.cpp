#include<iostream>
#include<filesystem>
#include<fstream>
#include<set>

using namespace std;
namespace fs = filesystem;

#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

const string MYGIT_DIR = ".mygit";
const string INDEX_FILE = ".mygit/index";

set<string> getTrackedFiles()
{
    set<string> trackedFiles;
    ifstream indexFile(INDEX_FILE);

    if(indexFile.is_open())
    {
        string file;
        while(getline(indexFile,file))
        {
            trackedFiles.insert(file);
        }
        indexFile.close();
    }
    return trackedFiles;
}


void checkStatus()
{
    if(!fs::exists(MYGIT_DIR))
    {
        cout << RED << "🚨 No repository found! Run 'mygit init' first." << RESET << endl;
        return;
    }
    
    set<string> trackedFiles = getTrackedFiles();
    set<string> untrackedFiles, modifiedFiles;

    for (const auto &entry : fs::directory_iterator(".")) {
        if (entry.is_directory() || entry.path().string() == "./mygit") continue;

        string fileName = entry.path().filename().string();
        
        if (trackedFiles.find(fileName) != trackedFiles.end()) {
            ifstream file(entry.path());
            if (!file.is_open()) continue;

            // Check if file contents changed
            string fileContents((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            file.close();

            ifstream indexFile(INDEX_FILE);
            string line;
            bool modified = false;

            while (getline(indexFile, line)) {
                if (line == fileName) {
                    modified = true;
                    break;
                }
            }
            indexFile.close();

            if (modified) modifiedFiles.insert(fileName);
        } else {
            untrackedFiles.insert(fileName);
        }
    }

    cout << CYAN << "🤩 MyGit Status  🌟" << RESET << endl<<endl;

    if(!trackedFiles.empty())
    {
        cout << GREEN << "✅ Tracked Files: " << RESET << endl;
        for(const auto &file: trackedFiles)
        {
            cout << "  📃 " << GREEN << file << RESET << endl<<endl;;
        }
    }

    if(!untrackedFiles.empty())
    {
        cout << YELLOW << "😵 Untracked Files: " << RESET << endl;
        for(const auto &file:untrackedFiles)
        {
            cout << "  ⛔️ " << RED << file << RESET << endl<<endl;
        }
    }

    if(trackedFiles.empty() && modifiedFiles.empty() && untrackedFiles.empty())
    {
        cout << GREEN << "🤗 Everything is up to date!" << RESET << endl;
    }

}

void handleStatus()
{
    checkStatus();
}
