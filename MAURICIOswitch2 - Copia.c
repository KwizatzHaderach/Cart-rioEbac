#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()//função responsável por cadastrar os usuários do sistema
{
	//inicio de criação de variáveis/strings
	setlocale(LC_ALL, "Portuguese");	//Definindo linguagem
	char arquivo[40]; // char variavel que representa um caractere de tipo texto
	char cpf[40]; //[40] quantidade de memória guardada para o caractere
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf); //armazenando cpf na variavel/ %s salvando as variáveis
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo na pasta/ mode w de write escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // a de atualização.
	fprintf(file,","); //dando espaço para ficar mais legível
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //armazenando nome
	
	file = fopen(arquivo, "a"); // a de acrescentar
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system ("pause");// para pausar a tela e o usuário conseguir ler	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");	//Definindo linguagem
	
	char cpf[40];
	char conteudo [200]; //conteudo do arquivo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //salvando na variavel
	
	FILE *file;
	file = fopen(cpf, "r"); //r de read ler
	
	if(file == NULL)//comparando para saber se o arquivo existe
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//enquanto procura  e se for diferente de nulo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);//porcentagem salvando s de string
	
	remove(cpf);//função usada para deletar usuário
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file != NULL) //se o arquivo for diferente
	{
		printf("O usuário não se encontra no sistema!. \n\n");
		system("pause");
	}
	else//companheiro do if...

	{

		printf("Usuário deletado com sucesso!\n\n");
        system("pause");

	}
}


int teste()
{
	printf("Funcionou a função do Mauzin");
	system("pause");
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int opcao=0;
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao;
    
    printf("### Cartório da EBAC ##\n\n");
    
    while(1) // loop infinito
    {
        printf("Login de Administrador:\n\nDigite a senha:");
        scanf("%s",senhadigitada);
        
        comparacao = strcmp(senhadigitada,"admin");
        
        if(comparacao == 0)
        {
            system("cls");
            for(laco=1;laco=1;) // loop infinito
            {
                system("cls");
                setlocale(LC_ALL, "Portuguese");
                
                printf("### Cartório da EBAC ###\n\n");
                printf("Escolha a opção desejada do menu:\n\n");
                printf("\t1 - Registrar Nomes \n");
                printf("\t2 - Consultar os Nomes \n");
                printf("\t3 - Deletar nomes \n\n");
                printf("\t4 - Sair do Sistema \n\n");
                printf("Opção:");
                
                scanf("%d", &opcao);
                
                system("cls");
                
                switch(opcao)
                {
                    case 1:
                        registro();
                        break;
                        
                    case 2:
                        consulta();
                        break;
                        
                    case 3:
                        deletar();
                        break;
                        
                    case 4:
                        printf("Obrigado por Utilizar o sistema");
                        return 0;
                        break;
                        
                    default:
                        printf("Essa opção não está disponível!\n");
                        system("pause");
                        break;
                }
            }
        }
        else 
        {
            printf("Senha incorreta\n");
            system("pause");
        }
    }
    
    return 0;
}

