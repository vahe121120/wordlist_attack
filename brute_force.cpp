#include <iostream>
#include <fstream>

using namespace std;
using uint=unsigned int;

//bool strcompare(string dest, stringa)

int main()
{
	// input file stream
	// contains passwords wordlist
	ifstream commonPasswords;

	commonPasswords.open("Security_Vault/commonPasswords.txt", ios::in);

	if ( !commonPasswords.is_open() )
	{
		cout << "Unable to open the file" << endl;
	}
	
	// Second file contains generated password
	ifstream mypass;

	mypass.open("Security_Vault/generatedPassword.txt", ios::in);

	if ( !mypass.is_open() )
	{
		cout << "Unable to open the file." << endl;
	}

	string line;	// common passwords
	string word;	// generated password
	
	getline( mypass, word );

	cout << endl;
	cout << "Passwords\t\tStatus" << endl;

	bool status = 0;	// by default

	// getline( stream, buffer )
	while ( commonPasswords.good() )
	{
		getline( commonPasswords, line );
		if ( line.compare(word) )
		{
			cout << line << "\t\t" << status << endl;
		}
		else
		{
			status = 1;
			cout << "--------------------------------" << endl;
			cout << line << "\t\t" << status << endl;
			cout << "--------------------------------" << endl;
			break;
		}
		
	}

	if ( !status )
	{
		cout << "-----------------------------" << endl;
		cout << " No matching results!" << endl;
		cout << "-----------------------------" << endl;
	}

	cout << endl;
	commonPasswords.close();
	mypass.close();

	if ( commonPasswords.is_open() )
	{
		cout << "File didn't closed" << endl;
	}

	if ( mypass.is_open() )
	{
		cout << "Passwords file didn't closed." << endl;
	}

	return 0;
}
