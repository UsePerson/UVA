#include<bits/stdc++.h>
using namespace std;
#define MAX 10000+5
struct Node{

    int to;
    long long e;
};
vector<Node> G[MAX];
vector<bool> visit(MAX, false);
int dis[MAX];
int cnt[MAX];
int n;
void init(){

    for(int i = 0; i < n ; i ++ ){

        G[i].clear();
        dis[i] = 1e9;
        cnt[i] = n;
        visit[i] = false;
    }
}
bool spfa(int start){

    queue<int> q;

    visit[start] = true;
    dis[start] = 0;
    q.push(start);

    while(!q.empty()){

        int now = q.front();
        q.pop();
        visit[now] = false;
        for(auto next : G[now]){

            if( dis[next.to] > (dis[now] + next.e) ){

                dis[next.to] = dis[now] + next.e;
                if( !visit[next.to] ){

                    cnt[next.to]--;
                    if(cnt[next.to] < 0){
                        return false;
                    }
                    visit[next.to] = true;
                    q.push(next.to);
                }             
            }
        }
    }
    return true;
}
int main(){

    int test;
    cin >> test;
    while(test--){

        int m;
        cin >> n >> m;
        init();
        for(int i = 0 ; i < m ; i ++ ){

            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(Node{b,c});
        }
        if(!spfa(0)){

            cout << "possible\n";
        }
        else{

            cout << "not possible\n" ;
        }
    }
}