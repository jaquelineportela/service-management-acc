#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"
#include "ServiceTree.h"
#include "user.h"

int main() {
    User users[100];
    int numUsers = 0;
    int numServices = 0;
    int option;
    Heap* heap = createHeap(100);

    // Main loop and menu options
   do {
        printf("\nMenu principal:\n");
        printf("1. Cadastrar usuario\n");
        printf("2. Cadastrar pedido de um servico\n");
        printf("3. Listar servicos de um usuario\n");
        printf("4. Alterar cadastro de um usuario\n");
        printf("5. Alterar status de um pedido\n");
        printf("6. Realizar atendimento de um pedido\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                registerUser(users, &numUsers);
                break;
            case 2:
                registerService(users, users, numUsers, &numServices, heap);
                break;
            case 3:
                listUserServices(users, numUsers);
                break;
            case 4:
                modifyUserRegistration(users, numUsers);
                break;
            case 5:
                modifyServiceStatus(users, numUsers);
                break;
            case 6:
                performServiceHandling(heap);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (option != 0);

    destroyHeap(heap);
    return 0;
}
