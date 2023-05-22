/**************************
Nome e RA: Italo Pereira Ventura - 2467259
Turma: AS31B - Algoritmo
Enunciado: Jogo de Caça ao Submarino
TRABALHO FEITO NO IDE FALCON !!!
***************************/

#include <stdio.h>
#include <locale.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

char comparacao(char N1[]) // função de jogar novamente
{
	int a,b,c; // variaveis de resultado da comparação 
	char COMP1[10] = {"SIM"}; // string de comparação de jogar novamente
	char COMP2[10] = {"sim"}; // string de comparação de jogar novamente
	char COMP3[10] = {"Sim"}; // string de comparação de jogar novamente
	int M; // variavel de retorno da função
	
		a = strcmp(N1,COMP1);
		b = strcmp(N1,COMP2); // comparando possiveis repostas de jogar novamente 
		c = strcmp(N1,COMP3);
		
	if(a==0 || b==0 || c==0) // se umas das opções forem verdadeiras o jogo continua 
	{
		M=1; // posivel retorno da função
		return M;
	}
	else // se for falsa o jogo acaba
	{
		M=-1; // posivel retorno da função
		return M;
	}
}

void perdeu (int mat[3][3],int X1,int Y1)
{
	int i,j,l;
	char PONTO[2] = {"."}; // auxiliar para mostrar o vazio no oceano
		
	l=0; // variavel auxiliar para apresentar a numeração das linhas e colunas 
	printf("\n  0 1 2"); // apresentar em cima as colunas
	
	// laço de repetição para apresentar o oceano quando perder
	for (i=0;i<=2;i++)
	{
		printf("\n%d ",l); // apresentar na latera as linhas
		l++;			
		for(j=0;j<=2;j++)
		{
			if(i == X1 && j == Y1) 
			{	
				printf("S ",mat[i][j]); // onde o submarino achou o usuario
			}
   		   	else 
			{ 
				printf("%s ", PONTO); // onde não tem nada no oceano	
			}
		}

	}
	// mostrando ao usuario o resultado
	printf("\n\nO submarino achou você!\n\n\n");
	printf("\tGAMER OVER!\n");
}

void continua (int mat[3][3],int A1,int B1,int X1,int Y1)
{
	int i,j,l;
	char PONTO[2] = {"."}; // auxiliar para mostrar o vazio no oceano
	
	l=0; // variavel auxiliar para apresentar a numeração das linhas e colunas
	printf("\n  0 1 2"); // apresentar em cima as colunas			
	
	// laço de repetição para apresentar o oceano quando não perder e nem ganhar consequentemente proxima rodada
	for (i=0;i<=2;i++)
	{
		printf("\n%d ",l); // apresentar na latera as linhas
		l++;				
		for(j=0;j<=2;j++)
		{
			if(i == X1 && j == Y1) 
			{
				printf("C ",mat[i][j]); // onde esta o usuario
			}
			else if(i == A1 && j == B1)
			{
				printf("S ",mat[i][j]); // onde esta o submarino
			}
			else 
			{
				printf("%s ", PONTO); // onde não tem nada no oceano
			}
		}
	}
	// mostrando ao usuario o resultado
	printf("\n\n Você não achou ele!\n");
	printf("\n Vez do submarino jogar\n\n");
	printf("Pressione (ENTER) para o submarino se movimentar...\n");
	getch();
	// aqui não tem break pois ele não ganhou e nem perdeu, fazendo que o jogo fique perguntando para ele até acontecer um dos dois	
}

void ganhou(int mat[3][3],int X1,int Y1)
{
	int i,j,l;
	char PONTO[2] = {"."}; // auxiliar para mostrar o vazio no oceano
	
	l=0; // variavel auxiliar para apresentar a numeração das linhas e colunas
	printf("\n  0 1 2"); // apresentar em cima as colunas
	
	// laço de repetição para apresentar o oceano quando ganhar
	for (i=0;i<=2;i++)
	{
		printf("\n%d ",l);// apresentar na latera as linhas
		l++;	
				
		for(j=0;j<=2;j++)
		{
			if(i == X1 && j == Y1) 
			{
				printf("S ",mat[i][j]); // onde o usuario achou o submarino
			}
			else 
			{
				printf("%s ", PONTO); // onde não tem nada no oceano	
			}
		}
	}
	// mostrando ao usuario o resultado
	printf("\n\nVocê encontrou o submarino!!!\n\n\n");
	printf("\tPARABENS!\n");	
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int mat[3][3]; // a matriz de ordem 3 (oceano do jogo)
	int i,j; // variaveis para a matriz
	int a,b; // posições que o submarino vai ficar na matriz do oceano
	int X,Y; // posições que o usuario quer ficar na matriz do oceano
	int l; // variaveis auxiliares
	int RC; // RESPOSTA DA COMPARAÇÃO (RC)
	
	char PONTO[2] = {"."}; // Char auxiliar para mostrar pontos na apresentação pro usuario
	char JN[5]; // variavel de resposta de jogar novamente 
	
	// tela de boas vindas ao usuario
	printf("\tBem vindo ao jogo!");
	printf("\n\n\n\n\tA caça ao submarino\n\n\n\n");
	printf("Pressione (ENTER) para continuar...");
	getch();
	
	do // laço de repetição do jogo caso usuario queira jogar novamente
	{
		// printfs para apresentar o jogo ao usuario
		printf("\n\n\nEsse é o oceano (mapa) do jogo\n");
		printf("\n  0 1 2 \n0 . . . \n1 . . . \n2 . . . \n");
		printf("\nVocê é um couraçado (C) e seu objtivo é ACHAR O SUBMARINO (S), antes que ele te ache! Boa sorte!\n");
		printf("\nVamos começar a caçada\n\nPressione (ENTER) para continuar...");
		getch(); // pause para o usuario ir interpretando o jogo 
		printf("\n\nEle esta já no oceano, Tente achar ele\n");
		
		while(1) // laço de petição infinito, só termina quando o usuario perde ou ganha o jogo 
		{
			srand(time(NULL));
			// sorteia numeros do submarino, vai ser numeros diferentes toda vez que repetir o laço fazendo com que o submarino se movimente 
			a = rand() % 3;	// linha do submarino
			b = rand() % 3;	// coluna do submarino
			
			// hipótese do usuario perder o jogo 
			// se o submarino achar o usuario primeiro 
			if (a == X && b == Y)
			{
				perdeu(mat,X,Y); // mostra a função perdeu
				break; // sai do laço de repetir a onde ele quer colocar o navio e vai perguntar se quer jogar novamente
			}
		
			// Vai repetir sempre que ele não ganhar e nem perder, para o usuario movimentar o
			printf("\n");
			printf("\nOnde você deseja colocar o couraçado? \n (Digite linha e depois a coluna)\n"); // usuario ia colocar a posição dele no oceano
			scanf("%d%d",&X,&Y); // posição onde o usuario quer colocar o navio 
			
			if (a != X || b != Y) // repetir o jogo infinito até ser igual
			{
				continua(mat,a,b,X,Y); // mostra a função continuar pois não ganhou nem perdeu então o jogo prosegue para proxima rodada
			}
			
			else // hipótese do usuario ganhar o jogo
			{
				ganhou(mat,X,Y); // mostra a função ganhou 
				break; // sai do laço de repetir a onde ele quer colocar o navio e vai perguntar se quer jogar novamente
			}
		}
		
		printf("\nDeseja jogar novamente? \n (Sim/Não) \n "); // perguntando se vai jogar novamente ao usuario
		scanf("%s",JN);
		
		RC = comparacao(JN); // chama a função
		
	}while(RC>0); // verificação de vai repetir o jogo ou encerrar 
	
	printf("\n\tObrigado por jogar!\n "); // agradecimento por jogar
	
	return 0;
}