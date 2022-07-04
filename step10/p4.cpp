#include <iostream>

using namespace std;

int main(){

    int n, m;
    int answer = 64;

    scanf("%d %d",&n,&m);

    char arr[n][m];

    getchar();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = getchar();
        }
        getchar();
    }

    for(int start_row = 0; start_row + 8 <= n; start_row++){
        for(int start_col = 0; start_col + 8 <= m; start_col++){
            //white first
            int fix_count = 0;
            for(int row = start_row; row < start_row + 8; row++){
                for(int col = start_col; col < start_col + 8; col++){
                    if((row + col) % 2 == 0){
                        if(arr[row][col] == 'B')
                            fix_count++;
                    }
                    else{
                        if(arr[row][col] == 'W')
                            fix_count++;
                    }
                }
                if(fix_count >= answer)
                    break;
            }

            if(fix_count < answer)
                answer = fix_count;

            //black first
            fix_count = 0;
            for(int row = start_row; row < start_row + 8; row++){
                for(int col = start_col; col < start_col + 8; col++){
                    if((row + col) % 2 == 0){
                        if(arr[row][col] == 'W')
                            fix_count++;
                    }
                    else{
                        if(arr[row][col] == 'B')
                            fix_count++;
                    }
                }
                if(fix_count >= answer)
                    break;
            }

            if(fix_count < answer)
                answer = fix_count;
        }
    }

    printf("%d",answer);


    return 0;
}