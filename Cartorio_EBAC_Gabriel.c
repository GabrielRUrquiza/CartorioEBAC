#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
		//inicio cria��o de vari�veis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//fim cria��o de vari�veis/string
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
		scanf("%s",cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //responsavel por copiar os valores das string
		
		FILE *file; // cria o arquivo 
		file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
		fprintf(file,cpf); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //"a" siginifica atualizar o arquivo
		fprintf(file, ",");
		fclose(file);
		
		printf("digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
		scanf("%s",nome);
		
		file = fopen(arquivo, "a"); //"a" siginifica atualizar o arquivo
		fprintf(file,nome); //salva o valor da variavel
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a"); //"a" siginifica atualizar o arquivo
		fprintf(file,sobrenome); //salva o valor da variavel
		fclose(file);
		
		file = fopen(arquivo, "a"); 
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
		scanf("%s",cargo);
		
		file = fopen(arquivo, "a"); //"a" siginifica atualizar o arquivo
		fprintf(file,cargo); //salva o valor da variavel
		fclose(file);
		
		printf("\n");
		printf("Usu�rio cadastrado com sucesso!\n\n");
		
		system("pause");
}

int consultar()
{
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o cpf a ser consultado: "); //coletando informa��o do usu�rio
		scanf("%s",cpf); //%s refere-se a string
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
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
		
		printf("Digitar o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
		scanf("%s",cpf); //%s refere-se a string
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("o usu�rio foi deletado com sucesso!.\n");
			system("pause");
		}
		
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	char logindigitado[]="a";
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador! \n\nDigite o seu login: ");
	scanf("%s",logindigitado);
	
	printf("Digite a seu senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(logindigitado, "administrador");
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;)
		{
		
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar os nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //Fim do menu

    		scanf("%d", &opcao); //Armazenando a escolha do usu�rio

    		system("cls"); //responsavel por limpar a tela

    	
			switch(opcao) //inicio da sele��o do menu
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consultar();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;	
			
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;	
			}
		
		}
	}
	
	else
		printf("Senha incorreta!");

}
