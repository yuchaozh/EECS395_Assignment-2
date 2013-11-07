/*
 *Author: Yuchao Zhou
 *Time: 11/05/2013
 */
#ifndef WORKSPACE_QTREELEAFNODE_H
#define WORKSPACE_QTREELEAFNODE_H

#include "QTNode.h"
#include "QTreeInternalNode.h"
#include <string>
#include <iostream>

using namespace std;

class QTreeLeafNode : public QTNode
{
public:
	//QTreeInternalNode* parent;
	//int x;
	//int y;
	//string cityName;
	//string directionInParent;

	QTreeLeafNode(string dir)
	{
		x = 0;
		y = 0;
		cityName = "";
		directionInParent = dir;
		internal = false;
	}
	QTreeLeafNode(int x_coordinate, int y_coordinate, string name, string dir)
	{
		x = x_coordinate;
		y = y_coordinate;
		cityName = name;
		directionInParent = dir;
		internal = false;
	}
};
#endif