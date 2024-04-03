#include <stdio.h>

#define TAM 9

int conflinha(int matriz[TAM][TAM], int lin){
  
  for (int lin = 0; lin < TAM ; lin++){
  int guarda[TAM] = {0}; //marcará nº que já apareceram
    for (int col = 0 ; col < TAM; col++) {
      int atual = matriz[lin][col];
       //Se sua casa correspondente já estiver preenchida com 1 então altera o res e retorna, não é necessário verificar as outras casas
        guarda[atual-1] = 1; //Se o Nº apareceu pela primeira vez guarda na casa do vetor o número 1. Exemplo o 5 fica guardado na 5ª casa (indice 4) do vetor.    
      
      
    }
    for (int i = 0 ; i < TAM ; i++){
      if(guarda[i] != 1)
         return 0;
    }
  
  }
  
  return 1;
}

//Mesma ideia da função para linha, só substituir lin por col
int confcoluna (int matriz[TAM][TAM]) {
  for (int col = 0 ;col < TAM ; col++){
      int guarda[TAM] = {0};
  
      for (int lin = 0; lin < TAM; lin++) {
          int atual = matriz[lin][col];
          
          if(guarda[atual -1] == 1){ 
            return 0;
          }
          else{
            guarda[atual-1] = 1;
          }
      }
      for (int i = 0 ; i < TAM ; i++){
          if(guarda[i] != 1){
              return 0;
          }
      }
  }
  
  return 1; 
} 

int confquadrado(int matriz[TAM][TAM], int linI, int colI){
  for (int linI = 0 ; linI < TAM ; linI += 3 ){
    for (int colI = 0 ; colI < TAM ; colI+= 3) {
      int guarda[TAM] = {0};
      
      for (int col = 0 ; col < 3 ; col++){
        for (int lin = 0 ; lin < 3; lin++) {
          int atual = matriz[lin+linI][col + colI];
          if(guarda[atual -1] == 1){ 
            return 0;
          }
          else{
            guarda[atual-1] = 1;
          }
        }
      }
    }  
  }
  return 1;
}

int main(void){
  
  int n, conf, matriz[TAM][TAM], i, j;

  scanf("%d", &n);

  if(n < 1){
    conf = 0;
  }

  for(int r = 0, res= 1; r < n; r++){
    conf=1;
    // Leitura da matriz
    for (i = 0 ; i < TAM ; i++) {
      for (j = 0 ; j < TAM; j++) {
        scanf("%d", &matriz[i][j]);
        if(matriz[i][j] < 1 || matriz[i][j] > 9){
          conf = 0;
        }
      }
    }

    // Verifica linha e coluna
     //Esse for já verifica se o valor do res está válido, se não for, ele não precisa verificar as outras linhas e colunas

    if (conf == 1)
    conf = conflinha(matriz, i);
    
    if (conf == 1) 
      conf = confcoluna(matriz);
  
    if (conf == 1)
      conf = confquadrado(matriz, i, j);
    
    if(conf == 1) {
      printf("Instancia %d\nSIM\n\n", r + 1);
    } 
    else {
      printf("Instancia %d\nNAO\n\n", r + 1);
    }

  }
  
  return 0;
}
