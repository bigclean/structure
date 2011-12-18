#include <string>

#define LINK_LIST_TEST

#ifdef LINK_LIST_TEST
    #include "link_list.h"
#endif

int
link_list_test()
{
        LinkNode<string> node = LinkNode<string>("hello");
        LinkList<string> list;

        const string str1("Hello, world.");
        const string str2("Hope is a good thing.");
        const string str3("Walking all the way taking you.");
        const string str4("Let's get started.");

        list.PushFront(str1);
        list.PushFront(str2);
        list.InsertBefore(list.GetHead()->GetNext(), str3);

        LinkList<string>::Foreach(&list, LinkNode<string>::Visit);
        list.PopFront();
        LinkList<string>::Foreach(&list, LinkNode<string>::Visit);
        list.PopBack();
        LinkList<string>::Foreach(&list, LinkNode<string>::Visit);

        return 1;
}

int main(int argc, char **agrv)
{
#ifdef LINK_LIST_TEST
        cout << "-------- Begin Link List tests --------" << endl;
        link_list_test(); // test link list
        cout << "-------- End Link List tests --------" << endl;
#endif
        return 1;
}
