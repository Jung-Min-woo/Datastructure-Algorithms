public class LList<E> implements List<E>{
    private Link<E> head;
    private Link<E> tail;
    private Link<E> curr;
    private int cnt;    //Size of List

    /** Constructor */
    LList(int size) { this();} //ignore Size
    LList() {
        curr = tail = head = new Link<E>(null);
        cnt = 0;
    }
    
    /** 
     * Remove all contents from the list, so it is once again empty.
     * Client is responsible for reclaiming storage used by the list elements.
     */
    public void clear(){
        //head.setNext(null); --> why it is needed??
        curr = tail = head = new Link<E>(null);
        cnt = 0;
    }

    /**
     * Insert an element at the current location.
     * The client must ensure that the list's capacity is not exceeded.
     * @param item the element to be inserted.
     */
    public void insert(E item){
        
    }

    /**
     * Append an element at the end of the list.
     * The client must ensure that the list's capacity is not exceeded.
     * @param item the element to be appended.
     */
    public void append(E item);

    /**
     * Remove and return the current element.
     * @return The element that was removed.
     */
    public E remove();

    /**
     * Set the current position to the start of the list.
     */
    public void moveToStart();

    /**
     * Set the current position to the end of the list.
     */
    public void moveToEnd();

    /** 
     * Move the current position one step left. 
     * No change if already at end.
     */
    public void prev();
    /** 
     * Move the current position one step right. 
     * No change if already at end.
     */
    public void next();

    /** @return The number of elements in the list. */
    public int length();
    /** @return The position of the current element. */
    public int currPos();
    /** Set current position
     * @param pos The position to make current.
     */
    public void moveToPos(int pos);
    /** @return The current element. */
    public E getValue();

}