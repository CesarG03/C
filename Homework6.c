/*la funcion para eliminar a un usuario no finciona pero las otras dos de 
agregar usuario y ordenar todos los usuarios en orden alfabetico si funcionan */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size_of_array 3  
 
int main()
{
    char nom[20];
    int x, a=0;
    typedef char usuarios[100]; 
    usuarios usu[100]; 
    typedef char contrasena[100]; 
    contrasena contr[100]; 

    printf("Bienvenido!!!\n\n");
	printf("Ingrese usuario: ");
    scanf("%s",usu[0]);
    printf("Ingrese contraseña: ");
    scanf("%s",contr[0]);


while (x!=3){

    printf("\n");
	printf("Escoja uns Opcion: \n 1 - Agregar un usuario \n 2 - Eliminar un usuario \n 3 - Lista de Usuarios\n ");
	scanf("%d",&x);
	
		if (x==1){
			a=a+1;
			printf("\nIngrese usuario: ");
    		scanf("%s",usu[a]);
    		printf("Ingrese contraseña: ");
    		scanf("%s",contr[a]);
			
		}
		if (x==2){
			printf("\n");
			int k, t;
			printf("Que usuario desea eliminar: \n");
			for(t=0;t<a+1;t++){
    		printf("Usuario %d es %s \n", t, usu[t]);
			}
			scanf("%d",&k);

		}
	}
	
	char temp[25];
	int j=0;
	int i=0;
	 for(i=0;i<=a;i++)
      for(j=i+1;j<=a;j++){
         if(strcmp(usu[i],usu[j])>0){
            strcpy(temp,usu[i]);
            strcpy(usu[i],usu[j]);
            strcpy(usu[j],temp);
         }
      }
   	printf("\nLista de usuarios: \n");
   	int f=0;
   	for(f=0;f<=a;f++)
      puts(usu[f]);
	

	

  return 0;
}
