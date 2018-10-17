#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int chunkSize = 100;
int arr[1000];

void *TestThread(void *arg) {

    int start = (int) arg;
    int sum = 0;

    for (int i = start * chunkSize; i < (start * chunkSize) + chunkSize; ++i) {
        sum = sum + arr[i];
    }
    return ((void *) sum);
}

int main() {
    for (int k = 0; k < 1000; ++k) {
        arr[k] = k + 1;
    }

    int status[10];
    pthread_t threads[10];

    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, TestThread, (void *) (i));
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], (void **) &status[i]);
    }

    int sum = 0;

    for (int j = 0; j < 10; j++) {
        sum = sum + status[j];
    }


    printf("\nTotal Sum: %d\n", sum);

    return 0;
}
