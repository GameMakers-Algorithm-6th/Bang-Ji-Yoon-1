#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, answer = 0;
    cin >> n >> k;

    const int number = n;
    int coin[number];
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }

    while(k!=0){
        for(int i=n-1;i>=0;i--){
            if(k>=coin[i]){
                answer++;
                k -= coin[i];
                break;
            }
        }
    }

    cout << answer;

    return 0;
}