/* 
 * This is an implementation of the open-addressing hash table.
 * Author: Rui Ueyama, the author of A small C compiler chibicc
 * that implements most C11 features.
 * github page: https://github.com/rui314/chibicc
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>

#define INIT_SIZE 16        		/* init hash buckets size */
#define HIGH_WATERMARK 70   		/* rehash if the usage exceeds 70% */
#define LOW_WATERMARK  50   		/* keep the usage below 50% after rehash */
#define TOMBSTONE ((void *) -1) 	/* represents a deleted hash entry */

struct entry {
        char    *key;
        int     len;
        void    *val;
};

struct map {
        struct entry *buckets;
        int     cap;
        int     used;
};

void *hashmap_get(struct map *map, char *key);
void *hashmap_get2(struct map *map, char *key, int len);
void hashmap_put(struct map *map, char *key, void *val);
void hashmap_put2(struct map *map, char *key, int len, void *val);
void hashmap_delete(struct map *map, char *key);
void hashmap_delete2(struct map *map, char *key, int len);
void hashmap_remove(struct map *map);

char *format(char *fmt, ...);

