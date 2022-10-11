public class LList<E> implements List<E>{
    private Link<E> head;
    private Link<E> tail;
    private Link<E> curr;
    private int cnt;    //Size of List

    /** Constructor */
    LList(int size) { this();} //ignore Size
    LList() {
        curr = tail = head = new Link<E>(null); //Create Header
        cnt = 0;
    }
    
    /** 
     * Remove all contents from the list, so it is once again empty.
     * Client is responsible for reclaiming storage used by the list elements.
     */
    public void clear(){
        //head.setNext(null); --> why is it needed??
        curr = tail = head = new Link<E>(null);
        cnt = 0;
    }

    /**
     * Insert an element at the current location.
     * The client must ensure that the list's capacity is not exceeded.
     * @param item the element to be inserted.
     */
    public void insert(E item){
        curr.setNext(new Link<E>(item, curr.next()));
        if(tail == curr) tail = curr.next();
        cnt++;
    }

    /**
     * Append an element at the end of the list.
     * The client must ensure that the list's capacity is not exceeded.
     * @param item the element to be appended.
     */
    public void append(E item){
        tail = tail.setNext(new Link<E>(item, null));
        cnt++;
    }

    /**
     * Remove and return the current element.
     * @return The element that was removed.
     */
    public E remove(){
        if (curr.next() == null) return null;
        E item = curr.next().getelement();
        curr.setNext(curr.next().next());
        cnt--;
        return item;
    }
    /**
     * Set the current position to the start of the list.
     */
    public void moveToStart(){
        curr = head;
    }

    /**
     * Set the current position to the end of the list.
     */
    public void moveToEnd(){
        curr = tail;
    }
    /** 
     * Move the current position one step left. 
     * No change if already at end.
     */
    public void prev(){
        if (curr == head) return;
        Link<E> temp = head;
        while( temp.next() != curr ){
            temp = temp.next();
        } 
        curr = temp;
    }
    /** 
     * Move the current position one step right. 
     * No change if already at end.
     */
    public void next(){
        curr.next();
    }
    /** @return The number of elements in the list. */
    public int length(){
        return cnt;
    }
    /** @return The position of the current element. */
    public int currPos(){
        Link<E> temp = head;
        int i = 0;
        while(temp == curr){
            temp = temp.next();
            i++;
        }
        return i;
    }
    /** Set current position
     * head = 0, Data starts from at 1
     * @param pos The position to make current.
     */
    public void moveToPos(int pos){
        Link<E> temp = head;
        for(int i = 0 ; i< pos ; i++ )
            temp = temp.next();
        curr = temp;
    }
    /** @return The current element. */
    public E getValue(){
        if(curr.next() == null) return null;
        return curr.next().getelement();
    }
}