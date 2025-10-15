# Inventario de Tienda

Este programa implementa un sistema de inventario para una tienda pequeña usando **listas enlazadas simples en C**.  
Permite gestionar productos con operaciones básicas como insertar, buscar, actualizar, eliminar y listar, todo a través de un menú interactivo en consola.

## Cómo compilar y ejecutar

Para compilar y ejecutar el programa en C, sigue estos pasos:

1. Abre una terminal en la carpeta raíz del proyecto (`src`).

2. Compila los archivos fuente con el compilador **gcc**:

   ```bash
   gcc src/main.c src/inventory.c -o inventario

3. Ejecutar el programa

   ```bash
   ./inventario

Esto generará un ejecutable que mostrará los resultados del programa.

## Operaciones Implementadas

- **Insertar al inicio:** Agrega un nuevo producto como primer nodo de la lista.

- **Insertar al final:** Recorre la lista hasta el último nodo y añade el producto allí.

- **Buscar por ID:** Recorre la lista hasta encontrar el producto con el ID indicado y muestra sus datos.

- **Actualizar stock:** Modifica la cantidad disponible de un producto existente.

- **Eliminar producto:** Elimina un nodo de la lista según el ID ingresado.

- **Listar inventario:** Muestra todos los productos en el orden actual de la lista.

## Ejemplos de Uso
- **Insertar un producto al inicio**
```bash
        --- Menú Inventario ---
    Opción: 1
    ID: 101
    Nombre: Arroz blanco
    Stock: 50
```

- **Insertar un producto al final**
```bash
    --- Menú Inventario ---
    Opción: 2
    ID: 102
    Nombre: Aceite vegetal
    Stock: 20
```

- **Listar inventario**
```bash
--- Menú Inventario ---
    Opción: 6

    Inventario:
    ID: 101 | Nombre: Arroz blanco | Stock: 50
    ID: 102 | Nombre: Aceite vegetal | Stock: 20
```

- **Buscar producto por ID**
```bash
    --- Menú Inventario ---
    Opción: 3
    ID a buscar: 101
    Producto encontrado: Arroz blanco, Stock: 50
```

- **Actualizar stock**
```bash
    --- Menú Inventario ---
    Opción: 4
    ID a actualizar: 101
    Nuevo stock: 60
    Stock actualizado.
```

- **Eliminar producto**
```bash
    --- Menú Inventario ---
    Opción: 5
    ID a eliminar: 102
    Producto eliminado.
```

- **Listar inventario**
```bash
    --- Menú Inventario ---
    Opción: 6

    Inventario:
    ID: 101 | Nombre: Arroz blanco | Stock: 60
```

##  Estructura del producto

Cada producto se representa como un nodo en la lista:

```c
struct Node {
    int id;            // Identificador único del producto
    char name[40];     // Nombre del producto (máx. 39 caracteres + '\0')
    int stock;         // Cantidad disponible en inventario
    struct Node* next; // Apuntador al siguiente nodo
};
