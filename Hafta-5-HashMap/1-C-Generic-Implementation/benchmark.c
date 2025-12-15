#include "hashtable.c" 
#include "time.h"
#include "stdlib.h"
#include "stdio.h"



int main(){
    HashTable* table = HashTableConstructor();
    srand(time(NULL));

    const int max_key = 100;

    for(int i = 0; i < 1e7 ; i++){
        
        int* key = (int*)malloc(sizeof(int));
        *key = rand() % max_key;

        int* count = (int*)get(table,key);


        if(count == NULL){ // 100
            int* newCount = (int*)malloc(sizeof(int));
            *newCount = 1;
            insert(table,*key,newCount); // 100 : 1

        }else{
            (*count) = *count + 1;
        }
    }
    
    clock_t start = clock();
    for(int i = 0; i < 1e8 ; i++){

        int aranan = rand() % max_key;

        int* data = (int*)get(table, &aranan); // O(1)
        if(data != NULL){
            //printf("%d : %d\n",i,*data);
        }else{
            //printf("%d : NULL\n",i);
        }
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Search time: %f seconds\n", time_taken);

}