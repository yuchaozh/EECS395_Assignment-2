/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */

#include "BSTree.h"

BSTNode::BSTNode()
{
	x = 0;
	y = 0;
	cityName = "";
	left = NULL;
	right = NULL;
}

BSTNode::BSTNode(int x_coordinate, int y_coordinate, string name)
{
	x = x_coordinate;
	y = y_coordinate;
	cityName = name;
	left = NULL;
	right = NULL;
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
		destroyTree(node->getLeft());
		destroyTree(node->getRight());
		delete node;
	}
}

//insert node into the tree, if name is equal insert into right
void BSTree::insert(BSTNode* node, int x_coordinate, int y_coordinate, string name)
{
	if (root == NULL)
	{
		root = new BSTNode(x_coordinate, y_coordinate, name);
		return;
	}
	if (name < node->getName())
	{
		if (node->getLeft()!= NULL)
		{
			insert(node->getLeft(), x_coordinate, y_coordinate, name);
		}
		else
		{
			BSTNode* newNode = new BSTNode(x_coordinate, y_coordinate, name);
			node->setLeft(newNode);
		}
	}
	else
	{
		if (node->getRight()!= NULL)
		{
			insert(node->getRight(), x_coordinate, y_coordinate, name);
		}
		else
		{
			BSTNode* newNode = new BSTNode(x_coordinate, y_coordinate, name);
			node->setRight(newNode);
		}
	}
}

//remove function
void BSTree::remove(string name, BSTNode* node)
{
	if (node == NULL)
		return;
	if (name < node->getName())
	{
		remove(name, node->getLeft());
	}
	else if (name >= node->getName())
	{
		remove(name, node->getRight());
	}
	else if (node->getLeft() != NULL && node->getRight() != NULL)  //two children
	{
		node->setName(findMin(node->getRight())->getName());
		node->setX(findMin(node->getRight())->getX());
		node->setY(findMin(node->getRight())->getY());
		remove(node->getName(), node->getRight());
	}
	else
	{
		BSTNode* parent = node;
		if (node->getLeft() != NULL)
		{
			node = node->getLeft();
		}
		else 
		{
			node = node->getRight();
		}
		delete parent;
	}
}

//find the minimum node in the right subtree
BSTNode* BSTree::findMin(BSTNode* node)
{
	if(node == NULL )
        return NULL;
	if(node->getLeft() == NULL )
        return node;
	return findMin(node->getLeft());
}