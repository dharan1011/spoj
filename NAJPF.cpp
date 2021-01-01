#include <bits/stdc++.h>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<int> get_lps(string &pattern){
    vector<int> pi(pattern.size(), 0);
    int j = 0;
    for(int i = 1; i < pattern.size();){
        if(pattern[i] == pattern[j]){
            pi[i++] = ++j;
        }else{
            if(j){
                j = pi[j-1];
            }else{
                pi[i] = 0;
                i++;
            }
        }
    }
    return pi;
}

void solve(string &text, string &pattern){
    vector<int> res;
    vector<int> lps = get_lps(pattern);
    int tl = text.size();
    int pl = pattern.size();
    int i = 0;
    int j = 0;
    while(i < tl && j < pl){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }else{
            if(j){
                j = lps[j-1];
            }else{
                i++;
            }
        }
        if(j == pl){
            res.push_back(i - j + 1);
            j = 0;
        }
    }
    if(res.size()){
        cout << res.size() << "\n";
        for(int x : res)
            cout << x << " ";
    }else{
        cout << "Not Found";
    }
    cout << "\n";
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        string text, pattern;
        cin >> text >> pattern;
        solve(text, pattern);
    }
}