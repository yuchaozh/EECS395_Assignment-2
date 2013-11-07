/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */
#ifndef WORKSPACE_QRTree_H
#define WORKSPACE_QRTree_H

#include "QTNode.h"
#include "QTreeLeafNode.h"
#include "QTreeInternalNode.h"

using namespace std;

class QRTree
{
public:
	QRTree();
	bool isEmpty();
	void insert(int x_coordinate, int y_coordinate, string name);
	void search(int x_coordinate, int y_coordinate, int radius);
	void remove(int x_coordinate, int y_coordinate);
	void findNode(int x_coordinate, int y_coordinate);
	void debug();
	void visitNode(QTNode* Node);
	//QTreeLeafNode* search(int x_coordinate, int y_coordinate);
	void output(QTNode* node, int x_coordinate, int y_coordinate, int radius);
	bool internalIsEmpty(QTreeInternalNode* node);
	void decompose(QTreeLeafNode* node, int x_coordinate, int y_coordinate, string direction);
	bool decomposeFinish(QTreeInternalNode* node, QTreeLeafNode* targetNode, int x_coordinate, int y_coordinate);
	QTNode* determineDirection(QTreeInternalNode* node, int x_coordinate, int y_coordinate);
private:
	QTreeInternalNode* internalRoot;
	QTreeLeafNode* leafRoot;
	//QTreeLeafNode* search(QTNode* node, int x_coordinate, int y_coordinate);
	void insert(QTNode* node, int x_coordinate, int y_coordiante, string name);
	void remove(QTreeInternalNode* root, int x_coordinate, int y_coordinate);
	QTreeLeafNode* findNode(QTNode* node, int x_coordinate, int y_coordinate);
	string location(QTreeInternalNode* node, int x_coordinate, int y_coordinate);
	void search(QTNode* node, int x_coordinate, int y_coordinate, int radius);
	void debug(QTNode* node);
};

#endif