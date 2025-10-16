#include <cstdint>

class CircularQueue
{
 public:

  // total number of enqueue operations
  uint32_t enqueues;

  // total number of dequeue operations
  uint32_t dequeues;

  // Index Mask - a bitmask
  uint32_t indexMask;

  // pointer to array of elements
  void** elementsArray;

  CircularQueue();

  ~CircularQueue();

  void reset();

  bool init(uint32_t size);

  void* enqueue(void* objectPointer);

  void* dequeue();

  void* peek();

  uint32_t size();
};
