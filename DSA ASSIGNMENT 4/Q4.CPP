#include<iostream>
using namespace std;
#define SIZE 100
char q[SIZE];
int front=-1,rear=-1;
int freq[256];

void enqueue(char c){
    if(rear==SIZE-1) return;
    if(front==-1) front=0;
    rear++;
    q[rear]=c;
}
char dequeue(){
    if(front==-1||front>rear) return '\0';
    char x=q[front];
    front++;
    return x;
}
void solve(string s){
    front=-1;rear=-1;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        freq[c]++;
        enqueue(c);
        while(front!=-1&&front<=rear&&freq[q[front]]>1){
            dequeue();
        }
        if(front==-1||front>rear) cout<<"-1 ";
        else cout<<q[front]<<" ";
    }
    cout<<endl;
}
int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    solve(s);
    return 0;
}
