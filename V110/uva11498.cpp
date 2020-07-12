#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int test;
    while(  scanf("%d",&test) && test ){

        int x,y;
        scanf("%d %d",&x,&y);
        for(int i= 0 ; i < test ; i ++){

            int a,b;
            scanf("%d %d",&a,&b);
            if( ( a == x ) || ( b == y ) ){

                puts("divisa");
            }
            else if( a > x ){
                
                ( b > y )? puts("NE") : puts("SE") ;
            }
            else{

                ( b > y )? puts("NO") : puts("SO") ;
            }
        }
    }
}
 
