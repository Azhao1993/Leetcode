package Leetcode_622_DesignCircularQueue;
/*
	设计你的循环队列实现。 
	循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。
	它也被称为“环形缓冲器”。
	循环队列的一个好处是我们可以利用这个队列之前用过的空间。
	在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。
	但是使用循环队列，我们能使用这些空间去存储新的值。
	
	你的实现应该支持如下操作：	
		MyCircularQueue(k): 构造器，设置队列长度为 k 。
		Front: 从队首获取元素。如果队列为空，返回 -1 。
		Rear: 获取队尾元素。如果队列为空，返回 -1 。
		enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
		deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
		isEmpty(): 检查循环队列是否为空。
		isFull(): 检查循环队列是否已满。
	
	示例：	
		MyCircularQueue circularQueue = new MycircularQueue(3); // 设置长度为3		
		circularQueue.enQueue(1);  // 返回true		
		circularQueue.enQueue(2);  // 返回true		
		circularQueue.enQueue(3);  // 返回true		
		circularQueue.enQueue(4);  // 返回false,队列已满		
		circularQueue.Rear();  // 返回3		
		circularQueue.isFull();  // 返回true		
		circularQueue.deQueue();  // 返回true		
		circularQueue.enQueue(4);  // 返回true		
		circularQueue.Rear();  // 返回4	 
	
	提示：	
		所有的值都在 1 至 1000 的范围内；
		操作数将在 1 至 1000 的范围内；
		请不要使用内置的队列库。
 */
//622. 设计循环队列
public class DesignCircularQueue {	

	
	private int[] Queue;	
	//首指针
	int head = -1;
	//尾指针
	int tail = -1;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public DesignCircularQueue(int k) {
    	//构造器，设置队列长度为 k
    	Queue = new int[k];
    }    
   

	/** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        //enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
    	//满
    	if(isFull()) {
    		return false;
    	}
    	//不满
    	if((head==-1)&(tail==-1)) {
    		head++;
    		tail++;
    		Queue[head] = value;
    		return true;
    	}else if((head<=tail)&(tail<Queue.length-1)) {
    		tail++;
    		Queue[tail] = value;
    		return true;
    	}else if((head>0)&&(tail==Queue.length-1)) {
    		tail = 0;
    		Queue[tail] = value;
    		return true;
    	}else if((head>0)&&(tail<head-1)) {
    		tail++;
    		Queue[tail] = value;
    		return true;
    	}
    	return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        //deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
    	if(isEmpty()) {
    		return false;
    	}
    	if(head<tail) {
    		head++;
    		return true;
    	}else if(head==tail) {
    		head=-1;
    		tail=-1;
    		return true;
    	}else if((head>tail)&&(head==Queue.length-1)) {
    		head = 0;
    		return true;
    	}else if((head>tail)&&(head<Queue.length-1)) {
    		head++;
    		return true;
    	}
    	return true;
    }
    
    /** Get the front item from the queue. */
    public int Front() {
        //Front: 从队首获取元素。如果队列为空，返回 -1 。
    	if(head==-1) {
    		return -1;
    	}else {
    		return Queue[head];
    	}
    }
    
    /** Get the last item from the queue. */
    public int Rear() {
        //Rear: 获取队尾元素。如果队列为空，返回 -1 。
    	if(tail==-1) {
    		return -1;
    	}else {
    		return Queue[tail];
    	}
    }
    
    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        //isEmpty(): 检查循环队列是否为空。
    	if(head==-1) {
    		return true;
    	}
    	return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
    	//isFull(): 检查循环队列是否已满。
    	//首先判断是否full
    	if(((head==0)&(tail==Queue.length-1))||((head-tail==1))) {
    		return true;
    	}
    	return false;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */
