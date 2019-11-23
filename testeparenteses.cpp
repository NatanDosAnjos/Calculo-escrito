#include<stdio.h>
#include <stdlib.h>

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
	int col = 0;
	int chav = 0;
	int paren = 0;
	
	int colFechado = 0;
	int parenFechado = 0;
	int chavFechado = 0;
	
   criapilha ();
   
   for (int i = 0; s[i] != '\0'; ++i) {
      char c;
      printf("%c",s[i]);
      
      switch (s[i]) {
    		case '(': 
				paren = 1;
        	break;
                   
        	case '[':
        		col = 1;
        	break;
        	
		 	case ')':
		 		if (paren == 0){
		 			printf("\n Você não abriu os parenteses");
				 }
			break;
			
			case ']':
				if((col == 0)||(col == 1) && (parenFechado == 0)){
					printf("\n Você não abriu os colchetes");
				}
			   
		 		      
			//if (chaveFechado)
			     
        	empilha (s[i]);
      	}
      	
      	
   }
   return pilhavazia ();
}

// faltam coisas
int main (void) {
   int retorno = bemFormada("}[(A+D*J]");
   printf ("%i", retorno);
}


