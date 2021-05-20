#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

int main(){
	int cas,op;
	float largo_pared,ancho_pared,area_pared,litros_necesarios,precio_1Cpintura,cubetas_necesarias,precio_pintura;//case 1 y case2
	float largo_zona,ancho_zona,area_zona,largo_piso,ancho_piso,area_piso,pisos_nesesarios,paquetes_nesesarios,sacos_nesesarios,precio_1paquete,numero_pisos_por_paquete,precio_total_piso,adhesivo_necesario,precio_saco,precio_total_adhesivo,precio_total;//case2
	float grosor,volumen,concreto_nesesario,precio_concreto;//caso 4
	float total;//costo final
	
	op=1;
	while(op==1)
{
	system("cls");
	
	printf("Calculadora para proyrctos de construccion\n");
	printf("Calculo que quieras realizar: \n1.Pintar pared \n2.Poner piso \n3.Impermeabilizar techo \n4.Firme \n");
	scanf("%d",&cas);
	
	switch(cas)
	{
		case 1:
			printf("Obra: Pintar pared\n\n");
			
			printf("Cual es el largo de la pared en metros: ");
			scanf("%f",&largo_pared);
			printf("Cual es el ancho de la pared en metros: ");
			scanf("%f",&ancho_pared);
			area_pared=largo_pared*ancho_pared;
			printf("\nEl area de la pared es de %.2fm^2\n",area_pared);
			
			litros_necesarios=area_pared/5;
			printf("Los litros necesarios son %.2fL\n",litros_necesarios);
			
			printf("\nCual presentacion va a comprar:\n1.19L  \n2.4L \n3.1L\n");
		    printf("Nota: \nCompra la presentacion adecuada segun los litros que se ocuparan\n");
	        scanf("%d",&cas);
	        
			switch(cas)
			{
				case 1:
				printf("Cuanto costo la cubeta de pintura de la marca deseada: ");
			scanf("%f",&precio_1Cpintura);
			cubetas_necesarias=litros_necesarios/19;
			printf("Cubetas necesarias %.2f\n",ceil(cubetas_necesarias));
			precio_pintura=ceil(cubetas_necesarias)*precio_1Cpintura;
			printf("\nPrecio total de la pintura $%.2f",precio_pintura);
			total=total+precio_pintura;
			
				break;	
				case 2:
		        printf("Cuanto costo la cubeta de pintura de la marca deseada: ");
			scanf("%f",&precio_1Cpintura);
			cubetas_necesarias=litros_necesarios/4;
			printf("Cubetas necesarias %.2f\n",ceil(cubetas_necesarias));
			precio_pintura=ceil(cubetas_necesarias)*precio_1Cpintura;
			printf("\nPrecio total de la pintura $%.2f",precio_pintura);
			total=total+precio_pintura;
				break;	
				case 3:
				printf("Cuanto costo la cubeta de pintura de la marca deseada: ");
			scanf("%f",&precio_1Cpintura);
			cubetas_necesarias=litros_necesarios/1;
			printf("Cubetas necesarias %.2f\n",ceil(cubetas_necesarias));
			precio_pintura=ceil(cubetas_necesarias)*precio_1Cpintura;
			printf("\nPrecio total de la pintura $%.2f",precio_pintura);
			total=total+precio_pintura;
				break;	
			}
			
		break;
		
		
		case 2:
			printf("Obra: Poner piso\n\n");
			
			printf("Cual es el largo de la zona en metros: ");
			scanf("%f",&largo_zona);
			printf("Cual es el ancho de la zona en metros: ");
			scanf("%f",&ancho_zona);
			area_zona=largo_zona*ancho_zona;
			printf("El area de la zona es de %.2fm^2",area_zona);
			
			printf("\n\nCual es el largo del piso en centimetros: ");
			scanf("%f",&largo_piso);
			printf("Cual es el ancho del piso en centimetros: ");
			scanf("%f",&ancho_piso);
			area_piso=(largo_piso/100)*(ancho_piso/100);
			printf("El area del piso es de %.2fm^2",area_piso);
			
			pisos_nesesarios=area_zona/area_piso;
			printf("\n\nPisos necesarios: %.2f",ceil(pisos_nesesarios));
			adhesivo_necesario=area_zona/.2;
			printf("\nAdhesivo para piso necesarios: %.2fKg",ceil(adhesivo_necesario));
			
			printf("\n\nCuanto cuesta un paquete del piso elegido: ");
			scanf("%f",&precio_1paquete);
			printf("Cuantos pisos tiene el paquete: ");
			scanf("%f",&numero_pisos_por_paquete);
			paquetes_nesesarios=pisos_nesesarios/numero_pisos_por_paquete;
			printf("Paquetes de piso nesesarios: %.2f",ceil(paquetes_nesesarios));
			precio_total_piso=ceil(paquetes_nesesarios)*precio_1paquete;
			printf("\nPrecio total por el piso: $%.2f",precio_total_piso);

			printf("\n\nPrecio del saco(20kg) del adhesivo para piso de la marca deseada: ");
			scanf("%f",&precio_saco);
			sacos_nesesarios=adhesivo_necesario/20;
			printf("Sacos necesarios: %.2f",ceil(sacos_nesesarios));
			precio_total_adhesivo=ceil(sacos_nesesarios)*precio_saco;
			printf("\nPrecio total del adhesivo: $%.2f",precio_total_adhesivo);
			
			precio_total=precio_total_adhesivo+precio_total_piso;
			printf("\n\nPresio total de materiales: $%.2f",precio_total);
			total=total+precio_total;
		break;
		case 3:
			printf("Obra: Impermeabilizar techo\n\n");
			
			printf("Cual es el largo del techo en metros: ");
			scanf("%f",&largo_pared);
			printf("Cual es el ancho del techen metros: ");
			scanf("%f",&ancho_pared);
			area_pared=largo_pared*ancho_pared;
			printf("\nEl area del techo es de %.2fm^2\n",area_pared);
			
			litros_necesarios=area_pared;
			
			printf("Los litros necesarios son %.2fL\n",litros_necesarios);
			
			printf("\nCual presentacion va a comprar:\n1.19L  \n2.4L\n");
		    printf("Nota: \nCompra la presentacion adecuada segun los litros que se ocuparan\n");
	        scanf("%d",&cas);
	        
			switch(cas)
			{
				case 1:
				printf("Cuanto costo la cubeta de impermeabilizante: ");
			scanf("%f",&precio_1Cpintura);
			cubetas_necesarias=litros_necesarios/19;
			printf("Cubetas necesarias %.2f\n",ceil(cubetas_necesarias));
			precio_pintura=ceil(cubetas_necesarias)*precio_1Cpintura;
			printf("\nPrecio total del impermeabilizante $%.2f",precio_pintura);
			total=total+precio_pintura;
				break;	
				case 2:
		        printf("Cuanto costo la cubeta de impermeabilizante: ");
			scanf("%f",&precio_1Cpintura);
			cubetas_necesarias=litros_necesarios/4;
			printf("Cubetas necesarias %.2f\n",ceil(cubetas_necesarias));
			precio_pintura=ceil(cubetas_necesarias)*precio_1Cpintura;
			printf("\nPrecio total del impermeabilizante $%.2f",precio_pintura);
			total=total+precio_pintura;
			}
		break;
		case 4:
			printf("Obra: Firme\n\n");
			
			printf("Cual es el largo de la zona en metros: ");
			scanf("%f",&largo_zona);
			printf("Cual es el ancho de la zona en metros: ");
			scanf("%f",&ancho_zona);
			area_zona=largo_zona*ancho_zona;
			printf("El area de la zona es de %.2fm^2",area_zona);
			
			printf("\n\nCual va a ser el grosor de firme (Lo recomendable son 0.8cm): ");
			scanf("%f",&grosor);
			
			volumen=largo_zona*ancho_zona*grosor;
			printf("\nConcreto necesario sin perdidas por compactacion y desperdicio: %.2fm^3",ceil(volumen));
			concreto_nesesario=(ceil(volumen))+(ceil(volumen)*.25)+(ceil(volumen)*.10);
			printf("\nConcreto necesario: %.2fm^3",concreto_nesesario);
			
			printf("\n\nPrecio de concreto y todos sus aditivos por m^3 (El precio ronda entre 2000 y 3000 por m^3): ");
			scanf("%f",&precio_concreto);
			precio_total=concreto_nesesario*precio_concreto;
			printf("\nPrecio total del concreto con todos sus aditivos: $%.2f",precio_total);
			total=total+precio_total;
		break;		
	}
	
	printf("\n\nDeseas realizar otro calculo: \nSI=1 NO=2\n");
	scanf("%d",&op);
	}
	
	printf("\nSu total en compras es de: $%.2f",total);
	return 0;
}
