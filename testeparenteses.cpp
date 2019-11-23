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

int bemFormada (char s[], int &i) 
{
	int colOpen = 0;
	int chavOpen = 0;
	int parenOpen = 0;
	
	int colClose = 0;
	int parenClose = 0;
	int chavClose = 0;
	
	
	criapilha ();
   
   for (i = 0; s[i] != '\0'; ++i) {
      char c;
    	switch (s[i]) {
      	
      		/* Executa a verificação condicional de duplicidade de abertura de CHAVES.
      		 * Caso as chaves não tenham sido abertas anteriormente a variável de controle recebe valor 1 "verdadeiro".
      		 */
      		case '{':				
      			chavOpen = 1;		
      		break;
      		
      		/* Executa a verificação condicional de duplicidade de abertura de COLCHETES.
      		 * Caso as chaves não tenham sido abertas anteriormente a variável de controle recebe valor 1 "verdadeiro".
      		 */
    		case '[': 
    			if(colOpen == 1){
					erro("Você já abriu os colchetes, use os parenteses agora '['.");
					return 1;
				}
				else
				{
					colOpen = 1;
				}
        	break;
                   
            /* Executa a verificação condicional de duplicidade de abertura de PARENTESES.
      		 * Caso as chaves não tenham sido abertas anteriormente a variável de controle recebe valor 1 "verdadeiro".
      		 */
        	case '(':
        		if(parenOpen == 1){
					erro("Você já abriu um parenteses, feche-o.");
					return 1;
				}
				else
				{
					parenOpen = 1;
				}
        	break;
        	
		 	case ')':
		 		if (parenOpen == 0){
		 			erro("Você está tentando fechar um parentese que não foi aberto.");
		 			return 1;
				}
				else if ((parenOpen == 1)&&(parenClose == 1)){
					erro("Você já abriu e fechou os parentese. Use um colchete no local.");
					return 1;
				}
				else
				{
					parenClose = 1;	
				}
			break;
			
			case ']':
				if ((parenOpen == 1)&&(parenClose == 0)){
					erro("Feche os parenteses ')' antes de fechar os colchetes.");
					return 1;
				}
				else if(colOpen == 0){
					erro("Você não abriu os colchetes.");
					return 1;
				}
				else{
					colClose = 1;
				}
			break;
        empilha (s[i]);	
    	}
   }
   return pilhavazia ();
}

// Função Principal do programa.
int main (void) {
	int retorno, cont, i;
	char s[] = "(A+[]D*J)";
	
	setlocale(LC_ALL,"PORTUGUESE");
	retorno = bemFormada(s, i);

	printf("\n\n\n-------------------------------------------------------------------------------\n");
	printf("Equação         |<>| %s\n",s);
	printf("Local do Erro   |<>| ");
	
	
	if (retorno == 1){
		for(cont = 0; s[cont] != '\0'; cont++){
			if (cont != i){
				printf("%c", s[cont]);
			}
			else{
				textcolor(1);
				printf("%c", s[cont]);
				textcolor(0);
			}
		}
	}
}


