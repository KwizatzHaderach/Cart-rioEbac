#include <stdio.h>
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
int main() 
{
	setlocale(LC_ALL, "Portuguese");	//Definindo linguagem
    int candidatoImpar, resto;//definindo vari�vel
    
    printf("Qual n�mero gostaria de saber se � par ou impar?\n");
    scanf("%d", &candidatoImpar);
    printf("Voc� digitou: %d.\n", candidatoImpar);

    resto = candidatoImpar % 2;
    if (resto != 0) {
        printf("O n�mero que voc� digitou � IMPAR!\n");
    } else {
        printf("O n�mero que voc� digitou � PAR!\n");
    }

    return 0;
}

