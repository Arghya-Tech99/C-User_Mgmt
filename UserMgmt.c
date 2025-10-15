#include<stdio.h>
#include<string.h>

#define MAX_USERS 15 
#define CREDENTIAL_LENGTH 60 
/*
# define is a preprocessor directive in C whose purpose is to create macros, 
which are symbolic names or constants that are substituted by the preprocessor 
before the actual compilation process begins.
*/
typedef struct { // Custom data type for this system
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
} User; // Defining a structure named 'User'

User users[MAX_USERS];
int user_count = 0;

void RegisterUser();
int LoginUser(); // Returns the user index who has login
void fix_fgets_input(char*); // Rectifies the username and exludes ENTER (\n) character from username
void fix_fgets_password(char*); // Rectifies the password
 
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
            int user_index = LoginUser();

            if(user_index >=0) {
                printf("\nLogin successful\n");
                printf("\nWelcome %s\n", users[user_index].username);
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
    if (user_count == MAX_USERS) {
        printf("\n No more User registrations allowed!\n");
        printf("\n Maximum users supported : %d", MAX_USERS);
    } 

    int new_index = user_count;

        printf("\n Register a new user\n");

        /* TAKES-IN USERNAME */
        printf("\n Enter Username : ");
        fgets(users[new_index].username, CREDENTIAL_LENGTH, stdin); // Using fgets() to read and store username 
        // fgets() also recognises ENTER (\n) as a character which is not part of username.
        // Need to rectify the input from fgets()
        fix_fgets_input(users[new_index].username); 

        /* TAKES IN PASSWORD WITH MASKING ENABLED*/
        printf("\n Enter Password (Masking enabled) : ");
        fgets(users[new_index].password, CREDENTIAL_LENGTH, stdin); // displays the characters in password
        // rectification required, masking of the characters needed.
        fix_fgets_password(users[new_index].password);

        user_count++;

    
    
    
    // printf("Dummy Registration");
}

void fix_fgets_input(char* string) {
    int index = strcspn(string, "\n");
    string[index] = '\0';

}

void fix_fgets_password(char* password) {
    
}

int LoginUser() {
    printf("Dummy login");
    return -1;
}