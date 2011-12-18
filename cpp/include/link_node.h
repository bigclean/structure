// link_node.h --- 
// 
// Filename: link_node.h
// Description: double link node header file
// Author: Bigclean Cheng
// Created: Sat Dec 17, 23:48 2011
// Last-Updated: Sun Dec 18, 19:26 2011
// 

// Code:

//!
//! \file link_node.h
//! \brief double link node header file
//!

#ifndef __LINK_NODE_H_
#define __LINK_NODE_H_

#include <iostream>
using namespace std;

// Defined in "link_list.h"
template <typename T>
class LinkList;

//!
//! \brief double link node
//! \todo add exception handling
//!
template <typename T>
class LinkNode
{
    public:
        LinkNode(const T &anObject, LinkNode<T> *prevNode, LinkNode<T> *nextNode);
        ~LinkNode(void);

        // accessors
        LinkNode<T> *GetPrev(void) const;
        LinkNode<T> *GetNext(void) const;

        // mutators
        void SetPrev(LinkNode<T> *prevNode);
        void SetNext(LinkNode<T> *nextNode);

        T GetData(void) const;
        T Retrieve(void) const;
        void SetData(T &abObj);

        virtual void Display(std::ostream &strm) const;

        // for callbacks
        static void Visit(LinkNode<T> *aNode);

    private:
        T               obj;
        LinkNode<T>    *prev;
        LinkNode<T>    *next;

    friend class LinkList<T>; // Let LinkList as friend class of LinkNode
};

// LinkNode
template <typename T>
LinkNode<T>::LinkNode(const T &anObject = T(), LinkNode<T> *prevNode = 0, LinkNode<T> *nextNode = 0)
{
        obj  = anObject;
        prev = prevNode;
        next = nextNode;
}

template <typename T>
LinkNode<T>::~LinkNode(void)
{
        prev = next = NULL;
}

template <typename T>
LinkNode<T> *LinkNode<T>::GetPrev(void) const
{
        return prev;
}

template <typename T>
LinkNode<T> *LinkNode<T>::GetNext(void) const
{
        return next;
}

template <typename T>
void LinkNode<T>::SetPrev(LinkNode<T> *aNode)
{
        prev = aNode;
}

template <typename T>
void LinkNode<T>::SetNext(LinkNode<T> *aNode)
{
        next = aNode;
}

template <typename T>
T LinkNode<T>::GetData(void) const
{
        return obj;
}

template <typename T>
T LinkNode<T>::Retrieve(void) const
{
        return GetData();
}
template <typename T>
void LinkNode<T>::SetData(T &anObj)
{
        obj = anObj;
}

template <typename T>
void LinkNode<T>::Display(std::ostream &strm) const
{
        strm << "Contents: "
            << obj;
}

// global function, overload '<<' operator
// TODO: should be compatoible with objc-version.
template <typename T>
std::ostream &operator<<(std::ostream &strm, const LinkNode<T> &aNode)
{
        aNode.Display(strm);
        return strm;
}

//!
//! \brief callback functions sample
//!
template <typename T>
void LinkNode<T>::Visit(LinkNode<T> *aNode)
{
        cout << *aNode << endl;
}

#endif

// link_node.h ends here
