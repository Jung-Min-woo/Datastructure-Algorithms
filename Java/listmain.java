public class listmain{
    public static void main(String[] args) {
        AList list1 = new AList<Number>();        
        list1.insert(new Integer(3));
        list1.append(new Integer(4));
        list1.append(new Long(1231234124));
        list1.append(new Double(123134.324));
        list1.insert(0, 300);
        list1.insert(0, 20023423413241L);

        printList(list1);                
        System.out.println("===================================================");
        list1.remove(1);
        list1.remove(3);
        printList(list1);


        AList<String> list2 = new AList<>();
        list2.insert(0, "test");
        list2.insert(0, "sample");  
        list2.insert(2, "test2");
        list2.insert(0,"String");
        list2.append("asdf");
        list2.remove(1);
        printList(list2);
    }



    public static void printList(List list){
        assert list != null : "<printList> NULL ERROR";
        list.moveToStart();
        while(list.currPos() <= list.length() -1 ){
            System.out.print(list.currPos() + "\t"+ list.getValue().getClass() + "\t\t");
            System.out.println(list.getValue() );
            list.next();
        }        
    }
}