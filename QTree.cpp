/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */

#include "QTree.h"
#include <iostream>

using namespace std;

void QTree::insert(int x_coordiante, int y_coordinate, string name)
{
	insert(internalRoot, x_coordiante, y_coordinate,name);
}

void QTree::insert(QTNode* node, int x_coordinate, int y_coordinate, string name)
{
	
}

void QTree::findNode(int x_coordinate, int y_coordinate)
{
	findNode(internalRoot, x_coordinate, y_coordinate);
}

void QTree::findNode(QTNode* node, int x_coordinate, int y_coordinate)
{
	string direction;
	//if the node is a leaf node
	if (typeid(node).name() == "QTreeLeafNode")
	{
		QTreeLeafNode* leaf = static_cast<QTreeLeafNode* >(node);
		if (leaf->x == x_coordinate && leaf->y == y_coordinate)
		{
			cout<<"find target node."<<endl;
		}
	}
	//the node is an internal node
	else if (typeid(node).name() == "QTreeInternalNode")
	{
		QTreeInternalNode* inter = static_cast<QTreeInternalNode* >(node);
		direction = location(inter, x_coordinate, y_coordinate);
		// find in nw
		if (direction == "nw")
		{
			QTNode* qtnode = static_cast<QTNode* >(inter->nw);
			return findNode(qtnode, x_coordinate, y_coordinate);
		}
		// find in ne
		if (direction == "ne")
		{
			QTNode* qtnode = static_cast<QTNode* >(inter->ne);
			return findNode(qtnode, x_coordinate, y_coordinate);
		}
		// find in sw
		if (direction == "sw")
		{
			QTNode* qtnode = static_cast<QTNode* >(inter->sw);
			return findNode(qtnode, x_coordinate, y_coordinate);
		}
		// find in se
		if (direction == "se")
		{
			QTNode* qtnode = static_cast<QTNode* >(inter->se);
			return findNode(qtnode, x_coordinate, y_coordinate);
		}
	}
	else if (node == NULL)
	{
		cout<<"we cannot find the node."<<endl;
	}
}

string QTree::location(QTreeInternalNode* node, int x_coordinate, int y_coordinate)
{
	string location;
	int Xlength = node->xMax - node->xMin;
	int Ylength = node->yMax - node->yMin;

	int Xleft = node->xMin;
	int Xright = node->xMax;
	int Xmiddle = node->xMin + Xlength/2;

	int Yup = node->yMin;
	int Ydown = node->yMax;
	int Ymiddle = node->yMin + Ylength/2;

	//nw
	if (Xleft < x_coordinate < Xmiddle)
	{
		if (Yup < y_coordinate < Ymiddle)
		{
			location = "nw";
			return location;
		}
	}

	//ne
	if (Xmiddle < x_coordinate < Xright)
	{
		if (Yup < y_coordinate < Ymiddle)
		{
			location = "ne";
			return location;
		}
	}

	//sw
	if (Xleft < x_coordinate < Xmiddle)
	{
		if (Ymiddle < y_coordinate < Ydown)
		{
			location = "sw";
			return location;
		}
	}

	//se
	if (Xmiddle < x_coordinate < Xright)
	{
		if (Ymiddle < y_coordinate < Ydown)
		{
			location = "se";
			return location;
		}
	}

}

void QTree::visitNode(QTreeLeafNode* node)
{
	cout<<"cityName: "<<node->cityName<<"  X_Coordinate: "<<node->x<<"  Y_Coordinate:"<<node->y<<endl;
}