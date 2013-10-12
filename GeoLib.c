struct TPonto{};
struct TLinha{};
struct TTriangulo{};
struct TRetangulo{};

#define ERRO printf("\nErro!\n")

//Parte 1: Aloca��o dinamica

//Alocaremos ponteiros do tipo char, i e j s�o inteiros com a dimens�o da matriz

char **Alocar(int i,int j){
	
	int cont;
	char **PontMAT; //Ponteiro para a matriz
	
	//Alocando
	PontMAT=(char**)malloc(i*sizeof(char*));    //� importante observar que temos aqui uma aloca��o de duas dimens�es
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
