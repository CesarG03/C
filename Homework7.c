/*Correr el programa en gdb online para evitar errores*/
/*Recuerda agregar usuarios antes de tomar asiastencia*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int x,a=0,i=0, contu=0,p,result;
	typedef char contrq[100]; 
    contrq q[100]; 
    typedef char usuarios[100]; 
    usuarios usu[100]; 
    typedef char contrasena[100]; 
    contrasena contr[100];
    typedef char horario_entrada[100]; 
    horario_entrada horario_de_entrada[100];
    typedef char horario_salida[100]; 
    horario_salida horario_de_salida[100];
    
	printf("Bienvenido al programa de horarios!!!\n");
	
	while (x!=5){

    
	printf("\nSelecciona la operacion deseada: \n1.Hora de Entrada \n2.Hora de Salida  \n3.Agregar empleado \n4.Reporte de horarios \n5.Salir del Programa\n");
	scanf("%d",&x);
	
		if (x==1){
		    printf("\nLista de usuarios\n");
			for(i=0;i+1<=contu;i++){
			
    		printf("Usuario %d es %s \n",i,usu[i]);
		}
		    printf("\nNumero de usuario: ");
    		scanf("%d",&p);
    		printf("Pin:");
    		scanf("%s",&q[0]);
            
            result= strcmp(&q[0], &contr[p]);
        
			if (result==0)
			{
    		printf("Escriba su hora de entrada Ej. 8:00 : ");
    		scanf("%s",&horario_de_entrada[p]);
			}
    		else 
    		printf("Contraseña Incorrecta");
		}
		if (x==2){
		    int k;
		    printf("\nLista de usuarios\n");
			for(k=0;k+1<=contu;k++){
			
    		printf("Usuario %d es %s \n",k,usu[k]);
		}
		    printf("\nNumero de usuario: ");
    		scanf("%d",&p);
    		printf("Pin:");
    		scanf("%s",&q[0]);
            
            result= strcmp(&q[0], &contr[p]);
            
			if (result==0)
			{
    		printf("Escriba su hora de salida Ej. 18:00 : ");
    		scanf("%s",&horario_de_salida[p]);
			}
    		else 
    		printf("Contraseña Incorrecta");

		}
		
		if (x==3){
		printf("\nNombre del nuevo empleado: ");
    		scanf("%s",usu[a]);
    		printf("Pin: ");
    		scanf("%s",contr[a]);
    		printf("\nEl empleado fue agragado exitosamente.\n");	
    		contu=contu+1;
    		a=a+1;
		}
		if (x==4){
			int g;
			printf("\nReporte de horarios\n");	 
			for(g=0;g+1<=contu;g++){
			
    		printf("Usuario %d es %s , con entrada: %s y salida: %s \n",g,usu[g], horario_de_entrada[g], horario_de_salida[g]);
		}
	
		}	
		
	}
	

	
	
	return 0;
	
	}

