#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;
using uint=unsigned int;

void file_existence_check(ifstream& file)
{
        if ( !file.is_open() )
        {
                cout << "Unable to open the file." << endl;
                throw;
        }
}

void file_closed(ifstream& file)
{
        if ( file.is_open() )
        {
                cout << "Unable to close the file." << endl;
                cout << "If you wouldn't see \"File closed!\" message from 2-3 seconds interrupt the process!" << endl;
                while ( file.is_open() )
                {
                        file.close();
                }
                cout << "File closed!" << endl;
        }
}

int main()
{
        // input file stream
        // contains passwords wordlist
        ifstream commonPasswords;
        commonPasswords.open("commonPasswords.txt", ios::in);

	file_existence_check(commonPasswords);

        // contains generated password
        ifstream mypass;
        mypass.open("generatedPassword.txt", ios::in);

	file_existence_check(mypass);

        string line;    // common passwords
        string word;    // generated password

        getline( mypass, word );

        cout << endl;
        cout << "Passwords" << endl;
        cout << endl;
        cout << "----------------------" << endl;

        bool status = false;    // by default
        uint compare_count{};

        auto old = steady_clock::now();

	while ( commonPasswords.good() )
        {
                // getline ( stream, buffer )
                getline( commonPasswords, line );
                if ( line.compare(word) )
                {
                        cout << line << endl;
                        compare_count++;
                }
                else
                {
                        auto dur = steady_clock::now() - old;
                        status = true;
                        cout << "--------------------------------" << endl;
                        cout << line << "\t\t" << status << endl;
                        cout << "--------------------------------" << endl;
                        compare_count++;

                        cout << "Spent time: " << duration_cast<seconds>(dur).count() << endl;
                        cout << "Compare count: " << compare_count << endl;

                        break;
                }

        }

        auto dur = steady_clock::now() - old;

        if ( !status )
        {
                cout << "-----------------------------" << endl;
                cout << " No matching results!" << endl;
                cout << "-----------------------------" << endl;
                cout << endl;
                cout << "Spent time: " << duration_cast<seconds>(dur).count() << endl;
        }

        cout << endl;
        commonPasswords.close();
        mypass.close();

        // Checking file closing
        file_closed(commonPasswords);
	file_closed(mypass);

        return 0;
}
