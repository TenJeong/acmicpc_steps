#include <iostream>

using namespace std;

int main(){

    string str;
    int str_size=0;
    int count=0;
    int ptr = 0;

    cin>>str;
    str_size = str.size();

    while(ptr < str_size){
        if(str[ptr] == 'c'){
            if(ptr<str_size-1 && (str[ptr+1] == '=' || str[ptr+1] == '-')){
                count++;
                ptr+=2;
            }
            else{
                count++;
                ptr+=1;
            }
        }
        else if(str[ptr] == 'd'){
            if(ptr<str_size-1 && str[ptr+1] == '-'){
                count++;
                ptr+=2;
            }
            else if(ptr < str_size - 2 && str[ptr+1] == 'z' && str[ptr+2] == '='){
                count++;
                ptr+=3;
            }
            else{
                count++;
                ptr+=1;
            }
        }
        else if(str[ptr] == 'l' || str[ptr] == 'n'){
            if(ptr<str_size-1 && str[ptr+1] == 'j'){
                count++;
                ptr+=2;
            }
            else{
                count++;
                ptr+=1;
            }
        }
        else if(str[ptr] == 's'){
            if(ptr<str_size-1 && str[ptr+1] == '='){
                count++;
                ptr+=2;
            }
            else{
                count++;
                ptr+=1;
            }
        }
        else if(str[ptr] == 'z'){
            if(ptr<str_size-1 && str[ptr+1] == '='){
                count++;
                ptr+=2;
            }
            else{
                count++;
                ptr+=1;
            }
        }
        else{
            count++;
            ptr+=1;
        }
    }

    cout<<count;

    return 0;
}