#include "LinkedList.h"
#include <iostream>
using namespace std;

/*int main(){
    cout << "enter main " << endl;
    LinkedList*l = new LinkedList(new double(47.1), NULL);
    l->add(l->head, 5);
    l->add(l->head->next->next, 5);
    l->print();
    l->cleanup();

}*/

#include <iostream>
#include "LinkedList.h"

using namespace std;
int main(int argc, const char * argv[])
{
    LinkedList * linkedList = new LinkedList(new double(47.1), NULL);
    linkedList->add(linkedList->head, 5);
    linkedList->add(linkedList->head->next->next, 5);
    linkedList->print();
    
    linkedList->cleanup();
    
    return 0;
}
