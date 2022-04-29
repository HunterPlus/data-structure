#include "c.h"

static uint64_t fnv_hash(char *s, int len)
{
  	uint64_t hash = 0xcbf29ce484222325;
    
    	for (int i = 0; i < len; i++) {
        	hash *= 0x100000001b3;
        	hash ^= (unsigned char) s[i];
    	}
    	return hash;
}

static void rehash(struct map *map) 
{
    	int nkeys = 0;
    	for (int i = 0; i < map->cap; i++) 
        	if (map->buckets[i].key && map->buckets[i].key != TOMBSTONE)
            		nkeys++;
    
    	int cap = map->cap;
    	while ((nkeys * 100) / cap >= LOW_WATERMARK)
        	cap *= 2;
    	assert(cap > 0);
    
    	struct map map2 = {};
    	map2.buckets = calloc(cap, sizeof(struct entry));
    	map2.cap = cap;
    
    	for (int i = 0; i < map->cap; i++) {
        	struct entry *ent = map->buckets + i;
        	if (ent->key && ent->key != TOMBSTONE)
            		hashmap_put2(&map2, ent->key, ent->len, ent->val);
    	}
    	assert(map2.used == nkeys);
    	free(map->buckets);
    	*map = map2;
}

static int match(struct entry *ent, char *key, int len)
{
    	return ent->key && ent->key != TOMBSTONE &&
            	ent->len == len && memcmp(ent->key, key, len) == 0;
}

static struct entry *get_entry(struct map *map, char *key, int len)
{
    	if (!map->buckets)
        	return NULL;
        
    	uint64_t hash = fnv_hash(key, len);
    
    	for (int i = 0; i < map->cap; i++) {
        	struct entry *ent = &map->buckets[(hash + i) % map->cap];
        	if (match(ent, key, len))
            		return ent;
        	if (ent->key == NULL)
            		return NULL;
    	}
    	assert(0);
}

static struct entry *get_or_insert_entry(struct map *map, char *key, int len) {
    	if (!map->buckets) {
        	map->buckets = calloc(INIT_SIZE, sizeof(struct entry));
        	map->cap = INIT_SIZE;
    	} else if ((map->used * 100) / map->cap >= HIGH_WATERMARK) 
        	rehash(map);
    
    	uint64_t hash = fnv_hash(key, len);
    
    	for (int i = 0; i < map->cap; i++) {
        	struct entry *ent = map->buckets + (hash + i) % map->cap;
        
        	if (match(ent, key, len))
            		return ent;
        	if (ent->key == TOMBSTONE) {
            		ent->key = key;
            		ent->len = len;
            		return ent;
        	}
        	if (ent->key == NULL) {
            		ent->key = key;
            		ent->len = len;
            		map->used++;
            		return ent;
        	}
    	}
    	assert(0);
}

void *hashmap_get(struct map *map, char *key)
{
    	return hashmap_get2(map, key, strlen(key));
}

void *hashmap_get2(struct map *map, char *key, int len)
{
    	struct entry *ent = get_entry(map, key, len);
    	return ent ? ent->val : NULL;
}

void hashmap_put(struct map *map, char *key, void *val)
{
    	hashmap_put2(map, key, strlen(key), val);
}

void hashmap_put2(struct map *map, char *key, int len, void *val)
{
    	struct entry *ent = get_or_insert_entry(map, key, len);
    	ent->val = val;
}

void hashmap_delete(struct map *map, char *key)
{
    	hashmap_delete2(map, key, strlen(key));
}

void hashmap_delete2(struct map *map, char *key, int len)
{
    	struct entry *ent = get_entry(map, key, len);
    	if (ent)
        	ent->key = TOMBSTONE;
}

void hashmap_remove(struct map *map)
{
    	if (map) {
        	if (map->buckets)
            		free(map->buckets);
        	free(map);
    	}
}

char *format(char *fmt, ...)
{
    	char 	*buf;
    	size_t 	buflen;
    	FILE *out = open_memstream(&buf, &buflen);
    
    	va_list ap;
    	va_start(ap, fmt);
    	vfprintf(out, fmt, ap);
    	va_end(ap);
    	fclose(out);
    	return buf;
}
