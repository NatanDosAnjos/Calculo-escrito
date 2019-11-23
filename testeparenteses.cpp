#include "header_functions.h"

#define N 100
char pilha[N];
int t;

// Esta fun��o devolve 1 se a string ASCII s 
// cont�m uma sequ�ncia bem-formada de 
// par�nteses e colchetes e devolve 0 se 
// a sequ�ncia � malformada.

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
      	
      		/* Executa a verifica��o condicional de duplicidade de abertura de chaves.
      		 * Caso as chaves n�o tenham sido abertas anteriormente a vari�vel de controle recebe valor 1 "verdadeiro".
      		 */
      		case '{':				
      			chavOpen = 1;		
      		break;
      		
    		case '[': 
				colOpen = 1;
        	break;
                   
        	case '(':
        		if(parenOpen == 1){
					printf("\n\nVoc� j� abriu os parenteses, use os colchetes '[' agora\n ");
					return 1;
				}
				else
				{
					parenOpen = 1;
				}
        	break;
        	
		 	case ')':
		 		if (parenOpen == 0){
		 			printf("\n Voc� n�o abriu os parenteses");
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
					printf("\n Voc� n�o abriu os colchetes");
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


