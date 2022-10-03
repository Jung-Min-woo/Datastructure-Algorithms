class listmain{
    public static void main(String[] args) {
        AList dd = new AList<Number>();        
        dd.insert(new Integer(3));
        dd.append(new Integer(4));
        dd.append(new Long(1231234124));
        dd.append(new Double(123134.324));

        dd.insert(0, 300);
        dd.insert(0, 20023423413241L);

        while(dd.currPos() <= dd.length() -1 ){
            System.out.print(dd.getValue().getClass() + "\t\t");
            System.out.println( dd.getValue() );
            dd.next();
        }

        System.out.println("===================================================");
//        dd.remove();

        while(dd.currPos() <= dd.length() -1 ){
            System.out.print(dd.getValue().getClass() + "\t\t");
            System.out.println( dd.getValue() );
            dd.next();
        }
    }
}