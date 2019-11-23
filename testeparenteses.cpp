#include "header_functions.h"

#define N 100
char pilha[N];
int t;

// Esta função devolve 1 se a string ASCII s 
// contém uma sequência bem-formada de 
// parênteses e colchetes e devolve 0 se 
// a sequência é malformada.

void criapilha (void) {
   t = 0;
}

void empilha (char y) {
   pilha[t++] = y;
}

char desempilha (void) {
   return pilha[--t];
} 

int pilhavazia (void) {
   return t <= 0;
}

int bemFormada (char s[]) 
{
	int colOpen = 0;
	int chavOpen = 0;
	int parenOpen = 0;
	
	int colClose = 0;
	int parenClose = 0;
	int chavClose = 0;
	
   criapilha ();
   
   for (int i = 0; s[i] != '\0'; ++i) {
      char c;
      printf("%c",s[i]);
      
    	switch (s[i]) {
      	
      		/* Executa a verificação condicional de duplicidade de abertura de chaves.
      		 * Caso as chaves não tenham sido abertas anteriormente a variável de controle recebe valor 1 "verdadeiro".
      		 */
      		case '{':				
      			chavOpen = 1;		
      		break;
      		
    		case '[': 
				colOpen = 1;
        	break;
                   
        	case '(':
        		if(parenOpen == 1){
					printf("\n\nVocê já abriu os parenteses, use os colchetes '[' agora\n ");
					return 1;
				}
				else
				{
					parenOpen = 1;
				}
        	break;
        	
		 	case ')':
		 		if (parenOpen == 0){
		 			printf("\n Você não abriu os parenteses");
		 			return 1;
				}
				else
				{
					parenClose = 1;	
				}
			break;
			
			case ']':
				if ((parenOpen == 1)&&(parenClose == 0)){
					printf("\n\nFeche os parenteses ')' antes de fechar os colchetes.\n ");
				}
				else if(colOpen == 1){
					printf("\n Você não abriu os colchetes");
				}
				else{
					colClose = 1;
				}
			   
        empilha (s[i]);
        	
    	}
      	
      	
   }
   return pilhavazia ();
}

// faltam coisas
int main (void) {
	setlocale(LC_ALL,"PORTUGUESE");
   int retorno = bemFormada("[((A+D*J)]");
}


