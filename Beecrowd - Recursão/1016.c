#include <stdio.h>

void tempo_distanciar();
 
int main() {
    int kmDistante, tempo =0;
    
    scanf("%d", &kmDistante);
    
    tempo_distanciar(kmDistante, tempo);
 
    return 0;
}

/*Recebe o parâmetro d (distancia) e retorna o tempo (t)
necessário para Y se distanciar de X em d quilometros*/
void tempo_distanciar(int d, int t){
    if(d == 0){
        printf("%d minutos\n", t);
    }
    else{
        tempo_distanciar(d-1, t+2);
    }
}
