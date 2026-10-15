#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        map<char, int> m;
        int answer = -1;
        int cur = 0;
        for(int i = 0; i<s.length()-1; i++){
            if(s[i]==s[i+1]) {
                m[s[i]]++; cur++;
                answer = max({answer, m[s[i]]});
            }
        }
        answer = max(answer, (cur+1)/2);
        cout<<answer+1<<endl;
    }
}
