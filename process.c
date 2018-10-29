#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
pid_t fork(void);

#define processes 10
int solve(int start, const int arr[]) {
    int sum = 0;
    for (int i = start * 100; i < (start * 100) + 100; ++i) {
        sum = sum + arr[i];
    }
    return sum;
}
int main() {
    int temp;
    int sum;
    int arr[1000];

    for (int i = 0; i < 1000; i++) {
        arr[i] = i + 1;
    }

    int pipes[10][2];
    for (int k = 0; k < processes; k++) {
        pipe(pipes[k]);
    }

    int pid = fork();

    for (int j = 0; j < processes ; j++) {
        pid = fork();
        if (pid == 0) {
            temp = solve(j,  arr);
            write(pipes[j][1], &temp, sizeof(temp));
            close(pipes[j][1]);
            exit(1);
        }
    }
    //Wait until all processes got processed
    for (int i = 0; i < processes; i++) {
        wait(NULL);
    }
    //Reading data from pipe and add to "sum"
    for (int l = 0; l < processes ; l++) {
        int tempsum = 0;
        read(pipes[l][0], &tempsum, sizeof(tempsum));
        sum = sum + tempsum;
    }

    //closing all pipes
    for (int m = 0; m < processes; m++) {
        close(pipes[m][0]);
    }


    printf("Sum of 0-1000: %d\n", sum);
}
