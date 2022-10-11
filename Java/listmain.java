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


        LList<String> list2 = new LList<>();
        list2.insert("test");
        list2.insert("sample");  
        list2.insert("test2");
        list2.insert("String");
        list2.append("asdf");
        list2.remove();
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