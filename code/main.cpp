/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */

#include "QRTree.h"
#include "BSTree.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

QRTree qrtree;
BSTree bstree;

void dealing(vector<string> command)
{
	string firstWord = command[0];
	
	//insert node into two trees
	if (firstWord == "insert")
	{
		bool whether;
		int x = atoi(command[1].c_str());
		int y = atoi(command[2].c_str());
		string name = command[3]; 

		whether = qrtree.insert(x, y, name);
		if (whether == true)
			bstree.insert(x, y, name);
	}

	//initiate two trees
	if (firstWord == "makenull")
	{
		qrtree.makenull();
		bstree.makenull();
	}

	//find name. only find in the BST.
	if (firstWord == "find")
	{
		BSTNode* node;
		string name = command[1];
		node = bstree.findNode(name);
	}

	//traverse QRTree
	if (firstWord == "debug")
	{
		qrtree.debug();
	}

	//Search region
	if (firstWord == "search")
	{
		int x = atoi(command[1].c_str());
		int y = atoi(command[2].c_str());
		int r = atoi(command[3].c_str());
		qrtree.search(x, y, r);
	}

	//remove node, that is find node in BST first and then delete them.
	if (firstWord == "remove")
	{
		BSTNode* node;
		//remove name
		if (command.size() == 2)
		{
			string name = command[1];
			node = bstree.findNode(name);
			if (node == NULL)
			{
				cout<<"there is no node in BST.(remove)"<<endl;
			}
			else
			{
				if (node->down == NULL)
				{
				}
				else
				{
					while(node->down!=NULL)
					{
						cout<<"remove: "<<node->cityName<<"("<<node->x<<", "<<node->y<<")"<<endl;
						qrtree.remove(node->x, node->y);
						node = node->down; 
					}
					bstree.remove(name);
				}
			}
		}

		//remove x, y
		else
		{
			QTNode* node = NULL;
			int x = atoi(command[1].c_str());
			int y = atoi(command[2].c_str());
			node = qrtree.findNode(x, y);
			//qrtree.findNode(x, y);
			if (node == NULL)
			{
				cout<<"cannot find the node.(remove x, y in qrtree)"<<endl;
			}
			else
			{
				cout<<"remove: (in qrtree) "<<node->cityName<<"("<<node->x<<";"<<node->y<<")"<<endl;
				qrtree.remove(x, y);
				bstree.remove(node->cityName);
			}
		}

	}
}

int main(int argc, char *argv[])
//int main()
{
	string input;
	vector<string> commandLine;
	ifstream commandfile;
    commandfile.open(argv[1]);
	//commandfile.open("PRQuadtree_Input.txt");
	//commandfile.open("input1.txt");
	while (getline(commandfile, input))
    {
		istringstream istr(input);
		while( !istr.eof() )
		{
			string tmp_s;
			istr >> tmp_s;
			commandLine.push_back(tmp_s);
		}
		dealing(commandLine);
		commandLine.clear();
	}
	system("pause");
}

