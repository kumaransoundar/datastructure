//hashtable

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct Node{
   int key;
   int value;
   struct Node *prev;
   struct Node *next;
};

//hashtable arr of pointer to node
struct Node *hashTable[SIZE]={NULL};

//hash function
int hashFunction(int key){
    return key %SIZE;
}


struct Node *createNode(int key,int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->key=key;
    newNode->value=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

//key value pair into hashTable
void insert(int key,int value){
    int index=hashFunction(key);
    struct Node *newNode=createNode(key, value);
    if(hashTable[index]==NULL){
        hashTable[index]=newNode;
    }else{
        struct Node *temp=hashTable[index];
        while(temp!=NULL){
            if(temp->key==key){
                temp->value=value;
                free(newNode);
                return;
            }
            if(temp->next==NULL)
            break;
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}

//display
void display(){
    for(int i=0;i<SIZE;i++){
        struct Node* temp=hashTable[i];
        printf("[%d]=",i);
        while(temp!=NULL){
            printf("(%d:%d) <-> ",temp->key, temp->value);
            temp=temp->next;
        }
    }
    printf("NULL\n");
}

int main()
{
    insert(0,100);
    insert(1,200);
    insert(2,300);
    display();
    insert(3,400);
    display();
    insert(4,100);
    insert(5,50);
    insert(6,500);
    insert(7,600);
    display();
    return 0;
}
