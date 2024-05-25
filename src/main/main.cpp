#include <main.h>

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

	return 0;
}
