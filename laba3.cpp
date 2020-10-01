#ifndef MQUEUE_H
#define MQUEUE_H
class mqueue {
private:
  int* p;
  int count;
public:
  mqueue() : count(0) { }
  ~mqueue();
  inline bool empty() { return count == 0; }
  inline int size() const { return count; }
  void push(int item);
  void pop();
  void print();
  void input(int size);
  mqueue& operator+=(int item);
  mqueue& operator-=(int count);
  mqueue& operator=(const mqueue &);
  friend mqueue operator+(const mqueue &, int item);
  friend mqueue operator-(const mqueue &, int count);
};
