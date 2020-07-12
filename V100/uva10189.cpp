#include<bits/stdc++.h>
using namespace std;

int main(){

    int row,col;
    int cas = 0;
    while(scanf("%d %d",&row,&col) && row && col){

        char ch[row+5][col+5];
        int ans[row+5][col+5];
        memset(ans,0,sizeof(ans));
        getchar();
        for(int i = 0 ; i < row ; i++ ){

            for(int j  = 0 ; j < col ; j ++){

                scanf("%c" ,&ch[i][j]);
               
            }
            getchar();
        }
        
        if(cas){

            puts("");
        }

        for(int i = 0 ; i < row ; i++ ){

            for(int j  = 0 ; j < col ; j ++){

                if( ch[i][j] == '*'){

                    if( i + 1 < row){

                        if( j + 1 < col ){

                            ans[i+1][j+1]++;
                        }
                        if( j - 1 >= 0){

                             ans[i+1][j-1]++;
                        }
                        ans[i+1][j]++;
                    }
                    if( i - 1 >= 0){

                        if( j + 1 < col ){

                            ans[i-1][j+1]++;
                        }
                        if( j - 1 >= 0){

                             ans[i-1][j-1]++;
                        }
                        ans[i-1][j]++;
                    }
                    if( j + 1 < col){

                        ans[i][j+1]++;
                    }
                    if( j - 1 >= 0){

                        ans[i][j-1]++;
                    }
                }
                
            }
        }
        
        printf("Field #%d:\n",++cas);
        
        for(int i = 0 ; i < row ; i ++ ){

            for(int j = 0 ; j < col ; j ++){

                if(ch[i][j] == '*')printf("*");
                else{
                    printf("%d",ans[i][j]);
                }
            }
            puts("");
        }
        
    }
}