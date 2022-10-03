/** Simple singly linked list node implementation */
class Link<E> {
    private E element;
    private Link<E> next;

    //Constructors
    Link(E it, Link<E> nextVal){
        element = it;
        next = nextVal;
    }
    Link(Link<E> nextVal){
        next = nextVal;
    }
    
    public Link<E> getnext() {return next;}
    public Link<E> setNext(Link<E> nextVal){
        return next = nextVal;
    }
    public E getelement() {return element;}
    public E setElement(E it) { return element = it;}
}