#include <stdio.h>

void selectionSort(int count, int* nums){
    int min = 0;
    int tmp = 0;
    for(int i = 0 ; i < count ;i++){
        min = nums[i];
        for(int j = 0 ; j < count ;j++){
            if(nums[j] > min){
                tmp = min;
                min = nums[j];
                nums[j] = tmp;
            }
        }
        nums[i] = min;
    }
}

void printArray(int count , int* nums){
    printf("{");
    for(int i = 0 ; i < count ; i++){
        printf("%d,",nums[i]);   
    }
    printf("\b}\n");
}

int main(void){
    int nums[] = {11,23,73,34,45,16,2};
    int count = 7;
    printArray(count,nums);
    printf("---------------sort--------------\n");
    selectionSort(count, nums);
    printArray(count,nums);
    return 0;
}