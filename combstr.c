#include <stdio.h>
#include <string.h>
#define SIZE 11 
//char arr[SIZE] = {"thismaybek"};
char arr[SIZE] = {"abc"};
int dp[SIZE];//{8,1,2,4,-1,111,19,-212,-3, 0};
int print() {
    printf("%s %d strlen=%d\n", arr, sizeof(arr), strlen(arr));
}

int swap(char *a, char *b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void findcomb(char *arr, int index, int size) {
    int i;
    if (index ==  size) {
        printf("%s\n", arr);
        return;
    }
    for (i = index; i <= size; i++) {
        swap(&arr[index], &arr[i]);
        findcomb(arr, index+1, size);
        swap(&arr[index], &arr[i]);
        //printf("<<\n");
    }
}
#define MAX(a, b) ((a) < (b) ? (b) : (a))

int main() {

    print();
    findcomb(arr, 0, strlen(arr) - 1);
    return 0;
}

