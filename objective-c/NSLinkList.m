// NSLinkList.m --- 
// 
// Filename: NSLinkList.m
// Description: double link list implementation
// Author: Bigclean Cheng
// Created: Wed Nov 16, 22:44 2011
// Last-Updated: Thu Dec 15, 23:55 2011
// 

// Code:

/*!
 * \file NSLinkList.m
 * \brief double link list implementation
 */
#import "NSLinkList.h"

@implementation NSLinkList

- (id)init {
  if (self = [super init]) {
    // initial head node
    head = [[NSLinkNode alloc] init];
    [head setPrev:nil];

    // initial tail node
    tail = [[NSLinkNode alloc] init];
    [tail setNext:nil];

    // concatenate head and tail node to construct list
    [head setNext:tail];
    [tail setPrev:head];

    length = 0;
  }
  return self;
}

// TODO: add memory manager
- (void)dealloc {
  [self  removeAllNodes];
  [head  release];
  [tail  release];

  [super dealloc];
}

@synthesize head;
@synthesize tail;
@synthesize length;

- (void)insertBefore:(NSLinkNode *)nextNode insertedObject:(id)anObject {
  NSLinkNode *newNode  = [[NSLinkNode alloc] initWithObject:anObject];
  NSLinkNode *prevNode = [nextNode prev];

  [newNode setPrev:prevNode];
  [newNode setNext:nextNode];

  [prevNode setNext:newNode];
  [nextNode setPrev:newNode];

  length++;
}

- (void)insertAfter:(NSLinkNode *)prevNode insertedObject:(id)anObject {
  NSLinkNode *newNode  = [[NSLinkNode alloc] initWithObject:anObject];
  NSLinkNode *nextNode = [prevNode next];

  [newNode setPrev:prevNode];
  [newNode setNext:nextNode];

  [prevNode setNext:newNode];
  [nextNode setPrev:newNode];

  length++;
}

- (void)pushFront:(id)anObject {
  [self insertBefore:[[self head] next] insertedObject:anObject];
}

- (void)pushBack:(id)anObject {
  [self insertAfter:[[self tail] prev] insertedObject:anObject];
}

- (void)removeNode:(NSLinkNode *)aNode {
  NSLinkNode *prevNode = [aNode prev];
  NSLinkNode *nextNode = [aNode next];

  if(prevNode) {
    [prevNode setNext:nextNode];
  } else {
    //
    // removed node is head node, so 'nextNode' would be started node of
    // original link list, 'nextNode' should be placed as new head node
    // of modified link list.
    //
    [head setNext:nextNode]; // because of memeory managment, retain 'nextNode' and
                            // release 'aNode', so not coding 'head = nextNode;'
  }

  if (nextNode) {
    [nextNode setPrev:prevNode];
  } else {
    //
    // removed node is tail node, so 'prevNode' would be last node of
    // original link list, 'prevNode' should be placed as new tail node
    // of modifiied link list.
    //
    [tail setPrev:prevNode]; // because of memory management, retain 'prevNode' and
                            // release 'aNode', so not coding 'tail = prevNode;'
  }

  [aNode release];

  length--;
}

- (void)removeAllNodes {
  // use 'foreach:withObject:' to rewrite code
  NSLinkNode *current = [head next]; // set iterator from started node
  NSLinkNode *next = nil;

  while ([current next]) { // iterated until last node
    next = [current next];
    [self removeNode:current];
    current = next;
  }
}

- (BOOL)isEmpty {
  return (length == 0);
}

- (NSString *)description {
  NSString *desc;
  NSString *className = NSStringFromClass([self class]);
  desc = [NSString stringWithFormat:@"Class: %@\nLength: %d\n",
                   className, length];
  return desc;
}

/*!
 * simple ieterated for methods has no parameters
 */
- (void)foreach:(SEL)aSelector {
  [self foreach:aSelector withObject:nil];
}

- (void)foreach:(SEL)aSelector withObject:(id)anObject {
  NSLinkNode *current = [head next]; // set iterator from started node

  while ([current next]) { // iterated until last node
    if ([current respondsToSelector:aSelector]) {
             [current visitLinkNode:aSelector withObject:anObject];
    }
    current = [current next];
  }
}

- (void)traverse {
  [self foreach:@selector(displayInfo)];
}

@end

/* vim:set cinoptions=>2 shiftwidth=2: */

// 
// NSLinkList.m ends here
