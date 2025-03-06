# MyGit - A Lightweight Version Control System

MyGit is a custom-built version control system written in C++. It provides essential features like commit tracking, branching, and file versioning through a simple command-line interface.

## Features
- **Initialize Repository (`init`)**: Creates a `.mygit/` directory to track changes.
- **Add Files (`add`)**: Stages files for commit.
- **Commit Changes (`commit`)**: Saves a snapshot of tracked files.
- **View Commit History (`log`)**: Displays previous commits.
- **Check Repository Status (`status`)**: Shows modified, staged, and untracked files.
- **Checkout Commit (`checkout`)**: Switches to a previous commit state.

## Directory Structure
```
akshat2508-my-git/
├── README.md
├── Makefile
├── include/
│   ├── add.h
│   ├── checkout.h
│   ├── commit.h
│   ├── init.h
│   ├── log.h
│   ├── status.h
│   └── utils.h
├── src/
│   ├── add.cpp
│   ├── checkout.cpp
│   ├── commit.cpp
│   ├── init.cpp
│   ├── log.cpp
│   ├── main.cpp
│   ├── status.cpp
│   └── utils.cpp
└── .mygit/
    ├── HEAD
    ├── index
    ├── logs
    ├── commits/
        ├── commit_<timestamp>.txt
```

## How to Use
1. **Initialize MyGit**
   ```sh
   ./mygit init
   ```
2. **Add Files**
   ```sh
   ./mygit add file1.txt file2.txt
   ```
3. **Commit Changes**
   ```sh
   ./mygit commit -m "Initial commit"
   ```
4. **View Commit History**
   ```sh
   ./mygit log
   ```
5. **Check Repository Status**
   ```sh
   ./mygit status
   ```
6. **Checkout a Commit**
   ```sh
   ./mygit checkout <commit_id>
   ```

## Compilation
Use the provided Makefile to compile the project:
```sh
make
```

## Future Enhancements
- Implement branching and merging.
- Optimize storage for efficient tracking.
- Add remote repository support.

---
🚀 Developed by Akshat2508
