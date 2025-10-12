#ifndef INVENTORY_H
#define INVENTORY_H

// Estructura que representa un producto en el inventario
struct Node {
    int id;                 // Identificador único del producto
    char name[40];          // Nombre del producto (máximo 39 caracteres)
    int stock;              // Cantidad disponible en inventario
    struct Node* next;      // Apuntador al siguiente nodo (producto)
};

// Muestra el menú principal y gestiona las opciones
void menu();

#endif
