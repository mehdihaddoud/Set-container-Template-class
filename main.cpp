#include "Set.h"
#include <fstream>

int main() {

    ifstream inputFile;

    inputFile.open("/Users/mehdihaddoud/Documents/C-CPP/cpp/template/Set_template/input.txt");

    Set<string> x = Set<string>();

    inputFile >> x;

    cout << x <<'\n';

    string input;

    while (!cin.fail())
    {
        cout << "Add input : \n";

        cin >> input;

        cout << "Adding : " << input << '\n';

        x.add(input);

        cout << x << '\n';
    }

    cin.ignore();

    cin.clear();

    inputFile.close();

    return 0;
}
