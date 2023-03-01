#include<bits/stdc++.h>

using namespace std;


void distance(vector<pair<int,int>> coordinates, vector<pair<int,int>> &output, int start, int end){
    if(start == end){
        return;
    }
    else if(start == end-1){
        if(abs(coordinates[start].first - coordinates[end].first) == 1 && abs(coordinates[start].second - coordinates[end].second) == 0){
            output.push_back(make_pair(start,end));
        }
        else if(abs(coordinates[start].first - coordinates[end].first) == 0 && abs(coordinates[start].second - coordinates[end].second) == 1){
            output.push_back(make_pair(start,end));
        }
        return;
    }
    else{
        int mid = (start+end)/2;
        distance(coordinates,output,start,mid);
        distance(coordinates,output,mid+1,end);
        int i = start;
        int j = mid+1;
        while(i<=mid && j<=end){
            if(coordinates[i].first < coordinates[j].first){
                i++;
            }
            else if(coordinates[i].first > coordinates[j].first){
                j++;
            }
            else{
                if(abs(coordinates[i].second - coordinates[j].second) == 1){
                    output.push_back(make_pair(i,j));
                }
                i++;
                j++;
            }
        }
    }
}





int main(){
    int n;
    //cin>>n;

    vector<pair<int,int>> coordinates = {{0, 0}, 
                                        {1, 0}, 
                                        {1,1},
                                        {1,2}};

    /*for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        coordinates.push_back(make_pair(x,y));
    }*/


    sort(coordinates.begin(),coordinates.end());

    vector<pair<int,int>> output;

    distance(coordinates,output,0,coordinates.size()-1);

    for(int i=0;i<output.size();i++){
        cout<<output[i].first<<" "<<output[i].second<<endl;
    }

    //output: 0 1 // 0 and 1 have distance 1 and also 1 2(indecies)
    //        1 2

}