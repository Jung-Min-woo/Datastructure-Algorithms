import java.util.Scanner;
public class ex03_02{
    public static void main(String[] args) {
        AList<NameCard> list1 = new AList<>();
        
        list1.append(new NameCard("Jung Minwoo", "010-1234-1234"));
        list1.append(new NameCard("Jung Jinwoo", "010-2345-2345"));
        list1.append(new NameCard("Park Jee Yeon", "012-131-123"));
        
        Scanner sc = new Scanner(System.in);
        String target;
        int mode;
        while(true){
            System.out.print("Find(1), Change PhoneNum(2), Remove(3), PrintAll(4) >> ");
            try{
                mode = Integer.parseInt(sc.nextLine());
            }catch(Exception e){continue;}
            switch(mode) {
                case 1:
                    System.out.print("[Search Mode] Type name >>");
                    target = sc.nextLine();
                    if(getNameCardinList(list1, target) != -1)
                        System.out.println(list1.getValue()); 
                    else continue;
                    break;

                case 2:
                    System.out.print("[Change PhoneNum] Type name >>");
                    target = sc.nextLine();
                    if(getNameCardinList(list1, target) != -1){
                        System.out.print("Type New PhoneNum >>");
                        list1.getValue().ChangePhoneNum(sc.nextLine());
                    }
                    else continue;
                    break;
                
                case 3:
                    System.out.print("[Remove] Type name >>");
                    target = sc.nextLine();
                    if(getNameCardinList(list1, target) != -1)
                        list1.remove();
                    else continue;
                    break;

                case 4:
                    listmain.printList(list1);    
                    break;
                default :
                    System.out.println("Invalid mode");
                    continue;
            }
        }
    }

    public static int getNameCardinList(List<NameCard> list, String target){
        for(list.moveToStart(); list.currPos()<list.length(); list.next()){
            if(list.getValue().NameCompare(target)){
                return list.currPos();
            }
        }
        return -1;
    }
}