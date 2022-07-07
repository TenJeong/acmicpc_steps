#include <iostream>
#include <cmath>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;

    cin>>n;

    // 0�� ������ �������� 10�� ������ �ľ��Ѵ�.
    // 10 = 2 x 5�̸�, ��� �ڿ����� ���丮���� ���μ������ϸ� 2�� 5���� �е������� ����.
    // ���� 5�� �������� ������ ã�´�.

    int count = 0;
    for(int i = 5; i <= n; i *= 5){
        count += (n / i);
    }

    cout<<count;

    return 0;
}