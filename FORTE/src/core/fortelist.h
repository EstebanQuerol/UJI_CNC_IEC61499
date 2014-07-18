/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <fortealloc.h>
#include "fortenode.h"
#include "forteiterator.h"

#ifndef _FORTELIST_H_
#define _FORTELIST_H_

/*! \ingroup CORE\brief FORTE implementation of a Singly Linked List
 *  @author MMM
 *  @version 20100202/mmm - deleted nested class Iterator and struct SSinglyLinkedListNode and put them into separate
 *    template classes and headers; inlined clearAll(), CSinglyLinkedList() and ~CSinglyLinkedList
 *  @version 20090806/mmm - initial version, minimum needed functionality for a singly linked list
 */

template <typename T, typename Container = CSinglyLinkedListNode<T> >
class CSinglyLinkedList {
private:

  friend class CIterator<T,Container>;

  /*!\brief First element of the singly linked list
   */
  Container* m_poFirstNode;

  /*!\brief Last element of the singly linked list
   */
  Container* m_poLastNode;

public:
  CSinglyLinkedList();
  ~CSinglyLinkedList();

  /*!\brief Typedef for getting the right iterator for the list
   * */
  typedef CIterator<T,Container> Iterator;

  /*!\brief Add's the given object at the start of the singly linked list
   *
   * \param pa_roElement the reference to the object to be added
   */
  void push_front(T const& pa_roElement);

  /*!\brief Add's the given object at the end of the singly linked list
   *
   * \param pa_roElement the reference to the object to be added
   */
  void push_back(T const& pa_roElement);

  /*!\brief Deletes the first object of the singly linked list
   *
   */
  void pop_front();

  /*!\brief Deletes all objects in the singly linked list
   */
  void clearAll();

  /*!\brief checks if the singly linked list is empty or not
   *
   * \return true if the list is empty, false if not
   */
  bool isEmpty() const {
    return (0 == m_poFirstNode);
  }

  /*!\brief returns an iterator with it's current position set to the start of the singly linked list
   *
   * \return iterator on position FirstNode
   */
  const Iterator begin()  {
    return Iterator(m_poFirstNode);
  }

  /*!\brief returns an iterator with it's current position set to 0
   *
   * \return iterator with current position 0
   */
  const Iterator end() const {
    return Iterator(0);
  }

  const Iterator back() {
    return Iterator(m_poLastNode);
  }

  /*!\brief erases the next node element after the position of the iterator
   *
   * \param it  iterator set on the element before the element to delete
   * \return Iterator set on the new next node element
   */
  const Iterator eraseAfter(Iterator& it);



};

template <typename T, typename Container>
inline CSinglyLinkedList<T,Container>::CSinglyLinkedList() : m_poFirstNode(0), m_poLastNode(0) {
}

template <typename T, typename Container>
inline CSinglyLinkedList<T,Container>::~CSinglyLinkedList() {
  clearAll();
}

template <typename T, typename Container>
void CSinglyLinkedList<T,Container>::push_front(T const& pa_roElement) {
  Container* poNewNode = new Container(pa_roElement, m_poFirstNode);
  m_poFirstNode = poNewNode;
  if(0 == m_poLastNode){
    m_poLastNode = poNewNode;
  }
}

template <typename T, typename Container>
void CSinglyLinkedList<T,Container>::push_back(T const& pa_roElement)  {
  Container* poNewNode = new Container(pa_roElement);

  if(0 != m_poLastNode){
    m_poLastNode->setNext(poNewNode);
  }
  else{
    m_poFirstNode = poNewNode;
  }
  m_poLastNode = poNewNode;
}

template <typename T, typename Container>
void CSinglyLinkedList<T,Container>::pop_front() {
  Container* pNodeToDelete = m_poFirstNode;
  m_poFirstNode = m_poFirstNode->getNext();
  if(0 == m_poFirstNode) {
    m_poLastNode = 0;
  }
  delete pNodeToDelete;
}

template <typename T, typename Container>
inline void CSinglyLinkedList<T,Container>::clearAll() {
  while(m_poFirstNode != 0)  {
    pop_front();
  }
}

template <typename T, typename Container>
const CIterator<T,Container> CSinglyLinkedList<T,Container>::eraseAfter(Iterator& it) {
  Container* pNodeToDelete = (it.getPosition())->getNext();
  it.getPosition()->setNext(pNodeToDelete->getNext());
  if(0 == it.getPosition()->getNext()) {
    m_poLastNode = it.getPosition();
  }
  delete pNodeToDelete;
  return Iterator((it.getPosition())->getNext());
}

/*!\brief explicit specialization for a void* list
 *
 */

template<>
class CSinglyLinkedList<void*, CSinglyLinkedListNode<void*> >  {
private:

  friend class CIterator<void*,CSinglyLinkedListNode<void*> >;

  /*!\brief First element of the singly linked list
   */
  CSinglyLinkedListNode<void*>* m_poFirstNode;

  /*!\brief Last element of the singly linked list
   */
  CSinglyLinkedListNode<void*>* m_poLastNode;

public:
  CSinglyLinkedList() : m_poFirstNode(0), m_poLastNode(0) {

  }
  ~CSinglyLinkedList()  {
    clearAll();
  }

  /*!\brief Typedef for getting the right iterator for the list
   * */
  typedef CIterator<void*,CSinglyLinkedListNode<void*> > Iterator;

  /*!\brief Add's the given object at the start of the singly linked list
   *
   * \param pa_poElement the reference to the object to be added
   */
  void push_front(void* const pa_poElement)  {
    CSinglyLinkedListNode<void*>* poNewNode = new CSinglyLinkedListNode<void*>(pa_poElement, m_poFirstNode);
    m_poFirstNode = poNewNode;
    if(0 == m_poLastNode){
      m_poLastNode = poNewNode;
    }
  }

  /*!\brief Add's the given object at the end of the singly linked list
   *
   * \param pa_poElement the reference to the object to be added
   */
  void push_back(void* const pa_poElement) {
    CSinglyLinkedListNode<void*>* poNewNode = new CSinglyLinkedListNode<void*>(pa_poElement);

    if(0 != m_poLastNode){
      m_poLastNode->setNext(poNewNode);
    }
    else{
      m_poFirstNode = poNewNode;
    }
    m_poLastNode = poNewNode;
  }

  /*!\brief Deletes the first object of the singly linked list
   *
   */
  inline void pop_front()  {
    CSinglyLinkedListNode<void*>* pNodeToDelete = m_poFirstNode;
    m_poFirstNode = m_poFirstNode->getNext();
    if(0 == m_poFirstNode) {
      m_poLastNode = 0;
    }
    delete pNodeToDelete;
  }

  /*!\brief Deletes all objects in the singly linked list
   */
  inline void clearAll() {
    while(0 != m_poFirstNode)  {
      pop_front();
    }
  }

  /*!\brief checks if the singly linked list is empty or not
   *
   * \return true if the list is empty, false if not
   */
  inline bool isEmpty() const {
    return (0 == m_poFirstNode);
  }

  /*!\brief returns an iterator with it's current position set to the start of the singly linked list
   *
   * \return iterator on position FirstNode
   */
  inline const Iterator begin()  {
    return Iterator(m_poFirstNode);
  }

  /*!\brief returns an iterator with it's current position set to 0
   *
   * \return iterator with current position 0
   */
  inline const Iterator end() const {
    return Iterator(0);
  }

  /*!\brief erases the next node element after the position of the iterator
   *
   * \param it  an iterator set on the element before the element to delete
   * \return Iterator set on the new next node element
   */
  const Iterator eraseAfter(Iterator& it) {
    CSinglyLinkedListNode<void*>* pNodeToDelete = (it.getPosition())->getNext();
    it.getPosition()->setNext(pNodeToDelete->getNext());
    if(0 == it.getPosition()->getNext()) {
      m_poLastNode = it.getPosition();
    }
    delete pNodeToDelete;
    return Iterator((it.getPosition())->getNext());
  }

};

/*!\brief partial specialization for pointer lists
 */

template <typename T>
class CSinglyLinkedList<T*> {
private:
  friend class CIterator<T*,CSinglyLinkedListNode<void*> >;
  CSinglyLinkedList<void*> m_List;

public:
  CSinglyLinkedList() {

  }

  ~CSinglyLinkedList()  {
    clearAll();
  }

  /*!\brief Typedef for getting the right iterator for the list
   * */
  typedef CIterator<T*,CSinglyLinkedListNode<void*> > Iterator;

  /*!\brief Add's the given object at the start of the singly linked list
   *
   * \param pa_pElement the reference to the object to be added
   */
  inline void push_front(T* const pa_pElement)  {
    m_List.push_front(pa_pElement);
  }

  /*!\brief Add's the given object at the end of the singly linked list
   *
   * \param pa_pElement the reference to the object to be added
   */
  inline void push_back(T* const pa_pElement) {
    m_List.push_back(pa_pElement);
  }

  /*!\brief Deletes the first object of the singly linked list
   *
   */
  inline void pop_front()  {
    m_List.pop_front();
  }

  /*!\brief Deletes all objects in the singly linked list
   */
  inline void clearAll() {
    m_List.clearAll();
  }

  /*!\brief checks if the singly linked list is empty or not
   *
   * \return true if the list is empty, false if not
   */
  inline bool isEmpty() const {
    return m_List.isEmpty();
  }

  /*!\brief returns an iterator with it's current position set to the start of the singly linked list
   *
   * \return iterator on position FirstNode
   */
  inline const Iterator begin()  {
    return Iterator((m_List.begin()).getPosition());
  }

  /*!\brief returns an iterator with it's current position set to 0
   *
   * \return iterator with current position 0
   */
  inline const Iterator end() const {
    return Iterator((m_List.end()).getPosition());
  }

  /*!\brief erases the next node element after the position of the iterator
   *
   * \param it  an iterator set on the element before the element to delete
   * \return Iterator set on the new next node element
   */
  const Iterator eraseAfter(Iterator& it) {
    CSinglyLinkedList<void*>::Iterator itBuff(it.getPosition());
    return Iterator((m_List.eraseAfter(itBuff)).getPosition());
  }

};


#endif /* CSINGLYLINKEDLIST_H_ */
