#include "CircularQueue.h"

CircularQueue::CircularQueue()
{
 this->elementsArray = nullptr;
};

CircularQueue::~CircularQueue()
{
 reset();
};

void CircularQueue::reset()
{
 // free array of elements:
 if (this->elementsArray)
  delete [] this->elementsArray;

 this->enqueues = 0;
 this->dequeues = 0;
 this->indexMask = 0;
 this->elementsArray = nullptr;
}

bool CircularQueue::init(uint32_t size)
{
 // allow object re-use:
 reset();

 // verify size is not zero:
 if (size == 0)
  return false;

 // calculate the bit mask:
 this->indexMask = size - 1;

 // verify size is a power of 2:
 if (size & (this->indexMask))
  return false;

 // allocate the queue elements:
 this->elementsArray = new void*[size];

 // will return true only if all of the above succeeded:
 return (this->elementsArray != nullptr);
}

void* CircularQueue::enqueue(void* objectPointer)
{
 // check for overflow:
 if (this->size() > this->indexMask)
  return nullptr;

 // calculate the enqueue index:
 uint32_t enqueueIndex = (this->enqueues & this->indexMask);

 // set the element value:
 *(this->elementsArray + enqueueIndex) = objectPointer;

 // increment enqueue count:
 this->enqueues++;

 return objectPointer;
}

void* CircularQueue::dequeue()
{
 // get the element value:
 void* objectPointer = peek();

 // increment dequeue count (if no peek error):
 if (objectPointer != nullptr)
  this->dequeues++;

 return objectPointer;
}

void* CircularQueue::peek()
{
 // check for underflow:
 if (this->size() == 0)
  return nullptr;

 // calculate the dequeue index:
 uint32_t dequeueIndex = (this->dequeues & this->indexMask);

 // return the element value:
 return *(this->elementsArray + dequeueIndex);
}

// returns the distance between dequeues and enqueues
// (the size of the actual queue contents):
uint32_t CircularQueue::size()
{
 if (this->dequeues < this->enqueues)
  return (this->enqueues - this->dequeues);
 else
  return (this->dequeues - this->enqueues);
}

