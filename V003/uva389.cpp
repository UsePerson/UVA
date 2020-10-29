#include<bits/stdc++.h>
using namespace std;
int main(){
    char display[7];
    int base1;
    int base2;
    char gar;
    while(~scanf("%7c %d %d",&display,&base1,&base2)){
        
        scanf("%c",&gar);
        int transfer = 0;
        int j = 0;
        for(int i = 6 ; i >= 0 ; i -- ){

            if(display[i] == ' ')break;
            if( display[i] >= 65 )
                transfer += ( display[i] - 55) * pow(base1,j);
            else
                transfer += ( display[i] - 48) * pow(base1,j);
            j++;
        }
        int ans[7];
        j = 6;
        bool error = false;
        memset(ans,0,sizeof(ans));
        while(transfer >= base2 ){

            ans[j--] = transfer % base2;
            transfer /= base2;
            if(j < 0 ){
                error = true;
                break;
            }
        }
        ans[j] = transfer;
        bool print = false;
        if(error)
            puts("  ERROR");
        else{
            
            for(int i = 0 ; i < 7 ; i ++ ){

                if(ans[i]!= 0) print = true;
                if( print ){

                    if(ans[i] > 9 ){
                        printf("%c",(ans[i]+55));
                    }
                    else{
                        printf("%d",ans[i]);
                    }
                }
                else{
                    
                    if(i != 6)
                        printf(" ");
                }
            }
            if(!print)
                puts("0");
            else
                puts("");
        }
    }
}

