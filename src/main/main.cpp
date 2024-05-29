// main.cpp
#include "main.h"

const string DB_PATH = "C:/Users/Marcel/Documents/GitHub/FisherDB/db";

int main()
{
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
					return 0;
				}
				else
				{
					cout << "Opening db " << dbName << "..." << endl;
					dbOpener(DB_PATH + "/" + dbName + "/" +".fisherDB.txt");
					break;
				}
			}
			break;
		}
		else if (modeInput == "exit")
		{
			cout << endl << "Exiting..." << endl;
			return 0;
		}
		else
		{
			cout << "Error: Please enter 'open' or 'create'." << endl;
		}
	}
	return 0;
}
