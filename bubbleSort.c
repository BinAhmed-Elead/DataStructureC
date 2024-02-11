#include <stdio.h>

void bubbleSort(int count, int* nums){
    //int *result = (int*)malloc(sizeof(int) * count);
    for(int i = 0 ; i < count ; i++){
        for(int j = 0 ; j < count ; j++){
            if(nums[i] < nums[j]){
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
            }
        }   
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
    bubbleSort(count, nums);
    printArray(count,nums);
    return 0;
}