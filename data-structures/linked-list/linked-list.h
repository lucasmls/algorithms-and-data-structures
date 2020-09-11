#ifndef __LINKED_LIST__
#define __LINKED_LIST__

/**
 * @brief Node is the item itself of a linked list.
 */
typedef struct node
{
  int value;
  struct node *next;
  struct node *previous;
} node;

/**
 * @brief LinkedList is the struct that holds the references to the list.
 * @param length is the total of elements that are included in the linked list.
 * @param head is the reference to the first item of the linked list.
 * @param tail is the reference to the last item of the linked list.
 */
typedef struct LinkedList
{
  int length;
  node *head;
  node *tail;
} linked_list_t;

/**
 * @brief Creates a linked list.
 */
linked_list_t linked_list_create();

/**
 * @brief Inserts a node into the first position of the linked list.
 */
void linked_list_insert_first(linked_list_t *list, int value);

/**
 * @brief Inserts a node into the last position of the linked list.
 */
void linked_list_insert_last(linked_list_t *list, int value);

/**
 * @brief Inserts a node into a specific position of the linked list.
 */
void linked_list_insert(linked_list_t *list, int value, int position);

/**
 * @brief Find the node in the specified position.
 */
struct node* linked_list_find(linked_list_t *list, int position);

/**
 * @brief Returns true of false if the specified value is included into the list.
 */
int linked_list_includes(linked_list_t *list, int value);

/**
 * @brief Removes the first node of the linked list.
 */
void linked_list_remove_first(linked_list_t *list);

/**
 * @brief Removes the last node of the linked list.
 */
void linked_list_remove_last(linked_list_t *list);

/**
 * @brief Removes the node in the specified position of the linked list.
 */
void linked_list_remove(linked_list_t *list, int position);

/**
 * @brief Returns the linked list size.
 */
int linked_list_length(linked_list_t *list);

/**
 * @brief Prints the linked list.
 */
void linked_list_print(linked_list_t *list);

#endif