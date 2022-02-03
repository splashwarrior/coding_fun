#include <stdio.h>
#define SIZE 10 

int arr[SIZE] = {1,2,4,14,15,19,21,30, 50, 111};

int print() {
    int i = 0;
    for (i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
void SWAP(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
int cnt_perm, cnt_srt;
int perm(int *arr, int size, int start, int end)
{
    int i = start;
    int pivot = 0;
    int pindex = start;
    cnt_perm++;
    if (start >= end) 
        return 0; 

    pivot = arr[end];
    for (i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            SWAP(&arr[i], &arr[pindex]);
            pindex++;
        }
    }
    SWAP(&arr[end], &arr[pindex]);
    return pindex;
}

void srt(int *arr, int start, int end, int num)
{
    int mid = 0;
    if (start > end) {
        printf("not found\n");
        return;
    }
    mid = (end + start ) >> 1;
    if (arr[mid] == num) {
        printf("Found %d at index %d\n", num, mid);
    } else if (arr[mid] > num) {
        srt(arr,start, mid-1, num);
    } else {
        srt(arr,mid+1, end, num);
    }
}
int main(int cnt, char *argv[]) {

    int num = 0;
    cnt_perm = 0;
    cnt_srt = 0;
    print(); 
    if (cnt == 2) 
       num = atoi(argv[1]);
    printf("num is %d\n", num);

    srt(arr, 0, SIZE-1, num);
    print(); 
    printf("perm=%d srt =%d\n", cnt_perm, cnt_srt);
    return 0;
}

