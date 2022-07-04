#include <iostream>

using namespace std;

int main(){
    string str;
    int total=0;

    cin>>str;

    for(char c : str){
        switch(c){
            case 'A':
            case 'B':
            case 'C':
                total+=2;
                break;
            case 'D':
            case 'E':
            case 'F':
                total+=3;
                break;
            case 'G':
            case 'H':
            case 'I':
                total+=4;
                break;
            case 'J':
            case 'K':
            case 'L':
                total+=5;
                break;
            case 'M':
            case 'N':
            case 'O':
                total+=6;
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                total+=7;
                break;
            case 'T':
            case 'U':
            case 'V':
                total+=8;
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                total+=9;
                break;
        }
    }

    cout<<total+1*str.size();

    return 0;
}