/*
 * demo.c - HashMap Test Programı
 * 
 * hashtable.c'yi doldurun, sonra derleyin:
 * gcc -o demo demo.c
 */

#include "hashtable.c"

int main() {
    printf("=== HASHMAP TEST ===\n\n");
    
    // HashMap oluştur
    HashTable* map = ht_create(7);
    
    // Ekle
    printf("Ekleniyor...\n");
    ht_insert(map, 5, 50);
    ht_insert(map, 12, 120);
    ht_insert(map, 19, 190);  // 19 % 7 = 5 (collision!)
    ht_insert(map, 8, 80);
    
    ht_print(map);
    
    // Ara
    printf("\nArama...\n");
    int found;
    int value = ht_search(map, 12, &found);
    printf("key=12: %s (value=%d)\n", found ? "var" : "yok", value);
    
    // Güncelle
    printf("\nGüncelleme...\n");
    ht_insert(map, 12, 999);
    value = ht_search(map, 12, &found);
    printf("key=12 yeni değer: %d\n", value);
    
    // Sil
    printf("\nSilme...\n");
    ht_delete(map, 5);
    ht_print(map);
    
    // Temizle
    ht_destroy(map);
    printf("\nBitti.\n");
    
    return 0;
}
