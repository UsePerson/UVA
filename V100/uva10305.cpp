#include<bits/stdc++.h>
using namespace std;
#define MAX 101 + 5
vector<int> vec[MAX];
bool visit[MAX];
stack<int> s;
void init(int n){

    fill(visit, visit+n+5, false);
    for(int i = 1 ;i <= n ; i ++ ){

        vec[i].clear();
    }
}
void dfs(int n){

    visit[n] = true;
    for(auto j : vec[n]){

        if(!visit[j]){

            dfs(j);                
        }
    }
    s.push(n);
}
int main(){

    int n, m;
    while( (cin >> n >> m) && (n || m) ){

        init(n);
        for(int i = 0 ; i < m ; i ++  ){

            int x, y;
            cin >> x >> y;
            vec[x].push_back(y);
        }
        
        for(int i = 1; i <= n ; i ++ )
            if(!visit[i])
                dfs(i);
        
        while(!s.empty()){

            if(s.size()!=1)
                cout << s.top() << " ";
            else    
                cout << s.top();
            s.pop();
        }
        cout << endl;

    }
}