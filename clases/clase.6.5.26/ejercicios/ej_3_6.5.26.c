
/* vector con valores numericos y maximo logico
    retornar maximo valor almacenado y su posicion*/

void return_max_pos(int vec[], int ml, int *max, int *pos){
    int i;

    for(i=0;i<ml;i++){
        if(vec[i]>*max){
            *max = vec[i];
            *pos = vec[i];
        }
    }
}