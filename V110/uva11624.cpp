#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_SIZE = 1000 + 5;
const int way[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int row, col;
int maze[MAX_SIZE][MAX_SIZE], vis[MAX_SIZE][MAX_SIZE];

struct Node{

    int x;
    int y;
    int time;
};

void fire_BFS(Node f){

    queue<Node> q;
    q.push(f);

    while(!q.empty()){
        
        Node willSpread = q.front();
        q.pop();
        for(int r = 0; r < 4 ; r ++ ){

            int R = willSpread.x + way[r][0];
            int C = willSpread.y + way[r][1];
            int T = willSpread.time + 1;
            if( ( R >= 0 ) && (C >= 0) && (R < row) && (C < col) && (T < maze[R][C]) ){

                q.push({R,C,T});
                maze[R][C] = T;
            }
        }
        
    }
}
void joe_BFS(Node j){

    memset(vis, 1 ,sizeof(vis));
    queue<Node> q;
    q.push(j);
    vis[j.x][j.y] = 0;
    while(!q.empty()){

        Node now = q.front();
        q.pop();
        if( (now.x == row - 1) || (now.y == col - 1) || (now.x == 0) || (now.y == 0) ){
                    
            printf("%d\n",(now.time+1));
            return;
        }

        for(int r = 0 ; r < 4 ; r ++ ){

            int R = now.x + way[r][0];
            int C = now.y + way[r][1];
            int T = now.time + 1;
            if( ( R >= 0 ) && (C >= 0) && (R < row) && (C < col) && (T < maze[R][C]) && (vis[R][C]) ){

                vis[R][C] = 0;
                q.push({R,C,T});
            }
        }
    }
    printf("IMPOSSIBLE\n");
}
int main(){

    int test; 
    cin >> test;
    while(test --){

        bool isFindFire = false;
        Node joe;
        vector<Node> fire;
        cin >> row >> col;
        string s[row];
        for(int r = 0 ; r < row ; r ++){

            
            cin >> s[r];
            for(int c = 0 ; c < col ; c ++ ){

                if(s[r][c]=='#'){

                    maze[r][c] = -1;
                }
                else if(s[r][c]=='.'){

                    maze[r][c] = INF;
                }
                else if(s[r][c]=='F'){
                    
                    isFindFire = true;
                    fire.push_back({r,c,0});
                    maze[r][c] = 0;
                }
                else{

                    joe = {r,c,0};
                    maze[r][c] = INF;
                }
            }
        }
        if(isFindFire){

            for(Node f : fire){

                fire_BFS(f);  
            }
        }
        
        joe_BFS(joe);
    }
}