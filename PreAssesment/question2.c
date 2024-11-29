#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function prototype
void createUser(const char *filename);
void readUsers(const char *filename);
void updateUser(const char *filename);
void deleteUser(const char *filename);
int userexists(const char *filename, int id);


struct User
{
    int id;
    char name[50];
    int age;
};

int main() {
    const char *filename = "users.txt"; // File name
    int choice;


// show options

    do {
        printf("1. Create User\n");
        printf("2. Read Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser(filename);
                break;
            case 2:
                readUsers(filename);
                break;
            case 3:
                updateUser(filename);
                break;
            case 4:
                deleteUser(filename);
                break;
            case 5:
                printf("Thank you");
                break;
            default:
                printf("Invalid choice. Please choose between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}


// function definition create new user
void createUser(const char *filename) {
    struct User user;

    printf("Enter user Id: ");
    scanf("%d", &user.id);
    getchar(); // Consume newline

    // Check if teh user exists or not
    if (userexists(filename, user.id)) {
        printf("Error: User already exists\n");
        return;
    }

    // Input user details
    printf("Enter New Name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0'; // Remove newline

    printf("Enter Age: ");
    scanf("%d", &user.age);
    getchar(); // Consume newline

    // Open file for appending
    FILE *file = fopen(filename, "a");
    if (!file) {
        printf("Error\n");
        return;
    }
    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User created\n");
}



// Read the file
void readUsers(const char *filename) {

    FILE *file = fopen(filename, "r");
    if(!file) {
        printf("No users found\n");
        return;
    }

    struct User user;
    printf("ID\t\tName\t\tAge\n");

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        printf("%d\t\t%s\t\t%d\n", user.id, user.name, user.age);
    }
    fclose(file);
}

// user update
void updateUser(const char *filename) {
    int id;
    printf("Enter User ID to be updated: ");
    scanf("%d", &id);

    if (!userexists(filename, id))
    {
        printf("user not exits");
        return;
    }

    FILE *file = fopen(filename, "r");
    FILE *tempfile = fopen("temp.txt", "w");

    // if(!file || )

    struct User user;
    int found = 0;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, &user.name, &user.age) == 3)
    {
        if (user.id = id) {
            found = 1;

            printf("Enter new Name: ");
            fgets(user.name, sizeof(user.name), stdin);
            user.name[strcspn(user.name, "\n")] = '\0';

            printf("Enter New Age: ");
            scanf("%d", &user.age);
        }

        fprintf(tempfile, "%d,%s,%d\n", user.id, user.name, user.age);
    }
    fclose(file);
    fclose(tempfile);

    remove(filename);
    rename("temp.txt", filename);

    if(found){
        printf("updated");
    }

}

// delete

void deleteUser(const char *filename) {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    if (!userexists(filename, id))
    {
        printf("User doesn't exit");
        return;
    }

    FILE *file = fopen(filename, "r");
    FILE *tempfile = fopen("temp.txt", "w");

    struct User user;
    int found = 0;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == id) {
            found = 1;
            continue; 
            
            // Skip the record to delete
        }
        fprintf(tempfile, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempfile);

    remove(filename);
    rename("temp.txt", filename);

    if (found)
        printf("User deleted\n");
    
}


// to check if the user exist or not by checking id 
int userexists(const char *filename, int id) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return 0; // File does not exist
    }


    struct User user;

    // Read file line by line and check for matching ID
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == id) {
            fclose(file);
            return 1;
        }
    }
// if user not found 
    fclose(file);
    return 0; 
}
