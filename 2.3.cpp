//2.C ×ÖÄ¸ÓÎÏ·
#include <bits/stdc++.h>
using namespace std;

vector<int> computenext(string &a) {
    int m = a.length();
    vector<int> nxt(m, 0);
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && a[i] != a[k]) k = nxt[k - 1];
        if (a[i] == a[k]) k++;
        nxt[i] = k;
    }
    return nxt;
}

int kmp(string &p, string &q, vector<int> &nxt) {
    int m = p.length(), n = q.length(), k = 0;
    for (int i = 0; i < m; i++) {
        if (k > 0 && p[i] != q[k]) k = nxt[k - 1];
        if (p[i] == q[k]) k++;
        if (k == n) return i - n + 1;
    }
    return -1;
}

int main() {
    string s;

    int len1;
    int len2;
    while(cin>>s){
        len1=0;
        len2=0;
        int len=s.length();
        for(int i=0;i<len;i++){
            string suffix=s.substr(i);
            vector<int> next=computenext(suffix);
            int pos=kmp(s,suffix,next);
            if(pos!=i){len1=len-i;break;}
        }
        vector<int> next=computenext(s);
        int t=0;
        if(next[len-1]>0){
            int f=next[len-1];
            if(f>0)t=next[f-1];
        }
        int len2=max(0,len-2*t);
        cout<<len1+len2<<endl;
    }
    return 0;
}