#include <iostream>

using namespace std;

int nums[9][9];
pair<int, int> zeros[81];
int zero_num = 0;
bool isFound = false;

bool check(int row, int col, int num){
    for(int i = 0; i < 9; i++){ // 행과 열을 검사함
        if((col != i && nums[row][i] == num) || (row != i && nums[i][col] == num)){ // 해당 행과 열에 중복된 숫자인지를 판단
            return false;
        }
    }

    int square_row = row / 3 * 3;   // 3 X 3 크기 판의 좌상단의 행
    int square_col = col / 3 * 3;   // 3 X 3 크기 판의 좌상단의 열

    for(int i = square_row; i < square_row + 3; i++){   // square_row로부터 3개
        for(int j = square_col; j < square_col + 3; j++){   // square_col로부터 3개
            if(i != row && j != col && nums[i][j] == num){  // 중복된 숫자인지를 판단
                return false;
            }
        }
    }
    return true;
}

void sudoku(int count){
    if(count == zero_num){  // 0을 모두 채워 넣었다면 출력
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout<<nums[i][j]<<' ';
            }
            cout<<'\n';
        }
        isFound = true; // 더 이상 계산을 하지 않기 위한 변수
        return;
    }

    for(int i = 1; i <= 9; i++){
        int row = zeros[count].first;   // count번째 0의 행
        int col = zeros[count].second;  // count번째 0의 열

        nums[row][col] = i; // 1~9의 수를 선택함
        if(check(row, col, i)) sudoku(count+1); // 넣을 수 있다면 다음 0을 찾음
        nums[row][col] = 0; // 선택한 수를 초기화
        if(isFound) return; // 판을 완성했다면 더이상 연산이 필요 없음
    }
}

int main(){


    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int temp;
            cin>>temp;
            if(temp == 0){  // 0 의 개수 및 위치 저장
                zeros[zero_num++] = make_pair(i, j);
            }
            nums[i][j] = temp;
        }
    }

    sudoku(0);


    return 0;
}