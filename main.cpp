#include<stdio.h>
#include<stdlib.h>
#include "GeoLib.h"

#define tamanhoGride 20//tamanho teste

//Funcao do Menu de Opções
int menu_opcoes(){
	int op;  //Variavel da opção
	printf("\n                 Menu de Op\x87oes\n\n");

	printf("\n1 - Incluir Ponto\n");
    printf("\n2 - Excluir Ponto\n");
    printf("\n3 - Incluir Linha\n");
    printf("\n4 - Excluir Linha\n");
    printf("\n5 - Incluir Triangulo\n");
    printf("\n5 - Excluir Triangulo\n");
    printf("\n7 - Incluir Retangulo\n");
    printf("\n8 - Excluir Retangulo\n");
    printf("\n9 - Imprimir Gráfico\n");
    printf("\n10 - Sair\n\n");
    printf("\n      Digite a sua escolha: ");
    scanf("%d",&op);
     if((op<1)||(op>10)){
     	printf("\n\n      Op\x87\xC6o n\xC6o existente\n\n");
     }
    return (op);
}//Fim da função de Opções


//Funcao Main
main(){
	//Declaração de Variaveis
	int opcao;
	//While para o menu
	 
	while (opcao!=10){
		system("cls");
	
	    printf("\n================================Plotagem de Figuras=============================\n\n");
		opcao=menu_opcoes(); //Chama a função menu_opcoes
	    system ("cls");
	       switch (opcao){
	       	  case 1:{
                
	       	  	 
	       	  	 break;
	       	  }
	       	  case 2:{
	       	  	 
	       	  	 break;
	       	  }
	       	  case 3:{
                 
	       	  	break;
	       	  }
			  case 4:{
			  
			  	break;
			  }
			  case 5:{
              
			  	break;
			  }
			  case 6:{
              
			  	break;
			  }
			  case 7:{
              
			  	break;
			  }
			  case 8:{
              
			  	break;
			  }
			  case 9:{
               //Funcao para imprimir grade.
			  	break;
			  }
		  }//Fim do Switch
	 }//Fim do While

    printf("\nFim do Programa!\n\n");
    system("pause");
}
