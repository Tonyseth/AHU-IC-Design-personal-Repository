// Program: EG0602.c
////////////////////////////////////////////////////////////
// Function:    int Prime( int Num )
// Description: ��д����Prime�ж�����Num�Ƿ�Ϊ������
// Input:       int Num�����ж�����
// Output:      Num����������������1��Num������������������0
////////////////////////////////////////////////////////////
int Prime( int Num )
{
     int i, flag=1;

     for( i = 2; i < Num; i ++ )
          if( Num% i == 0 )
               flag = 0;

     return flag;
}

