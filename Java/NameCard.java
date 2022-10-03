class NameCard {
    private String name;
    private String phoneNum;

    NameCard(String name, String phoneNum){
        this.name = name;
        this.phoneNum = phoneNum;
    }
    public boolean NameCompare(String name){
        return (this.name.equals(name) ? true : false );
    }
    public void ChangePhoneNum(String newNum){
        this.phoneNum = newNum;
    }
    public String toString(){
        return "Name : "+ name + "\t" + "PhoneNum : " +phoneNum ;
    }
}