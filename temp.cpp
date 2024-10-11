#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

struct PCB {
    pid_t pid;
    bool isActive;
};

int main() {
    PCB pcb_dino_phi, pcb_reader_writer;
    
    // Compile DinoPhi.cpp
    system("g++ Files/DinoPhi.cpp -o Files/DinoPhi");
    
    // Initialize PCB for DinoPhi
    pcb_dino_phi.pid = fork();
    if (pcb_dino_phi.pid == 0) {
        // Execute DinoPhi
        system("xterm -e ./Files/DinoPhi");
        return 0; // This line will not be reached
    }
    pcb_dino_phi.isActive = true;

    // Compile ReaderWriter.cpp
    system("g++ Files/ReaderWriter.cpp -o Files/ReaderWriter");

    // Initialize PCB for ReaderWriter
    pcb_reader_writer.pid = fork();
    if (pcb_reader_writer.pid == 0) {
        // Execute ReaderWriter
        system("xterm -e ./Files/ReaderWriter");
        return 0; // This line will not be reached
    }
    pcb_reader_writer.isActive = true;

    // Parent process
    while (true) {
        // Implement round-robin scheduling here
        if (pcb_dino_phi.isActive) {
            kill(pcb_dino_phi.pid, SIGSTOP); // Pause DinoPhi
            // Sleep or execute other processes
            kill(pcb_dino_phi.pid, SIGCONT); // Resume DinoPhi
        } else if (pcb_reader_writer.isActive) {
            kill(pcb_reader_writer.pid, SIGSTOP); // Pause ReaderWriter
            // Sleep or execute other processes
            kill(pcb_reader_writer.pid, SIGCONT); // Resume ReaderWriter
        }
        // Add more processes if needed
    }

    return 0;
}

