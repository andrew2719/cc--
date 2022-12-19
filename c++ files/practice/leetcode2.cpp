
#include <bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
#define ft(it,a) for(auto it=a.begin();it!=a.end();it++)
#define F first
#define S second
#define IOS ios_base::sync_with_stdio(false)
#define ctie cin.tie(NULL)
using namespace std;
class Node {
public:
	int data;
	Node* link;
	Node(int n)
	{
		this->data = n;
		this->link = NULL;
	}
};
class Stack {
	Node* top;
    public:
        Stack() { top = NULL; }

        void push(int data)
        {

            Node* temp = new Node(data);
            if (!temp) {
                cout << "\nStack Overflow";
                exit(1);
            }
            temp->data = data;
            temp->link = top;
            top = temp;
        }
        bool isEmpty()
        {
            return top == NULL;
        }
        int peek()
        {
            if (!isEmpty())
                return top->data;
            else
                0;
        }
        void pop()
        {
            Node* temp;
            if (top == NULL) {
                cout << "\nStack Underflow" << endl;
                exit(1);
            }
            else {
                temp = top;
                top = top->link;
                free(temp);
            }
        }
        void reverse()
        {
            Node *prev,*curr,*nxt;
            prev = NULL;
            curr = top;
            nxt = top;
            while (nxt!=NULL)
            {
                nxt = curr->link;
                curr->link = prev;
                prev = curr;
                curr = nxt;
            }
            //head = prev;
        }
        void display()
        {
            Node* temp;
            if (top == NULL) {
                cout << "\nStack Underflow";
                exit(1);
            }
            else {
                //reverse();
                temp = top;
                while (temp != NULL) {
                    cout << temp->data;
                    temp = temp->link;
                    if (temp != NULL)
                        cout << " ";
                }
            }
        }
};
int main()
{
    IOS;ctie;
	Stack s;
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        //k++;
        int x;
        cin>>x;
        s.push(x);
        f(i,1,n)
        {
            cin>>x;
            while(k && x>s.peek() && s.peek())
            {
                s.pop();
                k--;
            }
            s.push(x);
        }
        if(k>0)
        {
            f(i,0,k)
            s.pop();
        }
        s.display();
        cout<<endl;
    }
}
