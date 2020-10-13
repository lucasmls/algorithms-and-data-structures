#ifndef __HASH_TABLE__
#define __HASH_TABLE__

typedef struct hash_table_element hash_table_element_t;

/**
 * @brief Is the element that is stored into the Hash Table.
 */
struct hash_table_element
{
  /**
   * The hashed key that maps to the item.
   */
  char *key;

  /**
   * Pointer to the element value.
   */
  char *value;

  /**
   * The next chained element for this key.
   * Used to deal with colision.
   */
  hash_table_element_t * next;
};

/**
 * @brief The size that a single element occupy in memory.
 */
#define hash_table_element_size sizeof(hash_table_element_t)

/**
 * Creates a new element to be placed into Hash Table
 * 
 * @param key: the Key that references a item
 * @param value: the Value of the element referenced by the key
 */
hash_table_element_t *hash_table_create_element(char *key, char *value);

/**
 * Deletes a Hash Table element from memory
 * 
 * @param key: the pointer to the element to be deleted.
 */
void hash_table_free_element(hash_table_element_t *element);

/**
 * @brief Is the struct that holds all of the needed infos about the Hash Table. 
 */
typedef struct hash_table
{
  /**
   * The Hash Table array where all the values is stored.
   */
  hash_table_element_t **buckets;

  /**
   * It's how much keys the Hash Table can store.
   */
  int capacity;

  /**
   * It's the count of how much keys the Hash Tabler contains stored.
   */
  int length;
} hash_table_t;

#define hash_table_size sizeof(hash_table_t)

/**
 * @brief Creates a new Hash Table. 
 */
hash_table_t *hash_table_create();

/**
 * Deletes the whole Hash Table from memory.
 * 
 * @param ht: the pointer to the Hash Table to be deleted.
 */
void hash_table_free(hash_table_t *ht);

/**
 * @brief Hashes a given key into a index.
 * 
 * @param ht: the pointer to the Hash Table.
 * @param key: the key to be hashed.
 */
unsigned int hash_table_hash(hash_table_t *ht, char *key);

/**
 * @brief Adds a new element into the Hash Table.
 * 
 * @param ht: the pointer to the Hash Table.
 * @param key: the key that will be hashed and use to find the element.
 * @param value: the value that will be stored.
 */
int hash_table_put(hash_table_t *ht, char *key, char *value);

/**
 * @brief Get the element of the given key.
 * 
 * @param ht: the pointer to the Hash Table.
 * @param key: the element key.
 */
char *hash_table_get(hash_table_t *ht, char *key);

/**
 * @brief Deletes the element of the given key.
 * 
 * @param ht: the pointer to the Hash Table.
 * @param key: the element key.
 */
int hash_table_delete(hash_table_t *ht, char *key);

#endif