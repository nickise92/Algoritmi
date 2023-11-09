#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_LEN 1000

void switchElement(int *arr, int i, int j) {
    int c = arr[i];
    arr[i] = arr[j];
    arr[j] = c;
}

int partition(int *arr, int p, int r) {
    int x = arr[p]; // valore pivot
    int i = p-1;
    int j = r+1;
    while (1) {
        do{
            j--;
        } while (arr[j] > x);
        do{
            i++;
        } while (arr[i] < x);
        if (i < j) {
            switchElement(arr, i, j);
        } else {
            return j;
        }
    }
}

// Randomized partition
int rpartition(int *arr, int p, int r) {
    srand(123);
    int i = rand() % r + p;
    switchElement(arr, i, p);
    return partition(arr, p, r);
}

// Ricorsivo puro
void quicksort(int* arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q);
        quicksort(arr, q+1, r);
    }
}


// Rimozione della ricorsione di coda ed
// applicazione della ricorsione sul sotto-array
// di dimensioni minore, per ridurre lo stack di attivazione
void qksort(int* arr, int p, int r) {
    while (p < r) {
        int q = partition(arr, p, r);
        if (q - p >= r - q) {
            qksort(arr, q+1, r);
            r = q;
        } else {
            qksort(arr, p, q);
            p = q+1;
        } 
    }
}


int main(int argc, char * argv[]) {
    int arr[MAX_LEN];
    int i;

    srand(time(NULL));

    for (i = 0; i < MAX_LEN; i++) {
        arr[i] = rand() % 100;
    }
    printf("Input array:\n");
    for (i = 0; i < MAX_LEN; i++) {
        printf("%3d ", arr[i]);
    }
    printf("\n");


    qksort(arr, 0, MAX_LEN);
    //quicksort(arr, 0, MAX_LEN);

    printf("Ordered array:\n");
    for (i = 0; i < MAX_LEN; i++) {
        printf("%3d ", arr[i]);
    }
    printf("\n");

    return 0;
}