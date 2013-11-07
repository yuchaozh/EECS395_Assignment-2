/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */

#include "QRTree.h"
#include <iostream>

using namespace std;

QRTree::QRTree()
{
	internalRoot = new QTreeInternalNode(0,16384,0, 16384);

}
bool QRTree::isEmpty()
{
	if(internalRoot->nw == NULL && internalRoot->ne == NULL && internalRoot->sw == NULL && internalRoot->se == NULL)
		return true;
	else
		return false;
}

string QRTree::location(QTreeInternalNode* node, int x_coordinate, int y_coordinate)
{
	string location = "";
	int Xlength = node->xMax - node->xMin;
	int Ylength = node->yMax - node->yMin;

	int Xleft = node->xMin;
	int Xright = node->xMax;
	int Xmiddle = node->xMin + Xlength/2;

	int Yup = node->yMin;
	int Ydown = node->yMax;
	int Ymiddle = node->yMin + Ylength/2;
	//cout<<"Xlength: "<<Xlength<<endl;
	//cout<<"Ylength: "<<Ylength<<endl;
	//cout<<"Xleft: "<<Xleft<<endl;
	//cout<<"Xright: "<<Xright<<endl;
	//cout<<"Xmiddle: "<<Xmiddle<<endl;
	//cout<<"Yup: "<<Yup<<endl;
	//cout<<"Ydown: "<<Ydown<<endl;
	//cout<<"Ymiddle: "<<Ymiddle<<endl;
	//cout<<x_coordinate<<endl;
	//cout<<y_coordinate<<endl;

	//nw
	if ((Xleft < x_coordinate) && (x_coordinate < Xmiddle) && (Yup < y_coordinate) && (y_coordinate < Ymiddle))
	{
			location = "nw";
			return location;
	}

	//ne
	if ((Xmiddle < x_coordinate) && (x_coordinate < Xright) && (Yup < y_coordinate) &&(y_coordinate < Ymiddle))
	{
			location = "ne";
			return location;
	}

	//sw
	if ((Xleft < x_coordinate) && (x_coordinate < Xmiddle) && (Ymiddle < y_coordinate ) &&(y_coordinate < Ydown))
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

void QRTree::insert(int x_coordinate, int y_coordinate, string name)
	{
		string dir = location(internalRoot, x_coordinate, y_coordinate);
		if(isEmpty() == true)
		{
			if(dir == "nw")
			{
				internalRoot->nw = new QTreeLeafNode(x_coordinate, y_coordinate, name, "nw");
			}
			if(dir == "ne")
			{
				internalRoot->ne = new QTreeLeafNode(x_coordinate, y_coordinate, name, "ne");
			}
			if(dir == "sw")
			{
				internalRoot->sw = new QTreeLeafNode(x_coordinate, y_coordinate, name, "sw");
			}
			if(dir == "se")
			{
				internalRoot->se = new QTreeLeafNode(x_coordinate, y_coordinate, name, "se");
			}
		}
		else insert(internalRoot, x_coordinate, y_coordinate,name);
	}

void QRTree::insert(QTNode* node, int x_coordinate, int y_coordinate , string name)
{
	// if the node is a internal node
	if(node->internal == true)
	{
		QTreeInternalNode* temp = dynamic_cast<QTreeInternalNode*>(node);
		string dir = location(temp, x_coordinate, y_coordinate);
		//nw
		if(dir == "nw")
		{
			if(temp->nw==NULL)
				temp->nw = new QTreeLeafNode(x_coordinate, y_coordinate, name, "nw");
			else if(temp->nw->internal == true)
			{	
				QTreeInternalNode* te = dynamic_cast<QTreeInternalNode*>(temp);
				insert(te->nw, x_coordinate, y_coordinate, name);
			}
			else
			{
				int Xlength = temp->xMax - temp->xMin;
				int Ylength = temp->yMax - temp->yMin;

				int Xleft = temp->xMin;
				int Xright = temp->xMax;
				int Xmiddle = temp->xMin + Xlength/2;

				int Yup = temp->yMin;
				int Ydown = temp->yMax;
				int Ymiddle = temp->yMin + Ylength/2;

				int x = temp->nw->x;
				int y = temp->nw->y;
				string n = temp->nw->cityName;
				delete temp->nw;
				temp->nw = new QTreeInternalNode(Xleft, Xmiddle, Yup, Ymiddle);
				insert(temp->nw, x, y, n);
				insert(temp->nw, x_coordinate, y_coordinate, name);
			}
		}
		//ne
		if(dir == "ne")
		{
			if(temp->ne == NULL)
				temp->ne = new QTreeLeafNode(x_coordinate, y_coordinate,name, "ne");
			else if(temp->ne->internal == true)
			{	
				QTreeInternalNode* te =dynamic_cast<QTreeInternalNode*>(temp);
				insert(te->ne, x_coordinate, y_coordinate, name);
			}
			else
			{
				int Xlength = temp->xMax - temp->xMin;
				int Ylength = temp->yMax - temp->yMin;

				int Xleft = temp->xMin;
				int Xright = temp->xMax;
				int Xmiddle = temp->xMin + Xlength/2;

				int Yup = temp->yMin;
				int Ydown = temp->yMax;
				int Ymiddle = temp->yMin + Ylength/2;

				int x = temp->ne->x;
				int y = temp->ne->y;
				string n = temp->ne->cityName;
				delete temp->ne;
				temp->ne = new QTreeInternalNode(Xmiddle, Xright, Yup, Ymiddle);
				insert(temp->ne, x, y, n);
				insert(temp->ne, x_coordinate, y_coordinate, name);
			}
		}
		//sw
		if(dir == "sw")
		{
			if(temp->sw == NULL)
				temp->sw = new QTreeLeafNode(x_coordinate, y_coordinate,name, "sw");
			else if(temp->sw->internal == true)
			{	
				QTreeInternalNode* te =dynamic_cast<QTreeInternalNode*>(temp);
				insert(te->sw, x_coordinate, y_coordinate, name);
			}
			else
			{
				int Xlength = temp->xMax - temp->xMin;
				int Ylength = temp->yMax - temp->yMin;

				int Xleft = temp->xMin;
				int Xright = temp->xMax;
				int Xmiddle = temp->xMin + Xlength/2;

				int Yup = temp->yMin;
				int Ydown = temp->yMax;
				int Ymiddle = temp->yMin + Ylength/2;

				int x = temp->sw->x;
				int y = temp->sw->y;
				string n = temp->sw->cityName;
				delete temp->sw;
				temp->sw = new QTreeInternalNode(Xleft, Xmiddle, Ymiddle, Ydown);
				insert(temp->sw, x, y, n);
				insert(temp->sw, x_coordinate, y_coordinate, name);
			}
		}

		//se
		if(dir == "se")
		{
			if(temp->se == NULL)
				temp->se = new QTreeLeafNode(x_coordinate, y_coordinate,name, "se");
			else if(temp->se->internal == true)
			{	
				QTreeInternalNode* te =dynamic_cast<QTreeInternalNode*>(temp);
				insert(te->se, x_coordinate, y_coordinate, name);
			}
			else
			{
				int Xlength = temp->xMax - temp->xMin;
				int Ylength = temp->yMax - temp->yMin;

				int Xleft = temp->xMin;
				int Xright = temp->xMax;
				int Xmiddle = temp->xMin + Xlength/2;

				int Yup = temp->yMin;
				int Ydown = temp->yMax;
				int Ymiddle = temp->yMin + Ylength/2;

				int x = temp->se->x;
				int y = temp->se->y;
				string n = temp->se->cityName;
				delete temp->se;
				temp->se = new QTreeInternalNode(Xmiddle, Xright, Ymiddle, Ydown);
				insert(temp->se, x, y, n);
				insert(temp->se, x_coordinate, y_coordinate, name);
			}
		}
	}
}

void QRTree::search(int x_coordinate, int y_coordinate, int radius)
{
	search(internalRoot, x_coordinate, y_coordinate, radius);
}

void QRTree::search(QTNode* node, int x_coordinate, int y_coordinate, int radius)
{
	if (node == NULL)
	{
		//cout<<"node = NULL";
		return;
	}
	output(node, x_coordinate, y_coordinate, radius);
	search(node->nw, x_coordinate, y_coordinate, radius); 
	search(node->ne, x_coordinate, y_coordinate, radius);
	search(node->sw, x_coordinate, y_coordinate, radius);
	search(node->se, x_coordinate, y_coordinate, radius);
}

void QRTree::output(QTNode* node, int x_coordinate, int y_coordinate, int radius)
{
	if (node == NULL)
	{
		
	}
	else if(node->internal == true)
	{

	}		
	else
	{
		if ((((node->x - x_coordinate) * (node->x - x_coordinate)) + ((node->y - y_coordinate) * (node->y - y_coordinate))) <= radius * radius)
			cout<<node->x<<" , "<<node->y<<" "<<node->cityName<<endl;
	}
}

void QRTree::debug()
{
	debug(internalRoot);
}

void QRTree::debug(QTNode* node)
{
	if (node == NULL)
    {
		cout<<"E";
        return;
    }
	visitNode(node);
	if (node->internal == true)
	{
		debug(node->nw);
		debug(node->ne);
		debug(node->sw);
		debug(node->se);
	}
	else
	{
		return;
	}

}

void QRTree::visitNode(QTNode* node)
{
    if (node == NULL)
    {
		cout<<"E";
    }
    //cout<<node->directionInParent<<endl;
    else
    {
		if(node->internal == true)
			cout<<"I";
		if(node->internal == false)
        {
			if (node == NULL)
			{
				cout<<"E";
			}
			else
			{
				cout<<node->x<<","<<node->y<<node->cityName<<"|";
			}
		}
	}
}

