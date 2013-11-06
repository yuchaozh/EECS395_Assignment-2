/*
 *Author: Yuchao Zhou
 *Time: 11/05/2013
 */
#ifndef WORKSPACE_QTNODE_H
#define WORKSPACE_QTNODE_H

#include <string>
#include <iostream>

using namespace std;

class QTNode
{
public:
	int xMin, xMax, yMin, yMax;

	//virtual void setXMin(int x_Min) = 0;
	QTNode();
	QTNode(int x_Min, int x_Max, int y_Min, int y_Max);
};

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

class QTreeLeafNode : public QTNode
{
public:
	QTreeInternalNode* parent;
	int x;
	int y;
	string cityName;

	QTreeLeafNode()
	{
		x = 0;
		y = 0;
		cityName = "";
	}
	QTreeLeafNode(int x_coordinate, int y_coordinate, string name)
	{
		x = x_coordinate;
		y = y_coordinate;
		cityName = name;
	}
};

#endif