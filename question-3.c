//treasure hint
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char hint[100];//
    struct Node *next;
};
//head pointer null 
struct Node* head=NULL;
struct Node* createNode(char hint[]){//believer 
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->hint, hint);
    newNode->next=NULL;
    return newNode;
}
void addhint(char hint[]){
    struct Node* newNode=createNode(hint);
    newNode->next=head;
    head=newNode;
    printf("%s added to the first hint",hint);
}
void display(){
    if(head==NULL)
    {
        printf("No hint\n");return;}
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%s ->",temp->hint);
        temp=temp->next;
    }printf("NULL\n");
}
int main(){
    int choice;
    char hint[100];
    while(1){
        printf("\nChoice 1: Add a hint\nChoice 2: Display hint\nChoice 3: this is a hint\nEnter your choice ");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1:
            printf("Enter hint name\n");
            fgets(hint, sizeof(hint), stdin);
            hint[strcspn(hint, "\n")] = 0; 
            addhint(hint);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("The hint is");
            printf("\n You");
            exit(0);
        default:
            printf("Enter valid choice");
    }}return 0;
}
