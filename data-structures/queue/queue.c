#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/**
 * @brief Creates a new Queue.
 */
_queue_t queue_create(int capacity)
{
  _queue_t queue;

  queue.capacity = capacity;
  queue.data = malloc(capacity * sizeof(int));
  queue.size = 0;
  queue.front = 0;
  queue.rear = 0;

  return queue;
}

/**
 * @brief Adds a new item to the last position of the Queue.
 */
void queue_enqueue(_queue_t *queue, int item)
{
  if (queue_is_full(queue))
  {
    fprintf(stderr, "@queue_enqueue: The queue is full.");
    exit(1);
  }

  queue->size++;
  queue->data[queue->rear] = item;
  queue->rear = queue_calc_next_rear(queue);
}

/**
 * @brief Removes the top item of the Queue.
 */
int queue_dequeue(_queue_t *queue)
{
  if (queue_is_empty(queue))
  {
    fprintf(stderr, "@queue_dequeue: The queue is empty.");
    exit(1);
  }

  int item = queue->data[queue->front];

  queue->size--;
  queue->front = queue_calc_next_front(queue);

  return item;
}

/**
 * @brief Take a peek in to the top most item of the Queue but do not dequeue it.
 */
int queue_peek(_queue_t *queue)
{
  if (queue_is_empty(queue))
  {
    fprintf(stderr, "@queue_dequeue: The queue is empty.");
    exit(1);
  }

  int item = queue->data[queue->front];
  return item;
};

/**
 * @brief Destroys the Queue.
 */
void queue_destroy(_queue_t *queue)
{
  free(queue->data);
  queue = NULL;
}

/**
 * @brief Check if the queue is empty.
 */
int queue_is_empty(_queue_t *queue)
{
  return queue->size == 0;
}

/**
 * @brief Check if the queue is full.
 */
int queue_is_full(_queue_t *queue)
{
  return queue->size == queue->capacity;
}

/**
 * @brief "Calculates" the next front position.
 */
int queue_calc_next_front(_queue_t *queue)
{
  return (queue->front + 1 < queue->capacity)
             ? queue->front + 1
             : 0;
}

/**
 * @brief "Calculates" the next rear position.
 */
int queue_calc_next_rear(_queue_t *queue)
{
  return (queue->rear + 1 < queue->capacity)
             ? queue->rear + 1
             : 0;
}
