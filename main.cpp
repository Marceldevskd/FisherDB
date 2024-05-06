#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

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

		while (getline(ss, token, ',')) {
			tokens.push_back(token);
		}

		if (query == tokens[0]) {
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