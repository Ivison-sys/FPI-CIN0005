// Question name: Dudinha's password
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n; 
    scanf("%d", &n);

    char final[300] = {0};
    char final1[300] = {0};
    char final2[300] = {0};
    int inF = 0;
    // Gerando a string resultante das concatena��es do entradas
    for(int i= 0; i < n; i++){
        char inp[13];
        char sen;
        scanf(" %c %12s", &sen, inp);
        if(sen == 'd'){
            for(int z= 0; z < 6; z++){
                final[inF] = inp[z];
                inF++;
            }
        }
        else if(sen == 'e'){
            for(int z= 11; z >= 6; z--){
                final[inF] = inp[z];
                inF++;
            }
        }
    }

    char palavraAlvo[300];
    scanf(" %299s", palavraAlvo);
    int t = strlen(palavraAlvo);
    // Duplicando a strings para simular um giro
    int a = 0;
    for(int i = 0; final[i]; i++){
        final1[a] = final[i];
        a++;
    }
    for(int i = 0; i < t-1; i++){
        final1[a] = final[i];
        a++;
    }
    final1[a] = '\0';
    
    // Criando uma final invertida
    int b = 0;
    for(int i = a-1; i >= 0; i--){
        final2[b] = final1[i];
        b++;
    }
    final2[b] = '\0';
    
    int reps = 0, x = 0;
    char aux[300] = {0};
    for(int i= 0; final1[i]; ){
        if(x == t){
            x = 0;
            if(strcmp(aux, palavraAlvo) == 0){
                reps++;
            }
            strcpy(aux, "");
            i++;
        }
        else{
            int len = strlen(aux);
            aux[x] = final1[i+x];
            x++;
            
        }
    }

    x = 0;
    for(int i= 0; final2[i]; ){
        if(x == t){
            x = 0;
            if(strcmp(aux, palavraAlvo) == 0){
                reps++;
            }
            strcpy(aux, "");
            i++;
        }
        else{
            int len = strlen(aux);
            aux[x] = final2[i+x];
            x++;
            
        }
    }

    printf("%s%d", palavraAlvo,reps);
    
    return 0;
}