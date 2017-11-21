/////////////////////////////////////////////////////////////////////////////
// tombstones.h, expected interface for CS254 assignment 5
/////////////////////////////////////////////////////////////////////////////

#if !defined(__TOMBSTONES_H__)
#define __TOMBSTONES_H__

template <class T> class Pointer;
template <class T> class Tombstone;
template <class T> void free(Pointer<T>& obj);

template <class T>
class Pointer {
public:
  Tombstone<T> obj;

  Pointer<T>(){

  }                               // default constructor
  Pointer<T>(Pointer<T>& p){

  }                        // copy constructor
  Pointer<T>(T*){

  }                             // bootstrapping constructor
      // argument should always be a call to new
  ~Pointer<T>(){

  }                              // destructor
  T& operator*() const{

  }                   // deferencing
  T* operator->() const{

  }                  // field dereferencing
  Pointer<T>& operator=(const Pointer<T>& p){

  }       // assignment
  friend void free<T>(Pointer<T>& p){

  }           // delete pointed-at object
      // This is essentially the inverse of the new inside the call to
      // the bootstrapping constructor.
  // equality comparisons:
  bool operator==(const Pointer<T>& p) const{

  }
  bool operator!=(const Pointer<T>& p) const{

  }
  bool operator==(const int i) const{

  }
      // true iff Pointer is null and int is zero
  bool operator!=(const int i) const{

  }
      // false iff Pointer is null and int is zero
};
template <class T>
class Tombstone {
public:
  T* obj;
  int refcount;
  Tombstone<T>(T* o){
    obj = o;
    refcount = 1;
  }

  Tombstone<T>(){
    obj = 0;
    refcount=1;
  }

};

#endif // __TOMBSTONES_H__
