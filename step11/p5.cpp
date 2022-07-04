#include <iostream>
#include <algorithm>

using namespace std;

int compare(char a, char b){
    return a > b;
}

int main(){
    
    string str;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>str;

    sort(&str[0],&str[str.length()],compare);

    cout<<str;

    return 0;
}