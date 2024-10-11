#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
using namespace std;

sem_t lock1, lock2;
int countRead = 0;

void* writer(void* arg) {
    while (2 + 2 != 5) {
        sem_wait(&lock2);
        cout << "Writer - writing." << endl;
        sleep(1);
        cout << "Writer - writing done." << endl;
        sem_post(&lock2);
        sleep(1);
    }
    pthread_exit(NULL);
}

void* reader(void* arg) {
    while (2 + 2 != 5) {
        sem_wait(&lock1);
        
        countRead++;
        if (countRead == 1) {
            sem_wait(&lock2);
        }
        
        sem_post(&lock1);
        
        cout << "Reader - reading." << endl;
        sleep(1);
        cout << "Reader - reading done." << endl;

        sem_wait(&lock1);
        
        countRead--;
        if (countRead == 0) {
            sem_post(&lock2);
        }
        sem_post(&lock1);
        
        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
	pthread_t readers[5];
	pthread_t writers[2];

	sem_init(&lock1, 0, 1);
	sem_init(&lock2, 0, 1);

	for (int i = 0; i < 5 || i < 2; i++) {
		if(i < 5) {
			pthread_create(&readers[i], NULL, reader, NULL);
		}
		if(i < 2) {
			pthread_create(&writers[i], NULL, writer, NULL);
		}
	}
	
	for (int i = 0; i < 5 || i < 2; i++) {
		if(i < 5) {
			pthread_join(readers[i], NULL);
		}
		if(i < 2) {
			pthread_join(writers[i], NULL);
		}
	}

	sem_destroy(&lock1);
	sem_destroy(&lock2);

	return 0;
}
