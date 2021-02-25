#include  <stdio.h>
#include  <string.h>

int main()
{
    
    char str[1000], str2[1000], str3[1000], str4[1000];
    int i=0, j=0 , a=0;
    
    
    printf("Ingrese el html:\n");
    gets(str);
    
    
    while(str[i] != '\0')
    {
        if(str[i] == '<'  )
        { 
           
        	while (str[i] != '>'){
			i++; }
			
            }
        
        str2[j++] = str[i];
        i++;
    }
    
    i=0;
    j=0;
     while(str2[i] != '\0')
    {
        if(str2[i] != '<' &&  str2[i] != '>')
        {
            str3[j++] = str2[i];
        }
        i++;
    }
    
    
    printf("\nEl html corregido es:\n%s", str3);
    return 0;
}

