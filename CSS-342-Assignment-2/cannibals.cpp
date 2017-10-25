//
//  cannibals.cpp
//  CSS-342-Assignment-2
//
//  Created by Leo Le on 10/22/17.
//  Copyright © 2017 Leo Le. All rights reserved.
//

#include "cannibals.hpp"

//Constructors
/**
 Default constructor of the cannibals class
 */
cannibals::cannibals()
{
    executed.assign(11, 0);
    output.push_back("EEECCC \\--/         ------");
}

//getter
vector<string> cannibals::getOutput() const
{
    return this->output;
}

vector<string> cannibals::getAttempt() const
{
    return this->attempt;
}

//display
void cannibals::display()
{
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
}

//display for testing only!
void cannibals::displayAttempt()
{
    for (int i = 0; i < attempt.size(); i++) {
        cout << attempt[i] << endl;
    }
}

vector<string> cannibals::attempted(int cleft, int eleft, int eright, int cright, int boatps)
{
    attempt.push_back("Attempt: " + to_string(cleft) + to_string(eleft) + to_string( eright) + to_string(cright) + to_string(boatps));
    return attempt;
}

//boatps = 0 when the boat is on the left
//boatps = 1 when the boat is on the right
int cannibals::solve(int cleft, int eleft, int eright, int cright, int boatps)
{
    //condition check: 0 is true & 1 is false
    int check = 1;
    //string move = "Attempt: " + to_string(cleft) + to_string(eleft) + to_string( eright) + to_string(cright) + to_string(boatps);
    //Base case: all 3 explorers & 3 cannibals are on the right side
    if (cright == 3 && eright == 3 && boatps == 1) {
        check = 0;
        return check; //end the recursion
    }
        //Invalid case: cannibals(3) > explorers(1 or 2) on the right side
        else if (cright == 3 && eright > 0 && eright < 3)
        {
            check = 1;
            if (eright == 1) {
                //add to attempt to keep track
                attempted(cleft, eleft, eright, cright, boatps);
                return check;
            }
            else
            {
                //add to attempt to keep track
                attempted(cleft, eleft, eright, cright, boatps);
                return check;
            }
        }
        //Invalid case: cannibals(3) > explorers(1 or 2) on the left side
        else if (cleft == 3 && eleft > 0 && eleft < 3)
        {
            check = 1;
            if (eleft == 1) {
                //add to attempt to keep track
                attempted(cleft, eleft, eright, cright, boatps);
                return check;
            }
            else
            {
                //add to attempt to keep track
                attempted(cleft, eleft, eright, cright, boatps);
                return check;
            }
        }
        //Invalid case: cannibals(2) > explorers(1) on the right side
        else if (cright == 2 && eright == 1)
        {
            check = 1;
            //add to attempt to keep track
            attempted(cleft, eleft, eright, cright, boatps);
            return check;
        }
        //Invalid case: cannibals(2) > explorers(1) on the left side
        else if (cleft == 2 && eleft == 1)
        {
            check = 1;
            //add to attempt to keep track
            attempted(cleft, eleft, eright, cright, boatps);
            return check;
        }
    //Recursion process
    else
    {
        //add to attempt to keep track
        attempted(cleft, eleft, eright, cright, boatps);
        //Boat is on the left
        if (boatps == 0)
        {
            if (executed.at(0) != 1)
            {
                executed.at(0) = 1;
                check = solve(cleft - 1, eleft - 1, eright + 1, cright + 1, 1);
                if (check == 0)
                {
                    output.push_back("CC-EE-     \\EC/-->     ------");
                    output.push_back("CC-EE-            \\--/ E--C--");
                }
            }
            else
            {
                if (executed.at(2) != 1)
                {
                    executed.at(2) = 1;
                    check = solve(cleft - 2, eleft, eright, cright + 2,  1);
                    if (check == 0)
                    {
                        output.push_back("---EEE     \\CC/-->     ------");
                        output.push_back("---EEE            \\--/ ---CCC");
                    }
                }
                else
                {
                    if (executed.at(4) != 1)
                    {
                        executed.at(4) = 1;
                        check = solve(cleft, eleft - 2, eright + 2, cright,  1);
                        if (check == 0)
                        {
                            output.push_back("C--E--     \\EE/-->     ---CC-");
                            output.push_back("C--E--            \\--/ EE-CC-");
                        }
                    }
                    else
                    {
                        if (executed.at(6) != 1)
                        {
                            executed.at(6) = 1;
                            check = solve(cleft, eleft - 2, eright + 2, cright,  1);
                            if (check == 0)
                            {
                                output.push_back("CC----     \\EE/-->     E--C--");
                                output.push_back("CC----            \\--/ EEEC--");
                            }
                        }
                        else
                        {
                            if (executed.at(8) != 1)
                            {
                                executed.at(8) = 1;
                                check = solve(cleft - 2, eleft, eright, cright + 2,  1);
                                if (check == 0) {
                                    output.push_back("C-----     \\CC/-->     EEE---");
                                    output.push_back("C-----            \\--/ EEECC-");
                                }
                            }
                            else
                            {
                                if (executed.at(10) != 1)
                                {
                                    executed.at(10) = 1;
                                    check = solve(cleft - 2, eleft, eright, cright + 2,  1);
                                    if (check == 0)
                                    {
                                        output.push_back("------     \\CC/-->     EEEC--");
                                        output.push_back("------            \\--/ EEECCC");
                                        output.push_back("       End of Sequence!       ");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        //Boat is on the right
        else
        {
            if (executed.at(1) != 1)
            {
                executed.at(1) = 1;
                check = solve(cleft, eleft + 1, eright - 1, cright, 0);
                if (check == 0)
                {
                    output.push_back("CC-EE-     <--\\E-/     ---C--");
                    output.push_back("CC-EEE \\--/            ---C--");
                }
            }
            else
            {
                if (executed.at(3) != 1)
                {
                    executed.at(3) = 1;
                    check = solve(cleft + 1, eleft, eright, cright - 1, 0);
                    if (check == 0)
                    {
                        output.push_back("---EEE     <--\\-C/     ---CC-");
                        output.push_back("C--EEE \\--/            ---CC-");
                    }
                }
                else
                {
                    if (executed.at(5) != 1)
                    {
                        executed.at(5) = 1;
                        check = solve(cleft + 1, eleft + 1, eright - 1, cright - 1, 0);
                        if (check == 0)
                        {
                            output.push_back("C--E--     <--\\EC/     E--C--");
                            output.push_back("CC-EE- \\--/            E--C--");
                        }
                    }
                    else
                    {
                        if (executed.at(7) != 1)
                        {
                            executed.at(7) = 1;
                            check = solve(cleft + 1, eleft, eright, cright - 1, 0);
                            if (check == 0)
                            {
                                output.push_back("CC----     <--\\-C/     EEE---");
                                output.push_back("CCC--- \\--/            EEE---");
                            }
                        }
                        else
                        {
                            if (executed.at(9) != 1)
                            {
                                executed.at(9) = 1;
                                check = solve(cleft + 1, eleft, eright, cright - 1, 0);
                                if (check == 0)
                                {
                                    output.push_back("C-----     <--\\-C/     EEEC--");
                                    output.push_back("CC---- \\--/            EEEC--");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return check;
}











