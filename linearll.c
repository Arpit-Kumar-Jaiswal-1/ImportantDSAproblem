#include <stdio.h>
#include <stdlib.h>
struct list1{

    int data;
    struct list1 *next;
};

void insert(struct list1 *head,int d){

struct list1 *newnode=(struct list1*)malloc(sizeof(struct list1));
if (newnode == NULL) {
    printf("Memory allocation failed\n");
    return;
}
newnode->data=d;
newnode->next=NULL;
struct list1 *temp=head;
while(temp->next!=NULL && temp->next->data < d){
temp=temp->next;
  

}
newnode->next=temp->next;
temp->next=newnode;




}

void removedup(struct list1 *head){
struct list1 *temp1=head->next;
//since list is in sorted order
struct list1  *temp2;
while(temp1!=NULL  && temp1->next!=NULL){
if(temp1->data==temp1->next->data){
    temp2=temp1->next;
    temp1->next=temp2->next;
     free(temp2);
 }
 else
 temp1=temp1->next;

}






}
void display(struct list1 *head) {
    struct list1 *temp = head->next;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){

struct list1 *head = (struct list1*)malloc(sizeof(struct list1));
    head->next = NULL;

    insert(head, 10);
    insert(head, 5);
    insert(head, 20);
    insert(head, 10); // duplicate

    printf("List before removing duplicates:\n");
    display(head);

    removedup(head);

    printf("List after removing duplicates:\n");
    display(head);



    return 0;
}