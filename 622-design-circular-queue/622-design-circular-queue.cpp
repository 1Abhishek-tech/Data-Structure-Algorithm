class MyCircularQueue {
  private:
  vector<int> cq;
  int n, front = -1 , rear = -1;
public:
    MyCircularQueue(int k) {
      n = k;
      cq.resize(n);
    }
    
    bool enQueue(int value) {
      if( (front == 0 && rear == n-1) || front == rear + 1 ) return false; //when cq is full insert operation not possible
      if(front == -1) front = 0;
      rear = (rear + 1)%n;
      cq[rear] = value;
      return true;
    }
    
    bool deQueue() {
      if(front == -1) return false; //when cq is empty deque operation not possible
        if(front == rear) front = rear = -1; //only 1 element left
        else front = (front + 1)%n;
      return true;
    }
    
    int Front() {
      if(front == -1) return -1; //when cq is empty front pointing to -1
      return cq[front];
    }
    
    int Rear() {
      if(front == -1) return -1; //when cq is empty by checking front = -1, return rear pointing to -1
      return cq[rear];
    }
    
    bool isEmpty() {
      if(front == -1) return true;
      return false;
    }
    
    bool isFull() {
      if( (front == 0 && rear == n-1) || front == rear + 1 ) return true;
      return false;
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