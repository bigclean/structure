// NSLinkNode.m --- 
// 
// Filename: NSLinkNode.m
// Description: node of double link list implementation
// Author: Bigclean Cheng
// Created: Wed Nov 16, 22:42 2011
// Last-Updated: Thu Dec 15, 23:56 2011
// 

// Code:

/*!
 * \file NSLinkNode.m
 * \brief node of double link list implementation
 */
#import "NSLinkNode.h"

@implementation NSLinkNode

- (id)init {
  if (self = [self initWithObject:nil]) {
  }
  return self;
}

- (id)initWithObject:(id)anObject {
  if (self = [super init]) {
    obj  = anObject;
    prev = next = nil;
  }
  return self;
}

- (void)dealloc {
  [obj   release];
  [prev  release];
  [next  release];

  [super dealloc];
  NSLog(@"Deaclloc node success.");
}

@synthesize obj;
@synthesize prev;
@synthesize next;

- (NSString *)description {
  NSString *desc;
  NSString *className = NSStringFromClass([obj class]);
  // XXX: needs container type and contents
  desc = [NSString stringWithFormat:@"Data Class: %@\nContents: %@\n",
                   className, [obj description]];
  return desc;
}

- (void)displayInfo {
  NSLog([self description]);
}

- (void)extendContents:(id)extraObj {
  NSMutableString *endInfo;
  endInfo = [NSMutableString stringWithCapacity:70];
  [endInfo appendString:extraObj];
  [endInfo appendString:[self description]];

  NSLog(endInfo);
}

- (void)visitLinkNode:(SEL)aSelector {
  [self visitLinkNode:aSelector withObject:nil];
}

- (void)visitLinkNode:(SEL)aSelector withObject:(id)anObject {
  if ([self respondsToSelector:aSelector]) {
         [self performSelector:aSelector withObject:anObject];
  }
}

@end

/* vim:set cinoptions=>2 shiftwidth=2: */

// 
// NSLinkNode.m ends here
