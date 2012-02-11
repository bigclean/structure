/* NSLinkList.h --- 
 * 
 * Filename: NSLinkList.h
 * Description: 
 * Author: Bigclean Cheng
 * Created: Wed Nov 16, 22:45 2011
 * Last-Updated: Thu Dec 15, 23:56 2011
 */

/* Code: */

/*!
 * \file NSLinkList.h
 * \brief Objective-c double link list.
 * \note Because GNUstep doesn't support Objective-2.0, so accessor and
 *          mutator methods should be written explicitly.
 * \sa <a href="http://wiki.gnustep.org/index.php/ObjC2_FAQ">GNUstep Objc2 FAQ</a>
 */

#import <Foundation/Foundation.h>
#import "NSLinkNode.h"

// Objective-c link list
@interface NSLinkList : NSObject {
  NSLinkNode   *head;
  NSLinkNode   *tail;
  unsigned int length;
}

// double link list methods declaration

- (id)init;

- (void)dealloc;

@property (retain) NSLinkNode *head;
@property (retain) NSLinkNode *tail;
@property unsigned int length;

- (void)insertBefore:(NSLinkNode *)nextNode insertedObject:(id)anObject;

- (void)insertAfter:(NSLinkNode *)prevNode insertedObject:(id)anObject;

/*!
 * \brief insert object as start valid node.
 * \param anObject inserted object
 */
- (void)pushFront:(id)anObject;

/*!
 * \brief insert object as last valid node.
 * \param anObject inserted object
 */
- (void)pushBack:(id)anObject;

/*!
 * \brief remove selected node from list
 * \param aNode removed node
 * \note Even remove head or tail node is legal!
 */
- (void)removeNode:(NSLinkNode *)aNode;

/*!
 * \brief remove all valid nodes
 * \note Head and tail nodes is always preserved.
 */
- (void)removeAllNodes;

- (BOOL)isEmpty;

- (NSString *)description;

/*!
 * \brief perform specialized selector to each node
 * \param aSelector performed selector
 * \note
 *   \li NSLinkNode should respond to selected selector.
 *   \li Extend selector using Objective-c category.
 */
- (void)foreach:(SEL)aSelector;

/*!
 * \brief perfrom specialized selector to each node
 * \param aSelector performed selector
 * \param anObject extra related parameter to performed selector
 * \note
 *   \li NSLinkNode should respond to selected selector.
 *   \li Extend selector using Objective-c category.
 */
- (void)foreach:(SEL)aSelector withObject:(id)anObject;

- (void)traverse;

@end

// alias definition
typedef NSLinkList *NSLinkListPtr; /*!< general link list pointer */

enum traverseMode {
        FORWARD,
        REVERSE
};

/* vim:set cinoptions=>2 shiftwidth=2: */

/* NSLinkList.h ends here */
