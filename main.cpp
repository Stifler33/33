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
            cout << "Store: file not open\n";
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
                cout << "Store: base is full\n";
                for (const auto &itr: base) {
                    cout << itr.first << " " << itr.second << endl;
                }
            }
        }
    }
    bool issueGoods(string& name, int& sum) {
        if (sum <= 0 || sum > INT_MAX){
            cout << "Store: Error sum\n";
            return false;
        }
        if (auto itrBase = base.find(name); itrBase != base.end()){
            if (itrBase->second >= sum){
                itrBase->second -= sum;
                return true;
            }
            cout << "Store: there is no such quantity\n";
            return false;
        }
        cout << "Store: not product\n";
        return false;
    }
    bool returnBack(string& name, int& sum) {
        if (sum <= 0 || sum > INT_MAX){
            cout << "Store: Error sum\n";
            return false;
        }
        if (auto itr = base.find(name); itr != base.end()){
            itr->second += sum;
            return true;
        }
        cout << "Store: never had suh a product\n";
        return false;
    }
    void listBase(){
        cout << "Store :\n";
        for (auto i : base){
            cout << i.first << " " << i.second << endl;
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
        if (sum <= 0 || sum > INT_MAX){
            cout << "Basket: Error sum\n";
            return;
        }
        if (store->issueGoods(name, sum)){
            if (auto itr = usBas.find(name); itr != usBas.end()){
                itr->second += sum;
                cout << "Basket: add " << name << " in sum " << sum << endl;
                return;
            }
            usBas.insert({name, sum});
            cout << "Basket: add " << name << " in sum " << sum << endl;
        }
    }
    void remove(string name, int sum){
        if (auto itr = usBas.find(name); itr != usBas.end()){
            if (sum > itr->second || sum <= 0){
                cout << "Basket: not correct sum\n";
                return;
            }
            if (store->returnBack(name, sum)){
                if (itr->second - sum == 0) {
                    usBas.erase(name);
                    cout << "Basket: delete " << name << " in sum " << sum << endl;
                    return;
                }
                itr->second -= sum;
                cout << "Basket: remove " << name << " in sum " << sum << endl;
                return;
            }
        }else {
            cout << "Basket: there is no such product\n";
            return;
        }

        cout << "Basket: delete impossible product\n";
    }
    void listProduct(){
        if (usBas.empty()) cout << "Basket: basket empty\n";
        for (auto i : usBas){
            cout << i.first << " " << i.second << endl;
        }
    }
};

int main() {
    Store store("..\\data.txt", true);
    Basket basket(store);
    basket.add("banana", 4);
    basket.add("banana", 2);
    basket.remove("banana", 8);
    basket.add("banana", 7);
    basket.add("bread", 10);
    basket.remove("bread", 10);
    basket.listProduct();
    store.listBase();
    return 0;
}
