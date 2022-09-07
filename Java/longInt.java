/*
 * Design whole ADT for unbounded longInt
 */
class longInt {
    
    public CONSTRUCTOR(String s);
    public AddlongInt(longInt inp);
    public SubtractlongInt(longInt inp);
    public MultiplelongInt(longInt inp); // 
    public printlongInt(longInt inp); // 5자리씩 4자리씩 끊어서 곱하고 앞에 여떫자리는 다음 곱셈에 더함.
    // piece 8@
       1    2   3     4    5    6    7    8
    0000 0000 0000 0000 0000 0000 0000 0000
                        1111 1111 1111 1110
       >> 마지막자리는 저장하고 기타는 임시보존

}
