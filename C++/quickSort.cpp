//
//  quickSort.cpp
//  
//
//  Created by Monica Garcia on 3/18/20.
//

#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;
int partition(vector<int> &a, int frist, int last);
int partition_i(vector<int> &a, int frist, int last);
void quickSort(vector<int> &a, int frist, int last);

int main(){
    vector<int> a;
    srand(time(NULL));
    for(int i = 0; i <= 100; i++){
        int randn = 1 + rand() % 100;
        a.push_back(randn);
    }
    int size = a.size();
    quickSort(a,0,size - 1);
    for(int i = 0; i<100; i++)
        cout << a[i] << " ";
    cout << endl << endl;
    
}
int partition(vector<int> &a, int frist, int last){
    int pivot = a[last];
    int i = frist - 1;
    for(int j = frist; j <= last - 1; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[last]);
    return i + 1;
}


int partition_i(vector<int> &a, int frist, int last){
    int pivot = 1 + rand() % a.size();
    swap(a[pivot],a[last]);
    return partition(a, frist, last);
}

void quickSort(vector<int> &a, int frist, int last){
    if (frist < last) {
        int pivot = partition_i(a, frist, last);
        quickSort(a, frist, pivot - 1);
        quickSort(a, pivot + 1, last);
    }
}
