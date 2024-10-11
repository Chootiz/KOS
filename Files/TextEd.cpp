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
		cout << "1. Create File\n2. Open File\n3. Copy\n4. Exit\n\nYour Choice: ";
		cin >> c;
		switch (c) {
			case '1':
				cout << "Enter file name (without extension) to create: ";
				cin >> file;
				file = "touch Desktop/" + file + ".txt";
				system(file.c_str());
				break;
			case '2':
				cout << "Enter file name (without extension) to open: ";
				cin >> file;
				file = "nano Desktop/" + file + ".txt";
				system(file.c_str());
				break;
			case '3':
				cout << "Enter source file name (without extension): ";
				cin >> file;
				cout << "Enter destination file name (without extension): ";
				cin >> file2;
				file = "cat Desktop/" + file + ".txt > Desktop/" + file2 + ".txt";
				system(file.c_str());
				break;
		}
	}
}
