#include <stdio.h>
#include <unistd.h>
pid_t fork(void);
#include <sys/wait.h>
#include <stdlib.h>
//static int sum = 0;

int solve(int i, int e, const int arr[]) {
    int s = 0;
    for (int j = i; j < e; j++) {
        s = s + arr[j];
    }
    return s;
//     sum = sum + s;
}

int main() {
    int sum;
    int arr[1000];
    for (int i = 0; i < 1000; ++i) {
        arr[i] = i + 1;
    }
//    int pipeVal[2];
//    pipe(pipeVal);



    int pid = fork();
    if (pid == 0) {
        sum = solve(0, 100, arr);

//        exit(sum);
        printf("Sum of 1-100: %d\n", sum);
        exit(1);

    } else {
        pid = fork();
        if (pid == 0) {

//        int s;
//        read(pipeVal[1], &s, sizeof(s));
//        s = s + solve(0,100, arr);
//        write(pipeVal[1], &s, sizeof(s));
//        close(pipeVal[1]);

            sum = solve(100, 200, arr);
            printf("Sum of 100-200: %d\n", sum);
            exit(1);

        } else {
            pid = fork();
            if (pid == 0) {
                sum = solve(300, 400, arr);
                printf("Sum of 300-400: %d\n", sum);
                exit(1);
            } else {
                pid = fork();
                if (pid == 0) {
                    sum = solve(400, 500, arr);
                    printf("Sum of 400-500: %d\n", sum);
                    exit(1);
                } else {
                    pid = fork();
                    if (pid == 0) {
                        sum = solve(500, 600, arr);
                        printf("Sum of 500-600: %d\n", sum);
                        exit(1);
                    } else {
                        pid = fork();
                        if (pid == 0) {
                            sum = solve(600, 700, arr);
                            printf("Sum of 600-700: %d\n", sum);
                            exit(1);
                        } else {
                            pid = fork();
                            if (pid == 0) {
                                sum = solve(700, 800, arr);
                                printf("Sum of 700-800: %d\n", sum);
                                exit(1);


                            } else {
                                pid = fork();
                                if (pid == 0) {
                                    sum = solve(800, 900, arr);
                                    printf("Sum of 800-900: %d\n", sum);
                                    exit(1);


                                } else {
                                    pid = fork();
                                    if (pid == 0) {
                                        sum = solve(900, 1000, arr);
                                        printf("Sum of 900-1000: %d\n", sum);
                                        exit(1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

//    wait(NULL);
//    printf("Final Sum: %d\n", sum);

}
