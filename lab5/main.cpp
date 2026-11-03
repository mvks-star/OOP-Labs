#include <iostream>
#include <limits>
#include "FileWorker.h"

using namespace std;

int main() {
    TextFileWorker textWorker;
    FileWorker* workerPtr = &textWorker;
    int choice = -1;
    string filename = "lab5_output.txt";

    do {
        cout << "\n1. Open file and write data" << endl;
        cout << "2. Read data from file" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";

        try {
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                choice = -1;
                throw invalid_argument("Invalid input format!");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
            case 1: {
                workerPtr->OpenFile(filename, ios::out | ios::trunc);

                cout << "\nEnter text to write:\n";
                string line;
                while (getline(cin, line)) {
                    if (line == "STOP") break;
                    workerPtr->WriteData(line);
                }

                workerPtr->CloseFile();
                cout << "[Success] Data successfully written to '" << filename << "'!\n";
                break;
            }
            case 2: {
                workerPtr->OpenFile(filename, ios::in);
                workerPtr->ReadData();
                break;
            }
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
            }
        }
        catch (const exception& e) {
            cout << "\n[EXCEPTION CAUGHT]: " << e.what() << endl;
        }
    } while (choice != 0);

    return 0;
}