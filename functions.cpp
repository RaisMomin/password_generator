#include "functions.h"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

bool YesNo() {
    string input;
    cin >> input;
    if (input == "y" || input == "yes") {
        return true;
    }
    else {
        return false;
    }
}

std::string GetSymbols() {
    string input;
    string symbols = "!@#$%^&*~?";
    string options = "";
    bool valid;
    cout << endl << "What symbols would you like to include?" << endl;
    do {
        valid = true;
        cout << "Options are !@#$%^&*~? (or enter 'all'): ";
        cin >> input;
        if (input == "all") {
            options.append(symbols);
            break;
        }
        for (unsigned int i = 0; i < input.size(); ++i) {
            if (symbols.find(input.at(i)) != string::npos) {
                options.push_back(input.at(i));
            }
            else {
                cout << endl << "Ignored '" << input.at(i) << "', not a valid symbol." << endl;
            }
        }
        if (options.size() == 0) {
            cout << endl << "Invalid symbols, please reenter: ";
            valid = false;
        }
    } while (!valid);

    return options;
}
