#include <iostream>
#include <vector>
using namespace std;
template<typename T>
void average(vector<T>& vec)
{
    T sum = 0;
    for (auto i : vec){
        sum += i;
    }
    cout << "average " << sum / vec.size() << endl;
}

template<typename T2>
void addMyVec(){
    vector<T2> vec;
    T2 j = 0;
    do{
        cin >> j;
        if (j != 0){
            vec.push_back(j);
        }
    }while(j != 0);
        average(vec);
}

int main(){
    cout << "enter number array\n";
        addMyVec<double>();
        addMyVec<int>();
        addMyVec<float>();
    return 0;
}
