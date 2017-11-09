#include <stdio.h>
#define SIZE 3 
#define MAX_SIZE 100 
void change(int x) {
    x = 12;
}

void change_ref(int *x) {
    *x = 12;
}

int main(int argc, char *argv[]) {
    
    int sum = 10;
    printf("pre sum=%d \n", sum);
    change_ref(&sum);
    printf("post sum=%d \n", sum);
    return 0;
}

