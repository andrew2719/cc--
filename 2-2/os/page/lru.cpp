// LRU algorithm

#include<bits/stdc++.h>
using namespace std;

int main(){
    int no_frames;
    cin>>no_frames;

    vector<int> frames;

    vector<int> recently_came;

    char page_string;
    vector<int> page_no;
    int hits=0;
    // take input until EOF
    while(cin>>page_string){
        if(page_string=='X'){
            break;
        }
        page_no.push_back(page_string-'0');
        
    }
    for(int i=0;i<page_no.size();i++){
        if(frames.size()==0){
            frames.push_back(page_no[i]);
            recently_came.push_back(page_no[i]);
        }
        else{
            if(find(frames.begin(),frames.end(),page_no[i])!=frames.end()){ // conditon when page is already in the frames(hits)
                hits++;
                recently_came.erase(find(recently_came.begin(),recently_came.end(),page_no[i]));
                recently_came.push_back(page_no[i]);

            }
            else{
                if(frames.size()<no_frames){
                    frames.push_back(page_no[i]);
                    recently_came.push_back(page_no[i]);
                }
                else{
                    // here the replacing is done by the least recently used page
                    int index = distance(frames.begin(),find(frames.begin(),frames.end(),recently_came[0]));
                    frames[index] = page_no[i];
                    recently_came.erase(recently_came.begin());
                    recently_came.push_back(page_no[i]);
                }
            }
        }

        // print the frames and recently_came every time
        cout<<"frames:";
        for(int x:frames){
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<"recently_came:";
        for(int x:recently_came){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}