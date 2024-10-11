#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/wait.h>
#include <csignal>

void TerminateMain(int);

int main() {
	signal(SIGTERM, TerminateMain);
	system("g++ main.cpp -o main");
	system("xterm -T ""K-OS"" -bg black -fg green -fa ""CascadiaMonoSemiBold"" -fs 12 -e ./main &");
	system("clear");
	return 0;
}
void TerminateMain(int sig) {
	kill(0, SIGTERM);
	exit(0);
}
