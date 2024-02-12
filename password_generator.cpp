#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <fstream>

using namespace std;
using uint=unsigned int;

void file_existence_checker(ofstream& file)
{
        if ( !file.is_open() )
        {
                cout << "Unable to open/create the file." << endl;
                throw;
        }
}

int main()
{
        const char lowCase[] = "abcdefghijklmnopqrstuvwxyz";
        const char uppCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const char numbers[] = "0123456789";
        const char spec_sym[] = "!@#$^&?[]~|*";
        uint charactersCount = 4;

        // Sizes of our Arrays
        const uint low_size = sizeof( lowCase ) - 1;
        const uint upp_size = sizeof( uppCase ) - 1;
        const uint num_size = sizeof( numbers ) - 1;
        const uint spec_size = sizeof( spec_sym ) - 1;

        // User input size for passwords length
        size_t s{};
        do
        {
                cout << "Enter password's size [minimum 12 characters]: ";
                cin >> s;
        } while ( s < 12 );


        const size_t size = s;
        char passwd[size];

        srand( time(NULL) * getpid() );

        // For choosing index of chosen array
        int index{};

        // For choosing arrays lowercase, uppercase...
        int chooseCharGroup{};

	 for (int i = 0; i < size; ++i)
        {
                chooseCharGroup = rand() % charactersCount;

                switch( chooseCharGroup )
                {
                        case 0:
                                index = rand() % low_size;
                                passwd[i] = lowCase[index];
                                break;
                        case 1:
                                index = rand() % upp_size;
                                passwd[i] = uppCase[index];
                                break;
                        case 2:
                                index = rand() % num_size;
                                passwd[i] = numbers[index];
                                break;
                        case 3:
                                index = rand() % spec_size;
                                passwd[i] = spec_sym[index];
                                break;
                }
        }

        // output stream file
        ofstream file;

        // where to save generated password
        file.open("generatedPassword.txt");

        // Copying generated password to our file
        for (int i = 0; i < size; ++i)
        {
                file << passwd[i];
        }

        file.close();

        return 0;
}
