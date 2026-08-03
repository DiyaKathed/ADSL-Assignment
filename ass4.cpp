#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int KPerson(vector<int>& S,vector<int>& E,int k){
    vector<pair<int,int>> shops;
    for(int i=0;i<S.size();i++){
        shops.push_back({S[i],E[i]});
    }
    sort(shops.begin(),shops.end(),[](pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    });
    vector<int> freeAt(k,0);
    int count=0;

    for(int j = 0; j < shops.size(); j++){
        int best = -1;//person index who can visit the shop
        for(int i=0;i<k;i++){
            if(freeAt[i]<=shops[j].first){
                if(best==-1|| freeAt[i]>freeAt[best]) best=i;
            }
        }
        if(best != -1){
            freeAt[best] = shops[j].second;
            count++;
        }
    }
    return count;
}
int main(){
    int n,k;
    cout<<"enter number of shops and number of persons";
    cin>>n>>k;
    vector<int> S(n),E(n);
    cout<<"Enter start and end time of shops";
    for(int i=0;i<n;i++){
        cin>>S[i]>>E[i];
    }  
    cout << "Maximum shops visited = " << KPerson(S,E,k);
    return 0;
}