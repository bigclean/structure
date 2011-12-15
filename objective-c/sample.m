#import <assert.h>

#define NSLINKLIST_TEST

#ifdef NSLINKLIST_TEST
  #import "NSLinkList.h"
#endif

void
NSLinkListTest() {
  NSLinkList *list = [[NSLinkList alloc] init];
  assert(list);

  NSString *str1 = @"Hello, world.";
  NSString *str2 = @"Hope is a good thing.";
  NSString *str3 = @"Walking all the way taking you.";
  NSString *str4 = @"Let's get started.";

  [list pushFront:str1];
  [list insertAfter: [[list head] next] insertedObject:str2];
  [list insertBefore:[[list head] next] insertedObject:str3];

  // prints out
  [list traverse];
  [list foreach:@selector(extendContents:) withObject:str4];

  NSLog([list description]);

  [list removeAllNodes];

  NSLog([list description]);
}

int
main(int argc, const char *argv[]) {
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

#ifdef NSLINKLIST_TEST
  NSLog(@"-------- Begin NSLinkList tests --------");
  NSLinkListTest();
  NSLog(@"-------- End NSLinkList tests --------");
#endif

  // ends
  [pool drain];

  return 0;
}
/* vim:set cinoptions=>2 shiftwidth=2: */
