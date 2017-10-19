bool isEmpty() {
        if (front == -1)
                return false;
        return true;
}
bool isFull()
{
        if(rear - front + 1 == N)
                return true;
        return false;
}
void addFront(int item) 
{
        if (isFull())
                return;
        if (front == -1) {
                rear++;
                front++;
        } else if (front == 0) {
                shiftRight();
        } else {
                front--;
        }
        deque[front] = item;
}
void addRear(int item) 
{
        if (isFull())   
                return;
        if (rear == -1) {
                rear++;
                front++;
        } else if (rear == N - 1) {
                shiftLeft();
        } else {
                rear++;
        }
        deque[rear] = item;
}
int getFirst() {
        return deque[front];
}
int getLast() {
        return deque[rear];
}
void deleteFront() 
{
        if (isEmpty())
                return;
        if (front == rear) {
                front = -1;
                rear = -1;
        }
        /*        if (front != rear && front < N - 1) {
                front++;
        }
        else if (front == rear) {
                front = -1;
                rear = -1;
        }*/
        else 
                front++;
}
void deleteRear() 
{
        if (isEmpty())
                return;
        if (front == rear) {
                front = -1;
                rear = -1;
        }
        else
                rear--;
}
void shiftLeft()
{
        for (i = front; i <= rear; i++) {
                a[i - 1] = a[i];
        }
        front--;
        rear--;
}
void shiftRight()
{
        for (i = rear; i >= front; i--) {
                a[i + 1] = a[i];
        }
        front++;
        rear++;
}