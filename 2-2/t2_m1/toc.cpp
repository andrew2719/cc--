#include<bits/stdc++.h>
using namespace std;
// epsilon NFA to NFA


// epsilon closures contains the colusers of all states {A : {A,B,C}, B : {B,C}, C : {C}}
// transitions contains the transitions of all states {A : {(A,1),(B,0),(B,5),(C,5)}, B : {(B,1),(C,5)}, C : {(C,1),(C,0)}}
// transition table contains the final transition table {A : {0 : {A,B,C}, 1 : {A,B,C}}, B : {0 : {B,C}, 1 : {B,C}}, C : {0 : {C}, 1 : {C}}}


// all the global declarations
map<char,vector<pair<char,int>>> transitions_e_nfa_to_nfa;
map<char,set<char>> epsilon_closures;
map<char,map<int,set<int>>> transition_table_nfa;



map<char,map<int,set<int>>> final_transition_table_nfa(map<char,vector<pair<char,int>>> transitions,map<char,set<char>> epsilon_closures){
    map<char,map<int,set<int>>> transition_table;
    
    for(auto it:epsilon_closures){

        for(auto clousers:it.second){

            for(auto transition:transitions[clousers]){

                if(transition.second!=5){
                    for(auto epsilon_closure:epsilon_closures[transition.first]){
                        transition_table[it.first][transition.second].insert(epsilon_closure);
                    }
                }
            }
        }
    }
    
    return transition_table;
}


map<char,set<char>> find_epsilon_closure(map<char,vector<pair<char,int>>> transitions){
    map<char,set<char>> epsilon_states;
    stack<char> st;

    for(auto state:transitions){
        for(auto transition:state.second){

            if(transition.second==5){
               st.push(transition.first); 
            }
        }
        epsilon_states[state.first].insert(state.first);
        while(!st.empty()){
            char top = st.top();
            st.pop();
            epsilon_states[state.first].insert(top);
            for(auto transition:transitions[top]){
                if(transition.second==5){
                    st.push(transition.first);
                }
            }
        }
    }
    
    for(auto it:transitions){
        epsilon_states[it.first].insert(it.first);
    }

    return epsilon_states;
}


void print_map(map<char,vector<pair<char,int>>> transitions){
    for(auto it:transitions){
        cout<<it.first<<"->";
        for(auto it2:it.second){
            cout<<"("<<it2.first<<","<<it2.second<<")";
        }
        cout<<endl;
    }
}

void print_epsilon_map(map<char,set<char>> epsilon_closures){
    cout<<"epsilon closures:"<<endl;
    for(auto it:epsilon_closures){
        cout<<it.first<<"->";
        for(auto it2:it.second){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}

void print_transition_table(map<char,map<int,set<int>>> transition_table){
    cout<<"transition table:"<<endl;
    for(auto it:transition_table){
        cout<<it.first<<"->";
        for(auto it2:it.second){
            cout<<it2.first<<"->";
            for(char it3:it2.second){
                cout<<it3<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}


void E_NFA_TO_NFA(map<char,vector<pair<char,int>>> transitions){
    print_map(transitions);

    epsilon_closures = find_epsilon_closure(transitions);

    print_epsilon_map(epsilon_closures);

    transition_table_nfa = final_transition_table_nfa(transitions,epsilon_closures);

    print_transition_table(transition_table_nfa);
}


int main(){
    /*int n;
    cout<<"Enter the number of states: ";
    cin>>n;*/

    //map<char,vector<pair<char,int>>> transitions;
    // input sysmbols 0 , 1
    // 5 for epsilon

    // sample transitions
    transitions_e_nfa_to_nfa['A'] = {{'A',0},{'B',5}};
    transitions_e_nfa_to_nfa['B'] = {{'B',1},{'C',5}};
    transitions_e_nfa_to_nfa['C'] = {{'C',1},{'C',0}};


    // input transitions
    /*for(int i=0;i<n;i++){
        cout<<"enter state:";
        char state;
        cin>>state;
        cout<<"enter number of transitions:";
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            cout<<"enter transition "<<j+1<<":";
            char input;
            int output;
            cin>>input>>output;
            transitions[state].push_back({input,output});
        }
    }*/

    E_NFA_TO_NFA(transitions_e_nfa_to_nfa);


    
   
    
}