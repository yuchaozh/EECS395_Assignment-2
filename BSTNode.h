/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */
#ifndef WORKSPACE_BSTNODE_H
#define WORKSPACE_BSTNODE_H

#include <string>
#include <iostream>

using namespace std;

class BSTNode
{
public:
	int x;
	int y;
	string cityName ;
	BSTNode *left;
	BSTNode *right;
	BSTNode *down;
//public:
//	string getName()
//	{
//		return cityName;
//	}
//	void setName(string name)
//	{
//		cityName = name;
//	}
//	int getX()
//	{
//		return x;
//	}
//	void setX(int number)
//	{
//		x = number;
//	}
//	int getY()
//	{
//		return y;
//	}
//	void setY(int number)
//	{
//		y = number;
//	}
//	BSTNode* getLeft()
//	{
//		return left;
//	}
//	void setLeft(BSTNode* node)
//	{
//		left = node;
//	}
//	BSTNode* getRight()
//	{
//		return right;
//	}
//	void setRight(BSTNode* node)
//	{
//		right = node;
//	}
//	BSTNode* getdown()
//	{
//		return down;
//	}
//	void setDown(BSTNode* node)
//	{
//		down = node;
//	}
	BSTNode();
	BSTNode(int x_coodinate, int y_coordinate, string name);
};
#endif