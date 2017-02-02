//
//  main.cpp
//  hw1
//
//  Created by Moses Xie on 9/23/16.
//  Copyright © 2016 Moses Xie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include<cstdlib>
using namespace std;



template <class T>
class DynArray{
    T * data;
    int cap;
    int numOfElements;
public:
    DynArray() :numOfElements(0), cap(5){ data = new int[cap]; }
    ~DynArray(){ delete[] data; }
    DynArray(const DynArray& rhs) :numOfElements(0), cap(0),data(nullptr){ *this = rhs; }
    int size()const{ return numOfElements; }
    int capacity() const { return cap; }
    T operator[](int index) const{ return data[index]; }
    T& operator[](int index){ return data[index]; }
    
    int pop_back();
    void push_back(int newVal);
    void clear();
    void changeCapacity(int newCap);
    DynArray& operator=(const DynArray& rhs);
};



template <class T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T>& rhs){
    if (this == &rhs)
        return *this;
    delete[] data;
    cap = rhs.numOfElements;
    data = new int[cap];
    for (int i = 0; i < rhs.numOfElements; i++)
        data[i] = rhs.data[i];
    numOfElements = rhs.numOfElements;
    return *this;
}

template <class T>
void DynArray<T>::changeCapacity(int newCap){
    int* temp = new int[newCap];
    int itemsToCopy;
    if (newCap < numOfElements){
        itemsToCopy = newCap;
        numOfElements = newCap;
    }
    else
        itemsToCopy = numOfElements;
    for (int i = 0; i < itemsToCopy; i++)
        temp[i] = data[i];
    cap = newCap;
    delete[] data;
    data = temp;
}

template <class T>
void DynArray<T>::clear(){
    numOfElements = 0;
    delete[] data;
    cap = 5;
    data = new int[cap];
}

template <class T>
void DynArray<T>::push_back(int newVal){
    if (numOfElements == cap)
        changeCapacity(cap * 2 + 1);
    data[numOfElements++] = newVal;
}

template <class T>
int DynArray<T>::pop_back(){
    if (numOfElements > 0)
        numOfElements--;
    return data[numOfElements];
}




class Lock{
public:
    Lock (const int number1, const int number2, const int number3): opened(false){
        combination.push_back(number1);
        combination.push_back(number2);
        combination.push_back(number3);
    }
    
    void open(const int num1, const int num2, const int num3){
        if(num1 == combination[0] && num2 == combination[1] && num3 == combination[2]){
            opened = true;
        }
    }
    
    void changeCombo(const int changednum1, const int changednum2, const int changednum3, const int attemptnum1, const int attemptnum2, const int attemptnum3){
        if(attemptnum1 == combination[0] && attemptnum2 == combination[1] && attemptnum3 == combination[2]){
            combination[0] = changednum1;
            combination[1] = changednum2;
            combination[2] = changednum3;
        }
        
    }
    
    
private:
    
    bool opened;
    vector<int> combination;
    Lock(const Lock&);

};

double totalCost(map<int,double> items, vector<int> customerOrder){
    double sum = 0;
    for(int i: customerOrder){
        sum += items[i];
    }
    
    return sum;
}


int main(int argc, const char * argv[]) {

    map<int, double> itemInfo;
    
    ifstream file;
    int itemNumber;
    double itemPrice;
    
    file.open("HW1data.txt");
    
    if(!file){
        cerr << "Error" << endl;
        exit(1);
    }
    
    while(file >> itemNumber >> itemPrice){
        itemInfo[itemNumber] = itemPrice;
        
    }
    
    vector<int> purchasedItems;
    purchasedItems.push_back(99);
    purchasedItems.push_back(47);
    purchasedItems.push_back(22);
    
    cout << totalCost(itemInfo, purchasedItems);
    
    
    
    
}
