#include<stdio.h>

void RegisterUser();
void LoginUser();

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
            break;
        case 2:
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
