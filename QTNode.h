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
	int xMin, xMax, yMin, yMax, x, y;
	string cityName;
	string directionInParent;
	QTNode* nw;
	QTNode* ne;
	QTNode* sw;
	QTNode* se;
	bool internal;

	virtual ~QTNode()
	{

	}
};
#endif