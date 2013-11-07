/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */

#include "QTree.h"
#include <iostream>

using namespace std;

QTree::QTree()
{
	internalRoot->xMin = 0;
	internalRoot->xMin = 16384;
	internalRoot->yMin = 0;
	internalRoot->yMax = 16384;
	internalRoot->nw = new QTreeLeafNode("nw");
	internalRoot->ne = new QTreeLeafNode("ne");
	internalRoot->sw = new QTreeLeafNode("sw");
	internalRoot->se = new QTreeLeafNode("se");
	//internalRoot->parent = NULL;
}

bool QTree::internalIsEmpty(QTreeInternalNode* node)
{
	if ((node->nw == NULL) && (node->ne == NULL) && (node->sw == NULL) && (node->se == NULL))
		return true;
	else
		return false;
}

void QTree::insert(int x_coordiante, int y_coordinate, string name)
{
	//if (isEmpty(internalRoot) == true)
	//{
		//string location1 = location(internalRoot, x_coordiante, y_coordinate);

	//}
	insert(internalRoot, x_coordiante, y_coordinate,name);
}

void QTree::insert(QTNode* node, int x_coordinate, int y_coordinate, string name)
{
	//locate the leaf node
	QTreeLeafNode* target = findNode(node, x_coordinate, y_coordinate);
	//if the leaf node is empty, then store into it.
	if (target->cityName == "")
	{
		target->cityName = name;
		target->x = x_coordinate;
		target->y = y_coordinate;
	}
	//if the leaf already contain the same city
	else if (target->cityName == name || ((target->x == x_coordinate) && (target->y == y_coordinate)))
	{
		cout<<"node already exist."<<endl;
	}
	//if the leaf contain another record, decomposed it until fall into different leaf node
	else
	{
		QTreeInternalNode* parent = target->parent;
		//string dir = location(parent, x_coordinate, y_coordinate);
		//QTreeLeafNode* leaf = static_cast<QTreeLeafNode* >(determineDirection(parent, x_coordinate, y_coordinate));
		decompose(target, x_coordinate, y_coordinate, target->directionInParent);
		insert(x_coordinate, y_coordinate, name);
	}

}

bool QTree::decomposeFinish(QTreeInternalNode* node, QTreeLeafNode* targetNode, int x_coordinate, int y_coordinate)
{
	bool finish = false;
	if (location(node, targetNode->x, targetNode->y) == location(node, x_coordinate, y_coordinate))
	{
		finish = false;
	}
	else
	{
		finish = true;
	}
	return finish;
}

void QTree::decompose(QTreeLeafNode* node, int x_coordinate, int y_coordinate, string direction)
{
	QTreeInternalNode* newNode;
	int Xlength = node->parent->xMax - node->parent->xMin;
	int Ylength = node->parent->yMax - node->parent->yMin;

	int xleft = node->parent->xMin;
	int xright = node->parent->xMax;

	int yup = node->parent->yMin;
	int ydown = node->parent->yMax;

	int Xmiddle = node->parent->xMin + Xlength/2;
	int Ymiddle = node->parent->yMin + Ylength/2;

	if (node->directionInParent == "nw")
	{
		newNode = new QTreeInternalNode(xleft, Xmiddle, yup, Ymiddle);
		newNode->parent = node->parent;
		node->parent->nw = newNode;
		insert(node->x, node->y, node->cityName);	
	}

	if (node->directionInParent == "ne")
	{
		newNode = new QTreeInternalNode(Xmiddle, xright, yup, Ymiddle);
		newNode->parent = node->parent;
		node->parent->ne = newNode;
		insert(node->x, node->y, node->cityName);	
	}

	if (node->directionInParent == "sw")
	{
		newNode = new QTreeInternalNode(xleft, Xmiddle, Ymiddle, ydown);
		newNode->parent = node->parent;
		node->parent->sw = newNode;
		insert(node->x, node->y, node->cityName);	
	}

	if (node->directionInParent == "se")
	{
		newNode = new QTreeInternalNode(Xmiddle, xright, Ymiddle, ydown);
		newNode->parent = node->parent;
		node->parent->se = newNode;
		insert(node->x, node->y, node->cityName);	
	}

	//if (decomposeFinish(newNode, node, x_coordinate, y_coordinate) == true)
	//{
	//	return;
	//}
	//else
	//{
	//	return decompose(QTreeLeafNode* node, int x_coordinate, int y_coordinate, string direction);
	//}
}

//determine the leaf node in which direction of the internal node
QTNode* QTree::determineDirection(QTreeInternalNode* node, int x_coordinate, int y_coordinate)
{
	string direction = location(node, x_coordinate, y_coordinate);
	if (direction == "nw")
		return node->nw;
	else if (direction == "ne")
		return node->ne;
	else if (direction == "sw")
		return node->sw;
	else
		return node->se;
}

void QTree::findNode(int x_coordinate, int y_coordinate)
{
	QTreeLeafNode* target = findNode(internalRoot, x_coordinate, y_coordinate);
	visitNode(target);
}

QTreeLeafNode* QTree::findNode(QTNode* node, int x_coordinate, int y_coordinate)
{
	string direction;
	//if the node is a leaf node
	if (typeid(node).name() == "QTreeLeafNode")
	{
		QTreeLeafNode* leaf = static_cast<QTreeLeafNode* >(node);
		if (leaf->x == x_coordinate && leaf->y == y_coordinate)
		{
			cout<<"find target node."<<endl;
			return leaf;
		}
		else
		{
			return NULL;
		}
	}
	//the node is an internal node
	else
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
		else
		{
			QTNode* qtnode = static_cast<QTNode* >(inter->se);
			return findNode(qtnode, x_coordinate, y_coordinate);
		}
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
	if ((Xleft < x_coordinate < Xmiddle) && (Yup < y_coordinate < Ymiddle))
	{
			location = "nw";
			return location;
	}

	//ne
	else if ((Xmiddle < x_coordinate < Xright) && (Yup < y_coordinate < Ymiddle))
	{
			location = "ne";
			return location;
	}

	//sw
	else if ((Xleft < x_coordinate < Xmiddle) && (Ymiddle < y_coordinate < Ydown))
	{
			location = "sw";
			return location;
	}

	//se
	else
	{
			location = "se";
			return location;
	}
}

void QTree::visitNode(QTreeLeafNode* node)
{
	cout<<"cityName: "<<node->cityName<<"  X_Coordinate: "<<node->x<<"  Y_Coordinate:"<<node->y<<endl;
}

//int main()
//{
//	QTree qtree;
//	qtree.insert(500, 400, "vance");
//	system("pause");
//}