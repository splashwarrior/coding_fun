#include <stdio.h>
#define SIZE 10 
int arr[SIZE] = {8,1,2,4,-1,111,19,-212,-3, 1};

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

void srt(int *arr, int size, int start, int end)
{
    int pindex = 0;
    cnt_srt++;
    if (start >= end)
         return;
    pindex = perm(arr, size, start, end);

    srt(arr, SIZE, start, pindex - 1);
    srt(arr, SIZE, pindex + 1, end);

}
int main() {

    cnt_perm = 0;
    cnt_srt = 0;
    print(); 
    srt(arr, SIZE, 0, SIZE-1);
    print(); 
    printf("perm=%d srt =%d\n", cnt_perm, cnt_srt);
    return 0;
}

