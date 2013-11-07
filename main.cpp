/*
 *Author: Yuchao Zhou
 *Time: 11/01/2013
 */

#include "QRTree.h"
#include "BSTree.h"
#include <iostream>

using namespace std;

int main()
{
	QRTree qrtree;
	qrtree.insert(5,6,"evanston");
	qrtree.insert(16333, 32, "chicago");
	qrtree.insert(5,9999, "vance");
	qrtree.insert(9999,9999,"dada");
	//qrtree.insert(100,100, "sadf");
	//qrtree.insert(16300,16300, "jiashan");
	//qrtree.insert(16000,16000, "jiasdshan");
	//qrtree.insert(88,88, "jiaxing");
	//qrtree.search(85, 85, 10);
	qrtree.debug();
	system("pause");
}