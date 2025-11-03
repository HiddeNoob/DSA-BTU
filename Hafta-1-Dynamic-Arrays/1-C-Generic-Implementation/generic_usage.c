#include <stdio.h>
#include <stdlib.h>
#include "generic_dynarray.c"

void intElemanSil(void* data){
    free(data);
}

int main(){
    DynArray* array = createArray(intElemanSil);
    
    int* eleman = (int*)malloc(sizeof(int));
    int* eleman1 = (int*)malloc(sizeof(int));
    int* eleman2 = (int*)malloc(sizeof(int));

    *eleman = 1;
    *eleman1 = 2;
    *eleman2 = 3;
        
    append(array,eleman);
    append(array,eleman1);
    append(array,eleman2);

    void* ilk_elaman = get(array,0);
    int gercek_ilk_elaman = *((int*)ilk_elaman);

    printf("%d,",gercek_ilk_elaman);
    printf("%d,",*(int*)get(array,1));
    printf("%d,",*(int*)get(array,2));

    deleteArray(array);

    return 0;
}