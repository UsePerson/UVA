#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        for(auto c: s){

            printf("%c",(c-7));
        }
        puts("");
    }
}