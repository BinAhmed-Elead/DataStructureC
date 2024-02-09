#include <malloc.h>
#include <stdio.h>

typedef struct{
    int capacity;
    int numberOfElements;
    int *array;
} arrayList;

arrayList* new_ArrayList(){
    arrayList *arraylist = (arrayList*)malloc(sizeof(arrayList));
    if(!arraylist)//failed to malloc
        return NULL;
    arraylist->capacity = 10;
    arraylist->numberOfElements = 0;
    arraylist->array = (int *)malloc(arraylist->capacity * sizeof(int));
    //printf("%ld\n",arraylist->capacity * sizeof(int));
    if(!arraylist->array)//failed to allocate
        return NULL;
    return arraylist;
}

void copy_array(int *source, int *destination,int size){
    for(int i = 0 ; i < size ; i++){
        destination[i] = source[i];
    }
}
void printElements(arrayList *arraylist){
    for(int i = 0; i < arraylist->numberOfElements; i++){
        printf("[%d] - %d\n", i,  arraylist->array[i]);
    }
}
void print_array(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("[%d] - %d\n", i,  arr[i]);   
    }
}
int add(arrayList *arraylist,int element){
    if(arraylist->numberOfElements == arraylist->capacity){//not enough need to expand
        /*printf("expanding from %d to %d\nold array:\n",arraylist->capacity, (int)(arraylist->capacity*1.5));
        printElements(arraylist);
        printf("---------------\nnew array:\n");
        printElements(arraylist);
        printf("---------------\n");*/
        // hold the size of the old array before expantion
        int size = arraylist->capacity;
        // copy array temporary
        int tmp[size];
        copy_array(arraylist->array, tmp, arraylist->capacity);
        arraylist->capacity = (int)(arraylist->capacity*1.5);
        //free prevoius array
        free(arraylist->array);
        arraylist->array = (int *)malloc(arraylist->capacity * sizeof(int));
        if(!arraylist->array)//NULL
            return -1; // Error failed to malloc
        copy_array(tmp, arraylist->array, size);//copy the old array
        //add the element
    }
        //printf("Adding [%d]- %d\n",arraylist->numberOfElements,element);
        arraylist->array[arraylist->numberOfElements] = element;
        arraylist->numberOfElements++;
        return 1; // added successfully;
}
void remove(arrayList *arraylist,int index){
    int tmp[arraylist->numberOfElements-1];
    copy_array(arraylist->array, tmp, arraylist->numberOfElements);
    
    for(int i=0,j=0 ; i < arraylist->numberOfElements ; i++,j++){
        if(i != index)
            arraylist->array[j] = tmp[i];
        else
            j--;
    }
}
void free_arrayList(arrayList* arraylist){
    free(arraylist->array);
    free(arraylist);
}
int main(void){
    arrayList* arraylist = new_ArrayList();
    int n=0;
    add(arraylist, n++);
    add(arraylist, n++);
    add(arraylist, n++);
    add(arraylist, n++);
    add(arraylist, n++);
    add(arraylist, n++);
    printElements(arraylist);
    remove(arraylist, 1);
    printf("after removal:\n");
    printElements(arraylist);
    //free_arrayList(arraylist);
    return 0;
}