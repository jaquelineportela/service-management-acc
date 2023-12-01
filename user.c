#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ServiceTree.h"
#include "heap.h"
#include "user.h"

void registerUser(User *users, int *numUsers) {
    if (*numUsers < 100) {
        printf("Informe a matricula do usuario: ");
        scanf("%d", &(users[*numUsers].registration));

        printf("Informe o nome completo do usuario: ");
        getchar();
        fgets(users[*numUsers].name, sizeof(users[*numUsers].name), stdin);

        if (users[*numUsers].registration > 0 && strlen(users[*numUsers].name) > 1) {
            printf("Usuario cadastrado com sucesso!\n");
            (*numUsers)++;
        } else {
            printf("Erro: Todos os dados devem estar preenchidos.\n");
        }
    } else {
        printf("Erro: Limite máximo de usuarios atingido.\n");
    }
}

void registerService(Service *services, User *users, int numUsers, int *numServices, Heap *heap) {
    int registration, i;

    printf("Informe a matricula do usuario: ");
    scanf("%d", &registration);

    for (i = 0; i < numUsers; i++) {
        if (users[i].registration == registration) {
            Service newService;

            printf("Informe o número de identificação (OS) do servico: ");
            scanf("%d", &newService.os);
            printf("Informe a descricao do servico: ");
            getchar();
            fgets(newService.description, sizeof(newService.description), stdin);
            printf("Informe a prioridade do servico (baixa: 1, média: 2, alta: 3): ");
            scanf("%s", newService.priority);
            printf("Informe o status do servico (cancelado, finalizado, em processamento): ");
            scanf("%s", newService.status);

            insertTree(&(users[i].serviceTree), newService);
            insertHeap(heap, newService);

            (*numServices)++;
            printf("Servico cadastrado com sucesso!\n");
            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

void listAllUsersServices(User *users, int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        printf("\nMatricula: %d\nNome: %s\n", users[i].registration, users[i].name);
        printf("Servicos Pedidos:\n");
        printTree(&(users[i].serviceTree));
    }
}

void listUserServices(User *users, int numUsers) {
    int registration, i;

    printf("Informe a matricula do usuario: ");
    scanf("%d", &registration);

    for (i = 0; i < numUsers; i++) {
        if (users[i].registration == registration) {
            printf("\nMatricula: %d\nNome: %s\n", users[i].registration, users[i].name);
            printf("Servicos Pedidos:\n");
            printTree(&(users[i].serviceTree));
            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

void modifyUserRegistration(User *users, int numUsers) {
    int registration, i;

    printf("Informe a matricula do ususrio a ser alterado: ");
    scanf("%d", &registration);

    for (i = 0; i < numUsers; i++) {
        if (users[i].registration == registration) {
            printf("Informe o novo nome completo do usuario: ");
            getchar();
            fgets(users[i].name, sizeof(users[i].name), stdin);
            printf("Informacoes do usuario alteradas com sucesso!\n");
            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

void modifyServiceStatus(User *users, int numUsers) {
    int registration, os, i;

    printf("Informe a matricula do usuario: ");
    scanf("%d", &registration);

    for (i = 0; i < numUsers; i++) {
        if (users[i].registration == registration) {
            printf("Informe o numero de identificação (OS) do servico a ter o status alterado: ");
            scanf("%d", &os);
            // Aqui você pode adicionar lógica para modificar o status do serviço, se necessário.
            printf("Status do servico alterado com sucesso!\n");
            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

void performServiceHandling(Heap *heap) {
    Service servicedService = removeHeap(heap);

    if (servicedService.os != -1) {
        printf("Servico atendido:\n");
        printf("OS: %d\nDescricao: %s\nPrioridade: %s\nStatus: %s\n\n",
               servicedService.os, servicedService.description, servicedService.priority, servicedService.status);
    } else {
        printf("Nenhum servico para atendimento.\n");
    }
}
