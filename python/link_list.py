# link_list.py --- 
# 
# Filename: link_list.py
# Description: double link list demo
# Author: Bigclean Cheng
# Created: Thu Feb 16 21:58:09 2012 (+0800)
# Last-Updated: Thu Feb 16 22:03:21 2012 (+0800)

# Code:

""" Double Link List
@author:  Bigclean Cheng
@note: Using `next data fields in this version of `LinkNode, it's maybe
       not a good choice because `next is internal function in Python.
"""

class LinkList(object):
    def __init__(self):
        self.head = self.tail = LinkNode();
        # concatenate head and tail node
        self.head.next = self.tail
        self.tail.prev = self.head

        self.current = None # using for iterating
        self.length = 0

    def front(self):
        """
        get started valid node of list
        @return: started node
        @rtype:  LinkNode
        """
        return self.head.next

    def back(self):
        return self.tail.prev

    def insert_before(self, nextNode, item):
        newNode  = LinkNode(item)
        prevNode = nextNode.prev

        newNode.prev = prevNode
        newNode.next = nextNode

        prevNode.next = newNode
        nextNode.prev = newNode

        self.length += 1

    def insert_after(self, prevNode, item):
        newNode  = LinkNode(item)
        nextNode = prevNode.next

        newNode.prev = prevNode
        newNode.next = nextNode

        prevNode.next = newNode
        nextNode.prev = newNode

        self.length += 1

    def push_front(self, item):
        """
        insert object as started valid node.
        @param item: inserted object
        @type  item: LinkNode
        """
        self.insert_before(self.front(), item)

    def push_back(self, item):
        self.insert_after(self.back(), item)

    def pop_front(self):
        self.remove_node(self.front())

    def pop_back(self):
        self.remove_node(self.back())

    def remove_node(self, aNode):
        prevNode = aNode.prev
        nextNode = aNode.next

        if prevNode:
            prevNode.next = nextNode
        else:
            #
            # removed node is head node, so 'nextNode' would be started
            # node of original link list, 'nextNode' should be placed as
            # new head nodeof modified link list.
            #
            self.head = nextNode

        if nextNode:
            nextNode.prev = prevNode
        else:
            #
            # removed node is tail node, so 'prevNode' would be last
            # node of original link list, 'prevNode' should be placed as
            # new tail nodeof modifiied link list.
            #
            self.tail = prevNode

        self.length -= 1

    # needs to be fixed
    def remove_all_nodes(self):
        self.current = self.front()
        nextNode     = None

        # FIXME: 'self.tail.next' is 'None' obviously, but why code
        #         'while self.current.next is not None' sucks?
        while self.current.next is not self.tail.next:
            nextNode = self.current.next
            self.remove_node(self.current)
            self.current = nextNode

    def is_empty(self):
        return ((self.length) == 0)

    def __len__(self):
        return self.length

    def __iter__(self):
        self.current = self.front()
        return self

    # because Python in Cygwin is 2.6.5, so use 'def next(self):', but in
    # python 3, it's 'def __next__(self):'
    # see also: http://www.python.org/dev/peps/pep-3114/
    def next(self):
        tmp = self.current
        if tmp == self.tail:
            raise StopIteration
        self.current = self.current.next
        return tmp

    def __repr__(self):
        pass

    def __str__(self):
        stuff = ", ".join((str(x) for x in self))
        return '[ %s ]' % stuff

class LinkNode:
    def __init__(self, value = 0):
        self.obj  = value
        self.prev = None
        self.next = None

    def __repr__(self):
        return 'Value of List Node: %s' % self.obj

    def __str__(self):
        return '%s' % self.obj

# 
# link_list.py ends here
