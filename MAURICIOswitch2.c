#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//fun��o respons�vel por cadastrar os usu�rios do sistema
{
	//inicio de cria��o de vari�veis/strings
	setlocale(LC_ALL, "Portuguese");	//Definindo linguagem
	char arquivo[40]; // char variavel que representa um caractere de tipo texto
	char cpf[40]; //[40] quantidade de mem�ria guardada para o caractere
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf); //armazenando cpf na variavel/ %s salvando as vari�veis
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo na pasta/ mode w de write escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // a de atualiza��o.
	fprintf(file,","); //dando espa�o para ficar mais leg�vel
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
	
	system ("pause");// para pausar a tela e o usu�rio conseguir ler	
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
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//enquanto procura  e se for diferente de nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);//porcentagem salvando s de string
	
	remove(cpf);//fun��o usada para deletar usu�rio
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file != NULL) //se o arquivo for diferente
	{
		printf("O usu�rio n�o se encontra no sistema!. \n\n");
		system("pause");
	}
	else(file == NULL);//companheiro do if... caso n�o seja um, � o outro
    {
    	printf("Usu�rio deletado com sucesso! \n\n");
    	system("pause");
	}
	{

		printf("Usu�rio deletado com sucesso!\n\n");
        system("pause");

	}
}


int teste()
{
	printf("Funcionou a fun��o do Mauzin");
	system("pause");
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ##\n\n");
	printf("Login de Administrador:\n\nDigite a senha:");
	scanf("%s",senhadigitada);//salvando o comando que o usuario digitou
	
	comparacao = strcmp(senhadigitada,"admin");//comparando o que o usuario digitou
	
	if(comparacao ==0)
	{
	    system("cls");
	    for(laco=1;laco=1;)// para repetir o c�digo/continuar na mesma tela
	    {
            system ("cls");//respons�vel por limpar a tela
        
	         setlocale(LC_ALL, "Portuguese");	//Definindo linguagem
	
    	    printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
     	    printf("Escolha a op��o desejada do menu:\n\n");
    	    printf("\t1 - Registrar Nomes \n");
    	    printf("\t2 - Consultar os Nomes \n");
        	printf("\t3 - Deletar nomes \n\n");
        	printf("\t4 - Sair do Sistema \n\n");
        	printf("Op��o:");//fim do menu
	
    	    scanf("%d", &opcao); //armazenando a escolha do usu�rio 
	
        	system("cls");//limpezad da tela
    	
    	
      	switch(opcao)//in�cio da sele��o
    		{
			
			case 1:
			registro();//chamada de fun��es
			break; //para terminar a fun��o do switch 
			
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
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			//fim da sele��o
		    	
		     	
		  }
       }
	}
	else 
	    printf("Senha incorreta\n\n");
	    system("pause");
	    return 0;
}
