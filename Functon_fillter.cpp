#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// File output
ofstream fileOutput("Out.txt");
// Variable return of Function
string returnValue = "void ";

int main(){
	// Clear output file
	fileOutput.clear();
	string input;
	// File input
	cout << "Input file location: ";
	cin >> input;
	ifstream fileInput(input);

    if (fileInput.fail())
	{
		cout << "Failed to open this file!" << endl;
		return -1;
	}
	while (!fileInput.eof())
	{
        string line;
        getline(fileInput, line);

		if ((line.find(returnValue) != -1) && (line.find('(') != -1)){
			if (line.find(')') == -1){
				fileOutput << line << endl;
				while (line.find(")") == -1){
					getline(fileInput, line);
				}
			}
			// Delete redundant
			if(line.find("{") != -1){
				line.erase(line.begin() + line.find("{"));
			}

			fileOutput << line << endl;
			fileOutput << endl;
		}
	}

	// Close file after used
	fileInput.close();
	fileOutput.close();
	cout << "Done" << endl;
    return 0;
}
