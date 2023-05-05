// fifo page replacement algorithm

#include<bits/stdc++.h>
using namespace std;

int main(){
    int no_frames;
    cin>>no_frames;

    vector<int> frames;

    queue<int> q;

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
        if(q.empty()){
            q.push(page_no[i]);
            frames.push_back(page_no[i]);
        }
        else{
            if(find(frames.begin(),frames.end(),page_no[i])==frames.end()){
                if(frames.size()<no_frames){
                    frames.push_back(page_no[i]);
                    q.push(page_no[i]);
                }
                else{
                    // find the index of the top of the queue in the frames using distance
                    int index = distance(frames.begin(),find(frames.begin(),frames.end(),q.front()));
                    frames[index] = page_no[i];
                    q.pop();
                    q.push(page_no[i]);

                }
            }
            else{
                hits++;
                continue;
            }
        }
        // print the frames every time
        for(int x:frames){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    cout<<hits<<endl;
    
    
}