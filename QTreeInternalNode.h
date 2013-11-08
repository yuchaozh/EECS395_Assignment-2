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
		children = 0;
		parent = NULL;
	}
};
#endif