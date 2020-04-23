#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        string x;
        cin>>x;
        int n = x.length();
        if(n%2==0)
            cout<<"MUTANT"<<endl;
        else if(n==1&&x[0]=='A')
            cout<<"SIMPLE"<<endl;
        else if(x[n-2]=='A'&&x[n-1]=='B')
            cout<<"FULLY-GROWN"<<endl;
        else if(x[0]=='B'&&x[n-1]=='A')
            cout<<"MUTAGENIC"<<endl;
        else
            cout<<"MUTANT"<<endl;

    }
}