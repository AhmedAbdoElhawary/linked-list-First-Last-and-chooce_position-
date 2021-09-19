#include <iostream>
#include<string>
using namespace std;
#include <stdio.h>
#include<stdlib.h>

struct node {
  int pay;
  struct node *previos;
  struct node *next;
};
struct node *add_first(struct node *f){
  struct node *t=(struct node *)malloc(sizeof(struct node));
  printf("enter the number :");
  scanf("%d",&t->pay);
  t->next=f;
  t->previos=NULL;
  f->previos=t;
  return t;
}
int count=1;
struct node *sum;
struct node *add_position(struct node *p,int pos){
if(pos==count+1){
  sum=p->next;
  struct node *t=(struct node *)malloc(sizeof(struct node));
  printf("enter the number :");
  scanf("%d",&t->pay);
  t->next=sum;
  t->previos=p;
  sum->previos=t;
  p->next=t;
  return p;
  }
  else{
    count++;
    p->next=add_position(p->next, pos);
  }
  count=1;
  return p;
} 
struct node *add_last(struct node *a){
  if(a==NULL||a->next==NULL){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    printf("enter the number :");
    scanf("%d",&t->pay);
    t->next=NULL;
    if(a==NULL)
      t->previos=NULL;
    else{
      a->next=t;
      t->previos=a;
      return a;
    }
    return t;
  }
  a->next=add_last(a->next);
  return a;
}
void show(struct node *s){
  while(s!=NULL){
    printf("(%d) -> ",s->pay);
    s=s->next;
  }
  printf("NULL");
}
int main(void) {
  int num;
  struct node *head=NULL;
  string dash="-----------";
  do{
    printf("what would you want to do :\n1)add in the first:\n2)add in the last :\n3)choose the position :\n4)show and exit :\n");
    scanf("%d",&num);
    if(num==1&&head!=NULL)
      head=add_first(head);
    else if(num==2||head==NULL)
      head=add_last(head);
    else if(num ==3){
       printf("enter the position :");
       int pos;
       scanf("%d",&pos);
       struct node *total_node=head;
       int i;
        for(i=1;total_node!=NULL;i++){
            total_node=total_node->next;
       }
       if(pos>=i)
        head=add_last(head);
       else if(pos<=1)
        head=add_first(head);
       else
        head=add_position(head,pos);
    }
    
    cout<<"\n"<<dash<<"\n";
    show(head);
    cout<<"\n"<<dash<<"\n";
    dash+="-------";
  }while(num!=4);

  return 0;
}