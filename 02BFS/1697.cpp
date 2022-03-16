#include<iostream>
#include<queue>
using namespace std;

int node[100001];
bool visited[100001]={false};

int BFS(int a, int K);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,K;
    cin>>N>>K;

    cout<<BFS(N,K);

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

        if(current==K)
            return sec;

        int x1 = current * 2;
        int x2 = current + 1;
        int x3 = current - 1;

		//범위 내 & 방문x
		if(x1>=0&&x1<100001)
			if(!visited[x1]){
				q.push(make_pair(x1,sec+1));
				visited[x1] = true;
			}
        if(x2>=0&&x2<100001)
			if(!visited[x2]){
				q.push(make_pair(x2,sec+1));
				visited[x2] = true;
			}
        
        if(x3>=0&&x3<100001)
			if(!visited[x3]){
				q.push(make_pair(x3,sec+1));
				visited[x3] = true;
			}
		}
    return -1;
}