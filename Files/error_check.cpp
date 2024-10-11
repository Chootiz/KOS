#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;
int main() {
	char c = '0';
	string file = "", file2;
	while (c != '4') {
		system("clear");
		cout << "-----------------[K-OS]-----------------\n\n";
		cout << "1. Create File\n2. Open File\n3. Compile and Run\n4. Exit\n";
		cin >> c;
		switch (c) {
		case '1':
			cout << "Enter file name (without extension) to create: ";
			cin >> file;
			file = "touch ../Desktop/" + file + ".cpp";
			system(file.c_str());
			break;
		case '2':
			cout << "Enter file name (without extension) to open: ";
			cin >> file;
			file = "nano ../Desktop/" + file + ".cpp";
			system(file.c_str());
			break;
		case '3':
			cout << "Enter file name (without extension): ";
			cin >> file;
			file2 = "g++ " + file + ".txt -o " + file;
			system(file2);
			file2 = "g++ " + file + ".txt -o " + file + "> error_check.cpp";
			system(file2);
			ifstream checker("error_check.cpp");
			checker >> file2;
			if (file2 != "") {
				cout << "There are errors in your code, do you wish to run a previous version? (y/n)";
				cin >> c;
				if (c == 'Y' || c == 'y') {

				}
				else continue;
			}
			file2 = "./" + file;
			break;
		}
	}
}