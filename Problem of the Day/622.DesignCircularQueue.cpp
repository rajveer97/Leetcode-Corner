class MyCircularQueue {
public:
    
    
    int front = 0, rear = 0;
    int size=0, arrSize=0; 
    vector<int> arr;
    
    MyCircularQueue(int k) {
        arrSize = k;
        arr.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        if(isEmpty())
        {
            rear = front = 0;
            arr[rear] = value;
            size++;
            return true;
        }
        
        rear++;
        rear %= arrSize;
        arr[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        
        front = (front+1) % arrSize;
        
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return arrSize == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */