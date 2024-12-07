/*O que é um ponteiro?
Um ponteiro é uma variável que armazena o endereço de memória de outra variável.
Ele pode ser usado para acessar e manipular os dados armazenados nesse endereço.

Declarando um ponteiros 
tipo *nome_ponteiro;

Como funcionam os ponteiros?
Uma variável normal armazena um valor.
Um ponteiro armazena o endereço de memória dessa variável.
Com o operador *, podemos acessar ou modificar o valor na memória apontada pelo ponteiro.
*/

#include <stdio.h>

int main() {
    int x = 42;
    int *ptr = &x;

    printf("Valor de x: %d\n", x);       // 42
    printf("Endereço de x: %p\n", &x);  // Endereço em hexadecimal
    printf("Valor em ptr: %p\n", ptr);  // Mesmo endereço de x
    printf("Valor apontado por ptr: %d\n", *ptr);  // 42

    *ptr = 100;  // Modifica x através do ponteiro
    printf("Novo valor de x: %d\n", x);  // 100

    return 0;
}

/*Analogia!
Ponteiro como um endereço de casa

Imagine que você tem uma casa (variável) com um número de endereço.
O ponteiro é como um papel onde está escrito o endereço dessa casa.
Se você quiser visitar a casa ou modificar algo nela, pode usar o endereço anotado no papel (o ponteiro).*/