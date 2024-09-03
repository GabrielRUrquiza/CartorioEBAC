#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsavel por cadastrar os usuários no sistema
{
		//inicio criação de variáveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//fim criação de variáveis/string
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
		scanf("%s",cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //responsavel por copiar os valores das string
		
		FILE *file; // cria o arquivo 
		file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
		fprintf(file,cpf); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //"a" siginifica atualizar o arquivo
		fprintf(file, ",");
		fclose(file);
		
		printf("digite o nome a ser cadastrado: "); //coletando informação do usuário
		scanf("%s",nome);
		
		file = fopen(arquivo, "a"); //"a" siginifica atualizar o arquivo
		fprintf(file,nome); //salva o valor da variavel
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a"); //"a" siginifica atualizar o arquivo
		fprintf(file,sobrenome); //salva o valor da variavel
		fclose(file);
		
		file = fopen(arquivo, "a"); 
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
		scanf("%s",cargo);
		
		file = fopen(arquivo, "a"); //"a" siginifica atualizar o arquivo
		fprintf(file,cargo); //salva o valor da variavel
		fclose(file);
		
		system("pause");
}

int consultar()
{
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o cpf a ser consultado: "); //coletando informação do usuário
		scanf("%s",cpf); //%s refere-se a string
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
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
		
		printf("Digitar o CPF do usuário a ser deletado: "); //coletando informação do usuário
		scanf("%s",cpf); //%s refere-se a string
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("o usuário não se encontra no sistema!.\n");
			system("pause");
		}
		
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //Fim do menu

    	scanf("%d", &opcao); //Armazenando a escolha do usuário

    	system("cls"); //responsavel por limpar a tela

    	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;	
		}
		
	}
}
