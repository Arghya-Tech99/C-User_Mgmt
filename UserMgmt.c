#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

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

User users[MAX_USERS]; // Defining an array of User type
int user_count = 0;

void RegisterUser();
int LoginUser(); // Returns the user index who has login
void fix_fgets_input(char*); // Rectifies the username and exludes ENTER (\n) character from username
void input_credentials(char* username, char* password);
 
int main() {
    int action;
    int user_index;

    while(1) {
        printf("\n Welcome to User Management system\n");
        printf("\n 1. Register new user");
        printf("\n 2. Sign-in (existing user)");
        printf("\n 3. Exit");
        printf("\n Select your Action : ");
        scanf("%d", &action);
        getchar(); // Consume the extra ENTER

        switch (action)
        {
        case 1:
            RegisterUser();  
            break;
        case 2:
            user_index = LoginUser();

            if(user_index >=0) {
                printf("\nLOGIN SUCCESSFUL");
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

    /* TAKES-IN USERNAME AND PASSWORD */
    input_credentials(users[new_index].username, users[new_index].password);
    // mask_password(users[new_index].password); // Masks the password in real-time on terminal
    user_count++;
    printf("\n REGISTRATION SUCCESSFUL!\n");
}

void input_credentials(char* username, char* password) {
    int i = 0;
    char ch;

    /* INPUTS USERNAME */
    printf("\n Enter Username : ");
    fgets(username, CREDENTIAL_LENGTH, stdin); // Using fgets() to read and store username 
    // fgets() also recognises ENTER (\n) as a character which is not part of username.
    fix_fgets_input(username); // Rectifying the input username from fgets()

    /* INPUTS PASSWORD AND MASKS IT */
    printf("Enter Password (Masking enabled) : ");

    int max_len = sizeof(password) - 1;
    while(i < max_len) {
        // fgets(password, CREDENTIAL_LENGTH, stdin);
        ch = _getch(); // _getch() reads a single character without echoing it to the terminal.

        // Check for termination keys (Enter, Newline)
        if (ch == '\r' || ch == '\n') {
            fix_fgets_input(password); // rectify so that ENTER (\n) is not password character
            break; 
        } 

        // Handle backspace (delete a character)
        else if (ch == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b"); // Overwrite the last '*' with a space, then move cursor back
                fflush(stdout); // Ensure the change is immediately displayed
            }
            continue; // Ignore backspace if the buffer is empty
        } 

        // Handle regular printable characters
        else if (ch >= 32 && ch <= 126) { // Check for standard printable ASCII characters
            password[i] = ch; // Store the character in the buffer
            i++;            // Increment the index
            printf("*");    // Print * to mask
            fflush(stdout); // Ensure the '*' appears immediately
        }
    }

    // Terminate the string
    password[i] = '\0';

    // fgets(password, CREDENTIAL_LENGTH, stdin); --> USED TO GET UNMASKED PASSWORD
    // fix_fgets_input(password); --> RECTIFY UNMASKED PASSWORD
    
}

void fix_fgets_input(char* string) {
    int index = strcspn(string, "\n");
    string[index] = '\0';
}

int LoginUser() {
    // creating temporary username and password to check while login
    char temp_username[CREDENTIAL_LENGTH];
    char temp_password[CREDENTIAL_LENGTH];

    int i = 0; char ch;

    /* TAKES USERNAME FOR LOGIN*/
    printf("\n Enter Username to sign-in : ");
    fgets(temp_username, CREDENTIAL_LENGTH, stdin); // Using fgets() to read username 
    fix_fgets_input(temp_username); // Rectifies the username 

    /* TAKES PASSOWRD AND MASKS FOR LOGIN*/
    printf("Enter Password to sign-in : ");
    int max_len2 = sizeof(temp_password) - 1;
    while(i < max_len2) {
        ch = _getch(); // _getch() reads a single character without echoing it to the terminal.

        // Check for termination keys (Enter, Newline)
        if (ch == '\r' || ch == '\n') {
            fix_fgets_input(temp_password); // rectify so that ENTER (\n) is not password character
            break; 
        } 

        // Handle backspace (delete a character)
        else if (ch == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b"); // Overwrite the last '*' with a space, then move cursor back
                fflush(stdout); // Ensure the change is immediately displayed
            }
            continue; // Ignore backspace if the buffer is empty
        } 

        // Handle regular printable characters
        else if (ch >= 32 && ch <= 126) { // Check for standard printable ASCII characters
            temp_password[i] = ch; // Store the character in the buffer
            i++;            // Increment the index
            printf("*");    // Print * to mask
            fflush(stdout); // Ensure the '*' appears immediately
        }
    }
    // Terminate the string
    temp_password[i] = '\0';

    // fgets(temp_password, CREDENTIAL_LENGTH, stdin); --> USED TO GET UNMASKED PASSWORD
    // fix_fgets_input(temp_password); --> USED TO RECTIFY GET UNMASKED PASSWORD
    
    for (int i=0; i < user_count; i++) {
        if((strcmp(temp_username, users[i].username) == 0) && (strcmp(temp_password, users[i].password) == 0)) {
            return i;
        } else return -1;
    }
}