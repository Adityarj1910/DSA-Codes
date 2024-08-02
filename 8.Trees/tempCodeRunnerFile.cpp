
// #include <iostream>
// using namespace std;

// struct node {
//     node *left;
//     int data;
//     node *right;
// };

// class cQueue {
//     int size;
//     int front;
//     int rear;
//     node **cQ;

// public:
//     cQueue(int size);
//     void enqueue(node *data);
//     node* dequeue();
//     int isEmpty();
//     int isFull();
// };

// cQueue::cQueue(int size) { // Creating the queue
//     front = rear = -1;
//     this->size = size;
//     cQ = new node*[size]; // Allocate memory using new
// }

// void cQueue::enqueue(node *data) { // Add element to the queue
//     if (isFull()) {
//         cout << "Circular overflow" << endl;
//     } else {
//         rear = (rear + 1) % size;
//         cQ[rear] = data;
//         if (front == -1) // If the queue was empty
//             front = 0;
//     }
// }

// node* cQueue::dequeue() { // Remove element from queue
//     node* x = NULL;
//     if (isEmpty()) {
//         cout << "Queue Underflow" << endl;
//     } else {
//         x = cQ[front];
//         if (front == rear) { // Queue becomes empty
//             front = rear = -1;
//         } else {
//             front = (front + 1) % size;
//         }
//     }
//     return x;
// }

// int cQueue::isEmpty() { // Checks if the queue is empty
//     return front == -1;
// }

// int cQueue::isFull() { // Checks if the queue is full
//     return (rear + 1) % size == front;
// }
