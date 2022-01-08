#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANDIDATE_COUNT
#define CANDIDATE1 "David Hull"
#define CANDIDATE2 "Kristin Canella"
#define CANDIDATE3 "Jim Brar"
#define CANDIDATE4 "Donald Truimph"

FILE * file;


void castVote(){
    int choice, newvote;
    file = fopen("votes.csv","a");
    printf("\n\n ### Please choose your Candidate ####\n\n");
    printf("\n 1. %s", CANDIDATE1);
    printf("\n 2. %s", CANDIDATE2);
    printf("\n 3. %s", CANDIDATE3);
    printf("\n 4. %s", CANDIDATE4);
    printf("\n 5. %s", "None of These\n");
    printf("enter your choice:  ");
    scanf("%d",&choice);

    switch (choice){
    case 1:
        newvote = 1;
        fprintf(file,"%d,%d,%d,%d\n",newvote,0,0,0);
        fclose(file);
        break;
    case 2:
        newvote = 1;
        fprintf(file,"%d,%d,%d,%d\n",0,newvote,0,0);
        fclose(file);
        break;
    case 3:
        newvote = 1;
        fprintf(file,"%d,%d,%d,%d\n",0,0,newvote,0);
        fclose(file);
        break;
    case 4:
       newvote = 1;
        fprintf(file,"%d,%d,%d,%d\n",0,0,0,newvote);
        fclose(file);
        break;
    default:
        printf("wrong choice!!\n");
        break;
    }

}

int voteCount(){
    int vote1 = 0,vote2 = 0,vote3 = 0, vote4 = 0 ;
    int v1 = 0,v2 = 0,v3 = 0,v4 = 0;

    file = fopen("votes.csv", "r");

    while (!feof(file)){
        fscanf(file,"%d,%d,%d,%d\n",&v1,&v2,&v3,&v4);
        vote1 = vote1 + v1;
        vote2 = vote2 + v2;
        vote3 = vote3 + v3;
        vote4 = vote4 + v4;
    }
    fclose(file);
    printf("%s : %d\n%s : %d\n%s : %d\n%s : %d\n",CANDIDATE1,vote1,CANDIDATE2, vote2,CANDIDATE3, vote3,CANDIDATE4, vote4);
}

void leading(){
    int vote1 = 0,vote2 = 0,vote3 = 0, vote4 = 0 ;
    int v1 = 0,v2 = 0,v3 = 0,v4 = 0;

    file = fopen("votes.csv", "r");

    while (!feof(file)){
        fscanf(file,"%d,%d,%d,%d\n",&v1,&v2,&v3,&v4);
        vote1 = vote1 + v1;
        vote2 = vote2 + v2;
        vote3 = vote3 + v3;
        vote4 = vote4 + v4;
    }
    fclose(file);

    if (vote1 > vote2 & vote1 > vote3 & vote1 > vote4 ){
        printf("\n%s %d\n",CANDIDATE1,vote1);
    }else if (vote2 > vote1 & vote2 > vote3 & vote2 > vote4 ){
        printf("\n%s %d\n",CANDIDATE2,vote2);
    }else if (vote3 > vote1 & vote3 > vote2 & vote4 > vote4 ){
        printf("\n%s %d\n",CANDIDATE3,vote3);
    }else if (vote4> vote1 & vote4 > vote2 & vote4 > vote3 ){
        printf("\n%s %d\n",CANDIDATE4,vote4);
    }else{
        printf("no leader yet now!!\n");
    }

}
void clrscr()
{
    system("@cls||clear");
}
int generateId(){
    int id;
    do{
        // generate a random number between 10000 and 999999
        id = rand();
        id = id % 10000 + 10000;
    }while(id < 99999 && id > 10000);

    return id;
}
void generateUser(int typ){

    char name[30];
    char pass[30], pass2[30];
    int id;
    if(typ == 1){
        printf("Enter your full name: ");
        fgets(name, sizeof(name), stdin);
        printf("Enter your password: ");
        fgets(pass, sizeof(pass), stdin);
        printf("Re-enter your password: ");
        fgets(pass2, sizeof(pass2), stdin);
        if(strcmp(pass,pass2) == 0){
            id = generateId();
            file = fopen("users.csv","a");
            fprintf(file,"%s,%s,%d\n",name,pass,id);
            fclose(file);
        }else{
            // hadle error here (password not match) call a function
        }
         
    }
    if(typ == 2){
        printf("Enter your id: ");
        scanf("%d",&id);
        printf("Enter your full name: ");
        fgets(name, sizeof(name), stdin);
        printf("Enter your password: ");
        fgets(pass, sizeof(pass), stdin);
        printf("Re-enter your password: ");
        fgets(pass2, sizeof(pass2), stdin);

        if(strcmp(pass,pass2) == 0){
            file = fopen("users.csv","a");
            fprintf(file,"%s,%s,%d\n",name,pass,id);
            fclose(file);
        }else{
            // hadle error here (password not match) call a function
        }
    }
}

void registration(){
    int choice;
    while(1){
        printf("\n\n Registration Menu\n\n");
        printf("\n\n 1. New Student\n ");
        printf("\n 2. Existing Student\n ");
        printf("\n 0. Back\n");

        printf("Enter a selection : ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                generateUser();
                break;
            case 2:
                voteCount();
                break;
            case 0:
                break;
            default:
                printf("invalid choice!!\n");
                break;
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice;
    while(1){
        printf("\n\n ###### Welcome to Election/Voting 2019 #####");
        printf("\n\n 1. Register ");
        printf("\n 2. Login ");
        printf("\n 0. Exit\n");
    //     printf("\033[31mred text\n");
    //   printf("\033[33;44m yellow on blue \n");
    //   printf("\033[33;44m  ------------- \n");
    //   printf("\033[0mdefault colors\n");

        printf("enter a choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                registration();
                break;
            case 2:
                voteCount();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("invalid choice!!\n");
                break;
        }
    }
    return 0;
}
