/* NSLinkNode.h --- 
 * 
 * Filename: NSLinkNode.h
 * Description: node of double link list header
 * Author: Bigclean Cheng
 * Created: Wed Nov 16, 22:41 2011
 * Last-Updated: Thu Dec 15, 23:56 2011
 */

/* Code: */

/*!
 * \file NSLinkNode.h
 * \brief node of double link list header
 * \note I wonder if that using C standard structure representing NSLinkNode
 *         would be a better choice.
 * \note Because GNUstep doesn't support Objective-2.0, so accessor and
 *         mutator methods should be written explicitly.
 * \sa <a href="http://wiki.gnustep.org/index.php/ObjC2_FAQ">GNUstep Objc2 FAQ</a>
 */

#import <Foundation/Foundation.h>

@interface NSLinkNode : NSObject {
  id         obj;      /*!< generic data */
  NSLinkNode *prev;
  NSLinkNode *next;
}

// node of double link list methods declaration
- (id)init;

- (id)initWithObject:(id)anObject;

- (void)dealloc;

@property (retain) id obj;

@property (retain) NSLinkNode *prev;

@property (retain) NSLinkNode *next;

- (NSString *)description;

- (void)visitLinkNode:(SEL)aSelector;

- (void)visitLinkNode:(SEL)aSelector withObject:(id)anObject;

@end

typedef NSLinkNode *NSLinkNodePtr;    /*!< general node pointer */

/* vim:set cinoptions=>2 shiftwidth=2: */

/* NSLinkNode.h ends here */
