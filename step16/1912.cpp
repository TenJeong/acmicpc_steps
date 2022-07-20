#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
long long largest[100001]; // largest[i] -> � ������ i������ �� �߿��� ���� ū ��
long long answer = -1001;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    largest[0] = arr[0];
    answer = largest[0];

    for(int i = 1; i < n; i++){
        // largest[i-1] + arr[i]�� arr[i]�� ���Ѵ�.
        // arr[i]���� �۴ٴ� ���� �ձ����� ���� ������
        // arr[i]�� ������ �� �ս��� �߻��Ѵٴ� ���̴�.
        if(largest[i-1] + arr[i] < arr[i]){ // ���ذ� �ִٸ� i���� �ٽ� ����
            largest[i] = arr[i];
        }
        else{
            largest[i] = largest[i-1] + arr[i];
        }

        if(answer < largest[i]) answer = largest[i];
    }

    cout<<answer;

    return 0;
}