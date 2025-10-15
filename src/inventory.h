#ifndef INVENTORY_H
#define INVENTORY_H

// Estructura que representa un producto en el inventario
struct Node {
    int id;                 // Identificador único del producto
    char name[40];          // Nombre del producto (máximo 39 caracteres + '\0')
    int stock;              // Cantidad disponible en inventario
    struct Node* next;      // Apuntador al siguiente nodo (producto)
};

// Declaración de funciones que se implementan en inventory.c

// Inserta un producto al inicio de la lista
void insertAtBeginning(struct Node** head, int id, char name[], int stock);

// Inserta un producto al final de la lista
void insertAtEnd(struct Node** head, int id, char name[], int stock);

// Busca un producto por su ID
struct Node* searchById(struct Node* head, int id);

// Actualiza el stock de un producto por su ID
int updateStock(struct Node* head, int id, int newStock);

// Elimina un producto por su ID
int deleteById(struct Node** head, int id);

// Muestra todos los productos del inventario
void listInventory(struct Node* head);

// Muestra el menú principal y gestiona las opciones
void menu();

#endif