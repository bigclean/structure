// link_list.h --- 
// 
// Filename: link_list.h
// Description: double link list header file
// Author: Bigclean Cheng
// Created: Sat Dec 17, 23:48 2011
// Last-Updated: Sun Dec 18, 21:43 2011
// 

// Code:

//!
//! \file link_list.h
//! \brief double link list header file
//!

#ifndef __LINK_LIST_H_
#define __LINK_LIST_H_

#include "link_node.h"

//!
//! \brief dobule link list template
//! \note Because of API compatibled with C/Java/Objective-c version, so
//!       it's not compatible with STL coding style, maybe it's a better
//!       choice that follow its style.
//! \todo Add STL style API sets
//!
template <typename T>
class LinkList
{
    public:
        // TODO: add reverse iterator 'reverse_iterator'
        //!
        //! \brief Read-write iterator of double link list
        //!
        class iterator
        {
            public:
                iterator(void) : current(NULL) {};
                iterator(LinkNode<T> *aNode) : current(aNode) {};
                iterator operator++(void);
                iterator operator++(int);
                bool operator==(const iterator &rhs) const;
                bool operator!=(const iterator &rhs) const;
                T operator*(void);

            private:
                LinkNode<T> *current;

            friend class LinkList<T>;
        };
        typedef const iterator const_iterator; // Read-only iterator of link list

        LinkList(void);
        LinkList(const LinkList<T> &theList);
        ~LinkList(void);

        // accessors
        LinkNode<T> *GetHead(void) const;
        LinkNode<T> *GetTail(void) const;
        unsigned int GetLength(void) const;

        // mutators
        void SetHead(LinkNode<T> *aNode);
        void SetTail(LinkNode<T> *aNode);

        //!
        //! \brief get started valid node of list
        //!
        LinkNode<T> *Front(void) const;
        //!
        //! \brief get endded valid node of list
        //!
        LinkNode<T> *Back(void) const;

        void InsertBefore(LinkNode<T> *nextNode, const T &anObject);
        void InsertAfter(LinkNode<T> *prevNode, const T &anObject);

        //!
        //! \brief insert object as last valid node.
        //! \param anObject inserted object
        //!
        void PushFront(const T &anObject);

        //!
        //! \brief insert object as last valid node.
        //! \param anObject inserted object
        //!
        void PushBack(const T &anObject);

        //!
        //! \brief remove started node of list
        //! \note It doesn't return removed node, use Front() instead.
        //!
        void PopFront(void);

        //!
        //! \brief remove endded node of list
        //! \note It doesn't return removed node, use Back() instead.
        //!
        void PopBack(void);

        //!
        //! \brief remove selected node from list
        //! \param aNode removed node
        //! \note Even remove head or tail node is legal!
        //!
        void RemoveNode(LinkNode<T> *aNode);

        //!
        //! \brief remove all valid nodes
        //! \note Head and tail nodes is always preserved.
        //!
        void RemoveAllNodes(void);

        bool IsEmpty(void);

        // iterators accessors for LinkList
        //!
        //! \note the range between begin() and end() is half-open
        //!        range, so it's [head->GetNext(), tail] in `LinkList.
        //!
        iterator begin(void);
        //!
        //! \note because iteraor always past-the-end, so in `LinkList
        //!       class end node is located after last valid node, it's
        //!       could be treated as an alias of tail node in this version.
        //!
        iterator end(void);

        // callbacks
        // how to use function pointer to memember functions, even
        // functors?
        // see also: http://www.newty.de/fpt/callback.html/
        typedef void (*LinkNodeCallback)(LinkNode<T> *aNode);
        static void Foreach(LinkList<T> *theList, LinkNodeCallback callbackFunc);

    private:
        LinkNode<T>    *head;
        LinkNode<T>    *tail;
        unsigned int   length; // how about variable name 'count'?

    friend class LinkList<T>::iterator;
};

// iterator operators definition
template <typename T>
T LinkList<T>::iterator::operator*(void)
{
        if (current) {
                return current->GetData();
        } else {
                //TODO: throw exception
        }
}

template <typename T>
typename LinkList<T>::iterator LinkList<T>::iterator::operator++(void)
{
        current = current->GetNext();
        return *this;
}

template <typename T>
typename LinkList<T>::iterator LinkList<T>::iterator::operator++(int)
{
        iterator tmp = *this;
        operator++();
        return tmp;
}

template <typename T>
bool LinkList<T>::iterator::operator==(const LinkList<T>::iterator &rhs) const
{
        return (current == rhs.current);
}

template <typename T>
bool LinkList<T>::iterator::operator!=(const LinkList<T>::iterator &rhs) const
{
        return (current != rhs.current);
}

// class itself
template <typename T>
LinkList<T>::LinkList(void)
{
        head = new LinkNode<T>;
        tail = new LinkNode<T>;

        // concatenate head and tail node
        head->SetNext(tail);
        tail->SetPrev(head);

        length = 0;
}

template <typename T>
LinkList<T>::~LinkList(void)
{
        RemoveAllNodes();
        delete head;
        head = NULL;
        delete tail;
        tail = NULL;
}

template <typename T>
LinkNode<T> *LinkList<T>::GetHead(void) const
{
        return head;
}

template <typename T>
LinkNode<T> *LinkList<T>::GetTail(void) const
{
        return tail;
}

template <typename T>
unsigned int LinkList<T>::GetLength(void) const
{
        return length;
}

template <typename T>
void LinkList<T>::SetHead(LinkNode<T> *aNode)
{
        head = aNode;
}

template <typename T>
void LinkList<T>::SetTail(LinkNode<T> *aNode)
{
        tail = aNode;
}

template <typename T>
LinkNode<T> *LinkList<T>::Front(void) const
{
        // TODO: add exception handle when list is empty
        return (head->GetNext());
}

template <typename T>
LinkNode<T> *LinkList<T>::Back(void) const
{
        // TODO: add exception handle when list is empty
        return (tail->GetPrev());
}

template <typename T>
void LinkList<T>::InsertBefore(LinkNode<T> *nextNode, const T &anObject)
{
        LinkNode<T> *newNode  = new LinkNode<T>(anObject);
        LinkNode<T> *prevNode = nextNode->GetPrev();

        newNode->SetPrev(prevNode);
        newNode->SetNext(nextNode);

        prevNode->SetNext(newNode);
        nextNode->SetPrev(newNode);

        length++;
}

template <typename T>
void LinkList<T>::InsertAfter(LinkNode<T> *prevNode, const T &anObject)
{
        LinkNode<T> *newNode  = new LinkNode<T>(anObject);
        LinkNode<T> *nextNode = prevNode->GetNext();

        newNode->SetPrev(prevNode);
        newNode->SetNext(nextNode);

        prevNode->SetNext(newNode);
        nextNode->SetPrev(newNode);

        length++;
}

template <typename T>
void LinkList<T>::PushFront(const T &anObject)
{
        InsertBefore(Front(), anObject); // different implementaion with c version
}

template <typename T>
void LinkList<T>::PushBack(const T &anObject)
{
        InsertAfter(Back(), anObject); // different implementaion with c version
}

template <typename T>
void LinkList<T>::PopFront()
{
        RemoveNode(Front());
}

template <typename T>
void LinkList<T>::PopBack()
{
        RemoveNode(Back());
}

template <typename T>
void LinkList<T>::RemoveNode(LinkNode<T> *aNode)
{
        LinkNode<T> *prevNode = aNode->GetPrev();
        LinkNode<T> *nextNode = aNode->GetNext();

        if (prevNode) {
                prevNode->SetNext(nextNode);
        } else {
                //
                // removed node is head node, so 'nextNode' would be started node of
                // original link list, 'nextNode' should be placed as new head node
                // of modified link list.
                //
                head = nextNode;
        }

        if (nextNode) {
                //
                // removed node is tail node, so 'prevNode' would be last node of
                // original link list, 'prevNode' should be placed as new tail node
                // of modifiied link list.
                //
                nextNode->SetPrev(prevNode);
        } else {
                tail = prevNode;
        }

        // deconstructure
        delete aNode;
        aNode = NULL;
}

template <typename T>
void LinkList<T>::RemoveAllNodes(void)
{
        iterator it = this->begin();
        iterator tmp;
        while (it != this->end()) {
                tmp = it++;
                RemoveNode(tmp.current); // FIXME: to be updated
        }
}

template <typename T>
bool LinkList<T>::IsEmpty(void)
{
        return (length == 0);
}

template <typename T>
typename LinkList<T>::iterator LinkList<T>::begin()
{
        return iterator(Front()); // equal to code 'return typename LinkList<T>::iterator(Front());'
}

template <typename T>
typename LinkList<T>::iterator LinkList<T>::end()
{
        return iterator(tail);
}

// static callbacks
template <typename T>
void LinkList<T>::Foreach(LinkList<T> *theList, LinkNodeCallback callbackFunc)
{
        iterator it;
        for (it = theList->begin(); it != theList->end(); ++it) {
                callbackFunc(it.current); // LinkList<T> is friend class of LinkList<T>::iterator
        }
}

#endif

// link_list.h ends here
