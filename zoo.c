#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int i = 0;
int qtd = 0;
int codigobackup[100] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

struct dados{
	int codigo;
	int idade;
	char tipo[32]; //raça
	char data[16]; 
	char sexo; // f ou m;	
};

struct dados cadastro(struct dados animalc[]){
	char continuar;
	int j;
	system("cls"); //limpa a tela
	printf ("\n*Sistema de Cadastro*\n\n");
	

		printf("Insira o CODIGO do novo animal: ");
		getchar();
		scanf("%d", &animalc[i].codigo);
		
		for (j=0; j<100; j++){ //verificação se o codigo ja foi, laço simples com reset de verifiação;
			if(animalc[i].codigo == codigobackup[j]){
			printf("\nEsse Codigo ja esta sendo utilizado, insira outro: ");	//Pede o novo codigo do animal e verifica se ja foi utilizado.
			scanf("%d", &animalc[i].codigo);
			j=0;
			}
		}
		codigobackup[i] = animalc[i].codigo;
		//joga para um backup, para verificar depois.
	
		
		printf("\nInsira o TIPO do novo animal: "); //pega a raça do animal
		fflush(stdin);//limpa a sujeira do teclado
		gets(animalc[i].tipo);
		
		printf("\nInsira a idade do animal: ");//pega a idade do animal
		scanf("%d", &animalc[i].idade);
		
		getchar();//limpa a sujeira do teclado
		printf("\nInsira o Sexo do animal (F para Femea, M para Macho): ");//pega o sexo do animal
		scanf("%c", &animalc[i].sexo);
		
		printf("\nInsira a data de ENTRADA do novo animal(formado DD/MM/YY): ");//pega a data de entrada do animal
		fflush(stdin); //limpa a sujeira do teclado
		gets(animalc[i].data);
	
		i++; //aumenta a variavel global i, que controla o registro dos animais;
		qtd++; //faz a conta de quantos animais foram registrados. para uso posterior;
}

struct dados pesquisa(struct dados animalp[]){
	int escolhap;
	char raca[100]; 
	char sx;
	int x,y,z;
	system("cls");
	printf ("\n*Sistema de Pesquisa*\n\n");
	printf ("1-Pesquisar por raça.\n2-Pesquisar por Sexo."); //escolha do usuario
	printf("\n\nSelecione sua opcao:  ");
	scanf("%d", &escolhap);
	
	if (escolhap == 1){
		system("cls"); //limpa a tela
		printf("\nInsira a raca que deseja pesquisar: ");
		fflush(stdin);
		gets(raca);
			for (x=0;x<=qtd;x++){ //verifica se a raça é compativel com algum animal no sistema, caso sim, é printado.
				if(strcmp(raca, animalp[x].tipo) == 0){
					printf("\nTipo do Animal: "); 
						puts(animalp[x].tipo);
						printf("\nSexo: %c", animalp[x].sexo);
						printf("\n\nCodigo: %d", animalp[x].codigo);
						printf("\n\nData de Entrada: ");
						puts(animalp[x].data);
						printf("\nIdade = %d\n", animalp[x].idade);
						printf("---------------------------------------\n");
					
				}
			}
	}
	else if(escolhap == 2){
		system("cls");
		printf("\nInsira o sexo que deseja pesquisar(M para Masculino, F para Feminino.): "); //escolha do usuario
		getchar();
	
		scanf("%c", &sx);
				if(sx == 'm' || sx == 'M') {
					printf("\nAnimais Encontrados:\n");
					for(y=0;y<=qtd;y++){
						if (animalp[y].sexo == 'm'||animalp[y].sexo == 'M'){ //faz a verificação de todos os animais utilizando a variavel global 'qtd' e separa os sexos dos animais, para printar.	
						printf("*Tipo do Animal: ");
						puts(animalp[y].tipo);
						printf("\nSexo: %c", animalp[y].sexo);
						printf("\n\nCodigo: %d", animalp[y].codigo);
						printf("\n\nData de Entrada: ");
						puts(animalp[y].data);
						printf("\nIdade = %d\n\n", animalp[y].idade);
						printf("---------------------------------------\n");
						}
					}
				}
				
				else if(sx == 'f' || sx == 'F') {  //faz a verificação de todos os animais utilizando a variavel global 'qtd' e separa os sexos dos animais, para printar.	
					printf("\nAnimais Encontrados:\n"); 
					for(z=0;z<=qtd;z++){
						if (animalp[z].sexo == 'f'||animalp[z].sexo == 'F'){ //variaveis que sao apenas letras, utilizo como "variaveis de controle"
							
						printf("*Tipo do Animal: ");
						puts(animalp[z].tipo);
						printf("\nSexo: %c", animalp[z].sexo);
						printf("\n\nCodigo: %d", animalp[z].codigo);
						printf("\n\nData de Entrada: ");
						puts(animalp[z].data);
						printf("\nIdade = %d\n\n", animalp[z].idade);
						printf("---------------------------------------\n");
						}
					}
					
				}
			}
			system("pause");// pausa o sistema, para melhor dinamicidade 
}

struct dados relatorio(struct dados animalr[]){
	system("cls"); //limpa a tela
	printf("*Sistema de Relatorio*\n");
	int a;
	for(a=0;a<qtd;a++){ //novamente utilização da variavel global qtd; para nao printar coisa que nem existe.
		printf("\n\nTipo do Animal: ");
						puts(animalr[a].tipo);
						printf("\nSexo: %c", animalr[a].sexo);
						printf("\n\nCodigo: %d", animalr[a].codigo);
						printf("\n\nData de Entrada: ");
						puts(animalr[a].data);
						printf("\nIdade = %d\n", animalr[a].idade);
						printf("---------------------------------------\n"); //utilizei a mesma formatação para quase todas as vezes que o sistema precisa printar varias coisas.
	}
	system("pause");
}
	
struct dados animaisporsexo(struct dados animalr[]){
	system("cls");
	int b,c;
	int esc;
	int totalf = 0; //gosto de colocar as variaveis assim, para garantir que todas foram zeradas.
	int totalm = 0;
	float idadef = 0;
	float idadem = 0;
 	int idadesf = 0;
 	int idadesm =0;
	for(b=0;b<=qtd;b++){ //faz o calculo de quantos animais ha em cada sexo
				if (animalr[b].sexo == 'f' ||animalr[b].sexo == 'F' ){
					totalf++;
				}
				else if (animalr[b].sexo == 'm' ||animalr[b].sexo == 'M' ){
					totalm++;
				}
			}
	printf("*Sistema de Relatorio dividido por sexo*\n");
	printf("\n1-Apresentar total de animais por sexo\n2-Apresentar a media de idade de animais por sexo\n");
	printf("\nSelecione uma opcao: ");
	getchar();
	scanf("%d", &esc);

		
		if (esc == 1){
				 //printa o total
		printf("\nHa %d animais machos.", totalm);
		printf("\nHa %d animais femeas.\n", totalf);
		system("pause");
	}
	
		else if (esc == 2){
			for(c=0;c<=qtd;c++){  //verifica oque é oque, depois vai somando
				if (animalr[c].sexo == 'f' ||animalr[c].sexo == 'F' ){
				idadesf = animalr[c].idade + idadesf;
				}
				else if (animalr[c].sexo == 'm' ||animalr[c].sexo == 'M' ){
				idadesm = animalr[c].idade + idadesm;		
				}
		}
		if (totalm == 0){
			totalm++;
		}
		if (totalf==0){
			totalf++;
		} // caso o total é 0, adciona 1 pra nao bugar o codigo. //explicação no txt
		
	idadef = idadesf/totalf; // faz a media das idades separadas por sexo
	idadem = idadesm/totalm;
	printf("\nMedia de idade %.2f dos animais machos.", idadem);
	printf("\nMedia de idade %.2f das animais femeas.\n\n", idadef);
	system("pause");//pausa o sistema
	}		
}




int main(){
	int escolha;
	int saiu = 0;
	struct dados animais[100];
do{	
	system("cls");
	printf("\nBem vindo ao sistema de Registros do Zoologico:\n\n");
	printf("1- Cadastrar Animal\n2- Pesquisar\n3- Relatorio\n4- Animais Por Sexo\n5- Sair");
	
	
	printf("\n\nSelecione sua opcao:  ");
	scanf("%d", &escolha);

	if (escolha == 1){
	cadastro(animais);
	}
	else if(escolha == 2){
	pesquisa(animais);
	}
	else if(escolha == 3){
	relatorio(animais);	
	}
	else if(escolha == 4){
	animaisporsexo(animais);
	}
	else if(escolha == 5){
	saiu = 1;
	}
	
}while(saiu == 0); // continua o sistema até que o usuario saia
	
	return 0;
}