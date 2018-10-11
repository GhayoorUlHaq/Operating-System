#include <stdio.h>
#include <zconf.h>
#include <sys/wait.h>
#include <stdlib.h>

int solve(int i, int e, const int arr[]) {
    int s = 0;
    for (int j = i; j < e; j++) {
        s = s + arr[j];
    }
    return s;
}

int main() {
    int s;
    int sum;
    int arr[1000];
    for (int i = 0; i < 1000; ++i) {
        arr[i] = i + 1;
    }

    int p1[2];
    pipe(p1);
    int p2[2];
    pipe(p2);
    int p3[2];
    pipe(p3);
    int p4[2];
    pipe(p4);
    int p5[2];
    pipe(p5);
    int p6[2];
    pipe(p6);
    int p7[2];
    pipe(p7);
    int p8[2];
    pipe(p8);
    int p9[2];
    pipe(p9);
    int p10[2];
    pipe(p10);


    int pid = fork();
    if (pid == 0) {
        s = solve(0, 100, arr);
        write(p10[1], &s, sizeof(s));
//        close(p10[1]);
        exit(1);
    } else {
        pid = fork();
        if (pid == 0) {

            s = solve(100, 200, arr);
            write(p1[1], &s, sizeof(s));
//            close(p1[1]);
            exit(1);
        } else {
            pid = fork();
            if (pid == 0) {

                s = solve(200, 300, arr);
                write(p2[1], &s, sizeof(s));
//                close(p2[1]);
                exit(1);
            } else {
                pid = fork();
                if (pid == 0) {

                    s = solve(300, 400, arr);
                    write(p3[1], &s, sizeof(s));
//                    close(p3[1]);
                    exit(1);
                } else {
                    pid = fork();
                    if (pid == 0) {

                        s = solve(400, 500, arr);
                        write(p4[1], &s, sizeof(s));
//                        close(p4[1]);
                        exit(1);
                    } else {
                        pid = fork();
                        if (pid == 0) {

                            s = solve(500, 600, arr);
                            write(p5[1], &s, sizeof(s));
//                            close(p5[1]);
                            exit(1);
                        } else {
                            pid = fork();
                            if (pid == 0) {

                                s = solve(600, 700, arr);
                                write(p6[1], &s, sizeof(s));
//                                close(p6[1]);
                                exit(1);
                            } else {
                                pid = fork();
                                if (pid == 0) {

                                    s = solve(700, 800, arr);
                                    write(p7[1], &s, sizeof(s));
//                                    close(p7[1]);
                                    exit(1);
                                } else {
                                    pid = fork();
                                    if (pid == 0) {
                                        s = solve(800, 900, arr);
                                        write(p8[1], &s, sizeof(s));
//                                        close(p8[1]);
                                        exit(1);
                                    } else {
                                        pid = fork();
                                        if (pid == 0) {
                                            s = solve(900, 1000, arr);
                                            write(p9[1], &s, sizeof(s));
//                                            close(p9[1]);
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
    }

    //Wait until all processes got processed
    for (int i = 0; i < 10; i++) {
        wait(NULL);
    }

    //Reading data from pipe and add to "sum"
    int sm = 0;
    read(p1[0], &sm, sizeof(sm));
    sum = sum + sm;
    sm = 0;
    read(p2[0], &sm, sizeof(sm));
    sum = sum + sm;
    sm = 0;
    read(p3[0], &sm, sizeof(sm));
    sum = sum + sm;
    sm = 0;
    read(p4[0], &sm, sizeof(sm));
    sum = sum + sm;
    sm = 0;
    read(p5[0], &sm, sizeof(sm));
    sum = sum + sm;
    sm = 0;
    read(p6[0], &sm, sizeof(sm));
    sum = sum + sm;
    sm = 0;
    read(p7[0], &sm, sizeof(sm));
    sum = sum + sm;
    sm = 0;
    read(p8[0], &sm, sizeof(sm));
    sum = sum + sm;
    sm = 0;
    read(p9[0], &sm, sizeof(sm));
    sum = sum + sm;
    sm = 0;
    read(p10[0], &sm, sizeof(sm));
    sum = sum + sm;

//    close(p1[0]);
//    close(p2[0]);
//    close(p3[0]);
//    close(p4[0]);
//    close(p5[0]);
//    close(p6[0]);
//    close(p7[0]);
//    close(p8[0]);
//    close(p9[0]);
//    close(p10[0]);


    printf("Sum of 0-1000: %d\n", sum);

}
