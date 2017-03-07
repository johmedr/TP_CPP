#ifndef FILE_TPP
#define FILE_TPP

template <typename T>
int Cellule<T>::count = int(0); 

template <typename T> 
Cellule<T>::Cellule(T * elem) {
  element=elem; 
  next = NULL; 
  prev = NULL; 
  if( Cellule<T>::count ) {
    Cellule<T>::count++;
  } else { 
    Cellule<T>::count = 0; 
  }
}

template <typename T> 
Cellule<T>::Cellule(T * elem, Cellule<T> * cnext, Cellule<T> * cprev) {
  element = elem; 
  next = cnext; 
  prev = cprev; 
  if( Cellule<T>::count ) {
    Cellule<T>::count++;
  } else { 
    Cellule<T>::count = 0; 
  }
} 

template <typename T> 
File<T>::File() {
  first = NULL; 
  last = NULL; 
  size = 0; 
}

template <typename T> 
File<T>::File(T * elem) {
  first = new Cellule<T>(elem); 
  last = first; 
  size = 1; 
}

template <typename T> 
bool File<T>::empty() { 
  return ( size == 0 ); 
} 

template <typename T> 
int File<T>::len() { 
  return size; 
} 

template <typename T> 
void File<T>::push_back(T * elem) { 
  if( this->empty() ) {
    first = new Cellule<T>(elem); 
    last = first; 
    size = 1;
  } else { 
    Cellule<T> * new_cell =  new Cellule<T>(elem, NULL, last); 
    last->next = new_cell; 
    last = new_cell; 
    size++; 
  } 
}

template <typename T> 
void File<T>::push_front(T * elem) { 
  if( this->empty() ) {
    first = new Cellule<T>(elem); 
    last = first; 
    size = 1;
  } else { 
    Cellule<T> * new_cell = new Cellule<T>(elem, first, NULL); 
    first->prev = new_cell; 
    first = new_cell; 
    size++;
  }
} 

template <typename T> 
T * File<T>::pop_front() { 
  Cellule<T> * cel_out; 
  T * elem_out; 
  if( this->empty() ) {
    elem_out = NULL; 
  } else { 
    cel_out = first; 
    elem_out = cel_out->element; 
    size--; 
    if ( size == 1 ) { 
      first = NULL; 
      last = NULL; 
    } else { 
      first = cel_out->next; 
      first->prev = NULL; 
    }
  }
  return elem_out; 
}



template <typename T> 
T * File<T>::pop_back() {
  Cellule<T> * cel_out; 
  T * elem_out; 
  if( this->empty() ) {
    elem_out = NULL; 
  } else { 
    cel_out = last; 
    elem_out = cel_out->element; 
    size--; 
    if ( size == 1 ) { 
      first = NULL; 
      last = NULL; 
    } else { 
      last = cel_out->prev; 
      last->next = NULL; 
    }
  }
  return elem_out; 
}


#endif
