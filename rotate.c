static inline void SWAP(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
void rotate (int arr[], int size, int times) {
    int real = 0;
    int i = 0, j = 0;
    if (!arr || size < 2 || times < 1)  {
        return;
    }

    //no need to move
    real = times % size;
    if (real == 0)
        return;

    int *temp = (int*) malloc(real*sizeof(int));

    if (!temp)
        return;

    for (i = 0; i < real; i++) {
        temp[i] = arr[i];
    }
            
    j = 0;
    for (i = 0; i < size; i++) {

        if (i >= size - real)
            arr[i] = temp[j++];
        else 
            arr[i] =  arr[i + real];
    }
    free(temp);
}
