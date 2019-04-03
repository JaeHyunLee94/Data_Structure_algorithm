#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int SIZE=20;
void SWAP(int& a, int& b){
    int tmp=a;
    a=b;
    b=tmp;
}


using namespace std;


void insertion_sort(vector<int>& A){

    for(int i=0; i < A.size(); i++){
        
        int j=i;
        while(j>0&&A[j-1]>A[j]){
            SWAP(A[j-1],A[j]);
            --j;

        }
            
        


    }


}


int main(void){
    
    srand((unsigned) time(NULL));
    vector<int> vb;
    vb.reserve(SIZE);
    cout<< " Before sorting: ";

    for(int i = 0; i < SIZE; i++)
    {
        vb.push_back(rand()%100);
        cout<< vb[i]<<" ";
    }
    cout<< endl;

    insertion_sort(vb);
    cout<< "After sorting: ";

     for(int i = 0; i < SIZE; i++)
    {
        cout<< vb[i]<<" ";
    }




    return 0;

}
