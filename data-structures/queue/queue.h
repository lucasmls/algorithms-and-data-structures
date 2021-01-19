#ifndef QUEUE_H
#define QUEUE_H

/**
 * @brief Queue is a linear data structure which follows a particular order in which the operations are performed.
 *        The order is First In First Out (FIFO).
 *        A good example of a queue is any queue of consumers for a resource where the consumer that came first is served first.
 *        The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added.
 * 
 * @param front index to the front item of the Queue (the one that will be dequeued when needed)
 * @param rear index to the last item of the Queue (the last one that will be dequeed when needed)
 * @param size the quantity of items that are in the Queue
 * @param capacity the maximum capacity of items that the Queue can hold
 * @param data is the array that holds the Queue items
 */
typedef struct Queue
{
  int front;
  int rear;
  int size;
  int capacity;
  int *data;
} _queue_t;

/**
 * @brief Creates a new Queue.
 */
_queue_t queue_create(int capacity);

/**
 * @brief Adds a new item to the last position of the Queue.
 */
void queue_enqueue(_queue_t *queue, int item);

/**
 * @brief Removes the top item of the Queue.
 */
int queue_dequeue(_queue_t *queue);

/**
 * @brief Take a peek in to the top most item of the Queue but do not dequeue it.
 */
int queue_peek(_queue_t *queue);

/**
 * @brief Destroys the Queue.
 */
void queue_destroy(_queue_t *queue);

/**
 * @brief Check if the queue is empty.
 */
int queue_is_empty(_queue_t *queue);

/**
 * @brief Check if the queue is full.
 */
int queue_is_full(_queue_t *queue);

/**
 * @brief "Calculates" the next front position.
 */
int queue_calc_next_front(_queue_t *queue);

/**
 * @brief "Calculates" the next rear position.
 */
int queue_calc_next_rear(_queue_t *queue);

#endif
