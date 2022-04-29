#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>

struct entry {
    char *key;
    int len;
    void *val;
};

struct map {
    struct entry *buckets;
    int cap;
    int used;
};

void *hashmap_get(struct map *map, char *key);
void *hashmap_get2(struct map *map, char *key, int len);
void hashmap_put(struct map *map, char *key, void *val);
void hashmap_put2(struct map *map, char *key, int len, void *val);
void hashmap_delete(struct map *map, char *key);
void hashmap_delete2(struct map *map, char *key, int len);
void hashmap_remove(struct map *map);

char *format(char *fmt, ...);
