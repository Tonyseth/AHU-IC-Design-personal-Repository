// Program: EG0602.c
////////////////////////////////////////////////////////////
// Function:    int Prime( int Num )
// Description: 编写函数Prime判断整数Num是否为素数。
// Input:       int Num：待判断整数
// Output:      Num是素数，函数返回1；Num不是素数，函数返回0
////////////////////////////////////////////////////////////
int Prime( int Num )
{
     int i, flag=1;

     for( i = 2; i < Num; i ++ )
          if( Num% i == 0 )
               flag = 0;

     return flag;
}

