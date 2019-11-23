#ifndef HEADER_FUNCTIONS_H_INCLUDED
#define HEADER_FUNCTIONS_H_INCLUDED
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int erro(char text[]){
	printf("\n\n\n");
	printf("--------------------------------\n");
	printf("[Erro]  %s", text);
	return 0;
}



#endif

/*------------------------COLORS-DOS-------------------------*/
#if WIN32
	//#define RED		
	#define GRN		
	//#define BLU		"$e[1;34m"
	#define YEL		
	#define MAG		
	#define CYN		
	#define WHT		
	#define RESET	"$e[0m"
/*-----------------------COLORS-UNIX-------------------------*/
#elif UNIX || LINUX || Linux || linux
	#define RED   "\x1B[31m"
	#define GRN   "\x1B[32m"
	#define YEL   "\x1B[33m"
	#define BLU   "\x1B[34m"
	#define MAG   "\x1B[35m"
	#define CYN   "\x1B[36m"
	#define WHT   "\x1B[37m"
	#define RESET "\x1B[0m"
#endif
/*------------------------------------------------------------*/	


/** ----------------------Nome-das-cores------------------------------
*
*  BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY,
*  LIGHTBLUE,LIGHTGREEN,LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE
*---------------------------------------------------------------------*/


void textcolor (int choise)
{
	/*Salavando estado atual da tela*/
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD Saved_attributes;
	
	/*Instanciando Objeto tela*/
    HANDLE tela = GetStdHandle(STD_OUTPUT_HANDLE);
    
    if(choise != 0){
    	/*Define a cor do background em vermelho*/
    	SetConsoleTextAttribute(tela, BACKGROUND_RED /*| BACKGROUND_BLUE | BACKGROUND_GREEN*/);
	}
	else
	{
    	/*Define a cor do background em preto com escrita em cinza claro*/
    	SetConsoleTextAttribute(tela, Saved_attributes | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN);
    }
}
