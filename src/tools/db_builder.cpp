// db_builder.cpp

#include "db_builder.h"

const string FAIL = "";

string  dbBuilder()
{
    const string PATH = getenv("PATH");

    cout << "Enter the name of the db you want to create:" << endl;
    string dbName;
    cin >> dbName;

    const string FULL_PATH = PATH + "/" + dbName;
    const char* DB_PATH = FULL_PATH.c_str();

    // make directory for the db
    if (_mkdir(DB_PATH) == 1)
    {
        return FAIL; // error
    }

    // create db config file .FisherDB.txt
    const string filename = FULL_PATH + "/.FisherDB.txt";

    ofstream dbConfigFile(filename);
    if (!dbConfigFile)
    {
        return FAIL; // error
    }

    dbConfigFile << "Tables" << endl;

    while (true)
    {
        cout << "Do you want to create a table? (y/n)" << endl;
        string input;
        cin >> input;
        input = toLowerCase(input);

        if (input == "n" || input == "no" || input == "exit")
        {
            dbConfigFile << "endTables" << endl;
            dbConfigFile.close();
            break;
        }
        if (input != "y" && input != "yes")
        {
            cout << "Error: Please enter 'y' or 'n'." << endl;
        }

        cout << "Enter the name of the table:" << endl;
        std::string tableName;
        cin >> tableName;

        tableName = toLowerCase(tableName);

    std:
        string tableName2 = tableName;

        vector<string> forbiddenTableNames = {"tables", "endtables", "fisherdb"};
        if (find(forbiddenTableNames.begin(), forbiddenTableNames.end(), tableName2) != forbiddenTableNames.end())
        {
            cout << "Error: Table name is forbidden, try again." << endl;
            continue; // error
        }

        const string tablePath = FULL_PATH + "/" + tableName + ".txt"; // NOLINT(*-inefficient-string-concatenation)

        if (const ofstream outfile(tablePath); !outfile)
        {
            cout << "Error: Could not create table, try again." << endl;
            continue; // error
        }

        dbConfigFile << tableName << endl;
    }

    cout << "Database created successfully." << endl;
    cout << "Opening the database..." << endl;

    return filename;
}
