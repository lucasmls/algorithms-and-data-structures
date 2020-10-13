#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash-table.h"
#include "../linked-list/linked-list.h"

/**
 * @brief Creates a new Hash Table. 
 */
hash_table_t *hash_table_create()
{
  hash_table_t *ht = malloc(hash_table_size);

  ht->length = 0;
  ht->capacity = 53;
  ht->buckets = calloc(ht->capacity, sizeof(hash_table_element_t *));

  return ht;
}

/**
 * Deletes the whole Hash Table from memory.
 * 
 * @param ht: the pointer to the Hash Table to be deleted.
 */
void hash_table_free(hash_table_t *ht)
{
  for (int i = 0; i < ht->length; i++)
  {
    hash_table_element_t *element = ht->buckets[i];
    if (element != NULL)
      hash_table_free_element(element);
  }

  free(ht->buckets);
  free(ht);
}

/**
 * Creates a new element to be placed into Hash Table
 * 
 * @param key: the Key that references a item
 * @param value: the Value of the item referenced by the key
 */
hash_table_element_t *hash_table_create_element(char *key, char *value)
{
  hash_table_element_t *element = malloc(hash_table_element_size);

  element->key = strdup(key);
  element->value = strdup(value);
  element->next = NULL;

  return element;
}

/**
 * Deletes a Hash Table element from memory
 * 
 * @param key: the pointer to the element to be deleted.
 */
void hash_table_free_element(hash_table_element_t *element)
{
  free(element);
}

/**
 * @brief Hashes a given key into a index.
 * 
 * @param ht: the pointer to the Hash Table.
 * @param key: the key to be hashed.
 */
unsigned int hash_table_hash(hash_table_t *ht, char *key)
{
  unsigned int const PRIME_NUMBER = 151;
  unsigned long hash = 0;

  const int key_length = strlen(key);
  for (int i = 0; i < key_length; i++)
  {
    hash += (long)pow(PRIME_NUMBER, key_length - (i + 1)) * key[i];
    hash = hash % ht->capacity;
  }

  return (int)hash;
}

/**
 * @brief Adds a new element into the Hash Table
 * 
 * @param ht: the pointer to the Hash Table.
 * @param key: the key that will be hashed and use to find the element.
 * @param value: the value that will be stored.
 */
int hash_table_put(hash_table_t *ht, char *key, char *value)
{
  int index = hash_table_hash(ht, key);

  // If there's none value in the bucket, simply adds a new element.
  if (ht->buckets[index] == NULL)
  {
    hash_table_element_t *element = hash_table_create_element(key, value);
    ht->buckets[index] = element;

    ht->length++;
    return 1;
  }

  // If there's some element in the bucket and the first element has the same
  // key we are trying to update, we simply update this element.
  if ((ht->buckets[index] != NULL) && (strcmp(ht->buckets[index]->key, key) == 0))
  {
    ht->buckets[index]->value = value;
    return 1;
  }

  // In case the there's some element into this index and the key we're trying to
  // create or update is not the first one, we loop through the linked list
  // until we can append the new element in the last position.

  hash_table_element_t *current_element = ht->buckets[index];
  while (current_element->next)
  {
    if (strcmp(current_element->key, key) == 0)
    {
      current_element->value = value;
      return 1;
    }

    current_element = current_element->next;
  }

  if (strcmp(current_element->key, key) == 0)
  {
    current_element->value = value;
    return 1;
  }

  hash_table_element_t *element = hash_table_create_element(key, value);
  current_element->next = element;

  ht->length++;
  return 1;
}

/**
 * @brief Get the element of the given key.
 * 
 * @param ht: the pointer to the Hash Table.
 * @param key: the element key.
 */
char *hash_table_get(hash_table_t *ht, char *key)
{
  int index = hash_table_hash(ht, key);

  hash_table_element_t *element = ht->buckets[index];

  if (element == NULL)
    return NULL;

  while (element != NULL)
  {
    if (strcmp(element->key, key) == 0)
    {
      return element->value;
    }

    element = element->next;
  }

  return NULL;
}

/**
 * @brief Deletes the element of the given key.
 * 
 * @param ht: the pointer to the Hash Table.
 * @param key: the element key.
 */
int hash_table_delete(hash_table_t *ht, char *key)
{
  int index = hash_table_hash(ht, key);
  hash_table_element_t *element = ht->buckets[index];

  if (element == NULL)
    return -1;

  // If the first element of the index is the element with the key we're trying to delete
  // and it does not have any other element ahead. We simply deletes it.
  if (strcmp(element->key, key) == 0 && element->next == NULL)
  {
    hash_table_free_element(element);
    ht->buckets[index] = NULL;

    ht->length--;
    return 1;
  }
  
  // If the first element of the index is the element with the key we're trying to delete
  // and it has a element ahead. We simply points up the next element to the first position
  // of the index and deletes the first one.
  if (strcmp(element->key, key) == 0)
  {
    ht->buckets[index] = element->next;
    hash_table_free_element(element);

    ht->length--;
    return 1;
  }

  // In case there's some element into this index and the key we're trying to
  // delete it's not the first one, we loop through the linked list
  // until we find the element that needs to be deleted.
  while (element->next != NULL)
  {
    hash_table_element_t *next_element = element->next;

    if (strcmp(next_element->key, key) == 0 && next_element->next == NULL)
    {
      element->next = NULL;
      hash_table_free_element(next_element);

      ht->length--;
      return 1;
    }

    if (strcmp(next_element->key, key) == 0)
    {
      element->next = next_element->next;
      hash_table_free_element(next_element);

      ht->length--;
      return 1;
    }

    element = element->next;
  }

  return -1;
}