// DBOpener.cpp
#include "db_opener.h"


// opens a db file and checks if all the tables exist, returns a DBDataStruct with the tables and an error code
DBDataStruct dbOpener(const string& dbPath)
{
	DBDataStruct data;
	data.error = 0;

	if (ifstream file(dbPath); file.is_open())
	{
		string line;
		getline(file, line);
		if (line != "Tables")
		{
			data.error = 1;
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

		for (const string& table : data.tables)
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
