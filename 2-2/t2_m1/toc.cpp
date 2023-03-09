#include<bits/stdc++.h>
using namespace std;


// function declarations
map<char,map<int,set<int>>> final_transition_table_nfa(map<char,vector<pair<char,int>>> transitions,map<char,set<char>> epsilon_closures);
map<char,set<char>> find_epsilon_closure(map<char,vector<pair<char,int>>> transitions);
void print_map(map<char,vector<pair<char,int>>> transitions);
void print_epsilon_map(map<char,set<char>> epsilon_closures);
void print_transition_table(map<char,map<int,set<int>>> transition_table);
map<string,map<int,string>> clearing_dups_in_dfa(map<string,map<int,string>> transition_table_dfa);
void print_dfa(map<string,map<int,string>> transition_table_dfa);
map<char,map<int,set<int>>> check_all_are_present(map<char,map<int,set<int>>> transition_table_nfa);
void E_NFA_TO_NFA(map<char,vector<pair<char,int>>> transitions);
void NFA_TO_DFA(map<char,map<int,set<int>>> transition_table_nfa);
set<char> total_states(map<char,vector<pair<char,int>>> transitions_e_nfa_to_nfa);
set<int> set_of_alphabets(map<char,vector<pair<char,int>>> transitions);
// '$' is used to represent the empty set

// all the global declarations
map<char,vector<pair<char,int>>> transitions_e_nfa_to_nfa;
map<char,set<char>> epsilon_closures;
map<char,map<int,set<int>>> transition_table_nfa;
map<string,map<int,string>> transition_table_dfa;
set<int> alphabets;
set<char> states;
// transitions contains the transitions of all states {A : {(A,1),(B,0),(B,5),(C,5)}, B : {(B,1),(C,5)}, C : {(C,1),(C,0)}}


// transition table contains the final transition table nfa{A : {0 : {B,C}, 1 : {A,B,C}}, B : ....like that
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

// epsilon closures contains the colusers of all states {A : {A,B,C}, B : {B,C}, C : {C}}
map<char,set<char>> find_epsilon_closure(map<char,vector<pair<char,int>>> transitions){
    map<char,set<char>> epsilon_states;
    stack<char> st;
    map<char,char> mask;
    for(auto state:transitions){
        for(auto transition:state.second){

            if(transition.second==5){
               st.push(transition.first);
               mask[state.first] = transition.first; 
            }
        }
        epsilon_states[state.first].insert(state.first);
        while(!st.empty()){
            char top = st.top();
            st.pop();
            epsilon_states[state.first].insert(top);
            for(auto transition:transitions[top]){
                if(transition.second==5){
                    if(mask[transition.first]!=top)
                    st.push(transition.first);
                }
            }
        }
    }
    
    for(auto it:states){
        epsilon_states[it].insert(it);
    }

    return epsilon_states;
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


// clearing all the duplicates in the transition table of dfa {A : {0 : {B,C}, 1 : {A,B,C}}, B : ....like that
map<string,map<int,string>> clearing_dups_in_dfa(map<string,map<int,string>> transition_table_dfa){
    for(auto it:transition_table_dfa){
        for(auto inner_map:it.second){
            string s = "";
            for(int i=0;i<inner_map.second.size();i++){
                if(s.find(inner_map.second[i])==string::npos){
                    s+=inner_map.second[i];
                }
            }
            transition_table_dfa[it.first][inner_map.first] = s;
        }
    }
    return transition_table_dfa;
}


// to check if all the alphabets are present in the transition table
map<char,map<int,set<int>>> check_all_are_present(map<char,map<int,set<int>>> transition_table_nfa){ 
    for(auto it:states){
        for(int alphabet:alphabets){
            if(transition_table_nfa[it][alphabet].size()==0){
                transition_table_nfa[it][alphabet].insert('$');
            }
        }
    }
    return transition_table_nfa;
}

void E_NFA_TO_NFA(map<char,vector<pair<char,int>>> transitions){
    print_map(transitions);

    epsilon_closures = find_epsilon_closure(transitions);

    print_epsilon_map(epsilon_closures);

    transition_table_nfa = final_transition_table_nfa(transitions,epsilon_closures);

    transition_table_nfa = check_all_are_present(transition_table_nfa);

    print_transition_table(transition_table_nfa);
}

void print_transition_table(map<char,map<int,set<int>>> transition_table){
    cout<<"transition table nfa:"<<endl;
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

void NFA_TO_DFA(map<char,map<int,set<int>>> transition_table_nfa){


    
    set<string> new_states;
    for(auto it:transition_table_nfa){

        for(auto inner_map:it.second){
            string s = "";
            for(auto inner_set:inner_map.second){
                if(inner_set!='$')
                s+=inner_set;
            }

            stringstream ss;
            ss<<it.first;
            string s2 = ss.str();

            transition_table_dfa[s2][inner_map.first] = s;
            new_states.insert(s);
        }
    }

    for(string new_state:new_states){
        for(int i=0;i<new_state.size();i++){
            set<char> states;
            for(auto inner_map:transition_table_nfa[new_state[i]]){
                for(auto inner_set:inner_map.second){
                    if(inner_set!='$')
                    states.insert(inner_set);
                }
                for(char state:states){
                    transition_table_dfa[new_state][inner_map.first]+=state;
                }
            }
        }
    }
    

    transition_table_dfa = clearing_dups_in_dfa(transition_table_dfa);


    //check if the null state is present in the transition table
    bool null_state_present = false;
    for(auto it:transition_table_dfa){
        for(auto it2:it.second){
            if(it2.second==""){
                null_state_present = true;
                break;
            }
        }
    }

    if(null_state_present){
        for(int alphabet:alphabets){
        transition_table_dfa["$"][alphabet] = "$";
    }
    }
    
    print_dfa(transition_table_dfa);

}

void print_dfa(map<string,map<int,string>> transition_table_dfa){
    cout<<"transition table dfa:"<<endl;
    for(auto it:transition_table_dfa){
        cout<<it.first<<"->";
        for(auto it2:it.second){
            cout<<it2.first<<"->";
            cout<<it2.second<<endl;
        }
        cout<<endl;
    }
}

set<char> total_states(map<char,vector<pair<char,int>>> transitions_e_nfa_to_nfa){
    set<char> total_states;
    for(auto it:transitions_e_nfa_to_nfa){
        total_states.insert(it.first);
    }
    return total_states;
}

// to find the alphabets in the transition table
set<int> set_of_alphabets(map<char,vector<pair<char,int>>> transitions){
    
    for(auto it:transitions){
        for(auto it2:it.second){
            if(it2.second!=5)
            alphabets.insert(it2.second);
        }
    }
    return alphabets;
}

// transitions for epsilon nfa to nfa
void print_map(map<char,vector<pair<char,int>>> transitions){
    for(auto it:transitions){
        cout<<it.first<<"->";
        for(auto it2:it.second){
            cout<<"("<<it2.first<<","<<it2.second<<")";
        }
        cout<<endl;
    }
}

int main(){
    /*int n;
    cout<<"Enter the number of states: ";
    cin>>n;*/

    //map<char,vector<pair<char,int>>> transitions;
    // input sysmbols 0 , 1
    // 5 for epsilon

    // sample transitions
    transitions_e_nfa_to_nfa['A'] = {{'B',5},{'C',1}};
    transitions_e_nfa_to_nfa['B'] = {{'C',1},{'C',5},{'C',0}};
    transitions_e_nfa_to_nfa['C'] = {{'E',0},{'E',5},{'D',1}};
    transitions_e_nfa_to_nfa['D'] = {{'C',0},{'A',5}};
    transitions_e_nfa_to_nfa['E'] = {{'E',0},{'E',1}};
    


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

    states = total_states(transitions_e_nfa_to_nfa);

    cout<<"states: "<<endl;
    for(char state:states){
        cout<<state<<" ";
    }

    alphabets = set_of_alphabets(transitions_e_nfa_to_nfa);

    cout<<endl<<"alphabets: "<<endl;
    for(int alphabet:alphabets){
        cout<<alphabet<<" ";
    }
    cout<<endl;

    E_NFA_TO_NFA(transitions_e_nfa_to_nfa);

    NFA_TO_DFA(transition_table_nfa);

}