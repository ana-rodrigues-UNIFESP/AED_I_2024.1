#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para do nó da lista
typedef struct amigos{
  char amigo[50];
  struct amigos *prox, *ant;
} Lista;
typedef Lista *pLista; //Ponteiro para a estrutura

// Cria e inicializa uma lista duplamente encadeada vazia
pLista cria(){
  pLista lista = (Lista*)malloc(sizeof(Lista));

  if(lista==NULL){
    exit(1);
  }

  lista->prox = NULL;
  lista->ant = NULL;

  return lista;
}

//Recebe a lista e o nome do amigo a ser adicionado e cria nós para cada um inserindo sempre no final da lista
void lista_incial_amigos(pLista lista, char *amigo){
  pLista nova = (Lista*) malloc (sizeof(Lista));
  pLista aux=lista;

  if(nova == NULL){
    exit(1);
  } 

  strcpy(nova->amigo, amigo);

  if(lista->prox == NULL){
    lista->prox = nova;
    nova->ant = lista;
    nova->prox = NULL;
  }
  else{
     while(aux->prox != NULL){
       aux = aux->prox;
     } //Acha o último

    aux->prox = nova;
    nova->ant = aux;
    nova->prox = NULL;
  }

}

//Recebe como parâmetro a lista e o amigo que buscamos e retorna o nó encontrado ou erro caso não encontre
pLista busca(pLista lista, char *amigo){
  pLista aux;

  for(aux = lista; aux != NULL; aux = aux->prox){
    if(strcoll(aux->amigo, amigo) == 0){
      return aux;
    }
  }

  return 0;
}

//Recebe a lista, o amigo e o nó...Adiciona o amigo antes do amigo informado ou no final da lista se o parametro informado for "nao"
void insere_com_parametro(pLista lista, char *amigo, pLista achou, char *amigoParametro){
  pLista nova  = (Lista*) malloc (sizeof(Lista));
  pLista aux = lista;

  if(nova == NULL){
    exit(1);
  } 

  strcpy(nova->amigo, amigo);

  if(strcmp(amigoParametro, "nao") == 0){
    while(aux->prox != NULL){
       aux = aux->prox;
    }

    aux->prox = nova;
    nova->ant = aux;
    nova->prox = NULL;
  } 
  if(achou == 0){
    return;
  }
  else{
      (achou->ant)->prox = nova;
      nova->ant = achou->ant;
      nova->prox = achou;
      achou->ant = nova;
  }

}

void imprime(pLista lista){
  pLista aux;

  for(aux = lista->prox; aux !=NULL; aux = aux->prox){
    if(aux->prox!=NULL){
      printf("%s ", aux->amigo);
    }
    else{
     printf("%s\n", aux->amigo);
    }
  }

}

void libera(pLista lista) {
    pLista aux;

    while(lista->prox != NULL){
      aux = lista->prox;
      lista->prox = aux->prox;
      free(aux);
    }

  free(lista);
}

int main(void) {
  char listaInicio[20000], amigosAdicionados[20000], amigoParametro[15], *token;
  pLista lista, achou;

  lista = cria();

  scanf("%[^\n]", listaInicio);

  scanf(" %[^\n]", amigosAdicionados);

  scanf(" %[^\n]", amigoParametro);

  token = strtok(listaInicio, " ");
  while(token != NULL){
    lista_incial_amigos(lista, token);
    token = strtok(NULL, " ");
  } 

  achou = busca(lista,amigoParametro);
  token = strtok(amigosAdicionados, " ");

  while(token != NULL){
    insere_com_parametro(lista, token, achou, amigoParametro);
    token = strtok(NULL, " ");
  } 

  imprime(lista);

  libera(lista);

  return 0;
}
