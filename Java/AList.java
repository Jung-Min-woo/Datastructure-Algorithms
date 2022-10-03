class AList<E> implements List<E> {
    private static final int defaultSize = 10;
    private int maxSize;
    private int listSize;
    private int curr;
    private E[] listArray;

    /** Constructor */
    /** Create a list with the default capaacity  */
    AList() { 
        this(defaultSize);
    }
    /** Create a new list object.
     * @param size Max # of elements list can contain.
     */
    @SuppressWarnings("unchecked")
    AList(int size){
        maxSize = size;
        listSize = 0;
        listArray = (E[])new Object[size];        
    }
    public void clear()         //Reinitialize the list
    { listSize = curr = 0; }
    
    /** Insert "it" at current position */
    public void insert(E it){
        assert listSize < maxSize : "List capacity exceeded";
        for(int i=listSize ; i>curr ; i--){
            listArray[i] = listArray[i-1];
        }
        listArray[curr] = it;
        listSize++;
    }

    /** Insert "it" at pos */
    public void insert(int pos, E it){
        assert listSize < maxSize : "List capacity exceeded";
        assert pos>=0 && pos <= listSize : "Invalid pos input";
        for(int i = listSize ; i > pos ; i-- ){
            listArray[i] = listArray[i-1];
        }
        listArray[pos] = it;
        listSize++;
    }

    /** Append "it" to list */
    public void append(E it) {
        assert listSize < maxSize : "List capacity exceeded";
        listArray[listSize++] = it;
    }

    /** Remove and return the current element */
    public E remove() {
        if( curr<0 || curr>=listSize ) return null; //No current element
        E it = listArray[curr]; //copy the element
        for(int i = curr; i<listSize-1; i++)
            listArray[i] = listArray[i+1];
        listSize--;
        return it;
    }

    /** Remove at "pos" and return the current element */
    public E remove(int pos){
        if( pos <0 || pos>= listSize ) return null;
        E it = listArray[pos];
        for(int i=pos; i<listSize-1 ; i++){
            listArray[i] = listArray[i+1];
        }
        listSize--;
        return it;
    }

    public void moveToStart() {curr = 0;}
    public void moveToEnd() {curr = listSize;}
    public void moveToPos(int pos) {
        assert pos>=0 && pos<=listSize : "Pos out of range";
        curr = pos;
    }
    public void next() { if(curr<listSize) curr++;}
    public void prev() { if(curr!=0) curr--;}
    
    public int currPos() { return curr;}
    public int length() {return this.listSize;}
    public E getValue() { 
        assert curr>=0 && curr<=listSize : "No current element";
        return listArray[curr]; 
    }
}