// SchoolCoursesProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "BinarySearchTree.h"
using namespace std;
//print out a course and its information
void printCourseInfo(Course course) {
    if (course.courseId == "") {
        cout << "This course does not exist. Try capitalizing and checking your course id" << endl;
        return;
    }
    //case if no prereqs
    cout << course.courseId << ", " << course.courseName << endl;
        //case for if there is one prereq
        if (course.preReq1 != "") {
            //go here if there are two prereqs
            if (course.preReq1 == "") {
                cout << "Prerequisite: " << course.preReq1 << endl;
            }
            //print statement for 2 prereqs
            cout << "Prerequisites: " << course.preReq1 << ", " << course.preReq2 << endl;;
        }
    
}

void readFileandPopulate(BinarySearchTree* bst) {
    //storage for each line of the file
    string line;
    //file to be read
    ifstream CourseList ("ABCU_Advising_Program_Input.txt");

    //check if file exists and is open
    if (CourseList.is_open()) {

        while (getline(CourseList, line)) {
            //create a new course
            Course newCourse;
            stringstream ss(line);
            string courseInfo;

            //keep track of what part of course line code is on
            int counter = 1;
            //go through line and insert course information in new course
            while (getline(ss, courseInfo, ',')) {
                switch (counter) {
                case 1:
                    newCourse.courseId = courseInfo;
                    break;
                case 2:
                    newCourse.courseName = courseInfo;
                    break;
                case 3:
                    newCourse.preReq1 = courseInfo;
                    break;
                case 4:
                    newCourse.preReq2 = courseInfo;
                    break;
                default:
                    break;
                }
                counter++;
                printCourseInfo(newCourse);
            }
            //insert newly created course into bst
            bst->Insert(newCourse);
        }
    }//file cant be found or doesnt exist
    else {
        cout << "The file cant be found or doesnt exist" << endl;
    }
}

int main()
{
    //menu
    int userChoice = 0;
    string courseChoice;
    BinarySearchTree* bst = new BinarySearchTree();

    cout << "Welcome to the course planner." << endl;
    while (userChoice != 4) {
        //RESET userchoice
        userChoice = 0;
        cout << "1. Load Data Structure" << endl;
        cout << "2. Print Course List" << endl;
        cout << "3. Print Course" << endl;
        cout << "4. Exit" << endl;
        cout << "What would you like to do? ";
        cin >> userChoice;
        switch (userChoice) {
            //load the data into the bst
        case 1:
            cout << "loading data structure" << endl;
            readFileandPopulate(bst);
            cout << "data successfully loaded" << endl;
            break;
        case 2:
            //make sure bst isnt empty
            if (bst->isEmpty()) {
                cout << "The data has not been loaded. Please load data" << endl;
            }
            else {
                //print schedule contained in this bst instance
                cout << "Here is a sample schedule: " << endl;
                bst->PrintAll();
            }

            break;
        case 3:
            if (bst->isEmpty()) {
                cout << "The data has not been loaded. Please load data" << endl;
            }
            else {
                //search bst for user requested course
                cout << "What course do you want to know about?" << endl;
                cin >> courseChoice;
                cout << "loading course " << courseChoice << endl;
                printCourseInfo(bst->Search(courseChoice));
            }
            break;
        case 4:
            cout << "Thank you for using the course planner!";
            return 0;
            break;
        default:
            std::cout << userChoice << " is not a valid option." << endl;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


