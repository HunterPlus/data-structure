#include "c.h"

void hashmap_test(struct map *map) 
{
        for (int i = 0; i < 5000; i++)
            hashmap_put(map, format("key %d", i), (void *)(size_t)i);
        for (int i = 1000; i < 2000; i++)
            hashmap_delete(map, format("key %d", i));
        for (int i = 1500; i < 1600; i++)
            hashmap_put(map, format("key %d", i), (void *)(size_t)i);
        for (int i = 6000; i < 7000; i++)
            hashmap_put(map, format("key %d", i), (void *)(size_t)i);

        for (int i = 0; i < 1000; i++)
            assert((size_t)hashmap_get(map, format("key %d", i)) == i);
        for (int i = 1000; i < 1500; i++)
            assert(hashmap_get(map, "no such key") == NULL);
        for (int i = 1500; i < 1600; i++)
            assert((size_t)hashmap_get(map, format("key %d", i)) == i);
        for (int i = 1600; i < 2000; i++)
            assert(hashmap_get(map, "no such key") == NULL);
        for (int i = 2000; i < 5000; i++)
            assert((size_t)hashmap_get(map, format("key %d", i)) == i);
        for (int i = 5000; i < 6000; i++)
            assert(hashmap_get(map, "no such key") == NULL);
        for (int i = 6000; i < 7000; i++)
            hashmap_put(map, format("key %d", i), (void *)(size_t)i);

        assert(hashmap_get(map, "no such key") == NULL);
        printf("OK\n");
}

int main()
{
        struct map *map = calloc(1, sizeof(struct map));
    
        hashmap_test(map);
    
        for (int i = 6000; i < 6010; i++) 
            printf("%ld\n", (long)hashmap_get(map, format("key %d", i)));
    
        free(map);
   
        return 0;
}
