// db_builder.cpp

#include "db_builder.h"

const string FAIL = "";

// Makes a directory for the db and creates a config file and the table files for the db in the db folder
string dbBuilder()
{
    ofstream dbConfigFile;

    string fullPath;
    string configFilename;

    const string PATH = getenv("PATH");
    while (true)
    {
        cout << "Enter the name of the db you want to create:" << endl;
        string dbName;
        cin >> dbName;

        fullPath = PATH + "/" + dbName;
        const char* DB_PATH = fullPath.c_str();

        // make directory for the db
        if (_mkdir(DB_PATH) == 1)
        {
            cout << "The database name is invalid try again." << endl;
            continue; // error
        }


    
        // create db config file .FisherDB.txt
        configFilename = fullPath + "/.FisherDB.txt";

        dbConfigFile.open(configFilename);
        if (!dbConfigFile)
        {
            cout << "Failed to make the database config file." << endl;
            continue; // error
        }
        break;
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

        string tableName2 = tableName;

        vector<string> forbiddenTableNames = {"tables", "endtables", "fisherdb"};
        if (find(forbiddenTableNames.begin(), forbiddenTableNames.end(), tableName2) != forbiddenTableNames.end())
        {
            cout << "Error: Table name is forbidden, try again." << endl;
            continue; // error
        }
        const string tablePath = fullPath + "/" + tableName + ".txt"; // NOLINT(*-inefficient-string-concatenation)

        if (const ofstream outfile(tablePath); !outfile)
        {
            cout << "Error: Could not create table, try again." << endl;
            continue; // error
        }

        dbConfigFile << tableName << endl;
        forbiddenTableNames.push_back(tableName);
    }

    cout << "Database created successfully." << endl;
    cout << "Opening the database..." << endl;

    return configFilename;
}
