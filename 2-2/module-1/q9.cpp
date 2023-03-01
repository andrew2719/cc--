#include<bits/stdc++.h>

using namespace std;


// function that calculates the distance of every coordinate to every other coordinate
// in the vector and returns the output vector that contains the indices of the vector
// that have distance == 1 (both the compared indeces)

vector<pair<int,int>> distance(vector<pair<int,int>> coordinates, int start, int end){
    vector<pair<int,int>> output;
    for(int i=start;i<=end;i++){
        for(int j=i+1;j<=end;j++){
            if(abs(coordinates[i].first - coordinates[j].first) == 1 && abs(coordinates[i].second - coordinates[j].second) == 0){
                output.push_back(make_pair(i,j));
            }
            else if(abs(coordinates[i].first - coordinates[j].first) == 0 && abs(coordinates[i].second - coordinates[j].second) == 1){
                output.push_back(make_pair(i,j));
            }
        }
    }
    return output;
}



int main(){
    int n;
    //cin>>n;

    vector<pair<int,int>> coordinates = {{0, 0}, 
                                        {0,1},
                                        {1,1}};

    /*for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        coordinates.push_back(make_pair(x,y));
    }*/

    vector<pair<int,int>> output = distance(coordinates, 0, coordinates.size()-1);

    for(int i=0;i<output.size();i++){
        cout<<output[i].first<<" "<<output[i].second<<endl;
    }

    
}