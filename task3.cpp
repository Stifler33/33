#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
template<typename T1, typename T2>
class Base
{
    multimap<T1, T2> MyMap;
public:
    void add(T1 key, T2 value){
        MyMap.insert({key, value});
    }
    void remove(T1 key){
        if (auto i = MyMap.find(key); i != MyMap.end()){
            MyMap.erase(i);
        }else {
            cout << "no key\n";
        }
    }
    void print(){
        for (auto i : MyMap){
            cout << i.first << " " << i.second << endl;
        }
    }
    void find(T1 key){
        if (auto i = MyMap.find(key); i != MyMap.end()){
            cout << i->second << endl;
        }else{
            cout << "no key\n";
        }
    }
};

int main(){
    Base<int, string> base;
    Base<string, double> base1;
    base1.add("one", 0.123);
    base1.add("two", 12.22);
    base1.remove("one");
    base1.print();
    base.add(2,"sdfs");
    base.add(56,"sdfs");
    base.add(1,"werwr");
    base.find(56);
    base.print();
    return 0;
}