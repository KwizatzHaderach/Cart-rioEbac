#include <stdio.h>
#include <locale.h> //biblioteca de alocações de texto por região
int main() 
{
	setlocale(LC_ALL, "Portuguese");	//Definindo linguagem
    int candidatoImpar, resto;//definindo variável
    
    printf("Qual número gostaria de saber se é par ou impar?\n");
    scanf("%d", &candidatoImpar);
    printf("Você digitou: %d.\n", candidatoImpar);

    resto = candidatoImpar % 2;
    if (resto != 0) {
        printf("O número que você digitou é IMPAR!\n");
    } else {
        printf("O número que você digitou é PAR!\n");
    }

    return 0;
}

