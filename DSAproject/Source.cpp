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
#include "Mainmenu.h"
#include "err.h"
using namespace std;
class EMPTY {};
class EXISTS{};
class DONOTEXISTS{};
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
/*
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
*/
void searchdata(bst *q, int m)
{
	if (q != NULL)
	{
		if (q->data == m)
		{
			
		}
		else if (q->data > m)
			searchdata(q->left, m);
		else
			searchdata(q->right, m);
	}
}
void deletenode(bst *q, int m,int gfact=999)
{
	bst *temp;
	temp = q;
	if (root == NULL)
	{
		throw EMPTY();
	}
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
	else
	{
	throw DONOTEXISTS();
	}
}
int main()
{
	sf::ContextSettings settings;
	int arr[10] = { 10,4,6,5,20,30,40,23,24,26 };
	sf::RenderWindow window;
	INSERT IN;
	mainmenu M;
	INPUT A;
	int x, num;
	while (true)
	{
		try
		{
			x = M.draw();
			switch (x)
			{
			case 1:
				num = A.inputs(&window);
				if (num != -1)
				{
					settings.antialiasingLevel = 8;
					window.create(sf::VideoMode(1300, 750), "Insertion Process", sf::Style::Default, settings);
					window.setPosition(sf::Vector2i(10, 10));
					if (root != NULL)
					{
						IN.afterinsertion(&window, root, num, 0);
					}
					createbst(num);
					IN.afterinsertion(&window,root, num,1);
				}
				break;
			case 2:
				num = A.inputs(&window);
				if (num != -1)
				{
					deletenode(root,num);
				}
				break;
			case 3:
				SEARCH SS;
				num = A.inputs(&window);
				if (num != -1)
				{
					SS.search(root, num);
				}
				break;
			case 4:
				return 1;
			}
		}
		catch (EMPTY)
		{
			EMPTYOREXISTS B;
			B.showerr("Empty Tree");
		}
		catch (EXISTS)
		{
			EMPTYOREXISTS B;
			B.showerr("Data already present");
		}  
		catch (DONOTEXISTS)
		{
			EMPTYOREXISTS B;
			B.showerr("No such data found.");
		}
	}
	return 0;
}
