#include <iostream>
using namespace std;
#define SIZE 20
int queue[SIZE];
int front=-1,rear=-1;
void isEmpty(){
    if(front==-1)
        cout<<"Queue is empty\n";
    else
        cout<<"Queue is not empty\n";
}
void isFull(){
    if ((front==0&&rear==SIZE-1))
        cout<<"Queue is full\n";
    else
        cout<<"Queue is not full\n";
}
void enqueue(int value){
    if ((front==0&&rear==SIZE-1)){
        cout<<"Queue is full\n";
        return;
    }
    if(front==-1){ 
        front=rear=0;
    }else if(rear==SIZE-1&&front!=0){
        rear=0; 
    }else{
        rear++;
    }
    queue[rear]=value;
    cout<<value<<"inserted into queue\n";
}
void dequeue(){
    if(front == -1){
        cout<<"Queue is empty\n";
        return;
    }
    cout<<queue[front]<<"removed from queue\n";
    if(front==rear){
        front=rear=-1;
    }else if(front==SIZE-1){
        front=0;
    }else{
        front++;
    }
}
void peek(){
    if(front==-1){
        cout<<"Queue is empty\n";
    }else{
        cout<<"Front element:"<<queue[front]<<endl;
    }
}
void display(){
    if(front==-1){
        cout<<"Queue is empty\n";
        return;
    }
    cout<<"Queue elements:";
    if(rear>=front){
        for(int i=front;i<=rear;i++)
            cout<<queue[i]<<" ";
    }else{
        for(int i=front;i<SIZE;i++)
            cout<<queue[i]<<" ";
        for(int i=0;i<=rear;i++)
            cout<<queue[i]<< " ";
    }
    cout << endl;
}
int main() {
    int c, v;
    do{
        cout<<"1.Enqueue\n";
        cout<<"2.Dequeue\n";
        cout<<"3.Peek\n";
        cout<<"4.Display\n";
        cout<<"5.Check if Empty\n";
        cout<<"6.Check if Full\n";
        cout<<"7.Exit\n";
        cout<<"Enter your choice: ";
        cin>>c;

        switch(c){
            case 1:
                cout<<"Enter value to enqueue:";
                cin>>v;
                enqueue(v);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                isFull();
                break;
            case 7:
                cout<<"Exiting program\n";
                break;
            default:
                cout<<"Invalid choice\n";
        }
    } while (c!=7);
    return 0;
}
