#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include "insert.h"
#include "showinorder.h"
#include "delete.h"
using namespace std;
class EMPTY {};
class EXISTS{};
DELETE D;
bst *root = NULL, *newnode, *p;
void createbst(int dat)
{
	newnode = new bst;
	newnode->data = dat;
	newnode->left = NULL;
	newnode->right = NULL;
	if (root == NULL)
	{
		root = newnode;
	}
	else
	{
		int flag = 0;
		p = root;
		while (flag == 0)
		{
			if (newnode->data < p->data)
			{
				if (p->left == NULL)
				{
					p->left = newnode;
					flag = 1;
				}
				else
				{
					p = p->left;
				}
			}
			else if (newnode->data == p->data)
			{
				throw EXISTS();
			}
			else
			{
				if (p->right == NULL)
				{
					p->right = newnode;
					flag = 1;
				}
				else
				{
					p = p->right;
				}
			}
		}
	}
}
void preorder(bst *q)
{
	if (root == NULL)
	{
		throw EMPTY();
	}
	if (q != NULL)
	{
		cout << q->data << ends;
		preorder(q->left);
		preorder(q->right);
	}
}
void postorder(bst *q)
{
	if (root == NULL)
		throw EMPTY();
	else if (q != NULL)
	{
		postorder(q->left);
		postorder(q->right);
		cout << q->data << ends;
	}
}
void inorder(bst *q)
{
	if (root == NULL)
		throw EMPTY();
	else if (q != NULL)
	{
		inorder(q->left);
		cout << q->data << ends;
		inorder(q->right);
	}
}
bool searchdata(bst *q, int m)
{
	if (q != NULL)
	{
		if (q->data == m)
		{
			return true;
		}
		else if (q->data > m)
			searchdata(q->left, m);
		else
			searchdata(q->right, m);
	}
	else
		return false;
}
void deletenode(bst *q, int m,int gfact=999)
{
	bst *temp;
	temp = q;
	if (temp != NULL)
	{
		if (temp->data == m)
		{
			if (temp->left == NULL && temp->right == NULL)
			{
				if(gfact==999)
					D.afterdeletions(root, m);
				if (temp == root)
				{
					root = NULL;
					delete temp;
				}
				else if (p->right == NULL)
				{
					p->left = NULL;
					delete temp;
				}
				else if (p->left == NULL)
				{
					p->right = NULL;
					delete temp;
				}
				else if (p->left->data == m)
				{
					delete temp;
					p->left = NULL;
				}
				else
				{
					p->right = NULL;
					delete temp;
				}
			}
			else if (temp->right == NULL)
			{
				if (p->left != NULL)
				{
					if (gfact == 999)
						D.afterdeletions(root, m, temp->left->data,1);
					if (p->left->data == m)
					{
						p->left = temp->left;
						delete temp;
					}
					else
					{
						p->right = temp->left;
						delete temp;
					}
				}
				else
				{
					if (gfact == 999)
						D.afterdeletions(root, m,temp->left->data,1);
					p->right = temp->left;
					delete temp;
				}
			}
			else if (temp->left == NULL)
			{
				if (root == temp)
				{
					if (gfact == 999)
						D.afterdeletions(root, m, temp->right->data,1);
					root = temp->right;
					delete temp;
				}
				else if (p->left!=NULL && p->left->data == m)
				{
					if (gfact == 999)
						D.afterdeletions(root, m, temp->right->data,1);
					p->left = temp->right;
					delete temp;
				}
				else
				{
					if (gfact == 999)
						D.afterdeletions(root, m, q->right->data,1);
					p->right = q->right;
					delete temp;
				}
			}
			else
			{
				bst *temp1 = q;
				if (q != NULL)
				{
					if (q->left != NULL)
					{
						q = q->left;
						while (q->right != NULL)
						{
							q = q->right;
						}
						int k = q->data;
						D.afterdeletions(root, m, k,2);
						deletenode(root, q->data,1);
						temp1->data = k;
					}
					else
					{
						q = q->right;
						while (q->left != NULL)
						{
							q = q->left;
						}
						int k = q->data;
						D.afterdeletions(root, m, k,2);
						deletenode(root, q->data,1);
						temp1->data = k;
					}
				}
			}
		}
		else if (temp->data > m)
		{
			p = temp;
			deletenode(temp->left, m, gfact);
		}
		else
		{
			p = temp;
			deletenode(temp->right, m ,gfact);
		}
	}
}
int main()
{
	ORDER O;
	int i, data, arr[10] = { 10,4,6,5,20,30,40,23,24,26 };
	while(true)
	{
		try
		{
			cout<<"1.PUSH\n2.TRAVERSE PREORDER\n3.TRAVERSE POSTORDER\n4.TRAVERSE INORDER\n5.SEARCH\n";
			cout<<"6.DELETENODE\n7.EXIT\n";
			cout<<"Enter your choice:";
			cin>>i;
			if(i==1)
			{
				INSERT A;
				cout<<"Enter data do you want to push:";
				cin>>data;
				createbst(data);
				A.afterinsertion(root,data);
				/*
				for (i = 0; i < 10; i++)
				{
					createbst(arr[i]);
				}
				*/

			}
			else if(i==2)
			{
				cout<<"\nPreorder Traversing\n";
				O.order(root,1);
				preorder(root);
			}
			else if(i==3)
			{
				cout<<"\nPostorder Traversing\n";
				O.order(root, 2);
				postorder(root);
			}
			else if(i==4)
			{
				cout<<"\nInorder Traversing\n";
				O.order(root, 3);
				inorder(root);
			}
			else if(i==5)
			{
				cout<<"Enter data to be searched:";
				cin>>data;
				if(searchdata(root,data)==1)
				{
					cout<<"Data found\n";
				}
				else
				{
					cout<<"Data not found\n";
				}
			}
			else if(i==6)
			{
				cout<<"Enter data to be deleted:";
				cin>>data;
				deletenode(root, data);
			}
			else
			{
				exit(0);
			}
		}
		catch(EMPTY)
		{
			cout<<"The tree is empty\n";
		}
		catch (EXISTS)
		{
			cout << "Already exists";
		}
		cin.get();
		cin.get();
		system("cls");
	}
	return 0;
}
