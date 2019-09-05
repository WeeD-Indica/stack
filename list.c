#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
  int data;
  struct node *next;
}node;
node *p=NULL;
void ins(int x,int pos);
void del(int pos);
void traverse();
void search(int p);

void main()
{
  int ch,x,pos;
  int choice;
  do
    {
      printf("\n1)Insert\n2)Delete\n3)Traverse\n4)Search\nChoose your option:");
      scanf("%d",&ch);
      switch(ch)
	{
	case 1:printf("enter element and position:");
	  scanf("%d %d",&x,&pos);
	  ins(x,pos);
	  break;
	case 2:printf("Enter position to be deleted:");
	  scanf("%d",&pos);
	  del(pos);
	  break;
	case 3:traverse();
	  break;
	case 4:printf("Enter element to be found:");
	  scanf("%d",&x);
	  search(x);
	  break;
	default:printf("Error");
	}
      printf("\nDo you want to continue(1/0):");
      scanf("%d",&choice);
    }
  while(choice);
}
void ins(int x,int pos)
{
  int i=1;
  node* temp,*newnode;
  newnode=(node*)malloc(sizeof(p));
  newnode->data=x;
  temp=p;
  while(temp!=NULL)
    {
      temp=temp->next;
      i++;
    }
  if(pos>i)
    {
      printf("Error");
      exit(0);
    }
  else if(pos==1)
    {
      temp=p;
      p=newnode;
      newnode->next=temp;
      return;
    }
  else if(pos==i)
    {
      int j=1;
      temp=p;
      while(temp->next!=NULL);
      {
	temp=temp->next;
	j++;
      }
      temp->next=newnode;
      newnode=temp;
      newnode->next=NULL;
      return;
    }
      
  else
    {
      int j=1;
      temp=p;
      while(j!=pos)
	{
	  temp=temp->next;
	  j++;
	}
      temp=temp->next;
      newnode->next=temp->next;
      temp->next=newnode;    
    }
  return;
}

void del(int pos)
{
  int i=1;
  node* temp,*t,*c;
  temp=p;
  while(temp->next!=NULL)
    {
      temp=temp->next;
      i++;
    }
  if(pos>i||pos<1)
    {
      printf("Error");
      exit(0);
    }
  int j;
  if(pos==1)
    {
      temp=p;
      p=p->next;
      free(temp);
      return;
    }
  else if(pos=i)
    {
      j=1;
      temp=p;
      while(j!=pos-1)
	{
	  temp=temp->next;
	  j++;
	}
      free(temp->next);
      temp->next=NULL;
      return;
    }
  else if(pos<i&&pos>0)
    {
      temp=p;
      j=1;
      while(j!=pos)
	{
	  t=temp;
	  temp=temp->next;
	  j++;
	}
      c=t->next->next;
      free(t->next);
      t->next=c;
      return;
    }
  
  else
    {
      printf("Error");
      return;
    }
}

void traverse()	    
{
  node* temp=p;
  while(temp!=NULL)
    {
      printf("%d\n",temp->data);
      temp=temp->next;
    }
}
void search(int x)
{
  node*temp=p;
  while(temp!=NULL)
    {
      if(x==temp->data)
	{
	  printf("Element found");
	  return;
	}
      temp=temp->next;
    }
    printf("Element not found");
    return;
}
