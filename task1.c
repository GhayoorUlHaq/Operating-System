#include <stdio.h>
#include <unistd.h>
pid_t fork(void);

int main() {
    for(int i = 0; i < 4; i++){
        fork();
        printf("Hello\n");
    }
    printf("Exit\n");
}
