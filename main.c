#include<stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * file;

void clrscr()
{
    system("@cls||clear");
}
void viewCourses(){
    clrscr();
    printf("\n\n ### Selected Courses ####");
    printf("\n ## Please work to successed ##\n\n\n");
    FILE* fp = fopen("selectedCourses.csv", "r");
        if (!fp)
            printf("\n\nCan't open file\n");

        else {
            char buffer[1024];

            int row = 0;
            int column = 0;
            int num =0;

            while (fgets(buffer,1024, fp)) {
                column = 0;
                  row++;
                // Splitting the data
                char* value = strtok(buffer, ", ");
                 printf(" %d. ",row);
                while (value) {
                    // Column 1
                    if (column == 0) {
                        printf("(%s) ",value);
                    }
                    // Column 2
                    if (column == 1) {
                        printf("%s ",value);
                    }
                    num++;
                    value = strtok(NULL, ", ");
                    column++;
                }
                    printf("\n");
            }
            // Close the file
            fclose(fp);
        }
        userMenu();
}
void saveToSelected(int option, int credits){
    FILE* fp = fopen("courses.csv", "r");
    if (!fp)
        printf("Can't open file\n");

    else {
        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer,1024, fp)) {
            column = 0;
            row++;
            // Splitting the data
            char* value = strtok(buffer, ", ");
            while (value) {
                // Column 2
                if (column == 2 && row == option) {
                    FILE* fc = fopen("selectedCourses.csv","a");
                    fprintf(fc,"%d,%s",credits,value);
                    fclose(fc);
                }
                value = strtok(NULL, ", ");
                column++;
            }
        }
        // Close the file
        fclose(fp);
        header();
        printf("Done saving course\n\n");
        getCourses();
    }
}
void header(){
    clrscr();
    printf("\n\n ### Please choose your Course [maximum is 20 credits] ####");
    printf("\n ## Press 0 to (Cancel) ##\n\n\n");
}
void getCourses(){
    FILE* fp = fopen("courses.csv", "r");
        if (!fp)
            printf("\n\nCan't open file\n");

        else {
            char buffer[1024];

            int row = 0;
            int column = 0;
            int num =0;

            while (fgets(buffer,1024, fp)) {
                column = 0;
                  row++;
                // Splitting the data
                char* value = strtok(buffer, ", ");
                 printf(" %d. ",row);
                while (value) {
                    // Column 1
                    if (column == 0) {
                        printf("(%s) ",value);
                    }
                    // Column 2
                    if (column == 1) {
                        printf("(%s) ",value);
                    }
                    // Column 3
                    if (column == 2) {
                        printf("%s ",value);
                    }
                    num++;
                    value = strtok(NULL, ", ");
                    column++;
                }
                    printf("\n");
            }
            // Close the file
            fclose(fp);
        }
}
void selectCourses(){
    header();
    getCourses();
        int cred = 0,copyCredits=0;
        int i = 1, option, selected[5],n=0,flag=0;
        while(cred<22 && i<7){
            printf("You have selected [%d] credits\n\n",cred);
            printf("\nSelect option [%d]: ",i);
            scanf("%d",&option);
            // clrscr();
            if(option>0){
                for(n=0; n<i; n++){
                    if(selected[n] == option){
                        clrscr();
                        header();
                        getCourses();
                        printf("Not arrowed to repeat!\n\n");
                        flag=1;
                        break;
                    }else{
                        flag=0;
                    }
                }
                if(flag ==0){
                    selected[i-1] = option;
                }else{
                    continue;
                }
            }else{
                clrscr();
                userMenu();
                break;
            }
            FILE* fp = fopen("courses.csv", "r");
            if (!fp)
                printf("Can't open file\n");

            else {
                char buffer[1024];

                int row = 0;
                int column = 0;

                while (fgets(buffer,1024, fp)) {
                    column = 0;
                    row++;
                    // Splitting the data
                    char* value = strtok(buffer, ", ");
                    while (value) {
                        // Column 2
                        if (column == 1 && row == option) {
                            int credits = atoi(value);
                            if((cred + credits) < 22){
                                saveToSelected(option, credits);
                                cred = cred + credits;
                                break;
                            }else{
                                copyCredits = cred + credits;
                                break;
                            }
                        }
                        value = strtok(NULL, ", ");
                        column++;
                    }
                }
                // Close the file
                fclose(fp);
            if (copyCredits > 21){
                printf("\nYou have exceeded the maximum credits\n");
                printf("Click 0 to exit");
                copyCredits = cred;
            }else{
                i++;
            }
        }

    }
    userMenu();

}

void userMenu(){
    int choice;
    int done = 0;
    while(!done){
        printf("\n\n ###### Student Dashboard #####");
        printf("\n\n 1. Select Courses\n");
        printf("\n 2. View Your Courses\n");
        printf("\n 0. Logout\n");
        printf("\n Select One : ");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            selectCourses();
            break;
        case 2:
           viewCourses();
           done=1;
            break;
        case 0:
            done = 1;
            clrscr();
            break;
        default:
            clrscr();
            printf("\n\nInvalid selection!!\n");
            break;
        }
    }
}
void login(){
    int choice=1;
    clrscr();
    while(choice){
        char id[30];
        char password[30],name[30],userId[30],pass[30];
        char* data[30];
        
        printf("\n\n ###### Student Credentials #####");
        printf("\n\n Enter your ID : ");
        scanf("%s",&id);
        printf("\n Enter your password : ");
        scanf("%s",password);
        // check if id and password is correct from the users.csv file
        FILE* fp = fopen("users.csv", "r");

        if (!fp)
            printf("Can't open file\n");

        else {
            char buffer[1024];

            int row = 0;
            int column = 0;

            while (fgets(buffer,1024, fp)) {
                column = 0;
                row++;
                // Splitting the data
                char* value = strtok(buffer, ", ");
                while (value) {
                    // Column 1
                    if (column == 0) {
                        data[0] = value;
                    }
                    // Column 2
                    if (column == 1) {
                        data[1] = value;
                    }
                    // Column 3
                    if (column == 2) {
                        data[2] = value;
                    }
                    value = strtok(NULL, ", ");
                    column++;
                }
            }
            // Close the file
            fclose(fp);
            if((strcmp(id,data[0])==0) && (strcmp(password,data[1]) == 0)){
                clrscr();
                userMenu();
                choice = 0;
            }else{
                clrscr();
                printf("\n\nWrong ID and password, try again!\n");
            }
        }
    }
}
int generateId(){
    int id;
        // generate a random number between 10000 and 999999
        id = rand();
        id = id % 10000 ;
    return id;
}
void generateUser(int typ){

    char name[30];
    char pass[30], pass2[30];
    int id;
    clrscr();
    printf("\n\n ###### Student Details #####");
    if(typ == 1){
        
        printf("\n\nEnter your full name: ");
        gets(name);
        gets(name);
        printf("\nEnter your password: ");
        gets(pass);
        printf("\nConfirm your password: ");
        gets(pass2);
        if(strcmp(pass,pass2) == 0){
            id = generateId();
            file = fopen("users.csv","w");
            fprintf(file,"%d,%s,%s\n",id,pass,name);
            fclose(file);
            clrscr();
            printf("\n\nYou have been successfully registred!\n");
            printf("Please note, your ID is: %d", id);
        }else{
            printf("\n\nYour Password doesn't match, try again\n");
        }

    }
    if(typ == 2){
        printf("\n\nEnter your Student id : ");
        scanf("%d",&id);
        printf("\n Enter your full name: ");
        gets(name);
        gets(name);
        printf("\n Enter your password: ");
        gets(pass);
        printf("\nConfirm your password: ");
        gets(pass2);
        if(strcmp(pass,pass2) == 0){
            file = fopen("users.csv","w");
            fprintf(file,"%d,%s,%s\n",id,pass,name);
            fclose(file);
            clrscr();
            printf("\n\nYou have been successfully registred!\n");
            printf("Please note, your ID is: %d", id);
        }else{
            printf("\n\nYour Password doesn't match, try again\n");
        }
    }
}

void registration(){
    int choice, loggedin = 1;
    clrscr();
    while(loggedin){
        printf("\n\n ###### Registration Menu #####");
        printf("\n\n 1. New Student\n ");
        printf("\n 2. Existing Student\n ");
        printf("\n 0. Back\n");

        printf("\nSelect One : ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                generateUser(1);
                loggedin=0;
                break;
            case 2:
                generateUser(2);
                loggedin=0;
                break;
            case 0:
                starting();
                break;
            default:
                printf("invalid choice!!\n");
                break;
        }
    }
}

void starting(){

    int choice;

    clrscr();
    while(1){
        printf("\n\n ###### Welcome to University course picker #####");
        printf("\n\n 1. Register\n");
        printf("\n 2. Login\n");
        printf("\n 0. Exit\n");
    //     printf("\033[31mred text\n");
    //   printf("\033[33;44m yellow on blue \n");
    //   printf("\033[33;44m  ------------- \n");
    //   printf("\033[0mdefault colors\n");

        printf("\nSelect One : ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                registration();
                break;
            case 2:
                // selectCourses();
                login();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("invalid choice!!\n");
                break;
        }
    }
}
int main(int argc, char const *argv[])
{
    starting();
    return 0;
}
