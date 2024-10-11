#include <pthread.h>
#include <iostream>
#include <unistd.h>
using namespace std;
void* eat_spaghette(void* args);
pthread_mutex_t forks[5];
int eating_time = 5;
int digesting_time = 3;
int main() {
	pthread_t philosophers[5];
	for (int i = 0; i < 5; i++) pthread_mutex_init(&forks[i], NULL);
	for (int i = 0; i < 5; i++) pthread_create(&philosophers[i], NULL,
		eat_spaghette, &i);
	for (int i = 0; i < 5; i++) pthread_join(philosophers[i], NULL);
	return 0;
}
void* eat_spaghette(void* args) {
	int* philo = (int*)args;
	int philo_n = *philo;
	int left = philo_n;
	int right = (philo_n + 1) % 5;
	while (true) {
		cout << "Philosopher " << philo_n << " is thinking about something" <<

			endl;

		sleep(digesting_time);
		cout << "Philosopher " << philo_n << " is hungy" << endl;
		pthread_mutex_lock(&forks[left]);
		cout << "Philosopher " << philo_n << " picked up left fork" << endl;
		pthread_mutex_lock(&forks[right]);
		cout << "Philosopher " << philo_n << " picked up right fork" << endl;
		cout << "Philosopher " << philo_n << " is eating spaghette" << endl;
		sleep(eating_time);
		pthread_mutex_unlock(&forks[left]);
		pthread_mutex_unlock(&forks[right]);
		cout << "Philosopher " << philo_n << " has finished eating" << endl;
	}
}