#include "dlist.h"
#include "dlist_impl.h"
using namespace std;

class Stack : public Dlist<int> {
    // OVERVIEW: Stack of Objects
  private:
    int numStack = 0;

  public:
    Stack() : Dlist<int>(){};
    // constructor
    Stack(const Stack &s) : Dlist<int>(s){};
    int size();
    bool isEmpty();
    void push(int *op);
    int *pop();
    int *top();
    ~Stack();
};