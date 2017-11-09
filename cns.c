#include <stdio.h>
#define SIZE 3 
#define MAX_SIZE 100 
//int arr[SIZE] = {8,1,2,4,-1,111,19,-212,-3, 0};
int arr[SIZE] = {2, 3, 5};
int hist[MAX_SIZE][MAX_SIZE];
void init() {
    int i, j;
    for ( i = 0; i < MAX_SIZE; i++) {
        for ( j = 0; j < MAX_SIZE; j++) {
            hist[i][j] = -1;
        }
    }
}
int node_find(int amount, int index) {
    int i = 0, j = 0;
    int total = 0;

    printf("amount=%d ind=%d\n", amount, index);
    if (amount == 0)
        return 1;
    else if (amount < 0)
        return 0;
    if (hist[amount][index] != -1)
        return hist[amount][index];

    for (i = index; i < SIZE; i++) {
        total += node_find(amount - arr[i], i);
    }
    hist[amount][index] = total;
    return total;
}
int main(int argc, char *argv[]) {
    
    int sum = 0;
    int ways = 0;
    if (argc == 2)
        sum = atoi(argv[1]);
        
    init();
    ways = node_find(sum, 0);
    printf("sum=%d total=%d\n", sum, ways);
    return 0;
}

