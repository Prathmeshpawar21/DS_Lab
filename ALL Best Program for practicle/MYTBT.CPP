#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *lchild,*rchild;
	int lthread,rthread;
};

node *dummy=NULL,*root=NULL,*next,*temp;

class TBT
{
     public:
	node* create();
	void insert(node*,node*);
	void inorder(node*);
	void preorder(node*);
	void postorder(node*);
};


void main()
{
  int ch1;
  TBT t;
  node *x;
  clrscr();
  do
  {
     cout<<"\n *** MENU ***";
     cout<<"\n1.INSERT NODE THREADED BINARY TREE";
     cout<<"\n2.INORDER";
     cout<<"\n3.PREORDER";
     cout<<"\n4.POSTORDER";
     cout<<"\n5.EXIT";
     cout<<"\nENTER YOUR CHOICE:\t";
     cin>>ch1;
     switch(ch1)
     {
       case 1:
	      cout<<"\nCREATE TBT";
	      x=t.create();
	      t.insert(root,x);
	      break;

       case 2:
	      cout<<"\nINORDER TRAVERSAL OF TBT IS AS:";
	      t.inorder(root);
	      break;

       case 3:
	      cout<<"\nPREORDER TRAVERSAL OF TBT IS AS:";
	      t.preorder(root);
	      break;

       case 4:
	      cout<<"\nPOSTORDER TRAVERSAL OF TBT IS AS:";
	      t.postorder(root);
	      break;

       case 5:
	      exit(0);
	      break;
     }
     cout<<"\nDO YOU WANT TO CONTINUE ABOVE OPERATION[1=YES/0=NO]:\t";
     cin>>ch1;
  }
  while(ch1==1);
  getch();
}




node* TBT::create()
{
   node *new2;
   new2=(node*)malloc(sizeof(node));
   cout<<"\n ENTER THE DATA FOR THE NODE:\t";
   cin>>new2->data;
   new2->lchild=NULL;
   new2->rchild=NULL;
   new2->lthread=0;
   new2->rthread=0;
   return(new2);
}

void TBT::insert(node *root1,node *new1)
{

   if(dummy==NULL)
   {
	dummy=new1;
	dummy->lthread=0;   //LINK IS PRESENT
	dummy->rthread=0;   //THREAD IS PRESENT
	dummy->lchild=dummy;
	dummy->rchild=dummy;
	cout<<"\n THE DUMMY NODE IS CREATED & INSERTED:\t";
   }

   else if(root==NULL)
   {
	root=new1;
	dummy->lchild=root;
	dummy->lthread=1;
	root->lchild=dummy;
	root->rchild=dummy;
	root->lthread=0;
	root->rthread=0;
	cout<<"\n THE NODE IS INSERTED AS ROOT NODE ";

   }
   else
   {
	if(new1->data<root1->data)
	{
	     if(root1->lthread==0)
	     {
		new1->lchild=root1->lchild;
		new1->rchild=root1;
		root1->lchild=new1;
		root1->lthread=1;
		cout<<"\n THE NODE IS INSERTED IN LEFT SIDE OF "<<root1->data;
	     }
	     else
	     {
		insert(root1->lchild,new1);
	     }
	}

	if(new1->data>=root1->data)
	{
	     if(root1->rthread==0)
	     {
		new1->rchild=root1->rchild;
		root1->rchild=new1;
		new1->lchild=root1;
		root1->rthread=1;
		new1->lthread=0;
		new1->rthread=0;
		cout<<"\n THE NODE IS INSERTED IN RIGHT SIDE OF "<<root1->data;
	     }
	     else
	     {
		insert(root1->rchild,new1);
	     }
	}
   }
}


void TBT::inorder(node *root)
{
    int flag=0;
    temp=root;
    do
    {
    while(temp!=dummy)
    {
       while(flag==0 && temp->lthread==1)
       {
	 temp=temp->lchild;
       }
       if(temp->lthread==0)
	 cout<<temp->data<<"\t";
       if(temp->rthread==1)
       {
	 temp=temp->rchild;
	 flag=0;
       }
       else
       {
	 temp=temp->rchild;
	 cout<<temp->data<<"\t";
	 flag=1;
       }
    }
    }while(temp!= dummy);
}

void TBT::preorder(node *root)
{
  int flag=0;

  temp=root;
  while(temp!=dummy)
  {
    while(flag==0 && temp->lthread==1)
    {
       cout<<temp->data<<"\t";
       temp=temp->lchild;
    }
    if(temp->lthread==0)
       cout<<temp->data<<"\t";
    if(temp->rthread==1)
    {
       temp=temp->rchild;
       flag=0;
    }
    else
    {
       temp=temp->rchild;
       flag=1;
    }
  }
}

void TBT::postorder(node *root)
{
   int flag=0,j=-1,i;
   int a[20];
   temp=root;
   while(temp!=dummy)
   {
      while(flag==0 && temp->rthread==1)
      {
	j++;
	a[j]=temp->data;
	temp=temp->rchild;
      }
      if(temp->rthread==0)
      {
	 j++;
	 a[j]=temp->data;
      }
      if(temp->lthread==1)
      {
	 temp=temp->lchild;
	 flag=0;
      }
      else
      {
	  temp=temp->lchild;
	  flag=1;
      }
   }
   for(i=j;i>=0;i--)
      cout<<a[i]<<"\t";
}

