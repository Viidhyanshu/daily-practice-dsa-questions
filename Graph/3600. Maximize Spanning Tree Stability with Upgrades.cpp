#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n,1);

        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int x,int y){
        int px=find(x);
        int py=find(y);

        if(px==py) return false;

        if(rankv[px] > rankv[py]){
            parent[py]=px;
        }
        else if(rankv[px] < rankv[py]){
            parent[px]=py;
        }
        else{
            parent[py]=px;
            rankv[px]++;
        }

        return true;
    }
};

class Solution {
public:

    bool check(int n, vector<vector<int>>& edges, int k, int mid){

        DSU dsu(n);
        vector<vector<int>> upgrades;

        for(auto &e : edges){

            int u=e[0];
            int v=e[1];
            int s=e[2];
            int m=e[3];

            if(m==1){

                if(s < mid) return false;

                dsu.unite(u,v);
            }
            else{

                if(s >= mid){
                    dsu.unite(u,v);
                }
                else if(2*s >= mid){
                    upgrades.push_back(e);
                }
            }
        }

        sort(upgrades.begin(), upgrades.end(),
             [](auto &a, auto &b){
                 return a[2] > b[2];
             });

        for(auto &e : upgrades){

            if(k==0) break;

            int u=e[0];
            int v=e[1];

            if(dsu.unite(u,v)){
                k--;
            }
        }

        int root=dsu.find(0);

        for(int i=1;i<n;i++){
            if(dsu.find(i)!=root) return false;
        }

        return true;
    }


    int maxStability(int n, vector<vector<int>>& edges, int k) {

        DSU dsu(n);

        for(auto &e : edges){
            if(e[3]==1){
                if(!dsu.unite(e[0], e[1])) return -1;
            }
        }

        int l=1;
        int r=200000;
        int ans=-1;

        while(l<=r){

            int mid=l+(r-l)/2;

            if(check(n,edges,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        return ans;
    }
};
