#include "functions.h"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string options;
    unsigned int length;
    string password;
    int index;

    cout << "Welcome to password generator!" << endl;
    cout << "——————————————————————————————" << endl;
    
    do {
        do {
            options = "";
            cout << "Include lowercase letters? (y/n): ";
            if (YesNo()) {
                options.append(lower);
            }
            cout << "Include uppercase letters? (y/n): ";
            if (YesNo()) {
                options.append(upper);
            }
            cout << "Include numbers? (y/n): ";
            if (YesNo()) {
                options.append(numbers);
            }
            cout << "Include symbols? (y/n): ";
            if (YesNo()) {
                options.append(GetSymbols());
            }
            if (options == "") {
                cout << "Must agree to include something." << endl;
            }
        } while (options == "");

        cout << endl << "Enter password length: ";
        cin >> length;
        while (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid, enter password length as an integer: ";
            cin >> length;
        }

        password = "";
        for (unsigned int i = 0; i < length; ++i) {
            index = rand() % (options.size());
            password.push_back(options.at(index));
        }

        cout << endl << "Your randomly generated password is " << password << "." << endl;

        cout << endl << "Generate another password? (y/n): ";
    } while (YesNo());

    cout << endl << "Thanks for using password generator!" << endl;

    return 0;
}