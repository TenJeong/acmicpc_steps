#include <iostream>

using namespace std;

int main(void){
    int cur_hh,cur_mm;
    int est;

    cin>>cur_hh>>cur_mm>>est;

    cur_mm += est;

    cur_hh+=cur_mm/60;
    cur_mm%=60;
    if(cur_hh>=24) cur_hh%=24;

    cout<<cur_hh<<" "<<cur_mm;

    return 0;
}