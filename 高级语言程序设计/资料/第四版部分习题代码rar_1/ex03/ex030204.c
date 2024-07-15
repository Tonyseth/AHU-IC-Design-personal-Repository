#include <stdio.h> 
void main (void)  
{ 
    char ch; 	

    printf ("Please input a letter:"); 
    scanf ("%c", &ch); 

    if( 'A' <= ch && ch <= 'Z') 
		ch += 'a' - 'A'; 
    else 
		if( 'a' <= ch && ch <= 'z') 
			ch += 'A' - 'a'; 

	printf ("%c\n", ch); 
}
