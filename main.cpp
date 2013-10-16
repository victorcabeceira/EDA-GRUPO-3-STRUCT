#include<stdio.h>
    #include<stdlib.h>
    #include "GeoLib.h"

#define tamanhoGride 31//tamanho teste

//Funcao do Menu de Opções
int menu_opcoes(){
    int op;  //Variavel da opção
	
    printf("\n                 Menu de Op\x87oes\n\n");

    printf("\n1 - Incluir Ponto\n");
    printf("\n2 - Excluir Ponto\n");
    printf("\n3 - Incluir Linha\n");
    printf("\n4 - Excluir Linha\n");
    printf("\n5 - Incluir Triangulo\n");
    printf("\n6 - Excluir Triangulo\n");
    printf("\n7 - Incluir Retangulo\n");
    printf("\n8 - Excluir Retangulo\n");
    printf("\n9 - Sair\n\n");
    printf("\n      Digite a sua escolha: ");
    scanf("%d",&op);
    if((op<1)||(op>9)){
     	printf("\n\n      Op\x87\xC6o n\xC6o existente\n\n");
    }
    return (op);
}//Fim da função de Opções


//Funcao Main
main(){
    system("color f1");    
    //Declaração de Variaveis
    int opcao,cordenadas[4];
    char simbolo;   //Simbolo a ser inserido
    struct TVPontos pontos; //Essa Struct contem os pontos digitados
    struct Gride gride;      //Gride Com os pontos
    struct TVLinhas linhas;
    struct TVTriangulo triangulo;
    struct TVRetangulo retangulo;
    //While para o menu
    while (opcao!=9){
        system("cls");
        imprimeGride(&gride);  //Será mostrado o gride 
        printf("\n================================Plotagem de Figuras=============================\n\n");
        opcao=menu_opcoes(); //Chama a função menu_opcoes
        system ("cls");
        switch (opcao){
            case 1:{
                    if(pontos.Qtd >= 5 ){
                        printf("Quantidade excedida!\n");
                        system("pause");
                    }
                    else{
                        printf("Digite as cordenadas:\n");
                        printf("Coluna:\n");
                        scanf("%d",&pontos.elementos[pontos.Qtd].x);   //Coordenada x guardada
                        printf("Linha:\n");
                        scanf("%d",&pontos.elementos[pontos.Qtd].y);
                        fflush(stdin);
                        printf("Digite o tipo do ponto:\n");
                        scanf("%c",&simbolo);
                        PlotarPonto(&pontos,&gride,simbolo);
                        pontos.Qtd ++;
                    }            
	       	  	 
                    break;
                }
            case 2:{if (pontos.Qtd == 0) {
                        printf("Nao ha Nenhum ponto!!!");
                        getch();
                    }else{
                        MostraPontos(&pontos);
                        printf("\nInforme as cordenadas do seu ponto:\n");
                        printf("Coluna:\n");
                        scanf("%d",&cordenadas[0]);
                        printf("Linha:\n");
                        scanf("%d",&cordenadas[1]);
                        ExcluirPonto(&pontos,cordenadas,&gride);
                        system("pause");
                    }
                    break;
                }
            case 3:{
                    if(linhas.Qtd >= 5 ){
                        printf("Quantidade excedida!\n");
                        system("pause");
                    }
                    else{
                        printf("Digite as cordenadas iniciais:\n");
                        printf("Coluna:\n");
                        scanf("%d",&linhas.elementos[linhas.Qtd].primeiroponto.x);
                        printf("Linha:\n");
                        scanf("%d",&linhas.elementos[linhas.Qtd].primeiroponto.y);
                        printf("Digite as cordenadas finais:\n");
                        printf("Coluna:\n");
                        scanf("%d",&linhas.elementos[linhas.Qtd].segundoponto.x);
                        printf("Linha:\n");
                        scanf("%d",&linhas.elementos[linhas.Qtd].segundoponto.y);
                        while(linhas.elementos[linhas.Qtd].primeiroponto.x > linhas.elementos[linhas.Qtd].segundoponto.x || linhas.elementos[linhas.Qtd].primeiroponto.y > linhas.elementos[linhas.Qtd].segundoponto.y){
                        printf("Digite novamente:\n");
                        printf("Coluna:\n");
                        scanf("%d",&linhas.elementos[linhas.Qtd].segundoponto.x);
                        printf("Linha:\n");
                        scanf("%d",&linhas.elementos[linhas.Qtd].segundoponto.y);
                        }
                        fflush(stdin);  //Limpar buffer do teclado
                        printf("Digite o tipo do ponto:\n");
                        scanf("%c",&simbolo);
                        IncluirLinha(&linhas,&gride,simbolo);
                        linhas.Qtd ++;   //Incrementa a quantidade de linhas inseridas
                        system("pause");
                    }            
	       	  	 
                    break;
                }
            case 4:{if (linhas.Qtd == 0) {
                        printf("Nao ha Nenhuma linha!!!");
                        getch();
                    }else{
                        MostraLinhas(&linhas);
                        printf("\nInforme as cordenadas da sua linha:\n");
                        printf("Coluna:\n");
                        scanf("%d",&cordenadas[0]);
                        printf("Linha:\n");
                        scanf("%d",&cordenadas[1]);
                        printf("Coluna:\n");
                        scanf("%d",&cordenadas[2]);
                        printf("Linha:\n");
                        scanf("%d",&cordenadas[3]);
                    
                        ExcluirLinha(&linhas,cordenadas,&gride);
                    }
                    
                    system("pause");
                    break;
                }
            case 5:{
                    if(triangulo.Qtd >= 5 ){
                        printf("Quantidade excedida!\n");
                        system("pause");
                    }
                    else{
                        printf("Digite as cordenadas do pico do seu triangulo:\n");
                        printf("Coluna:\n");
                        scanf("%d",&triangulo.elementos[triangulo.Qtd].ponto.x);
                        printf("Linha:\n");
                        scanf("%d",&triangulo.elementos[triangulo.Qtd].ponto.y);
                        printf("Agora informe a altura:\n");
                        scanf("%d",&triangulo.elementos[triangulo.Qtd].altura);
                        fflush(stdin);
                        printf("Digite o tipo do ponto:\n");
                        scanf("%c",&simbolo);
                        IncluirTriangulo(&triangulo,&gride,simbolo);
                        triangulo.Qtd ++; //Aumenta a quantidade de triangulos inseridos
                        system("pause");
                    }            
	       	  	 
                    break;
                }
            case 6:{
              
                    break;
                }
            case 7:{
                    if(retangulo.Qtd >= 5 ){
                        printf("Quantidade excedida!\n");
                        system("pause");
                    }
                    else{
                        printf("Digite as cordenadas iniciais:\n");
                        printf("Coluna:\n");
                        scanf("%d",&retangulo.elementos[retangulo.Qtd].primeiroponto.x);
                        printf("Linha:\n");
                        scanf("%d",&retangulo.elementos[retangulo.Qtd].primeiroponto.y);
                        printf("Digite as cordenadas finais:\n");
                        printf("Coluna:\n");
                        scanf("%d",&retangulo.elementos[retangulo.Qtd].segundoponto.x);
                        printf("Linha:\n");
                        scanf("%d",&retangulo.elementos[retangulo.Qtd].segundoponto.y);
                        fflush(stdin);
                        printf("Digite o tipo do ponto:\n");
                        scanf("%c",&simbolo);
                        IncluirRetangulo(&retangulo,&gride,simbolo);
                        retangulo.Qtd ++;
                        system("pause");
                    }
                    break;
                }
            case 8:{
              
                    break;
                }//Fim do Switch
        }//Fim do While

    printf("\nFim do Programa!\n\n");
    system("pause");
}

