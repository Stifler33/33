#include <iostream>
#include <exception>
#include <map>
#include <fstream>
using namespace std;
class Store
{
    map<string, int> base;
public:
    Store() = default;
    Store(string _path, bool info = false){
        ifstream file;
        file.open(_path);
        if (!file.is_open()){
            cout << "file not open\n";
        }else{
            while (!file.eof()){
                string name;
                int sum;
                file >> name >> sum;
                base[name] = sum;
            }
            file.close();
            //input info base
            if (info) {
                cout << "base is full\n";
                for (const auto &itr: base) {
                    cout << itr.first << " " << itr.second << endl;
                }
            }
        }
    }
    void issueGoods(map<string, int>& _obj, string& name, int& sum) {
        if (sum <= 0 || sum > INT_MAX){
            cout << "Error sum\n";
            return;
        }
        if (auto itrBase = base.find(name); itrBase != base.end()){
            if (itrBase->second >= sum){
                if (auto i = _obj.find(name); i != _obj.end()){
                    i->second += sum;
                    itrBase->second -= sum;
                    return;
                }
                _obj.insert({itrBase->first, sum});
                itrBase->second -= sum;
                return;
            }
            cout << "there is no such quantity\n";
            return;
        }
        cout << "not product\n";
    }
    void returnBack(string& name, int& sum) {
        if (sum <= 0 || sum > INT_MAX){
            cout << "Error sum\n";
            return;
        }
        if (auto itr = base.find(name); itr != base.end()){
            itr->second += sum;
        }
    }
};

class Basket
{
    map<string, int> usBas;
    Store* store;
public:
    Basket(Store& _store){
        store = &_store;
    }
    void add(string name, int sum) {
        store->issueGoods(usBas, name, sum);
    }
    void listProduct(){
        if (usBas.empty()) cout << "basket empty\n";
        for (auto i : usBas){
            cout << i.first << " " << i.second << endl;
        }
    }
};

int main() {
    Store store("..\\data.txt", true);
    Basket basket(store);
    basket.add("banana", 4);
    basket.listProduct();
    return 0;
}
