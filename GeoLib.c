struct TPonto{};
struct TLinha{};
struct TTriangulo{};
struct TRetangulo{};

#define ERRO printf("\nErro!\n")

//Parte 1: Alocação dinamica

//Alocaremos ponteiros do tipo char, i e j são inteiros com a dimensão da matriz

char **Alocar(int i,int j){
	
	int cont;
	char **PontMAT; //Ponteiro para a matriz
	
	//Alocando
	PontMAT=(char**)malloc(i*sizeof(char*));    //É importante observar que temos aqui uma alocação de duas dimensões
	   if(!PontMat){
	   	ERRO;
	   	return (NULL);
	   }
	   //Colunas
	     for(cont=0;cont<j;cont++){
	     	PontMAT[cont]=(char*)malloc(j*sizeof(*char));  //Para cada linha vamos alocar colunas
	     	   if(!PontMAT[cont]){
	     	   	ERRO;
	     	   	return(NULL);
	     	   }
	     }
	
	  //Retornando o ponteiro da matriz criada
	  return(PontMAT);
	
}
