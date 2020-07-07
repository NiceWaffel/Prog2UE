#include "LinkedList.h"
#include "IntegerClass.h"

int main() {
	LinkedList<IntegerClass> ll;

	IntegerClass i1(1);
	IntegerClass i2(2);
	IntegerClass i3(3);
	IntegerClass i4(4);

	ll.append(i1);
	ll.append(i2);
	ll.append(i3);
	ll.insert(1, i1);

	ll.print();
}
