#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  int n, i = 3, count, c;
  int a=0;

  printf("Escribe el numero k de primos:\n");
  scanf("%d", &n);
  int  array[n];
  
  if (n >= 1) {
    array[0]=2;
  }

  for (count = 2; count <= n;)
  {
    for (c = 2; c <= i - 1; c++)
    {
      if (i%c == 0)
        break;
    }
    if (c == i)
    {
       array[a+1] = i;
      count++;
      a++;
    }
    i++;
  }


	int x=0, z=0, b[100];
	i=0;
	int e=n;

	
for (z=0; z<n;z++){
    x=array[z];
	for(i=0;x>0;i++)    
	{    
	b[i]=x%2;    
	x=x/2;    
	}    
	printf("\n"); 
	 
int g=0;
	
	for(g=7;g>=0;g--)    // Si quieres 8 bits poner g=7 y si quieres 16 bits poner g=15
	{  
	if(b[g]==1){
	printf("%d",b[g]); }
	else {
		int e=0;
	printf("%i",e); 	
	}
	} 

}
  return 0;
}
