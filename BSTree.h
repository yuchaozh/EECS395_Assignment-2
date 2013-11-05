/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */
#ifndef WORKSPACE_BSTree_H
#define WORKSPACE_BSTree_H

#include "BSTNode.h"

using namespace std;

class BSTree
{
public:
	BSTree();
	BSTree(int x_coordinate, int y_coordinate, string name);
	void destroyTree(BSTNode* node);
	void insert(int x_coordinate, int y_coordinate, string name);
	void remove(string name);
	void findNode(string name); 
	BSTNode* findMin(BSTNode* node);
	void preOrderTraverse();
	void visitNode(BSTNode* node);
private:
	BSTNode *root;
	void findNode(string name, BSTNode* node);
	void remove(string name, BSTNode* &node);
	void preOrderTraverse(BSTNode* node);
	void insert(BSTNode* node, int x_coordinate, int y_coordinate, string name);
};
#endif