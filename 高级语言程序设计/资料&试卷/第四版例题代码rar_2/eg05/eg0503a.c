// Program: EG0503.c 					    
// Description: ����ָ�뽫ָ�������������ݼ������ 
#include <stdio.h> 
void main( void )               	
{
     int Num1=28, Num2=36, Num3=72, *tmp; 
     int *Ptr1, *Ptr2, *Ptr3;

     Ptr1 = &Num1; Ptr2 = &Num2; Ptr3 = &Num3;
     printf("����ǰ��Num1=%d, Num2=%d, Num3=%d\n", Num1, Num2, Num3);
     if( *Ptr1 < *Ptr2 )
          tmp = Ptr1, Ptr1 = Ptr2, Ptr2 = tmp;
     if( *Ptr1 < *Ptr3 )
          tmp = Ptr1, Ptr1 = Ptr3, Ptr3 = tmp;
      if( *Ptr2 < *Ptr3 )
          tmp = Ptr2, Ptr2 = Ptr3, Ptr3 = tmp;

     printf("�����*Ptr1=%d, *Ptr2=%d, *Ptr3=%d\n", *Ptr1, *Ptr2, *Ptr3);
     printf("�����Num1=%d, Num2=%d, Num3=%d\n", Num1, Num2, Num3);  
}


