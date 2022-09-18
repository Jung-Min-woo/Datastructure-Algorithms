public class ListNode{
    private int data;
    private ListNode next;

    public ListNode(int data){
        this.data = data;
    }    
    public void setData(int data){
        this.data = data;
    }
    public int getData(){
        return data;
    }
    public void setNext(ListNode next){
        this.next = next;
    }
    public ListNode getNext(){
        return next;
    }

    static int ListLength(ListNode headNode){
        int length = 0;

        ListNode currentNode = headNode;
        while(currentNode!= null){
            length++;
            currentNode = currentNode.getNext();
        }
        return length;
    }

    //직전 position에 삽입
    static ListNode InsertInLinkedList (ListNode headNode, ListNode nodeToInsert, int position){
        if(headNode == null)
            return nodeToInsert; 
        int size = ListLength(headNode);
        if(position > size+1 || position < 1 ){
            System.out.println("Position of node to insert is invalid. The valid inputs are 1 to " + (size + 1));
            return headNode;
        }
        if (position == 1){
            nodeToInsert.setNext(headNode);
            return nodeToInsert;
        } else {
            ListNode previousNode = headNode;
            int count = 1;
            while(count < position - 1){
                previousNode = previousNode.getNext();
                count++;
            }
            ListNode currentNode = previousNode.getNext();
            nodeToInsert.setNext(currentNode);
            previousNode.setNext(currentNode);
        }
        return headNode;      
    }
}