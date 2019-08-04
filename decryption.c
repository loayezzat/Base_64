#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt(char*IN , char*OUT) ;


int main()
{
    //testing the decryption function
    char input_array[4001] ;
    char output_array[3001];
    while(1)
    {
    puts("Enter string:");
    gets(input_array);
    decrypt(input_array,output_array);

    printf("Input size=%d, output size =%d\n" , strlen(input_array) , strlen(output_array));
    puts("decrypted:");
    puts(output_array);
    puts("\n");
    }
    return 0;
}

void decrypt(char*IN , char*OUT)
{   char *IN_temp ,*OUT_temp;
    unsigned int len = 0 ; // to count the no. of elements in input_array
    unsigned char i ; //iterator

    //decrypt the bytes
    IN_temp= IN ;
    while (*IN_temp!= '\0')
    {

        if ((*IN_temp >= 'A') && (*IN_temp <='Z'))  //capital letter
                    {
                        *IN_temp -= 65 ;
                    }
                    else if ((*IN_temp>='a') && (*IN_temp<='z'))// small letter
                    {
                        *IN_temp-=71 ;
                    }
                    else if ((*IN_temp>='0') && (*IN_temp<='9')) //digits
                    {
                        *IN_temp+=4 ;
                    }
                    else
                    {
                        switch(*IN_temp)
                        {
                        case 43 : *IN_temp = 62;
                        case 47 : *IN_temp = 63;
                        case '=':*IN_temp  = '\0';
                        }
                    }



        IN_temp++ ;
        len ++ ;
    }




    //Shifting the bits
    IN_temp= IN ;
    OUT_temp= OUT ;
    for (i = 0 ; i < len/4 + 1; i++ )
    {
       // 00_11 11_11 00_11 11_11 00_11 11_11 00_11 11_11

         OUT_temp[0] = (IN_temp[0] <<2) | ((IN_temp[1])>>4&0x03) ;
         OUT_temp[1] = (IN_temp[1] <<4) | ((IN_temp[2])>>2&0x0F) ;
         OUT_temp[2] = (IN_temp[2] <<6) | ((IN_temp[3])&0x3F) ;

         IN_temp +=4 ;
         OUT_temp +=3;
    }

    OUT_temp[len%4 ] = 0 ;

}
