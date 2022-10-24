#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;
void mergeSort(vector<int> &a, int l, int r);
void MergeSort(vector<int> &a, int l, int m, int r);

int main(int argc, char *argv[]){
	srand (time(NULL));//only once 
	vector<int> a;
	
	for(int i = 0; i < 100; i++){
		int randn = 1 + rand() % 10000;
		a.push_back(randn);
	}
    for(int i = 0; i <= a.size()-1; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    cout << endl;
    mergeSort(a, 0, a.size() - 1);
    
    for(int i = 0; i <= a.size()-1; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

void MergeSort(vector<int> &a, int l, int m, int r){
    int i,j,k;
    int leftArrayN = m - l + 1;;
    int rightArrayN = r - m;
    
    int L[leftArrayN], R[rightArrayN];
    
    for(i = 0; i < leftArrayN; i++)
        L[i] = a[l + i];
    for(j = 0; j < rightArrayN; j++)
        R[j] = a[m + 1+ j];
    
    i = 0;
    j = 0;
    k = l;
    
    while(i < leftArrayN and j < rightArrayN){
        if(L[i] < R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < leftArrayN){
          a[k] = L[i];
          i++;
          k++;
      }
    while (j < rightArrayN){
          a[k] = R[j];
          j++;
          k++;
      }
    
}
void mergeSort(vector<int> &a, int l, int r){
    if (l < r){
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
  
        // Sort first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
  
        MergeSort(a, l, m, r);
    }
}
