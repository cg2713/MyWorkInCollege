#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;
void mergeSort(vector<int> &a, int left, int right);
void MergeSort(vector<int> &a, int left, int middle, int right);

int main(int argc, char *argv[]){
	srand (time(NULL));//only once 
	vector<int> a;
	
	for(int i = 0; i < 100000; i++){
		int randn = 1 + rand() % 10000000;
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

void MergeSort(vector<int> &a, int left, int middle, int right){
    int i,j,k;
    int leftArrayN = middle - left + 1;;
    int rightArrayN = right - middle;
    
    int L[leftArrayN], R[rightArrayN];
    
    for(i = 0; i < leftArrayN; i++)
        L[i] = a[left + i];
    for(j = 0; j < rightArrayN; j++)
        R[j] = a[middle + 1+ j];
    
    i = 0;
    j = 0;
    k = left;
    
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
void mergeSort(vector<int> &a, int left, int right){
    if (left < right){
        int middle = left+(right-left)/2;
        mergeSort(a, left, middle);
        mergeSort(a, middle+1, right);
        MergeSort(a, left, middle, right);
    }
}
