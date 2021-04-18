#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
  int data;
  int priority;
  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T> q;
  q.head = nullptr;
  q.tail = nullptr;
  return q;
}

/**
 * @brief Create a Element object
 * 
 * @param newElement new object on queue
 * @param value thing in object
 * @param priority a set number for affecting position of object on queue
 */
template <typename T>
void createElement(ElementPtr<T> newElement, const T &value, int priority){
  newElement->data = value;
  newElement->priority = priority;
  newElement->next = nullptr;
}

/**
 * @brief checking queue condition
 *  
 * @param q as checked query 
 * @return true as value when empty
 * @return false as value when not empty
 */
template <typename T>
bool isEmpty(Queue<T> q){
  if(q.head==nullptr && q.tail==nullptr){
    return true;
  } else {
    return false;
  }
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  ElementPtr<T> newElement;
  newElement= new Element<T>;
  createElement(newElement,value,priority);
  ElementPtr<T> pRev = nullptr;
  ElementPtr<T> pHelp = q.head;
  if(isEmpty(q)){
    q.head = newElement;
    q.tail = newElement;
  } 
  else {
    pRev = pHelp;
    if(pHelp->priority < newElement->priority){
      newElement->next = pHelp;
      q.head = newElement;
    }
    else if (newElement->priority = pHelp->priority){
      pRev = pHelp;
      pHelp->next= newElement;
      if(newElement->next = nullptr){
        newElement = q.tail;
      }
    }
    else {
      pRev = pHelp->next;
      while (pRev!=nullptr){
        while (pRev->priority > newElement->priority ) {
          pRev=pRev->next;
        }
        if(pRev->priority < newElement->priority){
          pHelp->next = newElement;
          newElement->next = pRev;
        }
      }
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  ElementPtr<T> delElement;
  if(isEmpty(q)){
    delElement = nullptr;
  } else if (q.head->next == nullptr){
    delElement = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  } else {
    delElement = q.head;
    q.head = q.head->next;
    delElement->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
