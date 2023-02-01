//Libreria del Modulo Recepcion
#include "Estructuras.h"





void registrarSocios(){
	system("cls");
	socios reg;
	FILE *arch;
	int b=0;
	arch=fopen("PruebaSocios.dat","a+b");
	
	printf("\n\n\t\t----------------------------%c REGISTRO DE SOCIOS %c----------------------------\n", 04, 04);
	do{
		printf("\n\n + Nombre y Apellido: "); _flushall();
		gets(reg.nomyape);
		
		printf("\n + Documento: ");
		scanf("%d",&reg.DNI);
		printf("\n + Direccion: "); _flushall(); gets(reg.direccion);
		
		printf("\n + Telefono: ");
		scanf("%d",&reg.tel);
		
		printf("\n + Peso: "); scanf("%d",&reg.peso);
		
		do{
		printf("\n + Numero de Socio: ");
		scanf("%d",&reg.numsocio);
		
		if(!(validarSocio(reg.numsocio))){
			printf("\n Este numero de socio ya esta ocupado, intente nuevamente. . .\n");
		}
		
		}while(!(validarSocio(reg.numsocio)));
		 
		/* INDICACIONES MEDICAS */
		
		printf("\n\n -------%c INDICACIONES MEDICAS &c-------\n ",04,04);
		
		printf("Si esta en condiciones de realizar la actividad ingrese [S]. De lo contrario ingrese [N]");
	    
	    do{
		
		printf("\n\nZumba: ");
		_flushall();
		scanf("%c",&reg.indMedicas.zum);
		if(!(validarCaracter(reg.indMedicas.zum))){
			printf("Caracter invalido, intente nuevamente . . .\n");
		}
	   }while(!(validarCaracter(reg.indMedicas.zum)));
	    
	    do{
		
		printf("\nSpining: ");
		_flushall();
		scanf("%c",&reg.indMedicas.spin);
		 if(!(validarCaracter(reg.indMedicas.spin))){
			printf("Caracter invalido, intente nuevamente . . .\n");
		 }
	    }while(!(validarCaracter(reg.indMedicas.spin)));
	    
	    do{
		
		printf("\nPilates: ");
		_flushall();
		scanf("%c",&reg.indMedicas.pil);
	      if(!(validarCaracter(reg.indMedicas.pil))){
	      	printf("Caracter invalido, intente nuevamente . . .\n");
		  }
		}while(!(validarCaracter(reg.indMedicas.pil)));
		
		/* ----------------------------------------------------------- */
		
		printf("\n\n -------%c FECHA DE INGRESO &c-------\n ",04,04);
		do{
			printf("Dia: ");scanf("%d",&reg.fec_ingreso.dia); 
			if(!(validarDia(reg.fec_ingreso.dia))){
				printf("\n Este Dia es invalido, intente nuevamente. . .\n");
			}
		}while(!(validarDia(reg.fec_ingreso.dia)));
	
		
		do{
		 printf("\nMes: ");scanf("%d",&reg.fec_ingreso.mes);
		  if(!(validarMes(reg.fec_ingreso.mes))){
			 printf("\n Este mes es invalido, intente nuevamente. . .\n");
			}
		}while (!(validarMes(reg.fec_ingreso.mes)));
	    
		
		printf("\nA%co: ",164);scanf("%d",&reg.fec_ingreso.anio);
		
		fwrite(&reg,sizeof(reg),1,arch);
		printf("Si desea ingresar un nuevo socio ingrese [0] de lo contrario ingrese [1]: ");
		scanf("%d",&b);
		
	}while(b==0);
}

void MenuRecepcion(){
	system("cls");
	int op;
	printf("\n\n\t\t--------------------------%c MENU DE RECEPCIONISTAS %c--------------------------\n", 04, 04);
   
    printf("\n\n\t\t[1].Registrar Socios.");
    printf("\n\n\t\t[2].Listar Socios.");
    printf("\n\n\t\t[3].Volver al Menu Principal.");
    
	printf("\n\n\t\t[Elija su opcion]:");
    scanf("%d",&op);
    
    switch(op){
 	case 1: registrarSocios();
 		break;
 	case 2: listarSocios();
 	    break;
 	case 3: MenuPrincipal();
 	    break;
 }
}

void SesionRecepcion(){
	system("cls");
	FILE *archivo;
	archivo = fopen("PruebaUsuarios.dat", "rb");
	user aux;
	
	char nick[20],contra[40];
	
	while(cod==1)
	{
		rewind(archivo);
		printf("\n\n\t\t---------------------%c INICIO DE SESION - RECEPCIONISTAS %c---------------------\n", 04, 04);
		_flushall();
		printf("\n %c Ingrese el nombre de usuario: ", 04); gets(nick);
		printf("\n %c Ingrese la contrase%ca: ", 04, 164); gets(contra);

		fread(&aux, sizeof(user), 1, archivo);
		while(!feof(archivo))
		{

			if(aux.tipo==2 and strcmp(aux.nick, nick)==0 and  strcmp(aux.pass, contra)==0)
			{
				fclose(archivo);
				printf("\n\n %c%c Presione una tecla para ingresar al sistema...", 33, 33); getchar(); system("CLS");
				MenuRecepcion();//Retorna 1 en caso de que haya coincidencia con la base de datos
			}
			else fread(&aux, sizeof(aux), 1, archivo);

		}

		printf("\n %c%c Nombre de usuario y/o contrase%ca INCORRECTOS\n\n", 33, 33, 164);
		printf("\n\n %c Ingrese 1 si quiere intentar nuevamente, o ingrese  0 para salir: ", 04); scanf("%d", &cod);
		system("CLS");

	 }
    

	fclose(archivo);
	
	
}