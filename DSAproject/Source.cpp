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
using namespace std;
class EMPTY {};
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
					//cout<<"Pushed data on left node:"<<dat<<endl;
				}
				else
				{
					p = p->left;
				}
			}
			else if (newnode->data == p->data)
			{
				cout << "Already exists";
				flag = 1;
			}
			else
			{
				if (p->right == NULL)
				{
					p->right = newnode;
					flag = 1;
					//cout<<"Pushed data on right node:"<<dat<<endl;
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
void deletenode(bst *q, int m)
{
	bst *temp;
	temp = q;
	if (temp != NULL)
	{
		if (temp->data == m)
		{
			if (temp->left == NULL && temp->right == NULL)
			{
				if (temp == root)
				{
					root = NULL;
					delete temp;
				}
				else if (p->right == NULL)
				{
					p->left = NULL;
					delete temp;
					/*cout<<"Left of p or q made null\n";
					if(p->left==NULL)
					{
						cout<<"Now left null\n";
					}
					if(p->right==NULL)
					{
						cout<<"right already null\n";
					}
					*/
				}
				else if (p->left == NULL)
				{
					p->right = NULL;
					delete temp;
					/*cout<<"right of p or q made null\n";
					if(p->right==NULL)
					{
						cout<<"Now right null\n";
					}
					if(p->left==NULL)
					{
						cout<<"Left already null\n";
					}*/
				}
				else if (p->left->data == m)
				{
					//cout<<"none branch of p null.Data to be deleted on left of p:"<<p->data<<endl;
					delete temp;
					p->left = NULL;
					/*if(p->left==NULL)
					{
						cout<<"Now left null\n";
					}
					if(p->right==NULL)
					{
						cout<<"right already null\n";
					}*/
				}
				else
				{
					p->right = NULL;
					delete temp;
					/*cout<<"none branch of p null.Data to be deleted on right of p:"<<p->data<<endl;
					if(p->right==NULL)
					{
						cout<<"Now right null\n";
					}
					if(p->left==NULL)
					{
						cout<<"Left already null\n";
					}*/
				}
			}
			else if (temp->right == NULL)
			{
				if (p->left != NULL)
				{
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
					p->right = temp->left;
					delete temp;
				}
			}
			else if (temp->left == NULL)
			{
				if (root == temp)
				{
					root = temp->right;
					delete temp;
				}
				else if (p->left->data == m)
				{
					p->left = temp->right;
					delete temp;
				}
				else
				{
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
						deletenode(root, q->data);
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
						deletenode(root, q->data);
						temp1->data = k;
					}
				}
			}
		}
		else if (temp->data > m)
		{
			p = temp;
			//cout<<"Go left. p-data:"<<p->data<<endl;
			deletenode(temp->left, m);
		}
		else
		{
			p = temp;
			//cout<<"Go right: p-data:"<<p->data<<endl;
			deletenode(temp->right, m);
		}
	}
}
int main()
{
	ORDER O;
	int i, data, arr[10] = {10,4,6,5,20,30,40,25,26,24};
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
				/*//INSERT A;
				cout<<"Enter data do you want to push:";
				cin>>data;
				createbst(data);
				//A.afterinsertion(root,data);
				cout << "How many data do you want to push:";
				cin >> n;
				for (i = 0; i < n; i++)
				{
					cout << "Data " << i + 1 << ":";
					cin >> arr[i];
				}
				*/
				for (i = 0; i < 10; i++)
				{
					createbst(arr[i]);
				}
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
				deletenode(root,data);
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
		cin.get();
		cin.get();
		system("cls");
	}
	return 0;
}
