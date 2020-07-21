#include<bits/stdc++.h>
using namespace std;

int sum = 0;
bool check[25 + 5][25 + 5];
void dfs( vector<int> vec[], int i, int len){

    if(sum < len)sum = len;
    for(int j : vec[i] ){
 
        if(check[ i ][ j ]){

            check[ i ][ j ] = 0;
            check[ j ][ i ] = 0;
            dfs( vec,j, len + 1 );
            check[ i ][ j ] = 1; 
            check[ j ][ i ] = 1;
        }
        
    }
}
int main(){
    
    int n,e;
    while( scanf("%d %d",&n,&e) && n && e ){

        vector<int> vec[25 + 5];
        memset(check, 0 , sizeof(check));
        for(int i = 0 ; i < e ; i ++ ){

            int a,b;
            scanf("%d %d",&a,&b);
            vec[a].push_back(b);
            vec[b].push_back(a);
            check[a][b] = 1;
            check[b][a] = 1;
        }

        sum = 0;
        for(int i = 0 ; i < n ; i ++){
            
            dfs(vec,i,0);  
        }
        
        printf("%d\n",sum);
    }
    return 0;
}