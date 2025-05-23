#include<iostream>
using namespace std;

#define GRAU_MAX 4
// 2n
#define GRAU_MIN 2
// n

class node
{
public:
	int chave[GRAU_MAX-1]; // chaves
	node *p [GRAU_MAX]; // filhos
	int tam; // variável auxiliar de tamanho
	// construtor
	node()
	{
		n = new node;
		n->tam = 0;
		for (int i = 0; i < GRAU_MAX; ++i)
		{
			n->p[i] = NULL;
		}
	}
}

// INCLUSÃO
// verificar a quantidade de chaves que tem naquele nó, quando ultrapassa o limite - SPLIT dividir o nó

//divide um no de uma arvore qundo ta cheio
// um not acheio qunado o num de chaves eh igual a grau-1

void SplitNo (node *pai, int indice, node *no)
{
	node *novo;
	novo ->tam = GRAU_MIN-1;
	// atribui chaves da segunda metade do no splitado, vai p o no novo
	for (int i = 0; i < GRAU_MIN-1; ++i)
	{
		novo->chave[i] = no->chave[i+GRAU_MIN];
	}
	//atribuição de ponteiros
	if (no->p[0] != NULL)
	{
		for (int i = 0; i <= GRAU_MIN-1; ++i)
		{
			novo->p[i] = no->p[i+GRAU_MIN];
		}
	}
	no->tam = GRAU_MIN-1;
	// desloca os ponteiros do nó pai p direita
	for (int i = pai->tam; i > indice; i--)
	{
		pai->p[i+1] = pai->p[i];
	}
	// ultimo indice aponta para o novo nó
	pai->p[indice+1] = novo;
	// deslocar as chaves dp pai p direita
	for (int i = pai->tam-1; i >= indice ; i--)
	{
		pai->chave[i+1] = pai->chave[i];
	}
	//sobe a cahve
	pai->chave[indice] = no->chave[GRAU_MIN];
	pai->tam = pai->tam+1;
}

node *splitRaiz(node *raiz) // adquiro nova raiz e um filho
{
	node *novaRaiz;
	SplitNo(novaRaiz, 0, raiz);
	novaRaiz->p[0] = raiz;
	novaRaiz->p[0]->tam = GRAU_MIN - 1;
	return novaRaiz;
}

//função de inclusão
node *inclusao (node *no, int chave, node *raiz)
{
	int i = no->tam-1;
	node *filho;
	//split na raiz
	if (no->tam == GRAU_MAXIMO - 1 && no == raiz)
	{
		raiz = splitRaiz(raiz);
		no = raiz;
		i = no->tam-1;
	}
	// nó folha
	if (no->p[0] == NULL)
	{
		while(i >= 0 && chave < no->chave[i])
		{
			no->chave[i+1] = no->chave[i];
			i--;
		}
		no->chave[i+1] = chave;
		no->tam = no->tam+1;
	}
	// descer na árvore
	else
	{
		while (i >= 0 && chave < no->chave[i])
			i--;
		i++;
		filho = no->p[i];		
		if (filho->tam == GRAU_MAX - 1)
		{
			SplitNo(no, i, filho);
			if (chave > no->chave[i])
			{
				i++;
			}
		}
		inclui(no->p[i], chave, raiz);
	}
	return raiz;
}

// função de merge!!!
// fusão
node *merge(node *esq, int chave, node *dir)
{
	int tamEsq = esq->tam;
	esq->chave[tamEsq] = chave;
	tamEsq++;
	esq->tam++;
	int i;
	// copar as chaves e ponteiros da direita p esquerda
	for (i = 0; i < dir->tam; ++i)
	{
		esq->chave[tamEsq + i] = dir->chave[i];
		esq->p[tamEsq + i] = dir->p[i];
	}
	esq->p[tamEsq + i] = dir->p[i];
	esq->tam = esq->tam + dir->tam;
	delete dir; // apaga o nó da direita;
	return esq;
}

node* exclusao (node *no, int chave, node* raiz)
{
	int j, i = no->tam-1;
	int aux=0;
	node *filho, *irmao, *sucessor, *antecessor;
	if (no->p[0] == NULL) // se o nó é folha
	{
		for (j = 0; j < no->tam && no->chave[j] != chave; j++);
		if (j == no->tam)
			return NULL;
		while(j < no->tam)
		{
			no->chave[j] = no->chave[j+1];
			j++;
		}
		no->tam = no->tam-1;		
	}
	// nao eh folha, no interno
	// desce na arvore e faz o merge quando necessario
	else
	{
		//encontrar o indice da chave a ser exluida
		for (j = 0; j < no->tam && no->chave[j] != chave; j++);
			// j tem o indice da chave a ser exluida
			//encontar a posição na subarvore que a chave se encontra
		i = no->tam-1;
		while(i >= 0 && chave < no->chave[i])
			i--;
		i++;
		if (j < no->tam)
		{
			//caso 02 - chave em no interno
			// filhos tem o numero minimo de filhos
			if (no->p[j] != NULL && no->p[j]->tam >= GRAU_MIN)
			{
				//antecessor
				antecessor = no->p[j];
				while(antecessor->p[antecessor->tam-1] != NULL)
					antecessor = antecessor->p[antecessor->tam-1];
				no->chave[j] = antecessor->chave[antecessor->tam-1];
				exclusao(no->p[j], antecessor->chave[antecessor->tam-1], raiz);
			}
			else
			{	//sucessor
				if (no->p[j+1] != NULL && no->p[j+1]->tam >= GRAU_MIN)
				{
					sucessor = no->p[j+1];
					while(sucessor->p[0] != NULL)
						sucessor = sucessor->p[0];
					no->chave[j] = sucessor->chave[0];
					exclusao(sucessor, sucessor->chave[0], raiz);
				}
				// nenhum dos filhos tem chvaes suficientes
				else
				{
					filho = merge(no->p[j], no->chave[j], no->p[j+1]);
					no->chave[j] = no->chave[j+1];
					//deslocar as chaves para a esqurda
					int i;
					for (i = j+1; i < no->tam; ++i)
						no->chave[i] = no->chave[i+1];
	 					no->p[i] = no->p[i+1]
					}
					no->p[i] = no->p[i+1];
					no->tam--;
					exclui(filho, chave, raiz);
			}
		}
		else { 
		//Caso 3: não encontrou a chave em nó interno
            filho = no->p[i]; //sub arvore da chave
            if (no->p[i]->tam == GRAU_MINIMO - 1)
            {
                if ( (i-1)>=0 && no->p[i-1]->tam >= GRAU_MINIMO)
                {
                     //filho esquerdo com ao menos t chaves
                    irmao = no->p[i-1];
                    aux = no->chave[i-1]; 
                    irmao->tam --;
                    no->chave[i-1] = irmao->chave[irmao->tam];
                    deslocaDireita(filho);
                    filho->tam ++;
                    filho->chave[0] = aux;
                    filho->p[0] = irmao->p[irmao->tam+1];
                }
                else 
                {
                    if ((i+1) <= no->tam && no->p[i+1]->tam >= GRAU_MINIMO)
                    {
                         //filho direito com ao menos t chaves
                        irmao = no->p[i+1];
                        aux = no->chave[i]; 
                        irmao->tam --;
                        no->chave[i] = irmao->chave[0];
                        deslocaEsquerda(irmao, 0);
                        filho->tam ++;
                        filho->chave[filho->tam-1] = aux;
                        filho->p[filho->tam] = irmao->p[0];                        
                    }
                    else { //fusao de nós
                        if (i == 0){//primeiro nó, fusiona com o direito
                            filho = fusionaNo(filho, no->chave[0], no->p[i+1]);
                            no->chave[0] = no->chave[1];
                            deslocaEsquerda(no, i+1);
                        } else { //fusiona com o esquerdo
                            filho = fusionaNo(no->p[i-1], no->chave[i-1], filho);
                            no->chave[i-1] = no->chave[i];
                            deslocaEsquerda(no, i);
                            i--;
                        }
                        no->tam --;
                    }   
                }
                
            }               
        exclui( no->p[i], chave, raiz);
    }
    return raiz;
}

// desloca as chaves e ponteiros de um nó 01 posição p direita
void deslocaDireita(node *no)
{
	for (int i = no->tam; i > 0; i--)
	{
		no->chave[i] = no->chave[i-1];
		no->p[i+1] = no->p[i];
	}
	no->p[i+1] = no->p[i];
}

// desloca as chaves e ponteiros de um no 01 posição p esquerda até um indice determinado
void deslocaEsquerda(node *no, int indice)
{
	for (int i = indice; i < no->tam ; i++)
	{
		no->chave[i] = no->chave[i+1];
		no->p[i] = no->p[i+1];
	}
	no->p[i] = no->p[i+1];
}