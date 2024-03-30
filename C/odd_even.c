#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>


pthread_mutex_t lock;
int num = 0;

void * odd_thread(void *) {
		while(num < 100) {
				if (!pthread_mutex_lock(&lock)) {
						if (num % 2 != 0) {						
								printf("\n Odd thread_id = %u,  number = %u\n", pthread_self(),num++);
						}
						pthread_mutex_unlock(&lock);
				}
		}
}

void * even_thread(void *) {
		while(num < 100) {
				if (!pthread_mutex_lock(&lock)) {
						if (num %2 == 0) {	
								printf("\n Even thread_id = %u,  number = %u\n", pthread_self(),num++);
						}
						pthread_mutex_unlock(&lock);
				}
		}
}

int main() {

	pthread_t tid[10];
	int num_threads = 2;
	
   	pthread_mutex_init(&lock, NULL);

   	for (int i = 0; i < num_threads; i++) {
		if (i % 2 == 0) {
				if (pthread_create(&tid[i], NULL, even_thread, NULL)) {
						printf("\nFailed to create thread num - %d\n",i);
				}
				else {
						printf("\ncreated EVEN thread num - %d, thread_id = %u\n",i, tid[i]);
				}
		}
		else {
				if (pthread_create(&tid[i], NULL, odd_thread, NULL)) {
						printf("\nFailed to create thread num - %d\n",i);
				}
				else {
						printf("\ncreated ODD thread num - %d, thread_id = %u\n",i, tid[i]);
				}
		}
	}

	sleep(10);

}
