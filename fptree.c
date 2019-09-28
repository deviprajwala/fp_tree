#include<stdio.h>
#include<stdlib.h>

int count1=0,count2=0,count3=0,count4=0,count5=0;
int n=5;//number of items
int it=4;//maximum nuber of items in one transaction


struct node
{
 int name;
 struct node *samelink;
 struct node *difflink;
 int counter;
};
typedef struct node *node;


struct transaction
{
  int item[5];
  struct transaction *link;
};
typedef struct transaction *trans;


node getnode();
trans gettrans();
trans input(trans troot);
void delete_less_than_supcount(int supcount,trans troot);
void delete(int key,trans troot);
void print(trans troot);

node getnode()
{
  node x;
  x=(node)malloc(sizeof(struct node));
  return x;
}
node root=NULL;

trans gettrans()
{
  trans x;
  x=(trans)malloc(sizeof(struct transaction));
  return x;
}
trans troot=NULL;

trans input(trans troot)
{
 int i;
 trans x,prev,cur;
 x=gettrans();
 x->link=NULL;
 
 for(i=1;i<=n;i++)
  {
    scanf("%d",&x->item[i]);
    if(x->item[i]==1)
    {
     count1++;
    }
    else if(x->item[i]==2)
    {
     count2++;
    }
    else if(x->item[i]==3)
    {
     count3++;
    }
    else if(x->item[i]==4)
    {
     count4++;
    }
    else if(x->item[i]==5)
    {
     count5++;
    }
  }
 if(troot==NULL)
 {
   troot=x;
   return troot;
 }
 else
 {
  prev=NULL;
  cur=troot;
  while(cur!=NULL)
  {
   prev=cur;
   cur=cur->link;
  }
  prev->link=x;
 }
 return troot;
}

void delete_less_than_supcount(int supcount,trans troot)
{
  if(count1<supcount)
  {
    delete(1,troot);
  } 
  if(count2<supcount)
  {
    delete(2,troot);
  } 
  if(count3<supcount)
  {
    delete(3,troot);
  } 
  if(count4<supcount)
  {
    delete(4,troot);
  } 
  if(count5<supcount)
  {
    delete(5,troot);
  } 
}
void delete(int key,trans troot)
{
 int i;
 trans cur;
 cur=troot;
 while(cur!=NULL)
 {
 for(i=1;i<=it;i++)
  {
   if(cur->item[i]==key)
   {
     cur->item[i]=0;
   }
  }
  cur=cur->link;
 }
}
void print(trans troot)
{
  int i;
  trans prev,cur;
  if(troot==NULL)
  {
   printf("Empty\n");
  }
  prev=NULL;
  cur=troot;
  while(cur!=NULL)
  {
   for(i=1;i<n;i++)
   {
    if(cur->item[i]==0)
    {
     break;
    }
    else if(cur->item[i]!=0)
    {
     printf("%d  ",cur->item[i]);
    }
   }
   printf("\n");
   cur=cur->link;
  }
}
int main()
{
 int t,i,supcount=6;
 trans troot;
 troot=gettrans();
 printf("Enter the number of transactions\n");
 scanf("%d",&t);
 for(i=1;i<=t;i++)
 {
  if(i==1)
  {
   troot=NULL;
  }
 troot=input(troot);
 }
 printf("%d %d %d %d %d\n",count1,count2,count3,count4,count5);
 print(troot);
 delete_less_than_supcount(supcount,troot);
 printf("after deletion\n");
 print(troot);
  return 0;
}