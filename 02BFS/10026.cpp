#include<iostream>
#include<queue>
using namespace std;

bool visited[100][100]={false};
char node[100][100];

//상하좌우, 인근 지역을 나타냄
int dX[] = {0,0,1,-1};
int dY[] = {1,-1,0,0};


void BFS(int a, int b, int N);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	//적록색약 아닌 사람 BFS -> 적록색약 BFS
    int N, count=0;
    cin>>N;

	//입력
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> node[i][j];

	//적록색약x
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(!visited[i][j]){
				BFS(i,j,N);
				count++;
			}
	cout<<count<<" ";

	//초기화
	count=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			visited[i][j]=false;

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(node[i][j]=='G')
				node[i][j]='R';

	//적록색약
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(!visited[i][j]){
				BFS(i,j,N);
				count++;
			}
	cout<<count;

    return 0;
}

void BFS(int a, int b, int N){
	queue<pair<int,int> > q;
	q.push(make_pair(a,b));
	visited[a][b] = true;   
	
	while(!q.empty()) {
		int cX = q.front().first;
		int cY = q.front().second;    
		q.pop();

		for(int i = 0; i<4;i++){
			int nX = cX + dX[i]; //상하좌우 반복
			int nY = cY + dY[i];

			//범위 내 & 방문x & 같은 색일 경우 큐에 추가
			if((nX>=0 && nX < N)&&(nY>=0 && nY<N))
				if(!visited[nX][nY]&&node[nX][nY]==node[cX][cY]){
					q.push(make_pair(nX,nY));
					visited[nX][nY] = true;

				}
			
		}
	}
}
