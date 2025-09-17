#include <iostream>
using namespace std;
#define MAX 20
int queue[MAX];
int front=-1; 
int rear=-1;
void enqueue(int x){
    if(rear==MAX-1) {
        cout <<"Queue is FULL\n";
    }else{
        if(front==-1) {
            front=0;
        }
        rear++;
        queue[rear]=x;
        cout<<x<<"inserted into queue\n";
    }
}
void dequeue(){
    if(front==-1) {
        cout<<"Queue is EMPTY\n";
    }else{
        cout<<queue[front]<<"removed from queue\n";
        front++;
        if (front>rear) {
            front=rear=-1; 
        }
    }
}
void peek(){
    if (front==-1) {
        cout<<"Queue is EMPTY\n";
    }else{
        cout<<"Front element:"<<queue[front]<<endl;
    }
}
void display(){
    if(front==-1) {
        cout<<"Queue is EMPTY\n";
    }else{
        cout<<"Queue elements:";
        for(int i=front;i<=rear;i++) {
            cout<<queue[i]<< " ";
        }
        cout<<endl;
    }
}
void isEmpty() {
    if(front==-1)
        cout<<"Queue is EMPTY\n";
    else
        cout<<"Queue is NOT empty\n";
}
void isFull() {
    if (rear==MAX-1)
        cout<<"Queue is FULL\n";
    else
        cout<<"Queue is NOT full\n";
}
int main() {
    int c,v;
    do {
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Peek\n";
        cout<<"4. Display\n";
        cout<<"5. Check if Empty\n";
        cout<<"6. Check if Full\n";
        cout<<"7. Exit\n";
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
                cout << "Invalid choice! Try again.\n";
        }
    } while (c!=7);
    return 0;
}
