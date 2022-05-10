#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct node
{
	int data;
	node *lchild,*rchild;
};
int n;
node *root=NULL,*next,*new2;
class BST
{

 public:
	node* create();
	void insert(node *root,node *next);
	void delnode(node *root);
	void traversal();
	void inorder(node *root);
	void preorder(node *root);
	void postorder(node *root);
	void findmin(node *root);
	void findmax(node *root);
};



void main()
{
	int ch;
	BST b;
	node *x;
	clrscr();
	do
	{
		 cout<<"\n\t*****MENU*****\n";
		 cout<<"\n 1.INSERT NODE";
		 cout<<"\n 2.DELETE NODE";
		 cout<<"\n 3.TREE TRAVERSAL";
		 cout<<"\n 4.FIND SMALLEST ELEMENT";
		 cout<<"\n 5.FIND LARGEST ELEMENT";
		 cout<<"\n 6.EXIT";
		 cout<<"\n\n ENTER UR CHOICE==>";
		 cin>>ch;
		 switch(ch)
		 {
			  case 1:
				x=b.create();
				b.insert(root,x);
			  break;
			  case 2:
				cout<<"\n DELETE NODE FROM BINARY TREE";
				cout<<"\n ENTER THE DATA TO DELETE NODE==>";
				cin>>n;
				b.delnode(root);
			  break;
			  case 3:
				cout<<"\n TRIVAL BINARY TREE";
				b.traversal();
			  break;
			  case 4:
				b.findmin(root);
			  break;
			  case 5:
				b.findmax(root);
			  break;
			  case 6:
				exit(0);
			  break;

		 }
		 cout<<"\n\n DO U WANT TO GO TO MAIN MENU [0=NO/1=YES] ==>";
		 cin>>ch;
	} while(ch==1);
	getch();
}


node* BST :: create()
{
	 new2=(node*)malloc(sizeof(node));
	 cout<<"\n ENTER DATA FOR THE NODE==>";
	 cin>>new2->data;
	 new2->lchild=NULL;
	 new2->rchild=NULL;
	 return(new2);
}

void BST::insert(node *root1,node *new1)
{
	  char ch;
	  if(root==NULL)
	  {
		root=new1;
		cout<<"\n Node inserted as root node";
	  }
	  else
	  {
		if(new1->data<root1->data)
		{
			if(root1->lchild==NULL)
			{
				root1->lchild=new1;
				cout<<"\n Node inserted on left side of "<<root1->data<<"\n";
			}
			else
				insert(root1->lchild,new1);

		}

		if(new1->data>root1->data)
		{
			if(root1->rchild==NULL)
			{
			     root1->rchild=new1;
			     cout<<"\n Node inserted on right side of "<<root1->data<<"\n";
			}
			else
			    insert(root1->rchild,new1);
		}
	  }
}

void BST::inorder(node *root)
{
	if(root!=NULL)
	{
	  inorder(root->lchild);
	  cout<<" " <<root->data;
	  inorder(root->rchild);
	}
}

void BST::preorder(node *root)
{
	if(root!=NULL)
	{
	   cout<<" "<<root->data;
	   preorder(root->lchild);
	   preorder(root->rchild);
	}
}

void BST::postorder(node *root)
{
	if(root!=NULL)
	{
	  postorder(root->lchild);
	  postorder(root->rchild);
	  cout<<" "<<root->data;
	}
}

void BST :: traversal()
{
	int ch;
	BST b;
	clrscr();

	cout<<"\n\n 1.INORDER TRAVERSAL";
	cout<<"\n\n 2.PREORDER TRAVERSAL";
	cout<<"\n\n 3.POSTORDER TRAVERSAL";
	cout<<"\n\n ENTER UR CHOICE==>";
	cin>>ch;
	switch(ch)
	{

		case 1:
			cout<<"\n INORDER TRAVERSAL IS";
			b.inorder(root);
		break;
		case 2:
			cout<<"\n PREORDER TRAVERSAL IS";
			b.preorder(root);
		break;
		case 3:
			cout<<"\n POSTORDER TRAVERSAL IS";
			b.postorder(root);
		break;
	}
}
void BST::findmin(node *r)
{
   if(r->lchild==NULL)
   {
	cout<<"\n The Smallest element in a tree is==>"<<r->data;
   }
   else
   {
       findmin(r->lchild);
   }
}

void BST::findmax(node *r)
{
   if(r->rchild==NULL)
   {
	cout<<"\n The Largest element in a tree is==>"<<r->data;
   }
   else
   {
       findmax(r->rchild);
   }

}

void BST:: delnode(node *r)
{
	node *curr;
	if(root->data==n)
	{
		cout<<"\n THE NODE U WANT TO DELETE IS A ROOT NODE";
		cout<<"SO CANT DELETE IT";
	}
       else if(n<r->data)
	{
	       curr=r->lchild;
	       if(curr->data==n)
	       {
			if(curr->lchild==NULL && curr->rchild==NULL)
			{
				r->lchild=NULL;
				free(curr);
				cout<<"\n NODE DELETED SUCESSFULY";
			}
			else
			{
				cout<<"\n NODE HAS A CHILD SO CANT DELETE";

			}
	       }
	       else
	       {
			delnode(r->lchild);
	       }
	}
	else if(r->data<n)
	{
	       curr=r->rchild;
	       if(curr->data==n)
	       {
			if(curr->lchild==NULL && curr->rchild==NULL)
			{
				r->rchild=NULL;
				free(curr);
				cout<<"\n NODE DELETED SUCESSFULY";
			}
			else
			{
				cout<<"\n NODE HAS A CHILD SO CANT DELETE";

			}
	       }
	       else
	       {
			delnode(r->rchild);
	       }
	}
	else if(r->data!=n)
	{
		cout<<"\n The data u want to delete is not present in a tree";
	}
}
