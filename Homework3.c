#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


int main()
{
    
    char str[1000], str2[1000], str3[1000];
    int i=0, j=0;
     
    
    printf("Ingrese el texto:\n");
    gets(str);
    
     
     while(str[i] != '\0')
    {
        if(str[i] != '.')
        {
            str2[j++] = str[i];
        }
        i++;
    }
    //printf("%s\n", str2);
    i=0;
    j=0;
    int cont=0, cont2=1;
	while(str2[i] != '\0')
    {
    
    	if(str[i] == '(')
		{
		while (str[i] != ')') 
		{
			str3[j++] = str2[i];
			i++;
		}
		
		}
		
		else if(str[i] == '"')
		{     
			str3[j++] = str2[i];
			i++;
			//printf("%s\n", str3);
			while (str[i] != '"' ) 
			{
			str3[j++] = str2[i];
			i++;
			//printf("%s\n", str3);
			}
			str3[j++] = str2[i];
			i++;
		}
		
		
		else if(str2[i]=='0' || str2[i]=='1' || str2[i]=='2' || str2[i]=='3' || str2[i]=='4' || str2[i]=='5' || str2[i]=='6' || str2[i]=='7' || str2[i]=='8' || str2[i]=='9')
        {
        	cont++;
        	if(cont==1)
			{     str3[j++] = 'X';
		  	 } 
			 i++;   
        }
        
        else {
		str3[j++] = str2[i];
		cont=0;
		i++;
		}
        
        
    }
    
    printf("%s\n", str3);
    
	}
