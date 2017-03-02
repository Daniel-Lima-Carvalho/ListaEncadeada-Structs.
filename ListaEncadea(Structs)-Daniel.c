#include <stdio.h>
#include <stdlib.h>

// Daniel Lima.

typedef struct No {
	int valor;			
	struct No* prox;	
}TNo;

typedef TNo* TLista;

inserir(TLista *L, int num1)
{
	TLista aux = (TLista) malloc (sizeof(TNo));
	
	TLista aux2 = *L;
	
	if (!aux)  
	{
		return 0;
	}
	if(*L == NULL)
	{
		aux->valor = num1;  
		aux->prox = *L; 
		*L = aux; 
		
		return 1;
	}
	else
	{
		while(aux2 != NULL)
		{
			if(aux2->valor >= num1)
			{
				aux->valor = num1;
				aux->prox = aux2;
				*L = aux;
				return 1;
			}
			else
			{
				if(aux2->prox == NULL || aux2->prox->valor >= num1)
				{
					aux->valor = num1;
					aux->prox = aux2->prox;
					aux2->prox = aux;
					return 1;
				}	
			}
			aux2 = aux2->prox;
		}
		
	}	
	
}
int verificar(TLista L, int num1)
{
	int cont = 0;
	
	while(L != NULL)
	{
		if(L->valor == num1)
		{
			cont++;
		}
		L = L->prox;
	}
	return cont;
}
void exibir (TLista L)
{
	TLista aux = L;   
	
	if (!aux)  
	{
		printf ("Lista vazia!\n");
	}
	else
	{
		printf ("Elementos da lista: ");
	
		while (aux)  
		{
			printf ("%d ", aux->valor);  
			
			aux = aux->prox; 
		}
		
		printf ("\n"); 
	}
}


int remover (TLista* L, int numero)
{
	TLista aux1, aux2;
	int cont = 0;

	while ((*L) && (*L)->valor == numero)
	{
		aux1 = *L;
		*L = (*L)->prox; 
		free (aux1);
		cont++;
	}
	if (*L)
	{
		aux2 = *L;
		aux1 = (*L)->prox;
		
		while (aux1)
		{
			if (aux1->valor == numero)
			{
				aux2->prox = aux1->prox;
				free (aux1);
				cont++;
				aux1 = aux2->prox;
			}
			else
			{
				aux2 = aux1;
				aux1 = aux1->prox;
			}
		}
	}
	return cont;
}
int remover1(TLista* L, int numero)
{
	TLista aux1, aux2;
	int cont = 0;

	if ((*L)->valor == numero)
	{
		aux1 = *L;
		*L = (*L)->prox; 
		free(aux1);
		return 0;
	}
	if(*L)
	{
		aux2 = *L;
		aux1 = (*L)->prox;
		
		while (aux1)
		{
			if (aux1->valor == numero)
			{
				aux2->prox = aux1->prox;
				free (aux1);
				return 0;
				aux1 = aux2->prox;
			}
			else
			{
				aux2 = aux1;
				aux1 = aux1->prox;
			}
		}
	}
	return cont;
}

TLista buscar (TLista L, int numero)
{
	TLista aux = L;
	
	while (aux)
	{
		if (aux->valor == numero)
		{
			return aux;
		}
			
		aux = aux->prox;
	}
	
	return NULL;
}

	
int alterar (TLista *L, int numero1, int numero2)
{
	TLista aux = *L;
	int cont, cont2 = 0;
	cont = verificar(aux,numero2);
	
	while (aux)
	{
		if (aux->valor == numero1 && cont < numero2)
		{
			inserir(L, numero2);
			aux = aux->prox;
			remover1(L,numero1);
			cont++;	
			cont2++;		
		}
		else
		{
			aux = aux->prox;
    	}
	}
	return cont2;
}
	

int main() {
	
	TLista L = NULL;
	TLista posicao;
	
	int escolha, num1, num2,res;
	
	do
	{
		printf("Inserir(1) Exibir(2) Remover(3) Buscar(4) Alterar(5) Sair(0): ");
		scanf("%i",&escolha);
		
		switch(escolha)
		{
			case 1:
				printf("Digite um numero: ");
				scanf("%i", &num1);
				if(verificar(L,num1) >= num1)
				{
					printf("Quantidade maxima do numero atingida!\n\n");
				}
				else
				{
					inserir(&L, num1);
					printf("Elemento Inserido!\n\n");
				}
				break;
			case 2:
				exibir(L);
				break;
			case 3:
				printf("Numero: ");
				scanf("%i",&num1);
				res = remover(&L,num1);
				if(res != 0)
				{
					printf("Removido com sucesso!\n\n");
				}
				else
				{
					printf("Elemento nao encontrado!\n\n");
				}
				break;
			case 4:
				printf("Numero: ");
				scanf("%i",&num1);
				posicao = buscar (L, num1);
				if(posicao)
				{
					printf("Encontrado na posicao: %p\n\n", posicao);
				}
				else
				{
					printf("Elemento nao encontrado!\n\n");
				}
				break;
			case 5:
				printf("Numero 1: ");
				scanf("%i",&num1);
				printf("Numero 2: ");
				scanf("%i",&num2);
				
				res = alterar(&L,num1,num2);
				if(res != 0)
				{
					printf("%i Alteracoes feitas do numero %i pelo numero %i\n\n.", res,num1, num2);
				}
				else
				{
					printf("ERRO: Numero %i nao encontrado ou Numero %i ja esta na quantidade maxima!\n\n",num1,num2);
				}
				break;
			default:
				printf(" Digite uma opcao valida!\n\n");	
		}
		system ("pause");
		system ("cls");
	}while(escolha != 0);
	
	return 0;
}
