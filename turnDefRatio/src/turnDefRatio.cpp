//============================================================================
// Name        : turnDefRatio.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;

int main() {

	std::vector<string> sinkSourceNode;
	sinkSourceNode.push_back("0/2to1/2");
	sinkSourceNode.push_back("0/5to1/5");
	sinkSourceNode.push_back("0/7to1/7");
	sinkSourceNode.push_back("0/9to1/9");
	sinkSourceNode.push_back("2/0to2/1");
	sinkSourceNode.push_back("5/0to5/1");
	sinkSourceNode.push_back("7/0to7/1");
	sinkSourceNode.push_back("9/0to9/1");
	sinkSourceNode.push_back("3/11to3/10");
	sinkSourceNode.push_back("5/11to5/10");
	sinkSourceNode.push_back("7/11to7/10");
	sinkSourceNode.push_back("9/11to9/10");
	sinkSourceNode.push_back("11/3to10/3");
	sinkSourceNode.push_back("11/5to10/5");
	sinkSourceNode.push_back("11/7to10/7");
	sinkSourceNode.push_back("11/9to10/9");

	int randInt;

	std::set<int> generatedInt;

	/* initialize random seed: */
	srand (time(NULL));


	int k = 1;

	do {
		/* generate secret number between 1 and 10: */
		randInt = rand() % 256;
		std::set<int>::iterator it = generatedInt.find(randInt);
		if (it == generatedInt.end()){
			generatedInt.insert(randInt);
//			cout << "random int : " << randInt << endl;

			int i = randInt / 16;
			int j = randInt % 16;
			if (i!=j){

				int depart = 0 + (k-1) * 10;

				cout << "<tripdef id=\"" << k << "\" from=\"" <<sinkSourceNode[i]<< "\" to=\"" << sinkSourceNode[j] << "\" depart=\"" << depart << "\" repno=\"12\"  period=\"600\"/>" << endl;
				k++;
			}
		}
	} while (generatedInt.size()!=256);



//	for (int i = 1; i <= 6; ++i) {
//		for (int j = 1; j <= 6; ++j) {
//			int begin = 0 + (i-1) * 60+ (j-1) * 10;
//			int end = 7200 + (i-1) * 60+ (j-1) * 10;
//
//
//			cout << "<flow id=\"" << i << j << "\" from=\"source" << i << "\" to=\"sink" << j << "\" number=\"20\" begin=\"" << begin << "\" end=\"" << end << "\"/>" << endl;
//		}
//	}

//	do {
//		/* generate secret number between 1 and 10: */
//		randInt = rand() % 36;
//		std::set<int>::iterator it = generatedInt.find(randInt);
//		if (it == generatedInt.end()){
//
////			cout << "random int : " << randInt << endl;
//
//
//			int i = randInt / 6 + 1;
//			int j = randInt % 6 + 1;
//
////			if (i/3 != j/3){
//			if ((i>3 && j<=3)||(i<=3 && j>3)){
//				generatedInt.insert(randInt);
//				int begin = 0 + (generatedInt.size()-1) * 10;
//				int end = 7200 + (generatedInt.size()-1) * 10;
//
//				cout << "<flow id=\"" << i << j << "\" from=\"source" << i << "\" to=\"sink" << j << "\" number=\"40\" begin=\"" << begin << "\" end=\"" << end << "\"/>" << endl;
//
//			}
//		}
//	} while (generatedInt.size()!=18);


//	int randInt;
//
//	std::set<int> generatedInt;
//	std::vector<int> copyOfGeneratedInt;
//
//	/* initialize random seed: */
//	srand (time(NULL));
//
//	do {
//		/* generate secret number between 1 and 10: */
//		randInt = rand() % 16+1;
//		std::set<int>::iterator it = generatedInt.find(randInt);
//		if (it == generatedInt.end()){
//			generatedInt.insert(randInt);
//			copyOfGeneratedInt.push_back(randInt);
////			cout << "random int : " << randInt << endl;
////
////
////			int i = randInt / 6 + 1;
////			int j = randInt % 6 + 1;
////
//////			if (i/3 != j/3){
////			if ((i>3 && j<=3)||(i<=3 && j>3)){
////				generatedInt.insert(randInt);
////				int begin = 0 + (generatedInt.size()-1) * 10;
////				int end = 7200 + (generatedInt.size()-1) * 10;
////
////				cout << "<flow id=\"" << i << j << "\" from=\"source" << i << "\" to=\"sink" << j << "\" number=\"40\" begin=\"" << begin << "\" end=\"" << end << "\"/>" << endl;
////			}
//		}
//	} while (generatedInt.size()!=16);
//
////	int iteration= 0;
//
//	std::vector<string> sinkSourceNode;
//	sinkSourceNode.push_back("0/2");
//	sinkSourceNode.push_back("0/5");
//	sinkSourceNode.push_back("0/7");
//	sinkSourceNode.push_back("0/9");
//	sinkSourceNode.push_back("2/0");
//	sinkSourceNode.push_back("5/0");
//	sinkSourceNode.push_back("7/0");
//	sinkSourceNode.push_back("9/0");
//	sinkSourceNode.push_back("3/11");
//	sinkSourceNode.push_back("5/11");
//	sinkSourceNode.push_back("7/11");
//	sinkSourceNode.push_back("9/11");
//	sinkSourceNode.push_back("11/3");
//	sinkSourceNode.push_back("11/5");
//	sinkSourceNode.push_back("11/7");
//	sinkSourceNode.push_back("11/9");
//
////	for (std::set<int>::iterator it = generatedInt.begin(); it != generatedInt.end(); ++it) {
////		// using built-in random generator:
////		std::random_shuffle(copyOfGeneratedInt.begin(),copyOfGeneratedInt.end());
////		for (std::vector<int>::iterator it2 = copyOfGeneratedInt.begin(); it2 != copyOfGeneratedInt.end(); ++it2) {
////	int i = *it;
////	int j = *it2;
////	int depart = 0 + iteration * 10;
////
////	if (i != j){
////		cout << "<tripdef id=\"" << iteration << "\" from=\"" <<sinkSourceNode[i-1]<< "\" to=\"" << sinkSourceNode[j-1] << "\"depart=\"" << depart << "\" repno=\"12\"  period=\"600\"/>" << endl;
////	}
////}
////}
//
//	std::set<int> generatedInt;
//	randInt = rand() % 240+1;
//
//
//	for (int iteration = 0; iteration < 240; ++iteration) {
//		if ()
//		int i = *it;
//		int j = *it2;
//		int depart = 0 + iteration * 10;
//
//		if (i != j){
//			cout << "<tripdef id=\"" << iteration << "\" from=\"" <<sinkSourceNode[i-1]<< "\" to=\"" << sinkSourceNode[j-1] << "\"depart=\"" << depart << "\" repno=\"12\"  period=\"600\"/>" << endl;
//		}
//
//	}




	return 0;
}
