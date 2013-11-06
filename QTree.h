/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */
#ifndef WORKSPACE_QTree_H
#define WORKSPACE_QTree_H

#include "QTNode.h"

using namespace std;

class QTree
{
public:
	void insert(int x_coordinate, int y_coordinate, string name);
	void remove(int x_coordinate, int y_coordinate);
	void findNode(int x_coordinate, int y_coordinate);
	void visitNode(QTreeLeafNode* node);
private:
	QTreeInternalNode* internalRoot;
	QTreeLeafNode* leafRoot;
	void insert(QTNode* node, int x_coordinate, int y_coordiante, string name);
	void remove(QTreeInternalNode* root, int x_coordinate, int y_coordinate);
	void findNode(QTNode* node, int x_coordinate, int y_coordinate);
	string location(QTreeInternalNode* node, int x_coordinate, int y_coordinate);
};

#endif