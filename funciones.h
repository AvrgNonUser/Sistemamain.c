#include <stdio.h>
#include <string.h>
#define max 50
#define nom 50

char producto[max][nom];
int stock[max];
float precio[nom];
int Pnum = 0;

void Registrar() {
    if (Pnum >= max) {
        printf("¡¡¡Inventario lleno!!!\n");
        return;
    }
    printf("Ingrese el nombre del producto: ");
    gets(producto[Pnum]);
    printf("Ingrese la cantidad: ");
    scanf("%d", &stock[Pnum]);
    printf("Ingrese el precio: ");
    scanf("%f", &precio[Pnum]);
    Pnum++;
    printf("Producto agregado con éxito.\n");
}

void Edit() {
    char nombre[nom];
    printf("Ingrese el nombre del producto a editar: ");
    gets(nombre); 
    for (int i = 0; i < Pnum; i++) {
        if (strcmp(producto[i], nombre) == 0) {
            printf("Producto encontrado.\n Ingrese nueva cantidad: ");
            scanf("%d", &stock[i]);
            printf("Ingrese nuevo precio: ");
            scanf("%f", &precio[i]);
            printf("Producto editado con éxito.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void Borrar() {
    char nombre[nom];
    printf("Ingrese el nombre del producto a eliminar: ");
    gets(nombre); 
    for (int i = 0; i < Pnum; i++) {
        if (strcmp(producto[i], nombre) == 0) {
            for (int j = i; j < Pnum - 1; j++) {
                strcpy(producto[j], producto[j + 1]);
                stock[j] = stock[j + 1];
                precio[j] = precio[j + 1];
            }
            Pnum--;
            printf("Producto eliminado con éxito.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}
void Enliste() {
    if (Pnum == 0) {
        printf("¡¡¡Inventario vacio!!!\n");
        return;
    }
    printf("Inventario:\n");
    for (int i = 0; i < Pnum; i++) {
        printf("%d. %s - Cantidad: %d - Precio: %.2f\n", i + 1, producto[i], stock[i], precio[i]);
    }
}

