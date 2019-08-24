#include <iostream>
#include <map>
using namespace std;
int main(){
    enum Season {
        Summer, Fall, Winter, Spring
    };
    string arSeason[] =
    {"Summer", "Fall", "Winter", "Spring"};

    map<string, Season> seasons = {
        {"Summer", Summer},
        {"Fall", Fall},
        {"Winter", Winter},
        {"Spring", Spring}};

    cout <<Winter << " " << arSeason[Winter] << endl;
    cout <<"Winter" << " " << seasons["Winter"] << endl;
    cout << (Winter==Season(2)) << endl;
    //winter is Season.Winter

}
