/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef FORTEITERATOR_H_
#define FORTEITERATOR_H_

/*! \ingroup CORE\brief FORTE implementation of a Singly Linked List Iterator
 *  @author MMM
 *  @version 20100202/mmm - added function Container* getPosition(), CSinglyLinkedList is not a friend class
 *    of Iterator anymore
 */


  /*!\brief Iterator class of the Singly linked list
   *
   * This is the iterator class of this singly linked list, with minimum functionality needed for read and write access.
   * It's nested in the singly linked list template class for reuse
   *
   * T ... Data Type
   * C ... Node Class i.e. CSinglyLinkedListNode
   */

template<typename T, typename Container>
class CIterator  {
public:
  CIterator(Container* pa_poNode) : m_poCurrentPosition(pa_poNode)  {

  }

  ~CIterator() {
  }

  /*!\brief returns the pointer of the current node element
   */

  Container* getPosition() const {
    return m_poCurrentPosition;
  }

  /*!\brief moves iterator to the next element
   */
  CIterator& operator++()  {
    m_poCurrentPosition = m_poCurrentPosition->getNext();
    return *this;
  }

  /*!\brief returns reference to contained object
   *
   * \return reference of the contained object of type T
   */
  T& operator*()  {
    return m_poCurrentPosition->getData();
  }

  /*!\brief Returns a pointer to the contained object
   * \return A Pointer to the contained object of type T
   */
  T* operator->() {
    return &(**this);
  }

  /*!\brief equality operator for the iterator
   *
   * \return true if position of iterators match, false if otherwise
   */
  bool operator==(CIterator const& rhs) const {
    return m_poCurrentPosition == rhs.m_poCurrentPosition;
  }

  /*!\brief inequality operator of the iterator
   *
   * \return false if positions of the iterators match, true if otherwise
   */
  bool operator!=(CIterator const& rhs) const {
    return !(*this == rhs);
  }

private:
  CIterator();
  Container* m_poCurrentPosition;
};

template<typename T, typename Container>
class CIterator<T*, Container>  {
public:
  CIterator(Container* pa_poNode) : m_poCurrentPosition(pa_poNode)  {

  }

  ~CIterator() {

  }

  /*!\brief returns the pointer of the current node element
   */

  Container* getPosition() const  {
    return m_poCurrentPosition;
  }

  /*!\brief moves iterator to the next element
   */
  CIterator& operator++()  {
    m_poCurrentPosition = m_poCurrentPosition->getNext();
    return *this;
  }

  /*!\brief returns reference to contained object
   *
   * \return reference of the contained object of type T
   */
  T* operator*()  {
    return (T*)m_poCurrentPosition->getData();
  }

  /*!\brief Returns a pointer to the contained object
   * \return A Pointer to the contained object of type T
   */
  T* operator->() {
    return (T*)m_poCurrentPosition->getData();
  }

  /*!\brief equality operator for the iterator
   *
   * \return true if position of iterators match, false if otherwise
   */
  bool operator==(CIterator const& rhs) const  {
    return m_poCurrentPosition == rhs.m_poCurrentPosition;
  }

  /*!\brief inequality operator of the iterator
   *
   * \return false if positions of the iterators match, true if otherwise
   */
  bool operator!=(CIterator const& rhs) const {
    return !(*this == rhs);
  }

private:
  CIterator();
  Container* m_poCurrentPosition;
};

#endif /* FORTEITERATOR_H_ */
