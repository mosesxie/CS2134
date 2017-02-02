#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Timer{
	double start;
public:
	Timer(){ start = clock(); }
	void reset(){ start = clock(); }
	double elapsed()const { return (clock() - start) / CLOCKS_PER_SEC; }
};

void printList(const list<int>& l){
	for (list<int>::const_iterator i = l.begin(); i != l.end(); i++)
		cout << *i << endl;

}

int main(){
	srand(time(NULL));
	map<string, int> m;
	m.insert(pair<string, int>("Daniel", 100));
	m.insert(pair<string, int>("Al", 98));
	m.insert(pair<string, int>("John", 80));
	m["George"] = 70;
	cout << "Daniel=" << m["Daniel"] << endl;
	if (m.find("Jimmy") != m.end())//make sure Jimmy exists, or he will be created!
		cout << "Jimmy=" << m["Jimmy"] << endl;
	cout << "*************************************" << endl;

	for (map<string, int>::iterator i = m.begin(); i != m.end(); i++)
		cout << i->first << "=" << i->second << endl;
	/*multiset<int> s;
	for (int i = 0; i < 100; i++)
		s.insert(rand() % 1000);
	for (int i : s)
		cout << i << endl;
	cout << "Size=" << s.size() << endl;
	*/
	/*set<int> s;
	double elapsed = 0;
	double previousTime = 0;
	Timer t;
	for (int i = 0; i < 100000000; i++){
		t.reset();
		s.insert(i);
		elapsed = t.elapsed();
		if (elapsed > previousTime){
			cout << "size=" << s.size() 
				<< " Elapsed=" << elapsed
				<< endl;
			previousTime = elapsed;
		}
	}*/

	//for (set<int>::iterator i = s.begin(); i != s.end(); i++)
	//	cout << *i << endl;
	//for (int i : s)
	//	cout << i << endl;
	
	/*pair<string, int> p1; //pair<string,int> p1("Daniel", 100);
	p1.first = "Daniel";
	p1.second = 100;
	pair<pair<string, int>, pair<float, char>> p2;
	p2.first.first = "Daniel";
	p2.first.second = 100;
	p2.second.first = 2.5;
	p2.second.second = 'A';*/
	/*list<int> l;
	for (int i = 0; i < 100; i++)
		l.push_back(rand() % 1000);

	l.sort();
	//sort(l.begin(), l.end());
	printList(l);
	//for (int& i : l)
	//	cout << i << endl;
	*/
	/*
	vector<int> v;
	double elapsed = 0;
	double previousTime = 0;
	Timer t;
	for (int i = 0; i < 100000000; i++){
		t.reset();
		v.push_back(i);
		elapsed = t.elapsed();
		if (elapsed > previousTime){
			cout << "size=" << v.size() << " capacity=" << v.capacity() 
				<<" Elapsed="<<elapsed
				<< endl;
			previousTime = elapsed;
		}
	}
	*/
	//for (int i : v)
	//	cout << i << endl;

	//for (int i = 0; i < v.size(); i++)
	//	cout << "v[" << i << "]=" << v[i] << endl;
}