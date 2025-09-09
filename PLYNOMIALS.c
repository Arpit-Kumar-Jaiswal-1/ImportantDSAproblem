#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node{
    int coff;
    int exp;
    struct Node *next;
};
struct Node *create(int coff, int exp){
 struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
 ptr->coff=coff;
 ptr->exp=exp;
 ptr->next=NULL;
 return ptr;
   
}
// Insert a term (sorted by exponent, descending)
struct Node *insert(struct Node *head,int coff,int exp){
    struct Node *newnode=create(coff,exp);
    //applying edge cases 
    if(coff==0){
        return head;
    }// ignore zero terms
    if(head==NULL || exp > head->exp){
        newnode->next=head;
        return newnode;
    }

//traverse to find the correct position 
     struct Node *temp=head;
while(temp->next!=NULL && temp->next->exp >= exp){
     if(temp->next->exp==exp){
        temp->next->coff=temp->next->coff+coff;
        free(newnode);
        return head;
      

     }

     temp=temp->next;
}
  newnode->next=temp->next;
  temp->next=newnode;
  return head;




}
struct Node *Add(struct Node *head1,struct Node *head2){
    struct Node *p1=head1;
    struct Node *p2=head2;    
    struct Node *result=NULL;
    while(p1&&p2){
       if(p1->exp==p2->exp){
        result=insert(result,p1->coff+p2->coff,p1->exp);
        p1=p1->next;
        p2=p2->next;
    }
     else  if(p1->exp>p2->exp){
       result=insert(result,p1->coff,p1->exp);
       p1=p1->next;

    }
    else{
    result=insert(result,p2->coff,p2->exp);
       p2=p2->next;

    }
}
    while(p1!=NULL){
        result=insert(result, p1->coff, p1->exp);
        p1=p1->next;
    }
    while(p2!=NULL){
        result=insert(result, p2->coff, p2->exp);
        p2=p2->next;
    }

 

    return result;


}

//Print polynomial
void display(struct Node *head){
struct Node *temp=head;
if(temp==NULL){
        printf("0\n");
        return ;
    }
while(temp!=NULL){
printf("%dx^%d",temp->coff,temp->exp);
temp=temp->next;
if (temp != NULL && temp->coff >= 0) printf(" + ");
 
  }

printf("\n");
}
struct Node  *read(){
    struct Node *poly=NULL;
 int n, coff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Enter the 1st element  coff and exp %d",i+1);
        scanf("%d  %d",&coff,&exp);
        poly=insert(poly,coff,exp);

    }

    
    return poly;
}

int main(){
    struct Node *poly1=NULL;
    struct Node *poly2=NULL;
    struct Node *result=NULL;

    printf("Enter the detail of polynomial 1 \n ");
    poly1=read();
    printf("Enter the detail of polynomial 2  \n ");
    poly2=read();
    
    printf("performing Addition \n");
    result=Add(poly1,poly2);
    printf("\nP1(x) = ");
    display(poly1);
    printf("\nP2(x) = ");
    display(poly2);

    printf("result is \n");
    display(result);









}