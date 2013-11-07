/*
 *Author: Yuchao Zhou
 *Time: 11/05/2013
 */
#ifndef WORKSPACE_QTINTERNALNODE_H
#define WORKSPACE_QTINTERNALNODE_H

#include "QTNode.h"
#include "QTreeLeafNode.h"
#include <string>
#include <iostream>

using namespace std;

class QTreeInternalNode : public QTNode
{
public:
	//QTreeInternalNode* parent;
	//QTNode* nw;
	//QTNode* ne;
	//QTNode* sw;
	//QTNode* se;

	//QTreeInternalNode()
	//{
	//	xMin = 0;
	//	xMax = 0;
	//	yMin = 0;
	//	yMax = 0;
	//	nw = NULL;
	//	ne = NULL;
	//	sw = NULL;
	//	se = NULL;
	//	//nw = new QTreeLeafNode("nw");
	//	//ne = new QTreeLeafNode("ne");
	//	//sw = new QTreeLeafNode("sw");
	//	//se = new QTreeLeafNode("se");
	//}
	QTreeInternalNode(int x_Min, int x_Max, int y_Min, int y_Max)
	{
		xMin = x_Min;
		xMax = x_Max;
		yMin = y_Min;
		yMax = y_Max;
		nw = NULL;
		ne = NULL;
		sw = NULL;
		se = NULL;
		internal = true;
		//nw = new QTreeLeafNode("nw");
		//ne = new QTreeLeafNode("ne");
		//sw = new QTreeLeafNode("sw");
		//se = new QTreeLeafNode("se");
	}

	//~QTreeInternalNode()
	//{

	//}
};

#endif