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
      	
      		/* Executa a verifica��o condicional de duplicidade de abertura de CHAVES.
      		 * Caso as chaves n�o tenham sido abertas anteriormente a vari�vel de controle recebe valor 1 "verdadeiro".
      		 */
      		case '{':				
      			chavOpen = 1;		
      		break;
      		
      		/* Executa a verifica��o condicional de duplicidade de abertura de COLCHETES.
      		 * Caso as chaves n�o tenham sido abertas anteriormente a vari�vel de controle recebe valor 1 "verdadeiro".
      		 */
    		case '[': 
    			if(colOpen == 1){
					erro("Voc� j� abriu os colchetes, use os parenteses agora '['.");
					return 1;
				}
				else
				{
					colOpen = 1;
				}
        	break;
                   
            /* Executa a verifica��o condicional de duplicidade de abertura de PARENTESES.
      		 * Caso as chaves n�o tenham sido abertas anteriormente a vari�vel de controle recebe valor 1 "verdadeiro".
      		 */
        	case '(':
        		if(parenOpen == 1){
					erro("Voc� j� abriu um parenteses, feche-o.");
					return 1;
				}
				else
				{
					parenOpen = 1;
				}
        	break;
        	
		 	case ')':
		 		if (parenOpen == 0){
		 			erro("Voc� est� tentando fechar um parentese que n�o foi aberto.");
		 			return 1;
				}
				else if ((parenOpen == 1)&&(parenClose == 1)){
					erro("Voc� j� abriu e fechou os parentese. Use um colchete no local.");
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
					erro("Voc� n�o abriu os colchetes.");
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

// Fun��o Principal do programa.
int main (void) {
	int retorno, cont, i;
	char s[] = "(A+[]D*J)";
	
	setlocale(LC_ALL,"PORTUGUESE");
	retorno = bemFormada(s, i);

	printf("\n\n\n-------------------------------------------------------------------------------\n");
	printf("Equa��o         |<>| %s\n",s);
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


