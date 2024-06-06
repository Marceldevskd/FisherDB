# FisherDB

A relation database runner in C++

## Short Description

FisherDB is a SQL-based database system with normal query's but with git-like opening and closing of the database.

### Example:

1. The client connects with FisherDB.
2. Logs in and connects to the database the client wants.
3. The client gets send a copy of the full database.
4. The client can run query's on its own machine and commit the changes later or can run query's on the database server.

## Table of Contents

1. [Problem It Solves](#problem-it-solves)
2. [What Makes My Project Special](#what-makes-my-project-special)
3. [How to Start the Project](#how-to-start-the-project)
4. [Usage](#usage)
5. [Contributing](#contributing)
6. [Important Notes](#important-notes)
7. [License](#license)

## Problem It Solves

Constantly having to make requests to the database server can be too much for lower-end devices or larger infrastructures with lots of load on the database server, FisherDB can solve that while holding the possibilities to use it as a normal database like MySQL.

## What Makes My Project Special

- Being able to run query's on the database from your own device while not having a constant connection to the database.
- The ability to have non-relational JSON objects stored in columns of the database tables.

## How to Start the Project

### Prerequisites

A C++ compiler

### Installation

Step-by-step instructions on how to set up your project. This should include:
1. Cloning the repository
   ```sh
   git clone https://www.github.com/Marceldevskd/FisherDB.git
   ```
2. Navigating to the project directory
   ```sh
   cd FisherDB
   ```

### Building the Project

Instructions for compiling the project. This may include:
```sh
g++ -o FisherDB main.cpp
```
or using a build system like CMake:
```sh
mkdir build
cd build
cmake ..
make
```

## Usage

Will be added in the future

## Important Notes

- Every file should be started with the filename like this:
  ```cpp
  // main.cpp
  #include <main.h>
  ...
  ```
  or
  ```cpp
  // main.h
  #include <string>
  ...
  ```

- Naming conventions:
    - Filenames: snake_case
    - Variables: camelCase
    - Objects or Classes: PascalCase
    - Functions: camelCase
    - Constants: UPPER_CASE
    - Macros or Preprocessor Directives: UPPER_CASE

- Comments:
    - Describe each function before you define it
    - Describe loops
    - Describe the function of a variable or constant if needed

## License

This project is licensed under the BSD License. See the [LICENSE](LICENSE) file for details.