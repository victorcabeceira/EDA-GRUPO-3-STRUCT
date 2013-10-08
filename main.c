#include<stdio.h>
#include<stdlib.h>
#include "GeoLib.c"

#define tamanhoGride 20//tamanho teste

//Funcao do Menu de Op��es
int menu_opcoes(){
	int op;  //Variavel da op��o
	printf("\n                 Menu de Op\x87oes\n\n");

	printf("\n1 - Incluir Ponto\n");
    printf("\n2 - Excluir Ponto\n");
    printf("\n3 - Incluir Linha\n");
    printf("\n4 - Excluir Linha\n");
    printf("\n5 - Incluir Triangulo\n");
    printf("\n5 - Excluir Triangulo\n");
    printf("\n7 - Incluir Retangulo\n");
    printf("\n8 - Excluir Retangulo\n");
    printf("\n9 - Imprimir Gr�fico\n");
    printf("\n10 - Sair\n\n");
    printf("\n      Digite a sua escolha: ");
    scanf("%d",&op);
     if((op<1)||(op>7)){
     	printf("\n\n      Op\x87\xC6o n\xC6o existente\n\n");
     }
    return (op);
}//Fim da fun��o de Op��es

void imprimeGride (){//lembrando que esta fun��o somente ir� imprimir!
     int i,j;
     char gride[tamanhoGride][tamanhoGride];//gride teste
     
          for(i=0;i<tamanhoGride;i++){
          
            for(j=0;j<tamanhoGride;j++){
            if(i==0 && j==0){printf("0  ");}                            
            else if(i==0){
              if(j>9){printf("%d ",j);} //maior que 9 pois acima disso ser� 2 algorismos,quebrando a formata��o      
              else{printf(" %d ",j);}
            }
            else if(j==0){
             if(i>9){printf("%d",i);} //maior que 9 pois acima disso ser� 2 algorismos,quebrando a formata��o    
              else{printf("%d ",i);}
            }
            else{
            gride[i][j] =' ';//atribui��o teste
            printf("|%c ",gride[i][j]);
            }
            }
          printf("\n");                     
          }

}
//Funcao Main
main(){
	//Declara��o de Variaveis
	int opcao;
	//While para o menu
	while (opcao!=10){
		system("cls");
	    printf("\n================================Plotagem de Figuras=============================\n\n");
		opcao=menu_opcoes(); //Chama a fun��o menu_opcoes
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
              imprimeGride(); //Funcao para imprimir grade.
			  	break;
			  }
		  }//Fim do Switch
	 }//Fim do While

    printf("\nFim do Programa!\n\n");
    system("pause");
}
