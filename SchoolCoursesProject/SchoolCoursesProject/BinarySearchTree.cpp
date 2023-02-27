#include "BinarySearchTree.h"
#include <string>
#include <iostream>

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    //root is equal to nullptr
    root = nullptr;
}

void BinarySearchTree::Insert(Course course) {
    //if there is no root make course the new root
	if (root == nullptr) {
		root = new Node(course);
	}
	else {
        //if there is a root add the new course to the tree
		this->addNode(root, course);
	}
}

void BinarySearchTree::addNode(Node* node, Course course) {
    // if course name comes before then add to left
    // if no left node
        // this node becomes left
    if (node->course.courseId > course.courseId) {
        if (node->left == nullptr) {
            node->left = new Node(course);
        }
        // else recurse down the left node
        else {
            this->addNode(node->left, course);
        }

    }
    else {
        // if no right node            
        // this node becomes right
        if (node->right == nullptr) {
            node->right = new Node(course);
        }
        else {
            // recurse down the right node
            this->addNode(node->right, course);
        }
    }
}

void BinarySearchTree::printAll(Node* node) {
    //exit condition for recursion
        //if the current node is null exit recursion
    if (node == nullptr) {
        return;
    }
    printAll(node->left);
    cout << node->course.courseId << ", " << node->course.courseName << endl;
    printAll(node->right);
}


Course BinarySearchTree::Search(string courseId) {
    // set current node equal to root
    Node* current = root;
    // keep looping downwards until bottom reached or matching bidId found

    while (current != nullptr) {
        // if match found, return current bid
        if (current->course.courseId.compare((courseId)) == 0) {
            return current->course;
        }
        // if bid is larger than current then traverse left
        if (current->course.courseId.compare(courseId) > 0) {
            current = current->left;
        }
        else {
            // else smaller so traverse right
            current = current->right;
        }
    }
    Course course;
    return course;
}

bool BinarySearchTree::isEmpty() {
    //if the root is empty the tree must be empty
    if (this->root == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void BinarySearchTree::PrintAll() {
    //access private print all function
    this->printAll(root);
}