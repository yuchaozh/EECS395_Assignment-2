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

void QRTree::makenull()
{
	QRTree();
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

	//nw
	if ((Xleft <= x_coordinate) && (x_coordinate <= Xmiddle) && (Yup <= y_coordinate) && (y_coordinate <= Ymiddle))
	{
			location = "nw";
			return location;
	}

	//ne
	if ((Xmiddle < x_coordinate) && (x_coordinate <= Xright) && (Yup < y_coordinate) &&(y_coordinate <= Ymiddle))
	{
			location = "ne";
			return location;
	}

	//sw
	if ((Xleft < x_coordinate) && (x_coordinate <= Xmiddle) && (Ymiddle < y_coordinate ) &&(y_coordinate <= Ydown))
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

bool QRTree::insert(int x_coordinate, int y_coordinate, string name)
	{
		bool caninsert = true;
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
			internalRoot->parent = NULL;
		}
		else  caninsert = insert(internalRoot, x_coordinate, y_coordinate,name);
		return caninsert;
	}

bool QRTree::insert(QTNode* node, int x_coordinate, int y_coordinate , string name)
{
	bool success = true;
	// if the node is a internal node
	if(node->internal == true)
	{
		QTreeInternalNode* temp = dynamic_cast<QTreeInternalNode*>(node);
		string dir = location(temp, x_coordinate, y_coordinate);
		//nw
		if(dir == "nw")
		{
			if(temp->nw==NULL)
			{
				temp->nw = new QTreeLeafNode(x_coordinate, y_coordinate, name, "nw");
				temp->children ++;
			}
			//if alrady exist same coordinate node.
			else if (temp->nw->x == x_coordinate && temp->nw->y == y_coordinate)
			{
				cout<<"same coordinate has already existed."<<endl;
				success = false;
				return success;
			}
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
				temp->children --;
				temp->nw = new QTreeInternalNode(Xleft, Xmiddle, Yup, Ymiddle);
				temp->children ++;
				insert(temp->nw, x, y, n);
				insert(temp->nw, x_coordinate, y_coordinate, name);
			}
		}
		//ne
		if(dir == "ne")
		{
			if(temp->ne == NULL)
			{
				temp->ne = new QTreeLeafNode(x_coordinate, y_coordinate,name, "ne");
				temp->children ++;
			}
			//if alrady exist same coordinate node.
			else if (temp->ne->x == x_coordinate && temp->ne->y == y_coordinate)
			{
				cout<<"same coordinate has already existed."<<endl;
				success = false;
				return success;
			}
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
				temp->children--;
				temp->ne = new QTreeInternalNode(Xmiddle, Xright, Yup, Ymiddle);
				temp->children++;
				insert(temp->ne, x, y, n);
				insert(temp->ne, x_coordinate, y_coordinate, name);
			}
		}
		//sw
		if(dir == "sw")
		{
			if(temp->sw == NULL)
			{
				temp->sw = new QTreeLeafNode(x_coordinate, y_coordinate,name, "sw");
				temp->children++;
			}
			//if alrady exist same coordinate node.
			else if (temp->sw->x == x_coordinate && temp->sw->y == y_coordinate)
			{
				cout<<"same coordinate has already existed."<<endl;
				success = false;
				return success;
			}
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
				temp->children--;
				temp->sw = new QTreeInternalNode(Xleft, Xmiddle, Ymiddle, Ydown);
				temp->children++;
				insert(temp->sw, x, y, n);
				insert(temp->sw, x_coordinate, y_coordinate, name);
			}
		}

		//se
		if(dir == "se")
		{
			if(temp->se == NULL)
			{
				temp->se = new QTreeLeafNode(x_coordinate, y_coordinate,name, "se");
				temp->children++;
			}
			//if alrady exist same coordinate node.
			else if (temp->se->x == x_coordinate && temp->se->y == y_coordinate)
			{
				cout<<"same coordinate has already existed."<<endl;
				success = false;
				return success;
			}
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
				temp->children--;
				temp->se = new QTreeInternalNode(Xmiddle, Xright, Ymiddle, Ydown);
				temp->children++;
				insert(temp->se, x, y, n);
				insert(temp->se, x_coordinate, y_coordinate, name);
			}
		}
	}
	return success;
}

void QRTree::remove(int x_coordinate, int y_coordinate)
{
	if (isEmpty() == true)
	{
		cout<<"the root is null"<<endl;
	}
	else remove(internalRoot, x_coordinate, y_coordinate);

}

void QRTree::remove(QTNode* node, int x_coordinate, int y_coordinate)
{
	//if the node is an internal node
	if (node->internal == true)
	{
		QTreeInternalNode* temp = dynamic_cast<QTreeInternalNode*>(node);
		string dir = location(temp, x_coordinate, y_coordinate);
		//nw
		if (dir == "nw")
		{
			if(temp->nw->internal == true)
				remove(temp->nw, x_coordinate, y_coordinate);
			if(temp->nw->internal == false)
			{
				if(temp->nw->x == x_coordinate && temp->nw->y == y_coordinate)
				{
					delete temp->nw;
					temp->children--;
					temp->nw = NULL;
				}
				if(temp->children == 1)
				{
				  if(temp->nw != NULL && temp->nw->internal == true && temp->ne == NULL && temp->sw == NULL && temp->se == NULL)
					  return;
				  else if(temp->ne != NULL && temp->ne->internal == true && temp->nw == NULL && temp->sw == NULL && temp->se == NULL)
					  return;
				  else if(temp->sw != NULL && temp->sw->internal == true && temp->nw == NULL && temp->ne == NULL && temp->se == NULL)
					  return;
				  else if(temp->se != NULL && temp->se->internal == true && temp->nw == NULL && temp->ne == NULL && temp->sw == NULL)
					  return;
				  else
				  {
					int x;
					int y;
					string name;
					if(temp->nw != NULL && temp->nw->internal == false)
					{
						name = temp->nw->cityName;
						x = temp->nw->x;
						y = temp->nw->y;
					}
					else if(temp->ne != NULL && temp->ne->internal == false)
					{
						name = temp->ne->cityName;
						x = temp->ne->x;
						y = temp->ne->y;
					}
					else if(temp->sw != NULL && temp->sw->internal == true)
					{
						name = temp->sw->cityName;
						x = temp->sw->x;
						y = temp->sw->y;
					}
					else if(temp->se != NULL && temp->se->internal == true)
					{
						name = temp->se->cityName;
						x = temp->se->x;
						y = temp->se->y;
					}
					if(temp->parent == NULL)
					{
						QTreeLeafNode* internalRoot = new QTreeLeafNode(x, y, name, "nw");
					} 
					else
					{
						QTreeInternalNode* te = dynamic_cast<QTreeInternalNode*>(temp->parent);
						if(te->nw == temp)
						{
							te->nw = new QTreeLeafNode(x, y, name, "nw");
						}
						else if(te->ne == temp)
						{
							te->ne = new QTreeLeafNode(x, y, name, "ne");
						}
						else if(te->sw == temp)
						{
							te->sw = new QTreeLeafNode(x, y, name, "sw");
						}
						else if(te->se == temp)
						{
							te->se = new QTreeLeafNode(x, y, name, "se");
						}
					}
			     }
				}
			}
		}

		//ne
		if (dir == "ne")
		{
			if(temp->ne->internal == true)
				remove(temp->ne, x_coordinate, y_coordinate);
			if(temp->ne->internal == false)
			{
				if(temp->ne->x == x_coordinate && temp->ne->y == y_coordinate)
				{
					delete temp->ne;
					temp->children--;
					temp->ne = NULL;
				}
				if(temp->children == 1)
				{
				  if(temp->nw != NULL && temp->nw->internal == true && temp->ne == NULL && temp->sw == NULL && temp->se == NULL)
					  return;
				  else if(temp->ne != NULL && temp->ne->internal == true && temp->nw == NULL && temp->sw == NULL && temp->se == NULL)
					  return;
				  else if(temp->sw != NULL && temp->sw->internal == true && temp->nw == NULL && temp->ne == NULL && temp->se == NULL)
					  return;
				  else if(temp->se != NULL && temp->se->internal == true && temp->nw == NULL && temp->ne == NULL && temp->sw == NULL)
					  return;
				  else
				  {
					int x;
					int y;
					string name;
					if(temp->nw != NULL && temp->nw->internal == false)
					{
						name = temp->nw->cityName;
						x = temp->nw->x;
						y = temp->nw->y;
					}
					else if(temp->ne != NULL && temp->ne->internal == false)
					{
						name = temp->ne->cityName;
						x = temp->ne->x;
						y = temp->ne->y;
					}
					else if(temp->sw != NULL && temp->sw->internal == true)
					{
						name = temp->sw->cityName;
						x = temp->sw->x;
						y = temp->sw->y;
					}
					else if(temp->se != NULL && temp->se->internal == true)
					{
						name = temp->se->cityName;
						x = temp->se->x;
						y = temp->se->y;
					}
					if(temp->parent == NULL)
					{
						QTreeLeafNode* internalRoot = new QTreeLeafNode(x, y, name, "ne");
					} 
					else
					{
						QTreeInternalNode* te = dynamic_cast<QTreeInternalNode*>(temp->parent);
						if(te->nw == temp)
						{
							te->nw = new QTreeLeafNode(x, y, name, "nw");
						}
						else if(te->ne == temp)
						{
							te->ne = new QTreeLeafNode(x, y, name, "ne");
						}
						else if(te->sw == temp)
						{
							te->sw = new QTreeLeafNode(x, y, name, "sw");
						}
						else if(te->se == temp)
						{
							te->se = new QTreeLeafNode(x, y, name, "se");
						}
					}
			     }
				}
			}
		}

		//sw
		if (dir == "sw")
		{
			if(temp->sw->internal == true)
				remove(temp->sw, x_coordinate, y_coordinate);
			if(temp->sw->internal == false)
			{
				if(temp->sw->x == x_coordinate && temp->sw->y == y_coordinate)
				{
					delete temp->sw;
					temp->children--;
					temp->sw = NULL;
				}
				if(temp->children == 1)
				{
				  if(temp->nw != NULL && temp->nw->internal == true && temp->ne == NULL && temp->sw == NULL && temp->se == NULL)
					  return;
				  else if(temp->ne != NULL && temp->ne->internal == true && temp->nw == NULL && temp->sw == NULL && temp->se == NULL)
					  return;
				  else if(temp->sw != NULL && temp->sw->internal == true && temp->nw == NULL && temp->ne == NULL && temp->se == NULL)
					  return;
				  else if(temp->se != NULL && temp->se->internal == true && temp->nw == NULL && temp->ne == NULL && temp->sw == NULL)
					  return;
				  else
				  {
					int x;
					int y;
					string name;
					if(temp->nw != NULL && temp->nw->internal == false)
					{
						name = temp->nw->cityName;
						x = temp->nw->x;
						y = temp->nw->y;
					}
					else if(temp->ne != NULL && temp->ne->internal == false)
					{
						name = temp->ne->cityName;
						x = temp->ne->x;
						y = temp->ne->y;
					}
					else if(temp->sw != NULL && temp->sw->internal == true)
					{
						name = temp->sw->cityName;
						x = temp->sw->x;
						y = temp->sw->y;
					}
					else if(temp->se != NULL && temp->se->internal == true)
					{
						name = temp->se->cityName;
						x = temp->se->x;
						y = temp->se->y;
					}
					if(temp->parent == NULL)
					{
						QTreeLeafNode* internalRoot = new QTreeLeafNode(x, y, name, "ne");
					} 
					else
					{
						QTreeInternalNode* te = dynamic_cast<QTreeInternalNode*>(temp->parent);
						if(te->nw == temp)
						{
							te->nw = new QTreeLeafNode(x, y, name, "nw");
						}
						else if(te->ne == temp)
						{
							te->ne = new QTreeLeafNode(x, y, name, "ne");
						}
						else if(te->sw == temp)
						{
							te->sw = new QTreeLeafNode(x, y, name, "sw");
						}
						else if(te->se == temp)
						{
							te->se = new QTreeLeafNode(x, y, name, "se");
						}
					}
			     }
				}
			}
		}

		//se
		if (dir == "se")
		{
			if(temp->se->internal == true)
				remove(temp->se, x_coordinate, y_coordinate);
			if(temp->se->internal == false)
			{
				if(temp->se->x == x_coordinate && temp->se->y == y_coordinate)
				{
					delete temp->se;
					temp->children--;
					temp->se = NULL;
				}
				if(temp->children == 1)
				{
				  if(temp->nw != NULL && temp->nw->internal == true && temp->ne == NULL && temp->sw == NULL && temp->se == NULL)
					  return;
				  else if(temp->ne != NULL && temp->ne->internal == true && temp->nw == NULL && temp->sw == NULL && temp->se == NULL)
					  return;
				  else if(temp->sw != NULL && temp->sw->internal == true && temp->nw == NULL && temp->ne == NULL && temp->se == NULL)
					  return;
				  else if(temp->se != NULL && temp->se->internal == true && temp->nw == NULL && temp->ne == NULL && temp->sw == NULL)
					  return;
				  else
				  {
					int x;
					int y;
					string name;
					if(temp->nw != NULL && temp->nw->internal == false)
					{
						name = temp->nw->cityName;
						x = temp->nw->x;
						y = temp->nw->y;
					}
					else if(temp->ne != NULL && temp->ne->internal == false)
					{
						name = temp->ne->cityName;
						x = temp->ne->x;
						y = temp->ne->y;
					}
					else if(temp->sw != NULL && temp->sw->internal == true)
					{
						name = temp->sw->cityName;
						x = temp->sw->x;
						y = temp->sw->y;
					}
					else if(temp->se != NULL && temp->se->internal == true)
					{
						name = temp->se->cityName;
						x = temp->se->x;
						y = temp->se->y;
					}
					if(temp->parent == NULL)
					{
						QTreeLeafNode* internalRoot = new QTreeLeafNode(x, y, name, "se");
					} 
					else
					{
						QTreeInternalNode* te = dynamic_cast<QTreeInternalNode*>(temp->parent);
						if(te->nw == temp)
						{
							te->nw = new QTreeLeafNode(x, y, name, "nw");
						}
						else if(te->ne == temp)
						{
							te->ne = new QTreeLeafNode(x, y, name, "ne");
						}
						else if(te->sw == temp)
						{
							te->sw = new QTreeLeafNode(x, y, name, "sw");
						}
						else if(te->se == temp)
						{
							te->se = new QTreeLeafNode(x, y, name, "se");
						}
					}
			     }
				}
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
	cout<<endl;
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
				cout<<node->directionInParent<<node->x<<","<<node->y<<node->cityName<<"|";
			}
		}
	}
}

QTNode* QRTree::findNode(int x_coordinate, int y_coordinate)
{
	QTNode* node;
	node = findNode(internalRoot, x_coordinate, y_coordinate);
	return node;
}

QTNode* QRTree::findNode(QTNode* node, int x_coordinate, int y_coordinate)
{
	if (node == NULL)
	{
		return NULL;
	}
	return findOut(node, x_coordinate, y_coordinate);
	findNode(node->nw, x_coordinate, y_coordinate); 
	findNode(node->ne, x_coordinate, y_coordinate);
	findNode(node->sw, x_coordinate, y_coordinate);
	findNode(node->se, x_coordinate, y_coordinate);
}

QTNode*	QRTree::findOut(QTNode* node, int x_coordinate, int y_coordinate)
{
	if (node == NULL)
	{
	}
	else if(node->internal == true)
	{
	}		
	else
	{
		if ((node->x == x_coordinate) && (node->y == y_coordinate))
		{
			return node;
		}
		else
		{
			return NULL;
		}
	}
}

