#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

// Inserta un nuevo producto al inicio de la lista
void insertAtBeginning(struct Node** head, int id, char name[], int stock) {
    struct Node* newNode = malloc(sizeof(struct Node)); // Reserva memoria
    newNode->id = id;
    strcpy(newNode->name, name); // Copia el nombre
    newNode->stock = stock;
    newNode->next = *head;       // Apunta al anterior primer nodo
    *head = newNode;             // Nuevo nodo se convierte en la cabeza
}

// Inserta un nuevo producto al final de la lista
void insertAtEnd(struct Node** head, int id, char name[], int stock) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->stock = stock;
    newNode->next = NULL;        // Será el último nodo

    if (*head == NULL) {
        *head = newNode;         // Si la lista está vacía, se convierte en cabeza
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) // Recorre hasta el último nodo
            temp = temp->next;
        temp->next = newNode;    // Lo agrega al final
    }
}

// Busca un producto por ID y retorna el nodo si lo encuentra
struct Node* searchById(struct Node* head, int id) {
    while (head != NULL) {
        if (head->id == id)
            return head;         // Producto encontrado
        head = head->next;
    }
    return NULL;                 // No encontrado
}

// Actualiza el stock de un producto por ID
int updateStock(struct Node* head, int id, int newStock) {
    struct Node* product = searchById(head, id);
    if (product != NULL) {
        product->stock = newStock;
        return 1;                // Actualización exitosa
    }
    return 0;                    // Producto no encontrado
}

// Menú principal que permite al usuario interactuar con el inventario
void menu() {
    struct Node* inventory = NULL; // Lista vacía al inicio
    int option, id, stock;
    char name[40];

    do {
        // Muestra opciones
        printf("\n--- Menú Inventario ---\n");
        printf("1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Buscar por ID\n");
        printf("4. Actualizar stock\n");
        printf("5. Eliminar producto\n");
        printf("6. Listar inventario\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Inserta al inicio
                printf("ID: "); scanf("%d", &id);
                printf("Nombre: "); scanf(" %[^\n]", name);
                printf("Stock: "); scanf("%d", &stock);
                insertAtBeginning(&inventory, id, name, stock);
                break;
            case 2:
                // Inserta al final
                printf("ID: "); scanf("%d", &id);
                printf("Nombre: "); scanf(" %[^\n]", name);
                printf("Stock: "); scanf("%d", &stock);
                insertAtEnd(&inventory, id, name, stock);
                break;
            case 3: {
                // Busca por ID
                printf("ID a buscar: "); scanf("%d", &id);
                struct Node* found = searchById(inventory, id);
                if (found)
                    printf("Producto encontrado: %s, Stock: %d\n", found->name, found->stock);
                else
                    printf("Producto no encontrado.\n");
                break;
            }
            case 4:
                // Actualiza stock
                printf("ID a actualizar: "); scanf("%d", &id);
                printf("Nuevo stock: "); scanf("%d", &stock);
                if (updateStock(inventory, id, stock))
                    printf("Stock actualizado.\n");
                else
                    printf("Producto no encontrado.\n");
                break;
            case 5:
                // Elimina producto
                printf("ID a eliminar: "); scanf("%d", &id);
                if (deleteById(&inventory, id))
                    printf("Producto eliminado.\n");
                else
                    printf("Producto no encontrado.\n");
                break;
            case 6:
                // Lista inventario
                listInventory(inventory);
                break;
            case 0:
                // Salir del programa
                printf("Saliendo del programa...\n");
                break;
            default:
                // Opción inválida
                printf("Opción inválida. Intenta de nuevo.\n");
        }
    } while (option != 0);
}
