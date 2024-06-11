// db_builder.cpp

#include "db_builder.h"

bool dbBuilder()
{
    const string PATH = getenv("PATH");

    cout << "Enter the name of the db you want to create:" << endl;
    string dbName;
    cin >> dbName;

    const string FULL_PATH = PATH + "/" + dbName;
    const char* DB_PATH = FULL_PATH.c_str();

    // make directory for the db
    if (_mkdir(DB_PATH) == 1) {
        return false; // error
    }

    // create db config file .FisherDB.txt
    const string filename = FULL_PATH + "/.FisherDB.txt";

    if (const ofstream dbConfigFile(filename); !dbConfigFile) {
        return false; // error
    }

    dbConfigFile << "Tables" << endl;

    while (true) {
        cout << "Do you want to create a table? (y/n)" << endl;
        string input;
        cin >> input;
        input = toLowerCase(input);

        if (input == "n" || input == "no") {
            dbConfigFile << "endTables" << endl;
            dbConfigFile.close();
            break;
        }
        else if (input == "y" || input == "yes") {
            cout << "Enter the name of the table:" << endl;
            string tableName;
            cin >> tableName;

            const string tablePath = FULL_PATH + "/" + tableName + ".txt";

            if (const ofstream outfile(tablePath); !outfile) {
                cout << "Error: Could not create table, try again." << endl;
                continue; // error
            }

            dbConfigfile << tableName << endl;

        }
        else {
            cout << "Error: Please enter 'y' or 'n'." << endl;
        }
    }



    return true;
}