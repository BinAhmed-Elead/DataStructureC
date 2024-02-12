#include <stdio.h>

void insertionSort(int count, int* nums){
    int tmp;
    for(int i = 0,j=0 ; i < count-1 ; i++){
        while(i>=j && nums[i-j] > nums[i-j+1]){
            tmp = nums[i-j];
            nums[i-j] = nums[i-j+1];
            nums[i-j+1] = tmp;
            j++;
        }
        j=0;
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
    insertionSort(count, nums);
    printArray(count, nums);
    return 0;
}