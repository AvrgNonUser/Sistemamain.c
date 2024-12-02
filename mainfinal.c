#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    int opcion;
    do {
        printf("\n------------------------ Inventario de Viveres Chana -----------------------\n");
        printf("1. Agregar Producto\n");
        printf("2. Editar Producto\n");
        printf("3. Eliminar Producto\n");
        printf("4. Listar Productos\n");
        printf("5. Salir\n");
        printf("Por favor ingrese el numero de la opcion que desea realizar: ");
        scanf("%d", &opcion);
        getchar();  // Limpiar el salto de línea pendiente de scanf
        switch (opcion) {
            case 1: Registrar(); break;
            case 2: Edit(); break;
            case 3: Borrar(); break;
            case 4: Enliste(); break;
            case 5: printf("Saliendo del programa...\n"); break;
            default: printf("La opcion ingresada no es valida.\n"); break;
        }
    } while (opcion != 5);;
    return 0;
}
