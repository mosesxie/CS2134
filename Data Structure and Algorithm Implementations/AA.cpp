#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

int func1(vector<int>& v, int item){  //O(N)
	for (int i = 0; i < v.size(); i++)
		if (item == v[i]) //CLOC 
			return i;
	return -1;
}

int func2(vector<int>& v, int item){//O(log N)
	int a = 0;
	int b = v.size() - 1;
	int c = (b + a) / 2;
	while (a <= b){
		if (item == v[c])
			return c;
		else if (item < v[c])
			b = c - 1;
		else
			a = c + 1;
		c = (b + a) / 2; //Controlling line of code
	}
	return -1;
}

void func3(vector<int>& v){ //O(N^2)
	for (int i = 0; i < v.size(); i++){
		int a = i;
		for (int j = i + 1; j < v.size(); j++)
			if (v[j] < v[a]) //controlling line of code
				a = j;
		int b = v[a];
		v[a] = v[i];
		v[i] = b;
	}
}

void func4(vector<int>& v){//O(N)
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	int b = 0;
	for (int i = 0; i < v.size(); i++)
		if (v[i] < v[b])
			b = i;
	cout << v[b] << endl;
}


int func5(int n){ //O(log10 N)
	int a = 0;
	while (n > 0){
		a += n % 10;
		n /= 10;
	}
	return a;
}

void func6(vector<int>& v){ //O(N^2)
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v.size(); j++)
			cout << v[i] << "," << v[j] << endl;
}


void func7(vector<int>& v){ //O(N^2)
	int counter = 0;
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v.size(); j++)
			if (i == j) //CLOC
				for (int k = 0; k < v.size(); k++)
					//cout << v[i] << "," << v[j] << ","<<v[k]<<endl; //CLOC
					counter++;
	//cout << "v.size=" << v.size() << " counter=" << counter << endl;
}

void func8(vector<int>& v){ //O(N)
	for (int i = 0; i < v.size(); i += 2)
		cout << v[i] << endl;
}

void func9(vector<int>& v){//O(N^2)
	for (int i = 0; i < v.size(); i++)
		func4(v);
}


class Point{
public:
	int x;
	int y;
	Point(int newx = 0, int newy = 0) :x(newx), y(newy){}
};

double pointDistance(Point a, Point b){//O(1)
	return sqrt(((a.x - b.x)*(a.x - b.x)) + ((a.y - b.y)*(a.y - b.y)));
}

double closestToOrigin(vector<Point>& vp){ //O(N)
	Point origin;
	double min = pointDistance(vp[0], origin);
	for (int i = 1; i < vp.size(); i++){
		double dist = pointDistance(vp[i], origin);
		if (dist < min)
			min = dist;
	}
	return min;
}

double closestPairOfPoints(vector<Point>& vp){//O(N^2)
	double min = pointDistance(vp[0], vp[1]);
	for (int i = 0; i < vp.size(); i++)
		for (int j = i + 1; j < vp.size(); j++){
		double dist = pointDistance(vp[i], vp[j]);
			if (dist < min)
				min = dist;
		}
	return min;
}

bool colinearPoints(vector<Point>& vp){//O(N^3)
	return true;
}

int mcss(vector<int>& v){//O(N^3)
	int max = 0;
	for (int i = 0; i < v.size(); i++){
		for (int j = i; j < v.size(); j++){
			int sum = 0;
			for (int k = i; k <= j; k++)
				sum += v[k];
			if (sum > max)
				max = sum;
		}
	}
	return max;
}
int mcss2(vector<int>& v){//O(N^2)
	int max = 0;
	for (int i = 0; i < v.size(); i++){
		int sum = 0;
		for (int j = i; j < v.size(); j++){
			sum += v[j];
			if (sum > max)
				max = sum;
		}
	}
	return max;
}
int mcss3(vector<int>& v){//O(N)
	int max = 0;
	int sum = 0;
	for (int i = 0; i < v.size(); i++){
		sum += v[i];
		if (sum > max)
			max = sum;
		if (sum < 0)
			sum = 0;
	}
	return max;
}
class Timer{
	double start;
public:
	Timer(){ start = clock(); }
	void reset(){ start = clock(); }
	double elapsed()const { return (clock() - start) / CLOCKS_PER_SEC; }
};

double fib(int n){
	if (n>1)
		return fib(n - 1) + fib(n - 2);
	return 1;
}

int main(){
	vector<int> v;
	v.resize(400);
	Timer t;
	double elapsed = 0;
	for (int i = 1; i < 100; i++){
		//v.resize(v.size()*2);
		t.reset();
		fib(i);
		elapsed = t.elapsed();
		//cout << "v.size()=" << v.size() << " time=" << elapsed << " seconds" << endl;
		cout << "Fib(" << i << ") took " << elapsed << " seconds." << endl;
	}
}
