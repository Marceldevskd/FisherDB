// main.cpp
#include "main.h"


int main()
{
	_putenv("PATH=C:/Users/Marcel/Documents/GitHub/FisherDB/db");

	const string DB_PATH = getenv("PATH");

	cout << "Welcome to FisherDB!" << endl;

	// select mode: "open" or "create"
	while (true)
	{
		cout << "Do you want to open ('o' / 'open') or create('c' / 'create') a db?" << endl;
		string modeInput;
		cin >> modeInput;
		modeInput = toLowerCase(modeInput);
		string mode;

		if (modeInput == "open" || modeInput == "o")
		{
			mode = "open";
			cout << "Which db do you want to open?" << endl;
			while (true)
			{
				string dbName;
				cin >> dbName;
				if (dbName == "exit")
				{
					cout << endl
						<< "Exiting..." << endl;
					return EXIT_SUCCESS;
				}
				else
				{
					cout << "Opening db " << dbName << "..." << endl;
					dbOpener(DB_PATH + "/" + dbName + "/" + ".fisherDB.txt");
					break;
				}
			}
			continue;
		}
		if (modeInput == "create" || modeInput == "c")
		{
			mode = "create";
			cout << "Creating a new db..." << endl;

			string dbPath = dbBuilder();

			if (dbPath.empty())
			{
				cout << "Error: Could not create db." << endl;
				return EXIT_FAILURE;
			}

			dbOpener(dbPath);
			continue;
		}
		if (modeInput == "exit")
		{
			cout << endl << "Exiting..." << endl;
			return EXIT_SUCCESS;
		}
		else
		{
			cout << "Error: Please enter 'open' or 'create'." << endl;
		}
	}
	return EXIT_SUCCESS;
}
