#ifndef __QUEUE_H__
#define __QUEUE_H__

template <class T>
class TQueue
{
private:
  int size;
  int start;
  int end;
  T* data;
  
public:
  TQueue(int _size = 1);
  TQueue(const TQueue &p);
  ~TQueue();
  
  void push(T &a);
  T pull();
  
  int getCount();
  int getSize();
  
  bool isFull();
  bool isEmpty();
};
#endif


template <class T>
TQueue<T>::TQueue(int _size)
{
  if (_size < 0) throw "size error";

  size = _size;
  start = 0;
  end = 0;
  data = new T[size];

  for (int i = 0; i < size; i++)
    data[i] = 0;
}

template <class T>
TQueue<T>::TQueue(const TQueue& p)
{
  if (p.size < 0) 
    throw "size error";

  size = p.size;
  start = p.start;
  end = p.start;
  data = new T[size];

  for (int i = 0; i < size; i++)
    data[i] = p.data[i];
}

template <class T>
TQueue<T>::~TQueue()
{
  delete[] data;
  size = 0;
  start = 0;
  end = 0;
}

template <class T>
void TQueue<T>::push(T& a)
{
  if (end > size)
    throw "size error";

  data[end] = a;
  end++;
}

template <class T>
T TQueue<T>::pull()
{
  if (start < 0)
    throw "size error";

  T a;
  a = data[start];
  start++;

  return a;
}

template <class T>
int TQueue<T>::getCount()
{
  return end - start;
}

template <class T>
int TQueue<T>::getSize()
{
  return size;
}

template <class T>
bool TQueue<T>::isFull()
{
  if (end > size)
    throw "size error";

  int res = false;
  if (end == size)
    res = true;
  
  return res;
}

template <class T>
bool TQueue<T>::isEmpty()
{
  if (start < 0)
    throw "size error";

  int res = false;
  if (start == end)
    res = true;
  
  return res;
}