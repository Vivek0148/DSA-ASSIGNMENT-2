#include<iostream>
using namespace std;
#define SIZE 50
int q1[SIZE],q2[SIZE];
int f1=-1,r1=-1,f2=-1,r2=-1;
void enqueue1(int x){
    if(r1==SIZE-1){
        return;
    }
    if(f1==-1){
        f1=0;
    }
    r1++;
    q1[r1]=x;
}
int dequeue1(){
    if(f1==-1||f1>r1){
        return -1;
    }
    int val=q1[f1];
    f1++;
    return val;
}
void enqueue2(int x){
    if(r2==SIZE-1){
        return;
    }
    if(f2==-1){
        f2=0;
    }
    r2++;
    q2[r2]=x;
}
int dequeue2(){
    if(f2==-1||f2>r2){
        return -1;
    }
    int val=q2[f2];
    f2++;
    return val;
}
void push(int x){
    enqueue2(x);
    while(f1!=-1&&f1<=r1){
        enqueue2(dequeue1());
    }
    f1=f2;
    r1=r2;
    f2=-1;
    r2=-1;
    for(int i=f1;i<=r1;i++){
        q1[i]=q2[i];
    }
}
int pop(){
    if(f1==-1||f1>r1){
        return -1;
    }
    return dequeue1();
}
void display(){
    if(f1==-1||f1>r1){
        cout<<"Empty\n";
        return;
    }
    for(int i=f1;i<=r1;i++){
        cout<<q1[i]<<" ";
    }
    cout<<endl;
}
int main(){
    push(10);
    push(20);
    push(30);
    display();
    cout<<"Popped:"<<pop()<<endl;
    display();
    return 0;
}
