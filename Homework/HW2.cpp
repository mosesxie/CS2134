//
//  main.cpp
//  hw3
//
//  Created by Moses Xie on 11/1/16.
//  Copyright © 2016 Moses Xie. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Cafeteria_account{
public:
    string name;
    int ID;
    double amount;
    
    
    void addToVector(string newname, int newID, double newamount,vector<Cafeteria_account>& ListofAccounts){
        Cafeteria_account newAccount;
        newAccount.name = newname;
        newAccount.ID = newID;
        newAccount.amount = newamount;
        
        ListofAccounts.push_back(newAccount);
        
        
    }
    
    
};

void print(vector<Cafeteria_account>& ListofAccounts){
    for(Cafeteria_account x:ListofAccounts){
        cout << x.name << "\n";
    }
    cout << "\n";
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

class lessThanOnID{
public:
    bool operator()(const Cafeteria_account& lhs, const Cafeteria_account& rhs) const{
        return lhs.ID < rhs.ID;
    }
};

class lessThanOnAmount{
public:
    bool operator()(const Cafeteria_account& lhs, const Cafeteria_account& rhs) const{
        return lhs.amount < rhs.amount;
    }
};

class lessThanOnName{
public:
    bool operator()(const Cafeteria_account& lhs, const Cafeteria_account& rhs) const{
        return lhs.name < rhs.name;
    }
};



int main() {
    string name;
    int ID;
    double amount;
    vector<Cafeteria_account> ListofAccounts;
    
    
    ifstream file;
    file.open("jabberwocky.txt");
    
    while(file >> name >> ID >> amount){
        Cafeteria_account newAccount;
        newAccount.addToVector(name, ID, amount, ListofAccounts);
    }
    int size = ListofAccounts.size()-1;
    
    cout << "orginal list \n";
    
    print(ListofAccounts);
    
    insertionSort(ListofAccounts,0,size, lessThanOnID());
    
    cout << "Sorted by ID \n";
    
    print(ListofAccounts);
    
    insertionSort(ListofAccounts,0,size,lessThanOnAmount());
    
    cout << "Sorted by amount \n";
    
    print(ListofAccounts);
    
    insertionSort(ListofAccounts,0,size,lessThanOnName());
    
    cout << "Sorted by name \n";
    
    print(ListofAccounts);
    
}
