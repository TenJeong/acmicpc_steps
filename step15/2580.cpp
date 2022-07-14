#include <iostream>

using namespace std;

int nums[9][9];
pair<int, int> zeros[81];
int zero_num = 0;
bool isFound = false;

bool check(int row, int col, int num){
    for(int i = 0; i < 9; i++){ // ��� ���� �˻���
        if((col != i && nums[row][i] == num) || (row != i && nums[i][col] == num)){ // �ش� ��� ���� �ߺ��� ���������� �Ǵ�
            return false;
        }
    }

    int square_row = row / 3 * 3;   // 3 X 3 ũ�� ���� �»���� ��
    int square_col = col / 3 * 3;   // 3 X 3 ũ�� ���� �»���� ��

    for(int i = square_row; i < square_row + 3; i++){   // square_row�κ��� 3��
        for(int j = square_col; j < square_col + 3; j++){   // square_col�κ��� 3��
            if(i != row && j != col && nums[i][j] == num){  // �ߺ��� ���������� �Ǵ�
                return false;
            }
        }
    }
    return true;
}

void sudoku(int count){
    if(count == zero_num){  // 0�� ��� ä�� �־��ٸ� ���
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout<<nums[i][j]<<' ';
            }
            cout<<'\n';
        }
        isFound = true; // �� �̻� ����� ���� �ʱ� ���� ����
        return;
    }

    for(int i = 1; i <= 9; i++){
        int row = zeros[count].first;   // count��° 0�� ��
        int col = zeros[count].second;  // count��° 0�� ��

        nums[row][col] = i; // 1~9�� ���� ������
        if(check(row, col, i)) sudoku(count+1); // ���� �� �ִٸ� ���� 0�� ã��
        nums[row][col] = 0; // ������ ���� �ʱ�ȭ
        if(isFound) return; // ���� �ϼ��ߴٸ� ���̻� ������ �ʿ� ����
    }
}

int main(){


    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int temp;
            cin>>temp;
            if(temp == 0){  // 0 �� ���� �� ��ġ ����
                zeros[zero_num++] = make_pair(i, j);
            }
            nums[i][j] = temp;
        }
    }

    sudoku(0);


    return 0;
}