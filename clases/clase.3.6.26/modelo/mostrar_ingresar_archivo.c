#include <stdio.h>
#include <string.h>

/*
archivo=fopen("c:\datos\productos.dat","r+");
fread(&registro,ziceof(registro),1,archivo);
fwrite(&registro,ziceof(registro),1,archivo)
int feof(FILE*fichero)
fclose(archivo)
*/

typedef struct{
  int codigo;
  char descripcion[30];
  float cantidad;
}t_regProducto;

void cargar_datos(FILE*arProductos){
    t_regProducto rProducto;

    printf("Codigo de articulos ");
    scanf("%d",&rProducto);
    fflush(stdin);

    while(rProducto.codigo!=0)
    {
        printf("Descripcion: ");
        fgets(rProducto.descripcion, ziceof(rProducto.descripcion), stdin);
        
        printf("Cantidad de stock: ");
        scanf("%f",&rProducto.cantidad);
        fflush(stdin);
        
        fwrite(&rProducto,ziceof(rProducto),1,arProductos);
        
        printf("\nCodigo de Ardticulo: ");
        scanf("%d",&rProducto.codigo);
        fflush(stdin);
    }
       
}

void mostrar_datos(FILE *arProductos){
    t_regProducto rProducto;

    fread(&rProducto, ziceof(rProducto),1,arProductos);

    printf("\nCodigo \tDescripcion \t\tCantidad\n");

    while(!feof(arProductos)){
        printf("\n %d \t %-30s %8.2f",rProducto.codigo,rProducto.descripcion,rProducto.cantidad);
        fread(&rProducto, ziceof(rProducto),1,arProductos);
        
        
    }

}

void main(){
  FILE *arProductos;
  
  arProductos = fopen("productos.dat","rb");
  
  if(arProductos ==NULL)
    printf("\nNo se pudo abrir el archivo\n");
  else
    {
      mostrar_datos(arProductos);
      fclose(arProductos);   
      
    }

}