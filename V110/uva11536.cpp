#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[1000000 + 5] = {-1,1,2,3};
    int t ;
    int cas = 1;
    cin >> t;

    while (t --){

        int n, m, k;
        cin >> n >> m >> k;
        
        for(int i = 4 ; i <= n ; i ++ ){

            arr[i] = (arr[i-3] + arr[i-2] + arr[i-1]) % m + 1;
        }
        int ans = 1e6 + 5;
        int seq = 0;
        int seq_cnt[k+5];
        fill(seq_cnt, seq_cnt+k+5, 0);
        for(int i = 1, j = 1 ; i <= n ; i ++){

            if(arr[i] > k)
                continue;
            
            if( ++seq_cnt[arr[i]] == 1 )
                seq ++;

            while( (seq == k) && (j <= i )){

                if( arr[j++] > k )
                    continue;

                ans = min(ans, i - j + 2);

                if( --seq_cnt[arr[j-1]] == 0)
                    seq --;

            }
        }
        if( ans > n ){

            cout << "Case " << cas++ << ": sequence nai\n"; 
        }
        else{

            cout << "Case " << cas++ << ": " << ans << '\n';
        }

    }
    

    
}