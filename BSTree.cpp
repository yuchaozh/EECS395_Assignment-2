/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */

#include "BSTree.h"
#include <iostream>

using namespace std;

BSTNode::BSTNode()
{
	x = 0;
	y = 0;
	cityName = "";
	left = NULL;
	right = NULL;
	down = NULL;
}

BSTNode::BSTNode(int x_coordinate, int y_coordinate, string name)
{
	x = x_coordinate;
	y = y_coordinate;
	cityName = name;
	left = NULL;
	right = NULL;
	down = NULL;
}

//constructor
BSTree::BSTree()
{
	root = NULL;
}

//delete all nodes in the tree
void BSTree::destroyTree(BSTNode* node)
{
	if(node!=NULL)
	{
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
}

void BSTree::insert(int x_coordinate, int y_coordinate, string name)
{
	if (root == NULL)
	{
		root = new BSTNode(x_coordinate, y_coordinate, name);
	}
	else
	{
		insert(root, x_coordinate, y_coordinate, name);
	}
}

//insert node into the tree, if name is equal insert into right
void BSTree::insert(BSTNode* node, int x_coordinate, int y_coordinate, string name)
{
	if (node == NULL)
	{
		node = new BSTNode(x_coordinate, y_coordinate, name);
		//cout<<node->cityName<<" "<<node->x<<" "<<node->y<<" "<<node->left<<" "<<node->right<<" "<<node->down<<endl;
		return;
	}
	// if the name is smaller, then store into the left subtree
	else if (name < node->cityName)
	{
		if (node->left!= NULL)
		{
			//insert(node->left, x_coordinate, y_coordinate, name);
			insert(node->left, x_coordinate, y_coordinate, name);
		}
		else
		{
			BSTNode* newNode = new BSTNode(x_coordinate, y_coordinate, name);
			node->left = newNode;
		}
	}
	// if the name is bigger, then store into the right subtree
	else if (name > node->cityName)
	{
		if (node->right!= NULL)
		{
			insert(node->right, x_coordinate, y_coordinate, name);
		}
		else
		{
			BSTNode* newNode = new BSTNode(x_coordinate, y_coordinate, name);
			node->right = newNode;
		}
	}
	// if the name is same then store into the down list
	else if (name == node->cityName)
	{
		while (node->down!= NULL)
		{
			node = node->down;
		}
		BSTNode* newNode = new BSTNode(x_coordinate, y_coordinate, name);
		node->down = newNode;
	}
}

void BSTree::remove(string name)
{
	cout<<"the city goint to remove: "<<name<<endl;
	remove(name, root);
}

//remove function
void BSTree::remove(string name, BSTNode* &node)
{
	if (node == NULL)
	{
		cout<<"can not find it."<<endl;
		return;
	}
		
	if (name < node->cityName)
	{
		remove(name, node->left);
	}
	else if (name > node->cityName)
	{
		remove(name, node->right);
	}
	else if (node->left != NULL && node->right != NULL)  //two children
	{
		cout<<"two children"<<endl;
		node-> cityName = (findMin(node->right)->cityName);
		node-> x = (findMin(node->right)->x);
		node->y = (findMin(node->right)->y);
		node->down = (findMin(node->right)->down);
		//node->left = (findMin(node->right)->left);
		//node->right = (findMin(node->right)->right);
		remove(node->cityName, node->right);
	}
	else
	{
		BSTNode* current =  node;
		if (node->left != NULL)
		{
			node = node->left;
		}
		else 
		{
			node = node->right;
		}
		delete current;
	}
}

//find the minimum node in the right subtree
BSTNode* BSTree::findMin(BSTNode* node)
{
	if(node == NULL )
        return NULL;
	if(node->left == NULL )
        return node;
	return findMin(node->left);
}

void BSTree::preOrderTraverse()
{
	cout<<"~~~~~~~~~~~~preOrderTraverse~~~~~~~~~~~~~~"<<endl;
	preOrderTraverse(root);
}

void BSTree::preOrderTraverse(BSTNode* node)
{
	if(node == NULL)  
	{
		return;  
	}
	visitNode(node);
	preOrderTraverse(node->left); 
	preOrderTraverse(node->right); 
}

void BSTree::visitNode(BSTNode* node)
{
	cout<<"name: "<<node->cityName<<endl;
	cout<<"left: "<<node->left<<endl;
	cout<<"right: "<<node->right<<endl;
	if (node->down!=NULL)
	{
		cout<<"has countries with same name: "<<endl;
		while (node->down!= NULL)
		{
			cout<<"cityName: "<<node->cityName<<"  X_Coordinate: "<<node->x<<"  Y_Coordinate:"<<node->y
			<<"  otherCity:"<<node->down<<endl;
			node = node->down;
		}
		cout<<"cityName: "<<node->cityName<<"  X_Coordinate: "<<node->x<<"  Y_Coordinate:"<<node->y
			<<"  otherCity:"<<node->down<<endl;
	}
	else
	{
		cout<<"cityName: "<<node->cityName<<"  X_Coordinate: "<<node->x<<"  Y_Coordinate:"<<node->y
			<<"  otherCity:"<<node->down<<endl;
	}
}

void BSTree::findNode(string name)
{
	return findNode(name, root);
}

void BSTree:: findNode(string name, BSTNode* node)
{
	if (node == NULL)
	{
		cout<<"Can not find node: "<<endl;
	}
	else if((name == node->cityName)) // not present, or present here 
    {
		visitNode(node);
    }
    // otherwise look in left / right subtree as appropriate 
	else if(name < node->cityName)
	{
		return findNode(name, node->left);
    }
    else
    {
		return findNode(name, node->right);
    }
}
//
//int main()
//{
//	BSTree tree;
//	tree.insert(500, 140, "skokie");
//	tree.insert(501, 140, "skokie");
//	tree.insert(1,1, "bbb");
//	tree.insert(401, 500, "evanston");
//	tree.insert(402, 500, "evanston");
//	tree.insert(403, 500, "evanston");
//	tree.insert(100, 500, "aaa");
//	tree.insert(320, 888, "zzzz");
//	tree.preOrderTraverse();
//	tree.remove("aaa");
//	//tree.preOrderTraverse();
//	tree.findNode("asd");
//	system("pause");
//}