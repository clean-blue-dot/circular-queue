#include "CircularQueue.h"
#include <iostream>
#include <string>

using std::string;

int g_tests = 0;
int g_passd = 0;

// reports on a numeric test:
void reportNT(
 string funcName,
 uint32_t got,
 uint32_t exp)
{
 g_tests++;

 if (got == exp)
 {
  g_passd++;

  std::cout << "PASS: " <<
   funcName << " == " <<
   exp << "\n";
 }
 else
 {
  std::cout << "FAIL: "<<
   funcName << " == " <<
   got << "\n";
 }
}

// reports on a string pointer test:
void report(
 string funcName,
 void* got,
 void* exp)
{
 g_tests++;

 string strExp = "nullptr";
 string strGot = "nullptr";

 if (exp)
  strExp = *((string*)exp);

 if (got)
  strGot = *((string*)got);

 if (got == exp)
 {
  g_passd++;

  std::cout << "PASS: " <<
   funcName << " == " <<
   strExp << "\n";
 }
 else
 {
  std::cout << "FAIL: "<<
   funcName << " == " <<
   strGot << "\n";
 }
}

int main(int argc, const char * argv[])
{
 string alpha   = "ALPHA";
 string bravo   = "BRAVO";
 string charlie = "CHARLIE";
 string delta   = "DELTA";
 string echo    = "ECHO";
 string foxtrot = "FOXTROT";
 string golf    = "GOLF";
 string hotel   = "HOTEL";
 string india   = "INDIA";

 std::cout << "Testing CircularQueue Class:\n\n";
 
 string enqueue  = "enqueue()";
 string dequeue  = "dequeue()";
 string getfront = "peek()";
 string size  = "size()";

 CircularQueue queue;

 std::cout << "init with 8 elements:\n";

 bool initOK = queue.init(8);

 std::cout << "verify init success:\n";

 reportNT("init()", initOK ? 1 : 0, 1);

 if (initOK)
 {
  std::cout << "queue should be empty:\n";

  reportNT(size, queue.size(), 0);
  report(dequeue, queue.dequeue(), nullptr);

  std::cout << "enqueue 8 items:\n";

  report(enqueue, queue.enqueue(&alpha),   &alpha);
  report(enqueue, queue.enqueue(&bravo),   &bravo);
  report(enqueue, queue.enqueue(&charlie), &charlie);
  report(enqueue, queue.enqueue(&delta),   &delta);
  report(enqueue, queue.enqueue(&echo),    &echo);
  report(enqueue, queue.enqueue(&foxtrot), &foxtrot);
  report(enqueue, queue.enqueue(&golf),    &golf);
  report(enqueue, queue.enqueue(&hotel),   &hotel);

  std::cout << "queue should have 8 elements:\n";

  reportNT(size, queue.size(), 8);

  std::cout << "expecting overfolw on attempt to enqueue ninth item:\n";

  report(enqueue, queue.enqueue(&india), nullptr);

  std::cout << "front of queue should be \"ALPHA\":\n";

  report(getfront, queue.peek(), &alpha);

  std::cout << "dequeue all items:\n";

  report(dequeue, queue.dequeue(), &alpha);
  report(dequeue, queue.dequeue(), &bravo);
  report(dequeue, queue.dequeue(), &charlie);
  report(dequeue, queue.dequeue(), &delta);
  report(dequeue, queue.dequeue(), &echo);
  report(dequeue, queue.dequeue(), &foxtrot);
  report(dequeue, queue.dequeue(), &golf);
  report(dequeue, queue.dequeue(), &hotel);

  std::cout << "queue should be empty (again):\n";

  reportNT(size, queue.size(), 0);
  report(dequeue, queue.dequeue(), nullptr);

  std::cout << "\n";
  std::cout << "\n";

  std::cout << "Tests:  "<< g_tests << "\n";
  std::cout << "Passed: "<< g_passd << "\n\n";
 }
 else
 {
  std::cout << "unable to proceed: init() ctriteria not met.\n";
 }

 return 0;
}
