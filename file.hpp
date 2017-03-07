#ifndef FILE_H
#define FILE_H

#include <iostream>

using namespace std; 

template <typename T> class File; 

template <typename T> class Cellule { 
  friend class File<T>; 
public: 
  Cellule(T * elem);
  Cellule(T * elem, Cellule<T> * next, Cellule<T> * prev); 

private: 
  static int count; 
  T * element; 
  Cellule<T> * next = NULL; 
  Cellule<T> * prev = NULL; 
};
 
template <typename T> class File {
public: 
  File(); 
  File(T * elem); 
  bool empty(); 
  int len(); 
  void push_back(T * elem); 
  void push_front(T * elem);
  T * pop_back();
  T * pop_front();   

private: 
  int size; 
  Cellule<T> * first;
  Cellule<T> * last; 
};


#include "file.tpp" 
#endif
