#include<iostream>
using namespace std;
#define SIZE 20
int queue[SIZE];
int front=-1,rear=-1;
void enqueue(int value){
    if(rear==SIZE-1){
        cout<<"Queue is full\n";
        return;
    }
    if(front==-1) front=0;
    rear++;
    queue[rear]=value;
}
int dequeue(){
    if(front==-1||front>rear){
        cout<<"Queue is empty\n";
        return -1;
    }
    int val=queue[front];
    front++;
    return val;
}
void display(){
    if(front==-1||front>rear){
        cout<<"Queue is empty\n";
        return;
    }
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}
void interleaveQueue(int n){
    int half=n/2;
    int firstHalf[SIZE];
    int f1=0,r1=-1;
    for(int i=0;i<half;i++){
        int x=dequeue();
        r1++;
        firstHalf[r1]=x;
    }
    int newQueue[SIZE];
    int r2=-1;
    while(f1<=r1&&front!=-1&&front<=rear){
        r2++;
        newQueue[r2]=firstHalf[f1];
        f1++;
        r2++;
        newQueue[r2]=dequeue();
    }
    front=0;
    rear=-1;
    for(int i=0;i<=r2;i++){
        rear++;
        queue[rear]=newQueue[i];
    }
}
int main(){
    int n;
    cout<<"Enter even number of elements:";
    cin>>n;
    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        enqueue(x);
    }
    cout<<"\nOriginal Queue: ";
    display();
    interleaveQueue(n);
    cout<<"Interleaved Queue: ";
    display();
    return 0;
}
