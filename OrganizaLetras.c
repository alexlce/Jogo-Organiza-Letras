#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
#define MAX 10
    int dificuldade,i,aux=0,k,b,vet[MAX]={0,0,0,0,0},c=0;
        printf("Selecione a dificuldade \n Digite 1 para dificuldade facil \n Digite 2 para dificuldade media \n Digite 3 para dificuldade dificil ");
        scanf("%d",&dificuldade);
        //SWITCH CASE PARA SELECIONAR A DIFICULDADE OU SEJA  QUAL SERA O INTERVALO DE LETRAS GERADAS NA FUN��O RAND
        switch (dificuldade){
            case 1: c=6;  break;
            case 2: c=16; break;
            case 3: c=26; break;
        }
    //SRAND PARA GERAR A SEMENTE DA LETRA A PARTIR DO TEMPO DE EXECU��O DO PORGRAMA
    srand(time(NULL));
    //LA�O PARA RODAS OS 10 TURNOS DO JOGO
    for(i=0;i<MAX;i++){
        //FUN��O ONDE VAI SER GERADA A LETRA DEPENDENDO DA DIFICULDADE REALIZADA C PASSA A VALER DIFERENTES VALORES
        b = 65+ ( rand()% c);
        printf("\nA letra gerada e %c",b);
       //LEITURA DA POSI��O QUE QUERO COLOCAR A LETRA GERADA
        printf("\nDigite a posi��o que voce quer colocar a letra ");
        scanf("%d",&aux);
        //AQUI SE O VETOR AUXILIA FOR DIFERENTE DE 0 OU SEJA J� ESTIVER PREENCHIDO POR ALGUM VALOR VOCE PERDERA O JOGO
        if(vet[aux]!=0){
            printf("Voce perdeu esta posicao ja estava preenchida");
            break;
        }
        //K PASSA A VALER A POSI��O QUE DESEJO COLOCAR A LETRA
        k=aux;
        //VETOR DA POSI��O QUE DESEJO COLOCAR A LETRA RECEBE A LETRA GERADA
        vet[aux]=b;
        //VET DE K RECEBE A LETRA GERADA
        vet[k]=vet[aux];
        //PERCORRE MEU VETOR DO INICIO ATE A POSI��O QUE QUERO COLOCAR A ATUAL LETRA GERADA
        for(k=0;k<aux;k++){
           //SE A MINHA LETRA ATUAL NA POSI��O ATUAL FOR MENOR QUE QUALQUER LETRA ANTERIOR EU PERCO O JOGO
            if(vet[aux]<vet[k]){
                    printf("YOU LOSE");
                    exit(0);
            }
        }
     //AQUI PERCORRO O VETOR DO FINAL ATE A POSI��O QUE QUERO COLOCAR A LETRA ATUAL
        for(k=MAX-1;k>aux;k--){
            //IGNORA AS POSI��ES VAZIAS DO VETOR OU SEJA QUE EST�O PREENCHIDAS COM 0
            if(vet[k]!=0){
                //SE MINHA LETRRA NA POSI��O ATUAL FOR MAIOR QUE AS LETRAS NAS POSI��ES POSTERIORES A ELA EU PERCO O JOGO
                if(vet[aux]>vet[k]){
                    printf("YOU LOSE");
                    exit(0);
                }
            }
        }
         //NESSE LA�O EU GERO MEU TABULEIRO A CADA RODADA
         for(k=0;k<MAX;k++){
                printf("\nA posicao %d esta preenchida com %c",k,vet[k]);
         }
     }
     //ENTRA AQUI APENAS QUANDO COMPLETO O JOGO SEM ENTRAR NAS OCASIOES DE DERROTA ACIMA
     printf("\nCONGRATULATIONS YOU WIN");
}

























