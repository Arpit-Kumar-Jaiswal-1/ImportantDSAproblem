#include <stdio.h>
#include <stdlib.h>
struct student{
    char name [50];
    int rollnumber;
    float marks;

};
void createAndprintStudents(int count){
  struct student *s=(struct student*)malloc(count*sizeof(struct student));
  if(s!=NULL){
    for(int i=0;i < count ;i++){
        printf("Enter the name of the stdent  %d \n", i+1);
        scanf("%s",s[i].name);
        printf("Enter the roll number of the student  \n ");
        scanf("%d",& s[i].rollnumber);
        printf("Enter the marks of the student ");
        scanf("%f",&s[i].marks);
    
    }
    // Printing data
    for(int i=0;i<count ;i++){
      printf("Name %s  , Roll no.  %d, Marks %.2f \n ",s[i].name, s[i].rollnumber, s[i].marks);
    }
    free(s);


  } 
  else{
   printf("Memory Allocation failed \n");

  }

}
int main(){
int n;
printf("Enter the Numbe of student details u wanna Enter \n");
scanf("%d",&n);
createAndprintStudents(n);
  

}