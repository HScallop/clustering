#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//	include clustering function in the user-defined header file
#include "clustering.h"

int main()
{
	Point temp;	// used to read each point in the file
	vector<Point> data;

	//	read input file
	ifstream fin("test.txt");
	
	while(!fin.eof())
	{
		fin>>temp.x>>temp.y;
		temp.clusterNo = -1;
		
		//	push temp to the end of data vector
		data.push_back(temp);
	}
	fin.close();
	
	// run the clustering function
	clustering(data);

	// show the result in data after the clustering
	for(int i=0;i<data.size();i++)
		cout<<data[i].x<<" "<<data[i].y<<" "<<data[i].clusterNo<<"\n";
	cout<<"\n";

	return 0;
}
