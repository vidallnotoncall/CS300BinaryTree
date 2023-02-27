#pragma once

#include <string>
using namespace std;
// define a structure to hold bid information
struct Course {
    string courseId; // unique identifier
    string courseName;
    //may not have preReqs so they need to be blank
    string preReq1;
    string preReq2;

    Course() {
        preReq1 = "";
        preReq2 = "";
    }

};

// Internal structure for tree node
struct Node {
    Course course;
    Node* left;
    Node* right;

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a course
    Node(Course aCourse) :
        Node() {
        this->course = aCourse;
    }
};
class BinarySearchTree
{
private:
    Node* root;
    void addNode(Node* node, Course course);
    void printAll(Node* node);
public:

    BinarySearchTree();
    void Insert(Course course);
    Course Search(string courseId);
    bool isEmpty();
    void PrintAll();
};


