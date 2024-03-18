#include <stdio.h>
#include <stdlib.h>

void printArray(int count , int* nums){
    if(nums == NULL){
        printf("{}");
        return;
    }
    printf("{");
    for(int i = 0 ; i < count ; i++){
        printf("%d,",nums[i]);   
    }
    printf("\b}\n");
}

void swap(int *num1, int *num2){
    int tmp = *num2;
    *num2 = *num1;
    *num1 = tmp;
} 

int* mergeSort(int count, int* nums){
    if(count == 2){
        if(nums[0] > nums[1])
            swap(&nums[0], &nums[1]);
        return nums;
    }else if(count == 1){
        return nums;
    }
    int *left = mergeSort(count/2, nums);
    int *right = mergeSort(count/2+count%2, nums+count/2);
    int *sorted = (int*)malloc(count*sizeof(int));
    int i=0,j=0,l=0;
    while(i<count/2 && j<(count/2+count%2)){
        if(left[i] > right[j]){
            sorted[l] = right[j];
            j++;
        }else{
            sorted[l] = left[i];
            i++;
        }
        l++;
    }
    while(j<(count/2+count%2)){
        sorted[l] = right[j];
        j++;
        l++;
    }
    while(i<count/2){
        sorted[l] = left[i];
        i++;
        l++;
    }
    free(right);
    free(left);
    return sorted;
}

int main(void){
    int nums[] = {23,11,3,4,1,6,353,352,25,53};
    int count = 10;
    printArray(count,nums);
    printf("---------------sort--------------\n");
    int *sorted = mergeSort(count, nums);
    printArray(count, sorted);
    return 0;
}