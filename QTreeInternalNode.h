/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */
#ifndef WORKSPACE_QTREEINTERNALNODE_H
#define WORKSPACE_QTREEINTERNALNODE_H

#include "QTNode.h"
using namespace std;


class QTreeInternalNode : public QTNode
{
public:
	QTreeInternalNode* parent;
	QTreeLeafNode* nw;
	QTreeLeafNode* ne;
	QTreeLeafNode* sw;
	QTreeLeafNode* se;

	QTreeInternalNode()
	{
		xMin = 0;
		xMax = 0;
		yMin = 0;
		yMax = 0;
		nw = NULL;
		ne = NULL;
		sw = NULL;
		se = NULL;
	}
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
	}


};