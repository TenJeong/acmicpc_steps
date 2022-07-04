#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct {
    int x;
    int y;
    int r;
}Planet;

bool isInPlanet(Planet p, int x, int y){
    if(pow(p.x - x, 2) + pow(p.y - y, 2) < pow(p.r, 2)){
        return true;
    }
    return false;
}

int main(){

    int case_num;
    int src_x, src_y;
    int dest_x, dest_y;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>case_num;

    for(int case_count = 0; case_count < case_num; case_count++){
        cin>>src_x>>src_y>>dest_x>>dest_y;

        int planet_num;
        cin>>planet_num;

        int count=0;
        for(int i = 0; i < planet_num; i++){
            Planet cur_Planet;
            cin>>cur_Planet.x>>cur_Planet.y>>cur_Planet.r;
            bool isSInPlanet = isInPlanet(cur_Planet, src_x, src_y);
            bool isDInPlanet = isInPlanet(cur_Planet, dest_x, dest_y);
            if((isSInPlanet && !isDInPlanet) || (!isSInPlanet && isDInPlanet)){
                count++;
            }
        }
        cout<<count<<'\n';
    }



    return 0;
}