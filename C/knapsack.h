#include<iostream>
#include<vector>
#include <map>

/*

 map<<datatype>,<datatype>>::iterator it = <mapName>.begin();

map<int, float> <name>

<mapName>.insert(make_pair(<data>,<data>);
*/



using namespace std;


template <typename T1, typename T2>
class knapsack{

private:

	//vector<int> val;
	//vector<float> wt;
	map<T1, T2> sack;
    bool full;

public:
    typename map<T1,T2>::iterator it;
    knapsack();
    ~knapsack();

    void insertItem(T1 a, T2 b){
        checkWt();
        if(full != true)
            sack.insert(make_pair(a, b));
    }
    
    bool checkWt(){
        if(sack.size() == 8){
            cout << "sack is full" << endl;
            full = true;
        }
        else if(sack.size() <= 8){
            cout << "sack is over filled" << endl;
            full = false;
            for(it = sack.begin(); it != sack.end(); ++it){
                if(it == 8){
                    sack.erase(it,sack.end());
                }
            }
        }
    }    
};








		

