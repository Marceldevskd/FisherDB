#include <main.h>

using namespace std;


void runQuery(string query)
{
	cout << "Running query: " << query << endl;

	string filename = "data.txt";
	ifstream fileRead;

	fileRead.open(filename.c_str());
	if (!fileRead.is_open())
	{
		cout << "Error: Could not open file " << filename << endl;
		return;
	}

	string rowContent;

	while (true)
	{
		getline(fileRead, rowContent);

		vector<string> tokens;
		stringstream ss(rowContent);
		string token;

		while (getline(ss, token, ','))
		{
			tokens.push_back(token);
		}

		if (query == tokens[0])
		{
			cout << tokens[0] << tokens[1] << endl;
			break;
		}

		if (fileRead.eof())
		{
			cout << "Error: Could not find row " << query << endl;
			break;
		}
	}
}

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

		if (modeInput == "open" || modeInput == "o")
		{
			break;
		}
		else if (modeInput == "create" || modeInput == "c")
		{
			break;
		}
		else if (modeInput == "exit")
		{
			cout << endl
				  << "Exiting..." << endl;
			return 0;
		}
		else
		{
			cout << "Error: Please enter 'open' or 'create'." << endl;
		}
	}

	// logic for selecting which DB will open
	while (true)
	{
		// ask the user which db to open
		cout << "Which db do you want to open?" << endl;

		// get the db name from the user
		string dbName;
		cin >> dbName;

		// check if the user has given an input
		if (dbName.empty())
		{
			cout << "Error: Please give an input. " << endl;
			continue;
		}

		// check if the user wants to exit
		if (dbName == "exit")
		{
			cout << endl
				  << "Exiting..." << endl;
			return 0;
		}

		string filename = dbName + "/.fisherDB.txt";
		ifstream fileRead;

		fileRead.open(filename.c_str());
		if (!fileRead.is_open())
		{
			cout << "Error: The db" << dbName << "is not found." << endl;
			continue;
		}
	}

	while (true)
	{
		cout << "Query format: row " << endl;
		cout << "Enter your query: ";
		string query;
		cin >> query;

		if (query == "exit")
		{
			cout << endl
				  << "Exiting..." << endl;
			break;
		}

		runQuery(query);
	}
	return 0;
}

// make structure of a .fisherDB.txt file
// build a structure in which way the queries will be run
