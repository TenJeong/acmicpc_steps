#include <iostream>

using namespace std;

int main(void){
    int case_num, stu_num;
    int sc, count=0;
    float total = 0.0f;

    cin.tie(NULL);

    cout<<fixed;
    cout.precision(3);

    cin>>case_num;

    for(int i = 0; i < case_num; i++){
        cin>>stu_num;
        total = 0;
        count = 0;
        int score[stu_num];
        for(int j = 0; j < stu_num; j++){
            cin>>sc;
            total += sc;
            score[j] = sc;
        }
        total/=stu_num;
        for(int j = 0; j < stu_num; j++)
            if(score[j] > total)
                count++;
        cout<<(float)count/stu_num*100<<'%'<<'\n';
    }


    return 0;
}