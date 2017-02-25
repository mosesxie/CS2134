#include <iostream>
#include <ctime>
#include <vector>
#include <set>

using namespace std;

template<class T>
void selectionSort(vector<T>& v){ //O(N^2)
	for (int i = 0; i < v.size(); i++){
		int min = i;
		for (int j = i + 1; j < v.size(); j++)
			if (v[j] < v[min])
				min = j;
		T temp = v[i];
		v[i] = v[min];
		v[min] = temp;
	}
}

template <class T>
void setSort(vector<T>& v){ //O(N log N)
	multiset<T> m;
	for (T i : v) //O(N)
		m.insert(i); //O(log N)
	v.clear();
	for (T i : m)
		v.push_back(i);
}

template <class T>
void insertionSort(vector<T>& v){ //O(N^2)
	for (int i = 1; i < v.size(); i++){
		int j = i;
		T temp = v[j];
		for (; j>0 && temp < v[j - 1]; j--){
			v[j] = v[j - 1];
		}
		v[j] = temp;
	}
}
template <class T>
void insertionSort(vector<T>& v, int start, int end){ //O(N^2)
	for (int i = start; i <= end; i++){
		int j = i;
		T temp = v[j];
		for (; j>start && temp < v[j - 1]; j--){
			v[j] = v[j - 1];
		}
		v[j] = temp;
	}
}
template <class T>
void shellSort(vector<T>& v){
	for (int gap = v.size() / 2; gap > 0; gap /= 2){
		for (int i = gap; i < v.size(); i++){
			T temp = v[i];
			int j = i;
			for (; j >= gap && temp < v[j - gap]; j -= gap)
				v[j] = v[j - gap];
			v[j] = temp;
		}
	}
}

class Timer{
	double start;
public:
	Timer(){ start = clock(); }
	void reset(){ start = clock(); }
	double elapsed(){ return (clock() - start) / CLOCKS_PER_SEC; }
};
template <class T>
void merge(vector<T>& v, vector<T>& temp, int leftstart, int leftend, int rightend){
	int rightstart = leftend + 1;
	int tempstart = leftstart;
	int temppos = leftstart;
	while (leftstart <= leftend && rightstart <= rightend){
		if (v[leftstart] < v[rightstart])
			temp[temppos++] = v[leftstart++];
		else
			temp[temppos++] = v[rightstart++];
	}
	while (leftstart<=leftend)
		temp[temppos++] = v[leftstart++];
	while (rightstart<=rightend)
		temp[temppos++] = v[rightstart++];

	for (; tempstart <= rightend; tempstart++)
		v[tempstart] = temp[tempstart];
}

template <class T>
void mergeSort(vector<T>& v, vector<T>& temp, int start, int end){
	if (start >= end)//base case for recursion
		return;
	int middle = (start + end) / 2;
	mergeSort(v, temp, start, middle);
	mergeSort(v, temp, middle + 1, end);
	merge(v, temp, start, middle, end);
}
template <class T>
void mergeSort(vector<T>& v){ //driver
	vector<T> temp;
	temp.resize(v.size());
	mergeSort(v, temp, 0, v.size() - 1);
}
template <class T>
void printArr(vector<T>& v){
	for (T i : v)
		cout << i << ",";
}
const int MIN_SIZE = 4;
template <class T>
void quickSort(vector<T>& v, int start, int end){
	if (start + MIN_SIZE > end)
		insertionSort(v, start, end);
	else
	{
		int middle = (start + end) / 2;
		if (v[middle] < v[start])
			swap(v[middle], v[start]);
		if (v[end] < v[start])
			swap(v[end], v[start]);
		if (v[end] < v[middle])
			swap(v[end], v[middle]);
		T pivot = v[middle];

		swap(v[middle], v[end - 1]); //move the pivot out of the way, for now
		int i = start;
		int j = end - 1;
		while (true){
			while (v[++i] < pivot){}
			while (pivot < v[--j]){}
			if (i < j)
				swap(v[i], v[j]);
			else
				break;
		}
		swap(v[end - 1], v[i]); //restore the pivot to its FINAL place
		/*DEBUG*/
		//cout << "QS: P=" << pivot << " S=" << start << " E=" << end<<" ";
		//printArr(v);
		//cout << endl;

		quickSort(v, start, i - 1);
		quickSort(v, i + 1, end);
	}
}

template <class T>
void quickSort(vector<T>& v){ //driver
	quickSort(v, 0, v.size() - 1);
}

template <class T, class Comparator>
void insertionSort(vector<T>& v, int start, int end, Comparator c){ //O(N^2)
	for (int i = start; i <= end; i++){
		int j = i;
		T temp = v[j];
		for (; j>start && c(temp,v[j - 1]); j--){
			v[j] = v[j - 1];
		}
		v[j] = temp;
	}
}
template <class T, class Comparator>
void quickSort(vector<T>& v, int start, int end, Comparator c){
	if (start + MIN_SIZE > end)
		insertionSort(v, start, end,c);
	else
	{
		int middle = (start + end) / 2;
		if (c(v[middle],v[start]))
			swap(v[middle], v[start]);
		if (c(v[end] ,v[start]))
			swap(v[end], v[start]);
		if (c(v[end] ,v[middle]))
			swap(v[end], v[middle]);
		T pivot = v[middle];

		swap(v[middle], v[end - 1]); //move the pivot out of the way, for now
		int i = start;
		int j = end - 1;
		while (true){
			while (c(v[++i],pivot)){}
			while (c(pivot,v[--j])){}
			if (i < j)
				swap(v[i], v[j]);
			else
				break;
		}
		swap(v[end - 1], v[i]); //restore the pivot to its FINAL place
		/*DEBUG*/
		//cout << "QS: P=" << pivot << " S=" << start << " E=" << end<<" ";
		//printArr(v);
		//cout << endl;

		quickSort(v, start, i - 1,c);
		quickSort(v, i + 1, end,c);
	}
}

template <class T, class Comparator>
void quickSort(vector<T>& v, Comparator c){ //driver
	quickSort(v, 0, v.size() - 1,c);
}
class Person{
public:
	string name;
	int age;
	double weight;
};

class lessThanOnAge{
public:
	bool operator()(const Person& lhs, const Person& rhs) const{
		return lhs.age < rhs.age;
	}
};

int main(){
	vector<Person> vp;
	quickSort(vp, lessThanOnAge());
	srand(time(NULL));
	vector<int> v;
	/*for (int i = 0; i < 20; i++)
		v.push_back(rand() % 100);
	quickSort(v);
	cout << "Sorted:         ";
	printArr(v);
	cout << endl;*/
	double elapsed;
	Timer t;
	Timer t2;
	for (int i = 0; i < 10; i++){
		v.clear();
		for (int j = 0; j < (i+1) * 1000000; j++)
			v.push_back(rand());
		t.reset();
		quickSort(v);
		elapsed = t.elapsed();
		cout << "v.size=" << v.size() << " Sorting took " << elapsed << " seconds" << endl;
	}
}