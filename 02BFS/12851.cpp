#include<iostream>
#include<queue>
using namespace std;

int minSec,cnt=0;
int node[100001];
bool visited[100001]={false};

int BFS(int a, int K);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin>>N>>K;

    cout<<BFS(N,K)<<"\n";
    cout<<cnt;
    return 0;
}

int BFS(int a, int K){
	queue<pair<int, int> > q;

	q.push(make_pair(a,0));
	visited[a] = true;
	
	while(!q.empty()) {
		int current = q.front().first;
        int sec = q.front().second;    

		q.pop();
        visited[current]=true;

        if(minSec && minSec==sec && current==K)
            cnt++;
        
        if(!minSec && current==K){
            minSec = sec;
            cnt++;
        }

		//범위 내 & 방문x
		if(current * 2<100001)
			if(!visited[current * 2]){
				q.push(make_pair(current * 2,sec+1));
			}

        if(current + 1<100001)
			if(!visited[current + 1]){
				q.push(make_pair(current + 1,sec+1));
			}
        
        if(current - 1>=0)
			if(!visited[current - 1]){
				q.push(make_pair(current - 1,sec+1));
			}
		}

    return minSec;

}