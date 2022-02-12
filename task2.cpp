#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <ctime>
using namespace std;
class GameOverExcept: public exception
{
public:
    const char* what() const noexcept{
        return "game over!";
    }
};
class WinExcept: public exception
{
public:
    const char* what() const noexcept{
        return "win";
    }
};
class InvalidArg: public exception
{
public:
    const char* what() const noexcept{
        return "invali argument";
    }
};
int main(){
    srand(time(0));
    char lake[9][9] = {0};
    int x = 0;
    int y = 0;
    for (int i = 0; i < 3; i++){
        while(lake[x][y] != 0){
            x = rand() % 9;
            y = rand() % 9;
        }
        lake[x][y] = 'b';
    }
    while(lake[x][y] != 0){
        x = rand() % 9;
        y = rand() % 9;
    }
    lake[x][y] = 'f';
    bool flag = true;
    if (false){
        for (int i = 8; i >= 0; i--){
            for (int j = 0; j < 9; j++){
                cout << lake[j][i];
            }
            cout << endl;
        }
    }
    while (flag) {
        cout << "enter coordinates\n";
        cin >> x >> y;
        try {
            if ((x >= 9 || x < 0) || (y >= 9 || y < 0)){
                throw InvalidArg();
            }
            if (lake[x][y] == 'f') {
                throw WinExcept();
            }
            if (lake[x][y] == 'b') {
                throw GameOverExcept();
            }
        }
        catch (const WinExcept& i) {
            cout << "game: " << i.what() << endl;
            flag = false;
        }
        catch (const GameOverExcept& i){
            cerr << "game: " << i.what() << endl;
            flag = false;
        }
        catch (const InvalidArg& i){
            cerr << "Error " << i.what() << endl;
        }
    }

    return 0;
}
