/* Std_Dev_Calc.cpp : This file contains the 'main' function.Program execution begins and ends there.
/*
Colin Harding
Std_Dev_Calc.cpp
8/25/21
This program is used to calculate the Standard Deviation of any number of grades






*/

#include <iostream>
#include <string>
#include <ctype.h> 
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;


int main()
{
    //s1 Welcome Messages
    //e is arbitrary... just to end early
    cout << "Standard Deviation Calculator\n"
            "========================================\n"
            ">> PRESS  return/enter to submit\n"
            ">> ENTER \"e\" to end program\n"
            ">> All grades should be entered contiguously with a space as a buffer.\n"
            "========================================\n";
    //end s1

    bool run = true;
    do { // continuously run the calculator
        
        //s2 grade entering
        cout << "Enter Your Grades on the Line Below\n";//
        string input;
        vector<double> gradeColl;
        double grade = 0;
        getline(cin, input);
        stringstream t(input);
        
        if (input[0] == 'e') {
            exit(0);
        }

        while (t >> grade) {
            gradeColl.push_back(grade);
        }
        //s2 end
        
       /*
       //s2 alt grade entering

       string input;
       vector<double> gradeColl;

       do {
           cout << "Enter New Grade\n";
           cin >> input;

           //exit
           if (input[0] == 'e') {
               exit(0);
           }

           //take input
           if (isdigit(input[0])) {
               //"is"
               stringstream t(input);
               double grade = 0;
               t >> grade;
               gradeColl.push_back(grade);
           }

           //invalid input
           if (input[0] != 'c' && !isdigit(input[0])) {
               cout << "invalid input try again\n";
               input[0] = '0';
           }

       } while (isdigit(input[0]));
       //s2 alt end
       */


       /*
       //check vector
       cout << "vector:\n";

       for (auto i = gradeColl.begin(); i != gradeColl.end(); ++i)
           cout << *i << " ";

       cout << "\n";
       */

       //s3 Calculation of S.D.
        double sum = 0;
        double mean = 0;
        double sumMean = 0;
        double popSize = gradeColl.size();


        for (auto i = gradeColl.begin(); i != gradeColl.end(); ++i)
            sumMean += *i;
        mean = sumMean / gradeColl.size();

        for (auto i = gradeColl.begin(); i != gradeColl.end(); ++i)
            sum += (*i - mean) * (*i - mean);


        double stdDev = sqrt(sum / popSize);
        //s3 end



        //s4 End reslut
        cout << "The S.D.: " << stdDev << "\n";
        //s4 end

        //s5 Restart calculation process
        char r = 'y';
        cout << "To run again submit \"y\"\n"
            "To exit submit \"n\"\n";

        cin >> r;

        if (r != 'y') {
            run = false;
        }
        getline(cin, input);//its set to input because everything will be reset.
        //s5 end

    } while (run);
    exit(0);
}//end main
//Don't use "beef stew" as a computer password. It's not stroganoff.

