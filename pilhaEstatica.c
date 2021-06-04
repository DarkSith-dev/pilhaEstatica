#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define N 4

typedef struct Pilha{
	int vetor[N];
	int topo;
}Pilha;

void inicializarPilha(Pilha *p){
	int i;
	for(i=0;i<N;i++){
		p->vetor[i] = 0;
	}
	p->topo = -1;
}

int pilhaCheia(Pilha *p){
	if( p->topo == N - 1 ){
		return 1; // Pilha Cheia
	}
	else{
		return 0; // Pilha n�o est� cheia
	}
}

int pilhaVazia(Pilha *p){
	if( p->topo == -1 ){
		return 1; // Pilha vazia
	}
	else{
		return 0; // Pilha n�o est� vazia
	}
}

void empilhar(Pilha *p, int numero){
	p->topo++;
	p->vetor[p->topo] = numero;
}

int desempilhar(Pilha *p){
	int auxiliar = p->vetor[p->topo];
	p->topo--;
	return auxiliar;
}

int elementoTopo(Pilha *p){
	if( p->topo == -1 ){
		return -999;
	} else{
		int numeroTopo = p->vetor[p->topo];
		return numeroTopo;	
	}
}

void menu(){
	printf("\n1 - Empilhar (Push)\n");
	printf("2 - Desempilhar (Pop)\n");
	printf("3 - Mostrar Topo\n");
	printf("4 - Sair\n");
	printf("Op��o: ");
}

int main(){
	printf("### Pilha ###");
	setlocale(LC_ALL,"Portuguese");
	Pilha pilha;
	inicializarPilha(&pilha);
	int opcao = 0;
	while(opcao != 4){
		menu();
		scanf("%d",&opcao);
		switch(opcao){
			
			case 1:
				if(pilhaCheia(&pilha) == 1){
					printf("\nPilha cheia. N�o � poss�vel usar a op��o Empilhar.\n");
				} else{
					int valor = 0;
					printf("\nInteiro: ");
					scanf("%d",&valor);
					empilhar(&pilha,valor);
				}
			break;
			
			case 2:
				if(pilhaVazia(&pilha) == 1){
					printf("\nPilha vazia. N�o � poss�vel usar a op��o Desempilhar.\n");
				} else{
					desempilhar(&pilha);
				}
			break;
			
			case 3:
				if( elementoTopo(&pilha) == -999){
					printf("\nA pilha n�o possui nenhum elemento.\n");
				}else{
					printf("\nTopo: %d\n",elementoTopo(&pilha));
				}
			break;
			
			case 4:
				printf("\nSaindo...");
			break;
			
			default:
				printf("\nOp��o inv�lida. Digite uma op��o novamente: ");
				menu();
				scanf("%d",&opcao);
			break;
		}
		
	}
	
	return 0;
}
