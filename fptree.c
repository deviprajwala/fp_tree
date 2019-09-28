#include<stdio.h>
#include<stdlib.h>

int count[5]={0};//1=0,count2=0,count3=0,count4=0,count5=0;
int n=5;//number of items
int it=4;//maximum nuber of items in one transaction


struct node
{
 int name;
 struct node *samelink;
 struct node *link[3];
 int counter;
 int linkc;
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
void sort_on_priority(trans troot);
node insert(node root,trans cur);
node search(int item,node root);

node getnode()
{
  node x;
  x=(node)malloc(sizeof(struct node));
  return x;
}


trans gettrans()
{
  trans x;
  x=(trans)malloc(sizeof(struct transaction));
  return x;
}
trans troot=NULL;

trans input(trans troot)
{
 int i,key;
 trans x,prev,cur;
 x=gettrans();
 x->link=NULL;
 
 for(i=1;i<=n;i++)
  {
    scanf("%d",&key);
    x->item[i]=key;
    if(x->item[i]==key)
    {
     count[key]+=1;
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
  int i;
  for(i=1;i<=n;i++)
  {
   if(count[i]<supcount)
   {
    delete(i,troot);
   } 
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
void sort_on_priority(trans troot)
{
 int key1,key2,temp,i,j;
 trans cur;
 cur=troot;
 while(cur!=NULL)
 {
  for(i=1;i<it;i++)
  {
   for(j=i+1;j<=it;j++)
   {
    key1=cur->item[i];
    key2=cur->item[j];
    if(count[key1]<count[key2]&&key1!=0&&key2!=0)
     {
       temp=cur->item[i];
       cur->item[i]=cur->item[j];
       cur->item[j]=temp;
     }
    }
   }
   cur=cur->link;
  }
}
node insert(node root,trans cur)
{
 int item1,item2,item3,item4;
 item1=cur->item[1];
 item2=cur->item[2];
 item3=cur->item[3];
 item4=cur->item[4];

 node x,y,z,a;
 node nodei;
 nodei=search(item1,root);

 if(nodei==NULL)
 {
  
label1:
  {
   x=getnode();
   if(item1==0){return;}
   x->name=item1;
   x->counter+=1;
   root->linkc++;
   root->link[root->linkc]=x;
label2:
  {
   y=getnode();
   if(item2==0){return;}
   y->name=item2;
   y->counter+=1;
   x->linkc++;
   x->link[x->linkc]=y;
label3:
  {
   z=getnode();
   if(item3==0){return;}
   z->name=item3;
   z->counter+=1;
   y->linkc++;
   y->link[y->linkc]=z;
label4:
  {  
   a=getnode();
   if(item4==0){return;}
   a->name=item4;
   a->counter+=1;
   z->linkc++;
   z->link[z->linkc]=a;
   }
   }
   }
   }
 }
 else if(nodei!=NULL)
 {
   int i,j,k,l,m,n,o,p;
   j=root->linkc;
   for(i=1;i<j;i++)
   {
     if(root->link[i]->name==item1)
     {
      l=root->link[i]->linkc;
      root->link[i]->counter+=1;
      for(k=1;k<=l;k++)
      {
       if(root->link[i]->link[k]->name==item2)
        {
         m=root->link[i]->link[k]->linkc;
         root->link[i]->link[k]->counter+=1;
         for(n=1;n<m;n++)
          {
           if(root->link[i]->link[k]->link[n]->name==item3)
            {
              o=root->link[i]->link[k]->link[n]->linkc;
              root->link[i]->link[k]->link[n]->counter+=1;
              for(p=1;p<o;p++)
             {
              if(root->link[i]->link[k]->link[n]->link[p]->name==item4)
              {
                root->link[i]->link[k]->link[n]->counter+=1;
              }
              else
              {
                z=root->link[i]->link[k]->link[n];
                goto label4;
              }  
             }
            }
            else
             {
              y=root->link[i]->link[k];
              goto label3;
             } 
            }
          }
          else
          { 
           x=root->link[i];
           goto label2;
          }
        }
      }
     else
     { 
     goto label1; 
     }
    }
  }
return root;
}
node search(int item,node root)
{
int i,x;
x=root->linkc;
 for(i=1;i<=x;i++)
 {
 if(root->link[i]->name==item)
 {
   return root->link[i];
 }
 }
  return NULL;
}

int main()
{
 int t,i,supcount=4;
 trans troot,cur;
 troot=gettrans();
 node root;
 root=getnode();
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
 for(i=1;i<=n;i++)
 {
  printf("%d ",count[i]);
 }
 printf("\n");
 print(troot);
 delete_less_than_supcount(supcount,troot);
 printf("after deletion\n");
 print(troot);
 sort_on_priority(troot);
 printf("after sorting\n");
 print(troot);
 cur=troot;
 for(i=1;i<=t;i++)
 {
 root=insert(root,cur);
 cur=cur->link;
 } 
 printf("%d %d\n",root->link[1]->name,root->link[1]->counter);
  return 0;
}
