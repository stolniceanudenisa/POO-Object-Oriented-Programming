#include "teste.h"
#include "patrat.h"
#include <assert.h>
#include <iostream>

void teste()
{
    Patrat my_square(5);

    // Test the getter method
    assert(my_square.getLatura() == 5);

    // Test the setter method
    my_square.setLatura(7);
    assert(my_square.getLatura() == 7);

    cout << "Testele au trecut!" << std::endl;
}
