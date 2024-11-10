#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct produto
{
    char nome[30];
    int quantidade;
};

typedef struct produto produto; // alterando o nome de 'struct produto' para 'produto'

int menu(){
    int opcao;
    printf("\n===== Sistema de Controle de Estoque =====\n");
    printf("1 - Adicionar Produto\n");
    printf("2 - Retirar Produto\n");
    printf("3 - Consultar Estoque\n");
    printf("4 Sair\n");
    printf("Esolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}
int main(){
    setlocale(LC_ALL,"portuguese");
    produto estoque[10]; //vareável estoque do tipo produto, array para armazenar produtos, lembrar!
    int numProdutos = 0; //Numero de produtos
    int opcao;

// iniciando o loop
    while(1){
        opcao = menu(); // Chamando o menu, lembrar variável opcao deve ser iniciada no main.

        if(opcao == 1){
            if(numProdutos <10){ // verificar se ainda há espaço no estoque
                printf("Digite o nome do produto: ");
                scanf("%s", estoque[numProdutos].nome);
                printf("Digite a quantidade: ");
                scanf("%d", &estoque[numProdutos].quantidade);
                numProdutos ++;
            } else{
                printf("Estoque cheio! Não é possível adicionar mais produtos. \n");
            }
        
        }else if (opcao == 2) { // Retirar Produto
            int produtoIndex, quantidade;
            printf("Digite o número do produto para retirar (0 a %d): ", numProdutos -1);
            scanf("%d", &produtoIndex);

            //Verficiar se o Indece do produto é Valido
            if(produtoIndex >= 0 && produtoIndex < numProdutos) { // Operador 'E ou and'= &&
                printf("Quantidade a retirar de %s: ", estoque[produtoIndex].nome);
                scanf("%d", &quantidade);
                    //verifica se há quantidade suficiente em estoque
                if (estoque[produtoIndex].quantidade >=quantidade){
                    estoque[produtoIndex].quantidade -= quantidade; //atulizando a quantidade
                    printf("Retirada realizad com sucesso!\n");
                }else{
                    printf("Quantidade insuficiente em estoque!\n");
                    }   
            
            }else{
                    printf("Produto não encontrado!\n");
                    }       
        
        }else if(opcao == 3) { // consulta de estoque mostra todo o estoque ao usuário
            printf("\n===== Estoque Atual =====\n");
            for (int i = 0; i < numProdutos; i++){
                printf("Produto: %s - Quantidade: %d\n", estoque[i].nome, estoque[i].quantidade);
            }
        }else if(opcao == 4){
            printf("Saindo do Programa...\n");
            break;
        }else{
            printf("Opção invalida");
        }
    }
    return 0;
}