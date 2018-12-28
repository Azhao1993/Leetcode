package Leetcode_622_DesignCircularQueue;

public class MyCircularQueueTest {
	
	public static void main(String[] args) {
		MyCircularQueue circularQueue= new MyCircularQueue(30);
		String[] intput = {"enQueue","isFull","enQueue","enQueue","isFull","enQueue","enQueue","enQueue","Front","Front","Rear","enQueue","Rear","enQueue","Rear","Front","enQueue","enQueue","Front","enQueue","enQueue","Rear","enQueue","isEmpty","Rear","Front","Rear","enQueue","Front","enQueue","Rear","isEmpty","Rear","enQueue","Front","Front","deQueue","enQueue","Front","enQueue","enQueue","deQueue","enQueue","isFull","Front","enQueue","deQueue","enQueue","isEmpty","isEmpty","enQueue","Front","Front","Rear","deQueue","Front","enQueue","Rear","enQueue","Rear","Rear","Front","deQueue","enQueue","deQueue","Rear","enQueue","Front","enQueue","enQueue","deQueue","enQueue","Front","enQueue","deQueue","enQueue","Front","Front","enQueue","enQueue","enQueue","Front","enQueue","enQueue","Rear","deQueue","enQueue","Front","enQueue","enQueue","Rear","enQueue","enQueue","Rear","isFull","enQueue","Rear","enQueue","deQueue","Rear","enQueue"};
		int[] value = {71,0,32,1,0,32,8,6,0,0,0,8,0,3,0,0,56,41,0,14,6,0,25,0,0,0,0,44,0,84,0,0,0,59,0,0,0,4,0,40,11,0,94,0,0,72,0,19,0,0,20,0,0,0,0,0,58,0,54,0,0,0,0,65,0,0,59,0,26,10,0,14,0,2,0,37,0,0,46,63,42,0,84,30,0,0,49,0,79,46,0,97,83,0,0,76,0,79,0,0,44};
		for(int i = 0;i<intput.length;i++) {
			if(intput[i].equals("enQueue")) {
				System.out.println("²åÈë"+value[i]);
				circularQueue.enQueue(value[i]);
			}else if(intput[i].equals("deQueue")) {
				System.out.println("É¾³ý");
				circularQueue.deQueue();
			}else if(intput[i].equals("isFull")) {
				System.out.print("Âú£¿£º");
				System.out.println(circularQueue.isFull());
			}else if(intput[i].equals("Front")) {
				System.out.print("Í·£º");
				System.out.println(circularQueue.Front());
			}else if(intput[i].equals("Rear")) {
				System.out.print("Î²£º");
				System.out.println(circularQueue.Rear());
			}else if(intput[i].equals("isEmpty")) {
				System.out.print("¿Õ£¿£º");
				System.out.println(circularQueue.isEmpty());
			}
		}
	}


}
