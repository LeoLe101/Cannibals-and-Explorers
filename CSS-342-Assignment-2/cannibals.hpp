//
//  cannibals.hpp
//  CSS-342-Assignment-2
//
//  Created by Leo Le on 10/22/17.
//  Copyright © 2017 Leo Le. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class cannibals
{
public:
    //Constructors
    /**
     Default constructor of the cannibals class
     */
    cannibals();
    
    vector<string> getOutput() const;
    
    vector<string> getAttempt() const;
    
    /**
     Solving for the scenario
     
     @param cleft The array of cannibals on the left
     @param eleft The array of explorers on the left
     */
    int solve(int cleft, int eleft, int eright, int cright, int boatps);

    //add attempt to list in order to keep track
    vector<string> attempted(int cleft, int eleft, int eright, int cright, int boatps);
    
    //display
    void display();
    void displayAttempt(); //testing purpose
    
private:
    //vector of string to hold the output
    vector<string> output;
    //vector of string to hold different attempts
    vector<string> attempt;
    vector<int> executed;
};
