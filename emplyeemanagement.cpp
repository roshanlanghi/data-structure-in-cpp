#include <iostream>
#include <string>

using namespace std;

// Employee Node Structure
class Employee {
public:
    int id;
    string name;
    double salary;
    Employee* left;
    Employee* right;

    Employee(int empID, string empName, double empSalary) {
        id = empID; 
        name = empName;
        salary = empSalary;
        left = right = NULL;
    }
};

// Employee Management BST Class
class EmployeeBST {
public:
    Employee* root;

    EmployeeBST() {
        root = NULL;
    }

    // Recursive Insert Function
    Employee* insert(Employee* node, int id, string name, double salary) {
        if (node == NULL) 
            return new Employee(id, name, salary);

        if (id < node->id)
            node->left = insert(node->left, id, name, salary);
        else if (id > node->id)
            node->right = insert(node->right, id, name, salary);
        return node;
    }

    void insertEmployee(int id, string name, double salary) {
        root = insert(root, id, name, salary);
    }

    // Search Function
    Employee* search(Employee* node, int id) {
        if (node == NULL || node->id == id)
            return node;

        if (id < node->id)
            return search(node->left, id);
        return search(node->right, id);
    }

    void searchEmployee(int id) {
        Employee* emp = search(root, id);
        if (emp)
            cout << "Found: ID: " << emp->id << ", Name: " << emp->name << ", Salary: $" << emp->salary << endl;
        else
            cout << "Employee not found!\n";
    }

    // Display (In-Order Traversal)
    void display(Employee* node) {
        if (node == NULL)
            return;
        display(node->left);
        cout << "ID: " << node->id << ", Name: " << node->name << ", Salary: $" << node->salary << endl;
        display(node->right);
    }

    void displayEmployees() {
        if (root == NULL)
            cout << "No employees to display.\n";
        else
            display(root);
    }

    // Find Minimum Salary Employee 
    Employee* findMin(Employee* node) {
        if (node == NULL || node->left == NULL)
            return node;
        return findMin(node->left);
    }

    void minSalaryEmployee() {
        Employee* minEmp = findMin(root);
        if (minEmp)
            cout << "Minimum Salary Employee: ID: " << minEmp->id << ", Name: " << minEmp->name << ", Salary: $" << minEmp->salary << endl;
        else
            cout << "No employees available.\n";
    }

    // Find Maximum Salary Employee
    Employee* findMax(Employee* node) {
        if (node == NULL || node->right == NULL)
            return node;
        return findMax(node->right);
    }

    void maxSalaryEmployee() {
        Employee* maxEmp = findMax(root);
        if (maxEmp)
            cout << "Maximum Salary Employee: ID: " << maxEmp->id << ", Name: " << maxEmp->name << ", Salary: $" << maxEmp->salary << endl;
        else
            cout << "No employees available.\n";
    }

    // Calculate Total Salary & Count Employees
    double totalSalary(Employee* node, int &count) {
        if (node == NULL)
            return 0;

        count++;
        return node->salary + totalSalary(node->left, count) + totalSalary(node->right, count);
    }

    void averageSalary() {
        int count = 0;
        double total = totalSalary(root, count);
        if (count == 0)
            cout << "No employees to calculate salary.\n";
        else
            cout << "Average Salary: $" << total / count << endl;
    }

    // Count Employees 
    int countEmployees(Employee* node) {
        if (node == NULL)
            return 0;
        return 1 + countEmployees(node->left) + countEmployees(node->right);
    }

    void totalEmployees() {
        cout << "Total number of employees: " << countEmployees(root) << endl;
    }
};


int main() {
    EmployeeBST company;
    int choice, id;
    string name;
    double salary;

    while (true) {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Display Employees\n";
        cout << "4. Find Minimum Salary Employee\n";
        cout << "5. Find Maximum Salary Employee\n";
        cout << "6. Calculate Average Salary\n";
        cout << "7. Total Employees Count\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Employee Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Employee Salary: ";
                cin >> salary;
                company.insertEmployee(id, name, salary);
                break;

            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                company.searchEmployee(id);
                break;

            case 3:
                company.displayEmployees();
                break;

            case 4:
                company.minSalaryEmployee();
                break;

            case 5:
                company.maxSalaryEmployee();
                break;

            case 6:
                company.averageSalary();
                break;

            case 7:
                company.totalEmployees();
                break;

            case 8:
                cout << "Exiting the program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

return 0;
}
