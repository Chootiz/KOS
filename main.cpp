#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <sys/wait.h>
using namespace std;

struct PCB {
	pid_t pid;
	bool isActive;
};

void PrintHeader();
int memoryMB = 3000;
int av_cores = 8;
int kernel_bit = 0;
int main() {
	system("clear");
	cout << endl << endl << endl << endl;
	system("figlet -c 'K - O S'");
	cout << endl;
	cout << "                                    \\ | /\n                                   --    --\n                                    / | \\" << endl << "                            Presented To you By\n                            22F-3070 Muhammad Arfa Barkat\n                            22F-3274 Muhammad Muzammil Noor\n                            22F-3379 Sameed Ahmad\n" << endl;
	sleep(1);
	system("clear");
	cout << endl << endl << endl << endl;
	system("figlet -c 'K - O S'");
	cout << endl;
	cout << "                                    \\   /\n                                   --    --\n                                    / | \\" << endl << "                            Presented To you By\n                            22F-3070 Muhammad Arfa Barkat\n                            22F-3274 Muhammad Muzammil Noor\n                            22F-3379 Sameed Ahmad\n" << endl;
	sleep(1);
	system("clear");
	cout << endl << endl << endl << endl;
	system("figlet -c 'K - O S'");
	cout << endl;
	cout << "                                    \\    \n                                   --    --\n                                    / | \\" << endl << "                            Presented To you By\n                            22F-3070 Muhammad Arfa Barkat\n                            22F-3274 Muhammad Muzammil Noor\n                            22F-3379 Sameed Ahmad\n" << endl;
	sleep(1);
	system("clear");
	cout << endl << endl << endl << endl;
	system("figlet -c 'K - O S'");
	cout << endl;
	cout << "                                    \\    \n                                   --      \n                                    / | \\" << endl << "                            Presented To you By\n                            22F-3070 Muhammad Arfa Barkat\n                            22F-3274 Muhammad Muzammil Noor\n                            22F-3379 Sameed Ahmad\n" << endl;
	sleep(1);
	system("clear");
	cout << endl << endl << endl << endl;
	system("figlet -c 'K - O S'");
	cout << endl;
	cout << "                                    \\    \n                                   --      \n                                    / | " << endl << "                            Presented To you By\n                            22F-3070 Muhammad Arfa Barkat\n                            22F-3274 Muhammad Muzammil Noor\n                            22F-3379 Sameed Ahmad\n" << endl;
	sleep(1);
	system("clear");
	cout << endl << endl << endl << endl;
	system("figlet -c 'K - O S'");
	cout << endl;
	cout << "                                    \\    \n                                   --      \n                                    /  " << endl << "                            Presented To you By\n                            22F-3070 Muhammad Arfa Barkat\n                            22F-3274 Muhammad Muzammil Noor\n                            22F-3379 Sameed Ahmad\n" << endl;
	sleep(1);
	system("clear");
	cout << endl << endl << endl << endl;
	system("figlet -c 'K - O S'");
	cout << endl;
	cout << "                                    \\    \n                                   --      \n                                       " << endl << "                            Presented To you By\n                            22F-3070 Muhammad Arfa Barkat\n                            22F-3274 Muhammad Muzammil Noor\n                            22F-3379 Sameed Ahmad\n" << endl;
	sleep(1);
	system("clear");
	cout << endl << endl << endl << endl;
	system("figlet -c 'K - O S'");
	cout << endl;
	cout << "                                    \\    \n      \n   " << endl << "                            Presented To you By\n                            22F-3070 Muhammad Arfa Barkat\n                            22F-3274 Muhammad Muzammil Noor\n                            22F-3379 Sameed Ahmad\n" << endl;
	sleep(1);
	system("clear");
	cout << endl << endl << endl << endl;
	system("figlet -c 'K - O S'");
	cout << endl;
	cout << "\n\n" << endl << "                            Presented To you By\n                            22F-3070 Muhammad Arfa Barkat\n                            22F-3274 Muhammad Muzammil Noor\n                            22F-3379 Sameed Ahmad\n" << endl;
	sleep(1);
	system("clear");
	sleep(1);
	
	char c = '0';
	int pid;
	while (c != '7') {
		PrintHeader();
		cout << "\nYour Choice: ";
		cin >> c;
		switch (c) {
		case '1':
			kernel_bit = 1;
			PrintHeader();
			if (memoryMB - 2000 <= 0) {
				cout << "\nNot enough space in memory to run Calculator. Clear some space\n";
				break;
			}
			memoryMB -= 2000;
			pid = fork();
			if (pid == 0) {
				PrintHeader();
				system("g++ Files/Calculator.cpp -o Files/Calculator");
				system("xterm -T ""Calculator"" -bg black -fg gold -fa ""CascadiaMonoSemiBold"" -fs 12 -e ./Files/Calculator");
				PrintHeader();
				return 0;
			}
			else {
				wait(NULL);
				kernel_bit = 0;
				memoryMB += 2000;
				PrintHeader();
			}
			break;
		case '2':
			kernel_bit = 1;
			PrintHeader();
			if (memoryMB - 500 <= 0) {
				cout << "\nNot enough space in memory to run Text Editor. Clear some space\n";
				break;
			}
			pid = fork();
			if (pid == 0) {
				memoryMB -= 500;
				PrintHeader();
				system("g++ Files/TextEd.cpp -o Files/TextEd");
				system("xterm -T ""TextEditor"" -bg black -fg teal -fa ""CascadiaMonoSemiBold"" -fs 12 -e ./Files/TextEd");
				memoryMB += 500;
				kernel_bit = 0;
				PrintHeader();

				return 0;
			}
			else {
				wait(NULL);
				kernel_bit = 0;
				memoryMB += 500;
				PrintHeader();
			}
			break;
		case '3':
			kernel_bit = 1;
			PrintHeader();
			if (memoryMB - 2500 <= 0) {
				cout << "\nNot enough space in memory to feed the philosophers. Just let them die. . .\n";
				break;
			}
			if (av_cores - 5 <= 0) {
				cout << "\nNot enough cores available to feed the philosophers. Tell them to imagine some food. . .\n";
				break;
			}
			memoryMB -= 2500;
			av_cores -= 5;
			PCB dino, readWrite;
			system("g++ Files/DinoPhi.cpp -o Files/DinoPhi");
			system("g++ Files/ReaderWriter.cpp -o Files/ReaderWriter");

			pid = fork();
			if (pid == 0) {
				PrintHeader();
				dino.pid = fork();
				if (dino.pid == 0) {
					system("xterm -T ""The-Dining-Philosophers"" -bg black -fg violet -fa ""CascadiaMonoSemiBold"" -fs 12 -e ./Files/DinoPhi");
					return 0; // This line will not be reached
				}
				dino.isActive = true;
				// Initialize PCB for ReaderWriter
				readWrite.pid = fork();
				if (readWrite.pid == 0) {
					system("xterm -T ""The-Reading-Writing-Den"" -bg black -fg pink -fa ""CascadiaMonoSemiBold"" -fs 12 -e ./Files/ReaderWriter");
					return 0; // This line will not be reached
				}
				readWrite.isActive = true;
				while (dino.isActive || readWrite.isActive) {
					int status;
					if (dino.isActive)
						if (waitpid(dino.pid, &status, WNOHANG) < 0)
							dino.isActive = false;

					if (readWrite.isActive)
						if (waitpid(readWrite.pid, &status, WNOHANG) < 0)
							readWrite.isActive = false;

					//Round Robin scheduling if both are still active
					if (dino.isActive) {
						kill(dino.pid, SIGSTOP); // Pause them philosophers
						//sleep(1);
						kill(dino.pid, SIGCONT); // Let them eat
					}

					if (readWrite.isActive) {
						kill(readWrite.pid, SIGSTOP); // no more reading writing
						//sleep(1);
						kill(readWrite.pid, SIGCONT); // go on
					}
				}
				kernel_bit = 0;
				PrintHeader();
				return 0;
			}
			else {
				waitpid(pid, NULL, 0); //it causes problems, if its not included, everything goes fine but wihtout updating but gets worse afterwards, you'll know
				kernel_bit = 0;
				memoryMB += 2500;
				av_cores += 5;
				PrintHeader();
			}
			break;
		case '4':
			kernel_bit = 1;
			PrintHeader();
			if (memoryMB - 1500 <= 0) {
				cout << "\nNot enough space in memory to run Code Editor. Clear some space\n";
				break;
			}
			memoryMB -= 1500;
			pid = fork();
			if (pid == 0) {
				PrintHeader();
				system("g++ Files/CodeEd.cpp -o Files/CodeEd");
				system("xterm -T ""CodeEditor"" -bg black -fg salmon -fa ""CascadiaMonoSemiBold"" -fs 12 -e ./Files/CodeEd");
				kernel_bit = 0;
				PrintHeader();

				return 0;
			}
			else {
				wait(NULL);
				kernel_bit = 0;
				memoryMB += 1500;
				PrintHeader();
			}
			break;
		case '5':
			kernel_bit = 0;
			pid = fork();
			if (pid == 0) {
				system("g++ Files/Terminal.cpp -o Files/Terminal");
				system("xterm -T ""Terminal"" -bg black -fg beige -fa ""CascadiaMonoSemiBold"" -fs 12 -e ./Files/Terminal");
				return 0;
			}
			else {
				wait(NULL);
				kernel_bit = 0;
				PrintHeader();
			}
			break;
		case '6':
			kernel_bit = 1;
			PrintHeader();
			if (memoryMB - 2000 <= 0) {
				cout << "\nNot enough space in memory to run Bingo. Clear some space\n";
				break;
			}
			memoryMB -= 2000;
			pid = fork();
			if (pid == 0) {
				PrintHeader();
				system("g++ Files/Bingo.cpp -o Files/Bingo");
				system("xterm -T ""Bingo"" -bg black -fg yellow -fa ""CascadiaMonoSemiBold"" -fs 12 -e ./Files/Bingo");
				kernel_bit = 0;
				PrintHeader();

				return 0;
			}
			else {
				wait(NULL);
				kernel_bit = 0;
				memoryMB += 2000;
				PrintHeader();
			}
			break;
		}
	}
	return 0;
}

void PrintHeader() {
	system("clear");
	cout << "-----------------[K-OS]-----------------\n";
	if(memoryMB > 3000) { memoryMB = 3000; }
	cout << "Memory: " << memoryMB << "\t\t" << "Mode: " << kernel_bit << endl << "\nCores: " << av_cores << endl << endl;
	cout << "1. Calculator\n2. Text Editor\n3. Problem Simulator\n4. Code Editor\n5. Terminal\n6. Bingo Game\n7. Exit\n";
}
