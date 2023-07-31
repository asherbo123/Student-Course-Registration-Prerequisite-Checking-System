#include <iostream>
#include <string>
using namespace std;

class node {
public:
	string course;
	node* left;
	node* right;

	node(string item) 
	{
		course = item;
		left = right = NULL;
	}
};
class BST {

public:
	node* root; 
	node* r;
	BST() 
	{
		root = NULL;
		r = NULL;
	}
	node* insert(node* pnode, string newCourse, string dep) {
		if (pnode == NULL) {
			node* newNode = new node(newCourse);
			pnode = newNode;
		}
		else {
			search(pnode, dep);
			if (r->left == NULL) //r = pre req
				r->left = insert(r->left, newCourse, dep);
			else if (r->right == NULL)
				r->right = insert(r->right, newCourse, dep);
		}

		return pnode;
	}
	void insert(string newCourse, string dep) {
		root = insert(root, newCourse, dep);
	}

	void search(node* list, string dep) {

		if (list != NULL) {
			if (list->course == dep)
				r = list;
			else {
				search(list->right, dep);
				search(list->left, dep);


			}
		}

	}

	bool checkCourse(string studiedCourses[], string s)
	{

		bool check = false;


		for (int i = 0; i <= 2; i++) {
			search(root, studiedCourses[i]);
			if (r->left->course == s)
			{
				check = true;
				return check;
			}
			else if (r->right->course == s) {
				check = true;
				return check;
			}

		}
		return check;
	}
};


int main() {
	BST list;


	list.insert("101Introduction to Programming", "");
	list.insert("207Fundamental of Data Structures & Algorithms", "101Introduction to Programming");
	list.insert("311Computer Architecture", "101Introduction to Programming");
	list.insert("217Advanced Computer Programming & Concepts", "207Fundamental of Data Structures & Algorithms");
	list.insert("313Software Engineering", "311Computer Architecture");
	list.insert("415Compiler Design", "311Computer Architecture");
	list.insert("304Analysis and Design of Algorithms", "217Advanced Computer Programming & Concepts");
	list.insert("419Theory of Computing", "217Advanced Computer Programming & Concepts");
	list.insert("315Operating Systems", "313Software Engineering");
	list.insert("404Database Systems", "313Software Engineering");



	string studiedCourses[3];
	string newCourses[3];
	string denied[3] = { "", "", "" };
	cout << "Enter the courses which you already studied: " << endl;
	for (int i = 0; i <= 2; i++) {
		getline(cin, studiedCourses[i]);
	}
	cout << endl;
	cout << "Enter the courses that you want to study: " << endl;
	for (int i = 0; i <= 2; i++) {
		getline(cin, newCourses[i]);
	}
	cout << endl << endl;
	cout << "Processing...";
	cout << endl << endl;

	cout << "The following courses are OK to take: " << endl;
	for (int i = 0; i <= 2; i++) {
		bool c = list.checkCourse(studiedCourses, newCourses[i]);
		if (c == true)
			cout << newCourses[i] << endl;
		else
			denied[i] = newCourses[i];
	}
	cout << endl;
	cout << "The following courses are CANNOT be taken: " << endl;
	for (int i = 0; i <= 2; i++) {
		if (denied[i] != "")
			cout << denied[i] << endl;
	}
}