#include<bits/stdc++.h>
using namespace std;

int actg[26];
int main(){
    
    int test;
    scanf("%d",&test);
    while(test -- ){

        int cas,l;
        cin >> cas >>l;
        char dna[ cas + 5 ][1000 + 5 ];
        for(int i = 0 ; i < cas ; i ++){
            
            scanf("%s",&dna[i]);
        }  
        int sum = 0;
        for(int j = 0 ; j < l ; j ++ ){

            memset(actg,0,sizeof(actg));
            for(int i = 0 ; i < cas ; i ++ ){

                actg[ dna[i][j] - 65 ]++;   
            }
            int max_num = actg[ 'T' - 65 ];
            char max_actg ='T' ;         
            if( max_num <= actg[ 'G' - 65 ]){

                max_num = actg[ 'G' - 65 ];
                max_actg = 'G';
            }
            if( max_num <= actg[ 'C' - 65 ]){

                max_num = actg[ 'C' - 65 ];
                max_actg = 'C';
            }
            if( max_num <= actg[ 0 ]){

                max_num = actg[ 'A' - 65 ];
                max_actg = 'A';
            }
            sum = sum + (cas - max_num);
            printf("%c",max_actg);
    
        }
        puts("");
        printf("%d\n",sum);  
    }
    return 0;
}