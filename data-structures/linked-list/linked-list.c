#include <stdio.h>
#include <stdlib.h>

#include "linked-list.h"

/**
 * @brief Creates a linked list.
 */
linked_list_t linked_list_create()
{
  linked_list_t list;

  list.length = 0;
  list.head = NULL;
  list.tail = NULL;

  return list;
}

/**
 * @brief Inserts a node into the first position of the linked list.
 */
void linked_list_insert_first(linked_list_t *list, int value)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->value = value;

  if (list->length == 0)
  {
    new_node->next = NULL;
    new_node->previous = NULL;

    list->head = new_node;
    list->tail = new_node;

    list->length++;
    return;
  }

  new_node->next = list->head;

  list->head->previous = new_node;
  list->head = new_node;

  list->length++;
}

/**
 * @brief Inserts a node into the last position of the linked list.
 */
void linked_list_insert_last(linked_list_t *list, int value)
{
  if (list->length == 0)
  {
    linked_list_insert_first(list, value);
  }

  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  new_node->value = value;
  new_node->next = NULL;
  new_node->previous = list->tail;

  list->tail->next = new_node;
  list->tail = new_node;

  list->length++;
};

/**
 * @brief Returns if the specified position exists or not.
 */
int list_is_valid_position(linked_list_t *list, int position)
{
  return position >= 0 && position < list->length;
}

/**
 * @brief Inserts a node into a specific position of the linked list.
 */
void linked_list_insert(linked_list_t *list, int value, int position)
{
  if (!list_is_valid_position(list, position))
  {
    fprintf(stderr, "@linked_list_find: Index out of range.");
    exit(1);
  }

  if (position == 0)
  {
    linked_list_insert_first(list, value);
  }

  if (position == list->length - 1)
  {
    linked_list_insert_last(list, value);
  }

  struct node *previous_node = linked_list_find(list, position - 1);
  struct node *next_node = previous_node->next;

  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->value = value;

  new_node->next = next_node;
  new_node->previous = previous_node;

  previous_node->next = new_node;
  next_node->previous = new_node;

  list->length++;
}

/**
 * @brief Find the node in the specified position.
 */
struct node *linked_list_find(linked_list_t *list, int position)
{
  if (!list_is_valid_position(list, position))
  {
    fprintf(stderr, "@linked_list_find: Index out of range.");
    exit(1);
  }

  struct node *node = list->head;
  for (int i = 0; i < position; i++)
  {
    node = node->next;
  }

  return node;
};

/**
 * @brief Returns true of false if the specified value is included into the list.
 */
int linked_list_includes(linked_list_t *list, int value)
{
  struct node *node = list->head;

  while (node->next != NULL)
  {
    if (node->value == value)
    {
      return 1;
    }

    node = node->next;
  }

  return 0;
}

/**
 * @brief Removes the first node of the linked list.
 */
void linked_list_remove_first(linked_list_t *list)
{
  if (list->length == 0)
  {
    fprintf(stderr, "@linked_list_remove_first: The list is empty.");
    exit(1);
  }

  struct node *node = list->head;

  list->head = list->head->next;
  list->head->previous = NULL;

  list->length--;

  node->next = NULL;
  node->previous = NULL;
  free(node);

  if (list->length == 0)
  {
    list->tail = NULL;
  }
}

/**
 * @brief Removes the last node of the linked list.
 */
void linked_list_remove_last(linked_list_t *list)
{
  if (list->length == 0)
  {
    fprintf(stderr, "@linked_list_remove_first: The list is empty.");
    exit(1);
  }

  struct node *node = list->tail;

  struct node *penultimate_node = node->previous;
  penultimate_node->next = NULL;

  list->tail = penultimate_node;
  list->length--;

  node->next = NULL;
  node->previous = NULL;
  free(node);

  if (list->length == 0)
  {
    list->head = NULL;
  }
}

/**
 * @brief Removes the node in the specified position of the linked list.
 */
void linked_list_remove(linked_list_t *list, int position)
{
  if (position == 0)
  {
    linked_list_remove_first(list);
    return;
  }

  if (position == list->length - 1)
  {
    linked_list_remove_last(list);
    return;
  }

  struct node *node_to_remove = linked_list_find(list, position);
  struct node *previous_node = node_to_remove->previous;
  struct node *next_node = node_to_remove->next;

  previous_node->next = node_to_remove->next;
  next_node->previous = node_to_remove->previous;

  node_to_remove->next = NULL;
  node_to_remove->previous = NULL;
  free(node_to_remove);

  list->length--;
}

/**
 * @brief Returns the linked list size.
 */
int linked_list_length(linked_list_t *list)
{
  return list->length;
}

/**
 * @brief Prints the linked list.
 */
void linked_list_print(linked_list_t *list)
{
  struct node *pointer = list->head;

  while (pointer != NULL)
  {
    printf("%d ", pointer->value);
    pointer = pointer->next;
  }

  printf("\n");
};
