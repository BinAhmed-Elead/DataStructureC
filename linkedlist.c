#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int val;
    Node *next;    
}Node;

typedef struct{
    int size;
    Node *head;
    Node *tail;
}LinkedList;

LinkedList* new_linkedlist(){
    LinkedList *linkedlist;
    linkedlist = (LinkedList*)malloc(sizeof(LinkedList));
};

uint8_t addElement(LinkedList *list ,int element){
    if(!list->head){
        list->head = (Node*)malloc(sizeof(Node));
        if(!list->head){//failed to allocate
            return -1;
        }
        list->head->val = element;
        list->head->next = NULL;
        list->size++;
        return 1;
    }
    if(!list->tail){
        list->tail = (Node*)malloc(sizeof(Node));
        if(!list->tail){//failed to allocate
            return -1;
        }
        list->head->next = list->tail;//since there is no tail that means the head's next element is the tail
        list->tail->val = element;
        list->tail->next = NULL;
        list->size++;
        return 1;
    }
    list->tail->next = (Node*)malloc(sizeof(Node));
    if(!list->tail->next)//failed to allocate
        return -1;
    list->tail->next->val = element;
    list->tail->next->next = NULL;
    list->tail = list->tail->next;
    list->size++;
    return 1;
}
void printList(LinkedList *list){
    Node *node = list->head;
    if(!node){
        printf("EmptyList\n");
    }
    for(int i = 0 ;i <list->size; i++){
        // printf("%p\n",node);
        printf("%d\n",node->val);
        node = node->next;
    }
}
int listSize(LinkedList *list){
    //use the data structure var or do the commented way
    return list->size;
    //     Node *node = list->head;
    // if(!node)
    //     return 0;//empty list
    // int count;
    // while(node){
    //     count++;
    //     node = node->next;
    // }
    // return count;
}
int removeElement(LinkedList *list, int index){
    Node *node = list->head;
    if(!node)
        return -1;//List empty
    if(index == 0){//head node is set for removal
        // printf("head\n");
        Node *tmp = list->head;
        list->head = tmp->next;// the head pointer moved to the next node leaving the old head without refrence
        free(tmp);
        list->size--;
        return 1;
    }
    int count = 0;
    while(node){
        count++;
        if(count == index){//the next node is to be removed since we increment first
            Node *tmp = node->next; // <- this node should be removed
            node->next = tmp->next; 
            // printf("node : %p\nremoved: %p\n",node,tmp);
            list->size--;
            free(tmp);
            return 1;
        }
        node = node->next;
    }
    return -1;
}
int main(){
    LinkedList *list = new_linkedlist();
    //printList(list);
    int n = 0;
    int ret = addElement(list,n++);
    // printf("add: %d\n",ret);
    ret = addElement(list,n++);
    // printf("add: %d\n",ret);
    ret = addElement(list,n++);
    // printf("add: %d\n",ret);
    ret = addElement(list,n++);
    // printf("add: %d\n",ret);
    ret = addElement(list,n++);
    // printf("add: %d\n",ret);
    printList(list);
    printf("size: %d\n",listSize(list));
    printf("removed element index: 4\n");
    int rem = removeElement(list, 4);
    // printf("%d\n",rem);
    printList(list);
    printf("size: %d\n",listSize(list));
    return 0;
}