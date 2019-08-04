#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char*IN , char*o) ;


int main()
{
    //testing the encryption function
    char input_array[3001] ;
    char output_array[4001];
    while(1)
    {
    puts("Enter string:");
    gets(input_array);
    encrypt(input_array,output_array);

    printf("Input size=%d, output size =%d\n" , strlen(input_array) , strlen(output_array));
    puts("encrypted:");
    puts(output_array);
    puts("\n");
    }
    return 0;
}

void encrypt(char*IN , char*OUT)
{
    char i ,count ;
    unsigned int len = strlen(IN) ;

    while(1)
    {

            if (len>=3) count = 3 ;
            else count = len ;
            //shifting and setting bits
            if (count == 0) break ;
            OUT[0] =  IN[0] >>2 ;
            OUT[1] = (IN[0]&0x03)<<4 |IN[1]>>4;

            if (count > 1)  OUT[2] = (IN[1]&0x0F)<<2 |IN[2]>>6;     //skip if count <2

            if (count > 2)  OUT[3] = (IN[2]&0x3F)<<0 |IN[3]>>8;     //skip if count <3

            //replacing each value in base64 with the corresponding value in ascii
            for (i=0;i<count+1;i++)
            {
                if ((*(OUT+i) >= 0) && (*(OUT+i) <=25))  //capital letter
                    {
                        *(OUT+i) += 65 ;
                    }
                    else if ((*(OUT+i)>=26) && (*(OUT+i)<=51))// small letter
                    {
                        *(OUT+i)+=71 ;
                    }
                    else if ((*(OUT+i)>=52) && (*(OUT+i)<=61))
                    {
                        *(OUT+i)-=4 ;
                    }
                    else
                    {
                        switch(*(OUT+i))
                        {
                        case 62 : *(OUT+i) = 43;
                        case 63 : *(OUT+i) =  47;
                        }
                    }
            }
            if (count == 2 ) OUT[3] = '=' ;
            if (count == 1 ) OUT[2] = OUT[3] = '=' ;
            if (count < 3) break ;

            IN +=3;
            OUT+=4;
            len-=3;

    }
    //placing NULL terminator
    if (count==0) OUT[0] = 0 ;
    else OUT[4] = 0 ;

}
