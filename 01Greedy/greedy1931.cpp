#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //2차원 배열에 값 저장 후 회의하는 시간 별로 정렬, 후에 반복문으로 
    int n, a, b, answer=1;
    vector<pair<int,int> > room;

    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> a >> b;
        room.push_back(make_pair(b,a));
    }

    sort(room.begin(),room.end());

    a=room[0].first;
    for(int i=1;i<n;i++){
        if(a<=room[i].second){
            answer++;
            a=room[i].first;
        }
    }


    cout<<answer;
    return 0;
}
