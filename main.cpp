#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <bits/atomic_base.h>
using namespace std;

int getMin(const int arr[], int start, int end) {
    int minNum = arr[start];
    for (int i = start+1; i < end; i++) {
        if (arr[i] < minNum) {
            minNum = arr[i];
        }
    }
    return minNum;
}
int main(){
    srand(time(nullptr));
    int arr[20];
    for (int &num : arr) {
        num = rand();
    }

    printf("Random numbers:\n");
    for (int i : arr) {
        printf("%d ", i);
        printf("\n");
    }

    int fd[2];
    if (pipe(fd) == -1) {
        return perror("pipe error"), 1;
    }
    int id = fork();
    if (id < 0) {
       return perror("fork error"), 2;
    }

    if (id == 0) {
        close(fd[0]);
        int MinChild = getMin(arr, 10, 20);
        write(fd[1], &MinChild, sizeof(MinChild));
        close(fd[1]);
        exit(0);
    }else {
        close(fd[1]);
        int MinParent =  getMin(arr, 0, 10);
        int MinChild;
        read(fd[0], &MinChild, sizeof(MinChild));
        close(fd[0]);
        int MinTotal;
        MinTotal = min(MinParent, MinChild);

        printf("Minimum number of the first half of the array: %d ", MinParent);
        printf("\n");
        printf("Minimum number of the second half of the array: %d ", MinChild);
        printf("\n");
        printf("Minimum number of the array: %d ", MinTotal);
        printf("\n");
    }
    return 0;
}