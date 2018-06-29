/////////////////////////////////////////////////////////////////////////////
// tombstones.h, expected interface for CS254 assignment 5
/////////////////////////////////////////////////////////////////////////////

#if !defined(__TOMBSTONES_H__)
#define __TOMBSTONES_H__

#include <cstddef>
#include <iostream>
#include <string>
#include <stdlib.h>

void err(const char *text)
{
    std::cout << "ERROR: " << text << std::endl;
    exit(-1);
}


template <class T> class Pointer;
template <class T> class Tombstone;
template <class T> void free(Pointer<T>& ptr){
  delete ptr.ts->getObj();
  ptr.ts->obj = NULL;
  ptr.ts->rip = 1;
}
template <class T>
class Pointer {
public:
  Tombstone<T>* ts;

  Pointer<T>(){
    ts = new Tombstone<T>();
  }                               // default constructor
  Pointer<T>(Pointer<T>& ptr){
    if(ptr.ts->rip) err("Dangling reference");
    ts = ptr.ts;
    ts->refcount++;
  }                        // copy constructor
  Pointer<T>(T* obj){
    ts = new Tombstone<T>(obj);

  }                             // bootstrapping constructor
      // argument should always be a call to new
  ~Pointer<T>(){
    ts->decRefcout();
  }                              // destructor
  T& operator*() const{
    return *(ts->getObj());
  }                   // deferencing
  T* operator->() const{
    return ts->getObj();
  }                  // field dereferencing
  Pointer<T>& operator=(const Pointer<T>& ptr){
    ts->decRefcout();
    ts = ptr.ts;
    ts->refcount++;
    return *this;
  }       // assignment
  friend void free<T>(Pointer<T>&);         // delete pointed-at object
      // This is essentially the inverse of the new inside the call to
      // the bootstrapping constructor.
  // equality comparisons:
  bool operator==(const Pointer<T>& ptr) const{
    return ts->obj == ptr.ts->obj;
  }
  bool operator!=(const Pointer<T>& ptr) const{
    return ts->obj!= ptr.ts->obj;
  }
  bool operator==(const int i) const{
    return (ts->obj == NULL && i == 0);
  }
      // true iff Pointer is null and int is zero
  bool operator!=(const int i) const{
    return ts->obj != NULL || i != 0;
  }
      // false iff Pointer is null and int is zero
};
template <class T>
class Tombstone {
public:
  bool rip;
  T* obj;
  int refcount;
  Tombstone<T>(T* ob){
    obj = ob;
    refcount = 1;
    rip =0;
  }

  Tombstone<T>(){
    obj = NULL;
    refcount=1;
    rip=0;
  }
  T* getObj(){
    if(obj == NULL && rip==1){
      err("Dangling reference");
    }else if (obj == NULL && rip==0){
      err("Tried to dereference a NULL pointer");
    }else{
      return obj;
    }
  }
  void decRefcout(){
    refcount--;
    if(refcount == 0 && obj != NULL){
      err("Memory leak.");
    }
  }

};

template <class T>
bool operator==(const int n, const Pointer<T>& t) {
  return t == n;
}
template <class T>
bool operator!=(const int n, const Pointer<T>& t) {
  return t != n;
}

#endif // __TOMBSTONES_H__
