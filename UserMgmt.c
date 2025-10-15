#include<stdio.h>

#define MAX_USERS 15 
/*
# define is a preprocessor directive in C whose purpose is to create macros, 
which are symbolic names or constants that are substituted by the preprocessor 
before the actual compilation process begins.
*/
typedef struct { // Custom data type for this system
    char username[60];
    char password[60];
} User; // Defining a structure named 'User'

User users[MAX_USERS];
int user_count = 0;

void RegisterUser();
int LoginUser(); // Returns the user index who has login

int main() {
    int action;

    while(1) {
        printf("\n Welcome to User Management system\n");
        printf("\n 1. Register new user");
        printf("\n 2. Sign-in (existing user)");
        printf("\n 3. Exit");
        printf("\n Select your Action : ");
        scanf("%d", &action);

        switch (action)
        {
        case 1:
            RegisterUser();  
            break;
        case 2:
            int index = LoginUser();

            if(index >=0) {
                printf("\nLogin successful\n");
                printf("\nWelcome %s\n", users[index].username);
            } else {
                printf("\nInvalid username or password. Login failed!\n");
            }
            break;
        case 3:
            printf("\n Exiting User management system.");
            printf("\n Thank you for using this system! Please visit again");
            return 0;
            break;
        default:
            printf("\n Invalid action!");
            printf("\n Please try again with a valid action");
            break;
        }
    }
    

    return 0;
}

void RegisterUser() {
    printf("Dummy Registration");
}
int LoginUser() {
    printf("Dummy login");
    return -1;
}