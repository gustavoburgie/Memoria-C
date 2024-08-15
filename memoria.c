#include <stdio.h>
#include <inttypes.h>

int main(){
    uint8_t tiny = 0xff;
    uint16_t small = 0xffff;
    uint32_t medium = 0xffffffff;
    uint64_t big = 0xffffffffffffffff;

    //%zu - unsigned long (retorno do operador sizeof())
    printf("Tamanho de tiny: %dbytes\n", sizeof(tiny));
    printf("Tamanho de small: %dbytes\n", sizeof(small));
    printf("Tamanho de medium: %dbytes\n", sizeof(medium));
    printf("Tamanho de big: %dbytes\n", sizeof(big));

    //Somando +1 ao medium...
    medium++;
    printf("medium: %d\n", medium);
    medium--;

    printf("\n");
    printf("Maior valor possível -\n");
    printf("tiny: %d\n", tiny);
    printf("small: %d\n", small);
    printf("medium: %zu\n", medium);
    printf("big: %zu\n", big);

    //Exemplo de problema com sinal
    for(char i = 0; i < 200; i++){
        printf("%d\n", i);
        if(i == -1)
        break;
    }

    // Ponto flutuante tem seus PROBLEMAS!
    float valor2 = 314000000;
    printf("%f\n", valor2);
    valor2 += 5.5;
    printf("%f\n", valor2);
    
}