#include <stdio.h>
#define SIZE 10 
int arr[SIZE] = {0,1,2,4,-1,111,19,-212,-3, 0};
int dp[SIZE];//{8,1,2,4,-1,111,19,-212,-3, 0};
int print(int *dp) {
    int i = 0;
    for (i = 0; i < SIZE; i++)
        printf("%d ", dp[i]);

    printf("\n");
}

int init() {
    int i = 0;
    for (i = 0; i < SIZE; i++)
        dp[i] = -1;

}
#define MAX(a, b) ((a) < (b) ? (b) : (a))

int maxinc(int *arr, int end)//, int start, int end)
{
    int len = 0, i = 0;
    if (end < 0)
         return;
    dp[end-1] = 1;
    for (i=end-2; i >=0; i--) {
            dp[i] = (arr[i] <= arr[i+1]) ?  dp[i+1] + 1 : 1;
            len = MAX(dp[i], len);
    }
    return len;

}
int main() {

    print(arr);
    init();
    printf("len=%d\n", maxinc(arr, SIZE));//, 0, SIZE-1);
    print(dp);
    return 0;
}

