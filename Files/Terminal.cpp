#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;
int main() {
	string cmd = "";
	chdir("Desktop");
	while (cmd != "exit") {
		cout << "Enter a command: ";
		getline(cin, cmd);
		system(cmd.c_str());
		if (cmd == "pwd") cout << "This directory cannot be changed\n";
		cout << endl;
	}
}