struct QNode { 
	int data; 
	QNode* next; 
	QNode(int d) 
	{ 
		data = d; 
		next = NULL; 
	} 
}; 

struct Queue { 
	QNode *front, *rear; 
	Queue() 
	{ 
		front = rear = NULL; 
	} 

	void enQueue(int x) 
	{ 

		QNode* temp = new QNode(x); 

		if (rear == NULL) { 
			front = rear = temp; 
			return; 
		} 

		rear->next = temp; 
		rear = temp; 
	} 

	void deQueue() 
	{ 
		 
		if (front == NULL) 
			return; 
	 
		QNode* temp = front; 
		front = front->next; 

		if (front == NULL) 
			rear = NULL; 

		delete (temp); 
	} 
}; 
