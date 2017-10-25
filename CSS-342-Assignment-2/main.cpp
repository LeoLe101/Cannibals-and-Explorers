//
//  main.cpp
//  CSS-342-Assignment-2
//
//  Created by Leo Le on 10/19/17.
//  Copyright © 2017 Leo Le. All rights reserved.
//

#include <iostream>
#include <string>
#include "cannibals.hpp"
using namespace std;

int main()
{
    int cl = 3;
    int el = 3;
    int er = 0;
    int cr = 0;
    int b = 0; //1 - right and 0 - left

    cout << "Sequence of Moves:" << endl;
    cannibals c;
    c.solve(cl, el, er, cr, b);
    c.display();
    c.displayAttempt();
    return 0;
}


