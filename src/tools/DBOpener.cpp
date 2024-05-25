#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct DataObject
{
	string dbPath;
	vector<string> tables;
};

DataObject DBOpener(string dbPath)
{
	DataObject data;
	ifstream file(dbPath);
	if (file.is_open())
	{
		string line;
		getline(file, line);
		if (line != "Tables")
		{
			return data;
		}

		while (getline(file, line))
		{
			if (line == "endTables")
			{
				break;
			}
			data.tables.push_back(line);
		}

		file.close();

		for (const string table : data.tables)
		{
			cout << table << endl;
		}

		return data;
	}
	else
	{
		cout << "Error: Could not open db" << endl;
		return data;
	}
	
}
