#ifndef CLUSTERING_H
#define CLUSTERING_H

//	implement your own clustering method here
#include <iostream>
#include <vector>
//include <math.h> to compute the distances
#include <math.h>
#include <ctime>
#include <cstdlib>
//	a data structure to store each data point
struct Point{
	double x;
	double y;
	int clusterNo;	// used to store the cluster number. -1 means not assigned.
};
void kmeans(vector <Point>& data, vector <Point>& means);



//	data is passed by reference
void clustering(vector<Point>& data)
{
	srand(time(0));
	//use <point> means to record means
	vector<Point> means(10);

	int i = 0;
	int record = 0;
	double min = 0.0;



	vector<int> lastcount1(10);
	vector<int> lastcount2(10);
	vector<int> lastcount3(10);
	bool stop = false;

	while (stop == false){

		//choose data points to be the initial points
		//find four different points
		int a[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		bool s = false;
		while (s == false){
		for (int i = 0; i < 4; i++){
		a[i] = rand() % data.size();
		}
		if (a[0] != a[1] && a[0] != a[2] && a[0] != a[3] && a[1] != a[2] && a[1] != a[3] && a[2] != a[3]){
		s = true;
		}
		}


		for (int k = 0; k < 4; k++){
		means[k] = data[a[k]];
		}

		

		//distance=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		//let every point find a colsest cluster
		for (int i = 0; i < data.size(); i++){



			//give min a initial value
			min = sqrt(pow(data[i].x - means[0].x, 2.0) + pow(data[i].y - means[0].y, 2.0));
			for (int k = 0; k < 4; k++){


				if (sqrt(pow(data[i].x - means[k].x, 2.0) + pow(data[i].y - means[k].y, 2.0)) <= min){
					min = sqrt(pow(data[i].x - means[k].x, 2.0) + pow(data[i].y - means[k].y, 2.0));

					record = k;


				}
				data[i].clusterNo = record;

			}
		}


		//use k-means algorithm to cluster
		kmeans(data, means);



		//inspect if the initial points randomly given is proper
		vector<int> counter(10);
		for (i = 0; i < 10; i++){
			counter[i] = 0;
		}
		for (int i = 0; i < data.size(); i++){
			switch (data[i].clusterNo){
			case 0:
				counter[0]++;
				means[0].x += data[i].x;
				means[0].y += data[i].y;
				break;
			case 1:
				counter[1]++;
				means[1].x += data[i].x;
				means[1].y += data[i].y;
				break;
			case 2:
				counter[2]++;
				means[2].x += data[i].x;
				means[2].y += data[i].y;
				break;
			case 3:
				counter[3]++;
				means[3].x += data[i].x;
				means[3].y += data[i].y;
				break;
			case 4:
				counter[4]++;
				means[4].x += data[i].x;
				means[4].y += data[i].y;
				break;
			case 5:
				counter[5]++;
				means[5].x += data[i].x;
				means[5].y += data[i].y;
				break;
			case 6:
				counter[6]++;
				means[6].x += data[i].x;
				means[6].y += data[i].y;
				break;
			case 7:
				counter[7]++;
				means[7].x += data[i].x;
				means[7].y += data[i].y;
				break;
			case 8:
				counter[8]++;
				means[8].x += data[i].x;
				means[8].y += data[i].y;
				break;
			case 9:
				counter[9]++;
				means[9].x += data[i].x;
				means[9].y += data[i].y;
				break;
			}
		}

		//sort
		int temp;
		for (int n = 0; n < 10; n++){
			for (int i = n + 1; i < 10; i++){
				if (counter[n] > counter[i]){
					temp = counter[n];
					counter[n] = counter[i];
					counter[i] = temp;
				}
			}
		}

		if (counter == lastcount1&&counter == lastcount2&&counter==lastcount3){
			stop = true;
		}
		else{
			lastcount3 = lastcount2;
			lastcount2 = lastcount1;
			lastcount1 = counter;
			
			
		}
	}


}









void kmeans(vector <Point>& data, vector <Point>& means){
	int record = 0;
	double min = 0.0;
	int counter[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	//record last clustering result
	vector<Point> last_mean(10);
	last_mean = means;


	//initialize means
	for (int i = 0; i < 4; i++){
		means[i].x = 0;
		means[i].y = 0;
	}
	//find out how many points is in the cluster and recompute each mean
	for (int i = 0; i < data.size(); i++){
		switch (data[i].clusterNo){
		case 0:
			counter[0]++;
			means[0].x += data[i].x;
			means[0].y += data[i].y;
			break;
		case 1:
			counter[1]++;
			means[1].x += data[i].x;
			means[1].y += data[i].y;
			break;
		case 2:
			counter[2]++;
			means[2].x += data[i].x;
			means[2].y += data[i].y;
			break;
		case 3:
			counter[3]++;
			means[3].x += data[i].x;
			means[3].y += data[i].y;
			break;
		case 4:
			counter[4]++;
			means[4].x += data[i].x;
			means[4].y += data[i].y;
			break;
		case 5:
			counter[5]++;
			means[5].x += data[i].x;
			means[5].y += data[i].y;
			break;
		case 6:
			counter[6]++;
			means[6].x += data[i].x;
			means[6].y += data[i].y;
			break;
		case 7:
			counter[7]++;
			means[7].x += data[i].x;
			means[7].y += data[i].y;
			break;
		case 8:
			counter[8]++;
			means[8].x += data[i].x;
			means[8].y += data[i].y;
			break;
		case 9:
			counter[9]++;
			means[9].x += data[i].x;
			means[9].y += data[i].y;
			break;
		}
	}

	for (int i = 0; i < 4; i++){
		//find the new centers
		if (counter[i] != 0){
			means[i].x = means[i].x / counter[i];
			means[i].y = means[i].y / counter[i];
		}
	}


	//let every point find a closest cluster
	for (int i = 0; i < data.size(); i++){

		min = sqrt(pow(data[i].x - means[0].x, 2.0) + pow(data[i].y - means[0].y, 2.0));

		for (int k = 0; k < 4; k++){

			if (sqrt(pow(data[i].x - means[k].x, 2.0) + pow(data[i].y - means[k].y, 2.0)) <= min){
				min = sqrt(pow(data[i].x - means[k].x, 2.0) + pow(data[i].y - means[k].y, 2.0));
				record = k;
			}

		}
		data[i].clusterNo = record;
	}

	//if converge, end clustering
	int same = 0;
	for (int i = 0; i < 4; i++){
		if (last_mean[i].x == means[i].x&&last_mean[i].y == means[i].y){
			same++;
		}

	}

	if (same == 4){
		return;
	}
	else{
		kmeans(data, means);
	}

}



#endif
