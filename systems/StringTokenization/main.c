#include <stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>



int main()
{
      printf("Enter The String \n");
    
      int length = 100;

      char * name = malloc(length * sizeof(char));                            //malloc allotes a definite size initially for the string input 

      int count = 0;

      char c;



      while((c = getchar()) != '\n')
         {

            if(count >= length)

            name = realloc(name, (length += 10) * sizeof(char));              //realloc increases the size for the string input in case the initial 
                                                                               //alloted size is not enough
            name[count++] = c;

         }
      int len=strlen(name);

      printf("Enter Delimiters \n");

      char dem[256];                                                          
      
      scanf("%s",dem);                                                        //delimiter input is done here

      int len2=strlen(dem);

      char copy[len];

      strcpy(copy,name);                                                      //copying of input string into another character array 

      int flag=0;
      
      int d=0,b=0;                                                            // d and b indicate the row and coloumn for the array of strings. 
      
      char outp[50][100];

      for(int i=0;i<len;i++)                                                  //loop to iterate through the characters of input string
         {
            
            flag=0;
            
            for(int j=0;j<len2;j++)                                           //loop to check if any of the string character is a delimiter  
              {                                                               // each character is checked with all delimiters
                  if(copy[i]==dem[j]) 
                  {
                     flag=1;                                                   // flagged if true.
                  }
               }
         if(flag==0)                                                          //if the character doesn't match with any of the delimiters
            {                                                                 //the charcter is added to the same row until a delimiter is found
               outp[d][b]=copy[i];
           
               b++;
            }
               else
            {                                                                   //if a character is a delimiter. Terminate the ongoing row with NULL
               outp[d][b]='\0';                                                   
        
               d++;                                                             //increment to the next row 
        
               b=0;                                                             //resetting coloumn no. back to 1st coloumn.
            }                                                                   
                                                                               //above processes continue until the last charcter is checked
         }
         for(int i=0;i<=d;i++)
         {
               printf("%s \n",outp[i]);                                          //printing each part of the string without any delimiters
         }

}