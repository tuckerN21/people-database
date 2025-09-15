#include <iostream>
#include <fstream>
#include "table.h"
using namespace std;

// Function to get user choice
int getUserChoice() {
	// Declare variable to store user choice, prompt for input, and store input
	int choice;
	cout << "Enter choice: ";
	cin >> choice;
	cout << endl;

	// Check if input is valid
	if (choice < 1 || choice > 4) {
		cout << "Invalid choice. Please try again." << endl;
		return getUserChoice();
	}

	// Return user choice
	return choice;
}

// Function to print menu to console
void printMenu() {
	cout << "\t1. Search by first name" << endl;
	cout << "\t2. Search by last name" << endl;
	cout << "\t3. Search using a range of birth years" << endl;
	cout << "\t4. Exit" << endl << endl;
}

// Main function
int main() {
    cout << "Welcome to the Computer Scientists Database!" << endl << endl;

    // Create table and read from "people.txt"
    Table scientistTable;
    scientistTable.read("people.txt");

    // Prompt user for choice
    cout << "Please select one of the following options:" << endl;
    printMenu();
    int userChoice = getUserChoice();

    // While loop to keep program running as long as the user doesn't enter 4
    while (userChoice != 4) {
    // Switch statement for different user choices
        switch (userChoice) {
            case 1: { // Search by first name
                string firstName;
                cout << "Please enter a first name (Be sure to capitalize the first letter!): ";
                cin >> firstName;
                cout << endl;
                scientistTable.searchFirstName(firstName);
                break;
            }
            case 2: { // Search by last name
                string lastName;
                cout << "Please enter a last name: (Be sure to capitalize the first letter!): ";
                cin >> lastName;
                cout << endl;
                scientistTable.searchLastName(lastName);
                break;
            }
            case 3: { // Search by range of birth years
                int startYear, endYear;
                cout << "Please enter the starting birth year: ";
                cin >> startYear;
                cout << "Please enter the ending birth year: ";
                cin >> endYear;
                cout << endl;
                scientistTable.searchYear(startYear, endYear);
                break;
            }
        }

        // Prompt user for next choice
        cout << "What would you like to do next?" << endl;
        printMenu();
        userChoice = getUserChoice();
    }

    // Thank user and end program
    cout << "Thank you for using the Computer Scientists Database. Goodbye!" << endl;
    return 0;
}
