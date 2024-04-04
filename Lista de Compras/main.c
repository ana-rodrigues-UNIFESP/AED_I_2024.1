#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da Estrutura Comida
struct comida {
    char item[21]; 
    struct comida *prox;
};
typedef struct comida Comida; 

// Função para criar uma lista encadeada COM cabeça
Comida *cria(){
  Comida *lista = (Comida *) malloc (sizeof(Comida));

  //Se não foi possível alocar memória
  if(lista == NULL){
    exit(1);
  }
  
  lista->prox = NULL; //inicializa lista

  return lista;
}

// Confere se o item já está na lista
int buscaRepeticao(Comida *lista, char *itemc){
  Comida *copiaLista;
  copiaLista = lista->prox;

  while(copiaLista!=NULL){
    if(strcmp(copiaLista->item, itemc) == 0){
      return 1;
    }
      copiaLista = copiaLista->prox;
  }

  return 0;
}

void insere(Comida *lista, char *itemc){

  //Se a função busca retorna 1 o item já está na lista e não deve ser inserido
  if(buscaRepeticao(lista, itemc)){
    return;
  }

  //Caso não seja repetido insere
  Comida *nova = (Comida *) malloc (sizeof(Comida));

  if(nova == NULL){
    exit(1);
  } //Se não foi possível alocar memória

  strcpy(nova->item, itemc);
  nova->prox= lista->prox;
  lista->prox= nova;
}

void ordenar(Comida **pLista){
  
  //Se a lista estiver vazia ou com apenas um elemento não tem o que ordenar
  if((*pLista)->prox == NULL || ((*pLista)->prox)->prox == NULL){
    return;
  }

  Comida *aux = *pLista, *aux2;

  char temp_nome[21]; //Armazena o nome durante a troca

  //Loop percorre lista
  while(aux != NULL) {
      aux2 = aux->prox;

      //Loop percorre comparação lista
      while(aux2 != NULL) {

        //Se o anteior (aux) for "maior" trocam de lugar
          if(strcmp(aux->item, aux2->item) > 0) {
            strcpy(temp_nome, aux->item);
            strcpy(aux->item, aux2->item);
            strcpy(aux2->item, temp_nome);
          }
          aux2 = aux2->prox;
      }
      aux = aux->prox;
  }
}

void imprime(Comida *lista) {
  Comida *aux;
  
  for (aux = lista->prox; aux != NULL; aux = aux->prox){
    printf ("%s ", aux->item);
  }
  printf("\n");
}

void libera(Comida *lista) {
    Comida *aux;

    while(lista->prox != NULL){
      aux = lista->prox;
      lista->prox = aux->prox;
      free(aux);
    }

  free(lista); //Libera cabeça da lista
}


int main() {
  int n;
  char linha[20001], *itemc;
  Comida *lista;
  
  scanf("%d", &n);

  //Confere n válido
  if(n < 1 || n >= 100){
    exit(1);
  }

  // Loop - Casos teste
  for (int i = 0; i < n; i++) {
    lista = cria();
    scanf(" %[^\n]", linha);
    getchar();

    //Reparte a string sempre que encontra espaço e adiciona na lista (se não for repetido, devido verificação interna da função)
    char *token = strtok(linha, " "); 
    while (token != NULL) {
      insere(lista, token);
      token = strtok(NULL, " ");
    }

    //Ordena
    ordenar(&lista);

    //Imprime
    imprime(lista);
    
    libera(lista);
    }
  
    return 0;
}