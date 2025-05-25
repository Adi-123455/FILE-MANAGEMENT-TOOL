
#include <iostream>   // For standard input/output operations
#include <fstream>    // For file handling operations
#include <string>     // For string operations
using namespace std;

// Functions to be applied
void createAndWriteFile();  // Creates a new file and writes content to it
void readFile();           // Reads and displays content from a file
void appendToFile();       // Appends content to an existing file
void displayMenu();        // Displays the main menu to the user

int main() {
    int choice;  // Stores user's menu choice

    // Main program loop
    do {
        displayMenu();  // Show the menu
        cout << "Enter your choice (1-4): ";
        cin >> choice;  // Get user's choice
        cin.ignore();   // Clear the input buffer to handle subsequent getline() calls

        // Process user's choice
        switch(choice) {
            case 1:
                createAndWriteFile();  // Create and write to a file
                break;
            case 2:
                readFile();  // Read from a file
                break;
            case 3:
                appendToFile();  // Append to a file
                break;
            case 4:
                cout << "Exiting program..." << endl;  // Exit message
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;  // Error for invalid input
        }
    } while(choice != 4);  // Continue until user chooses to exit

    return 0;  // Program ends successfully
}

// Displays the main menu options to the user
void displayMenu() {
    cout << "\nFile Handling Menu\n";
    cout << "1. Create and Write to a File\n";
    cout << "2. Read from a File\n";
    cout << "3. Append to a File\n";
    cout << "4. Exit\n";
}

 //Creates a new file and writes content to it
void createAndWriteFile() {
    string filename, content;

    // Get filename from user
    cout << "\nEnter the filename to create: ";
    getline(cin, filename);

    // Open file in output mode (creates new or overwrites existing)
    ofstream outFile(filename);

    // Check if file opened successfully
    if(!outFile) {
        cerr << "Error creating file!" << endl;
        return;
    }

    // Get content from user
    cout << "Enter content to write (press Enter on an empty line to finish):\n";

    // Read multiple lines until empty line is entered
    while(true) {
        string line;
        getline(cin, line);

        // Stop reading if empty line is entered
        if(line.empty()) {
            break;
        }

        // Write line to file
        outFile << line << endl;
    }

    // Close the file
    outFile.close();
    cout << "File created and written successfully!" << endl;
}

 //Reads and displays content from a file
void readFile() {
    string filename, line;

    // Get filename from user
    cout << "\nEnter the filename to read: ";
    getline(cin, filename);

    // Open file in input mode
    ifstream inFile(filename);

    // Check if file opened successfully
    if(!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    // Display file content with formatting
    cout << "\nFile content:\n";
    cout << "----------------------------------------\n";

    // Read and display each line
    while(getline(inFile, line)) {
        cout << line << endl;
    }

    cout << "----------------------------------------\n";
    inFile.close();  // Close the file
}
 //Appends content to an existing file
void appendToFile() {
    string filename, content;

    // Get filename from user
    cout << "\nEnter the filename to append to: ";
    getline(cin, filename);

    // Open file in append mode (creates if doesn't exist)
    ofstream outFile(filename, ios::app);

    // Check if file opened successfully
    if(!outFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    // Get content to append from user
    cout << "Enter content to append (press Enter on an empty line to finish):\n";

    // Read multiple lines until empty line is entered
    while(true) {
        string line;
        getline(cin, line);

        // Stop reading if empty line is entered
        if(line.empty()) {
            break;
        }

        // Append line to file
        outFile << line << endl;
    }

    // Close the file
    outFile.close();
    cout << "Content appended successfully!" << endl;
}
