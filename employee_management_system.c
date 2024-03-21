#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Structure to represent an employee
struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
};

// Array to store employees
struct Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

// Function to add a new employee
void addEmployee() {
    struct Employee newEmployee;
    
    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.id);
    printf("Enter employee name: ");
    scanf("%s", newEmployee.name);
    printf("Enter employee age: ");
    scanf("%d", &newEmployee.age);
    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);
    
    employees[numEmployees++] = newEmployee;
    printf("Employee added successfully.\n");
}

// Function to update information of an employee
void updateEmployee() {
    int employeeId, choice;
    int found = 0;
    
    printf("Enter employee ID to update: ");
    scanf("%d", &employeeId);
    
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == employeeId) {
            printf("1. Update Name\n");
            printf("2. Update Age\n");
            printf("3. Update Salary\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            
            switch(choice) {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", employees[i].name);
                    break;
                case 2:
                    printf("Enter new age: ");
                    scanf("%d", &employees[i].age);
                    break;
                case 3:
                    printf("Enter new salary: ");
                    scanf("%f", &employees[i].salary);
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            printf("Employee information updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee not found.\n");
    }
}

// Function to view details of all employees
void viewEmployees() {
    if (numEmployees == 0) {
        printf("No employees in the database.\n");
    } else {
        printf("Employee Database:\n");
        printf("ID\tName\tAge\tSalary\n");
        for (int i = 0; i < numEmployees; i++) {
            printf("%d\t%s\t%d\t%.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
        }
    }
}

// Function to remove an employee from the database
void removeEmployee() {
    int employeeId;
    int found = 0;
    
    printf("Enter employee ID to remove: ");
    scanf("%d", &employeeId);
    
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == employeeId) {
            for (int j = i; j < numEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            numEmployees--;
            printf("Employee removed from database successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee not found.\n");
    }
}

int main() {
    int choice;
    
    while(1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Update Employee Information\n");
        printf("3. View Employees\n");
        printf("4. Remove Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                updateEmployee();
                break;
            case 3:
                viewEmployees();
                break;
            case 4:
                removeEmployee();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
