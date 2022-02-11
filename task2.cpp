#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <ctime>
using namespace std;
class MyException: public exception
{
    string myError;
public:
    MyException(string text): myError(text){}
    const char* what() const noexcept{return myError.c_str();}
};
int main(){
    srand(time(0));
    char lake[9][9] = {0};
    for (int i = 0; i < 3; i++){
        int x = rand() % 9;
        int y = rand() % 9;
        lake[x][y] = 'b';
    }
    int x = rand() % 9;
    int y = rand() % 9;
    lake[x][y] = 'f';

    if (true){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cout << lake[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
