#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int leapYear( int year );
int leapYearNum( int year );
int todayOf( int y, int m, int d);
long days( int y, int m, int d);
void calendar(int y, int m);
int getDayNumber(int d,int m,int y);
char *getName(int day);

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


typedef struct {
  int day;
  int month;
  int year;
  char note[255];
} Note;



int main(int argc, char* argv[]){

    int pw;

    int year,month, day;
    Note note;
    FILE *userfile;

    userfile = fopen("note.bin", "r");
    if (userfile == NULL) {
      userfile = fopen("note.bin", "w");
    }
    fclose(userfile);

    void RoT1(char*Un, char*Pass, int key);
    char username[101];
    char password[101];
    int input;
    int choice;
    char again;
    int key=1;


      printf("Enter your username:\n");
      scanf("%s", username);

      printf("Enter your password. If guest user, enter 'none':\n");
      scanf("%s", password);

      if(userfile == NULL){
        printf("An error occurred! Exit and try again.\n");
        return 0;
      }


      if(strcmp(username, "guest")==0){
        printf("\nWelcome!\n");
        printf("Enter 1 to find the day\n");
        printf("Enter 2 to print calendar of a month\n");
        printf("Enter 3 to add note\n");
        printf("Enter 4 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            // find day
            printf("Enter the day, month and year: ");
            scanf("%d %d %d", &day, &month, &year);
            printf("The day is : %s\n", getName(getDayNumber(day, month, year)));
            break;
            case 2:
            printf("Enter the month and year: ");
            scanf("%d %d", &month, &year);
            printf("Please enter 's' to see the notes\n Press any other key to continue\n");
            calendar(year, month);
            break;
            // print calendar of month
            // option to view notes
            case 3:
            printf("Enter the day, month and year: ");
            scanf("%d %d %d", &note.day, &note.month, &note.year);
            flush();
            printf("Enter the note: ");
            fgets(note.note, 255, stdin);
            userfile = fopen("note.bin", "a+");
            if (userfile == NULL) {
            printf("File note.bin can not be opened\n");
            exit(1);
            }
            fwrite(&note, sizeof(Note), 1, userfile);
            printf("Note added sucessfully\n");
            fclose(userfile);
            break;
            // add note
            case 4:
            printf("goodbye!");
            return 0;
            break;
            }
        }
     

      if(strcmp(username,"admin")==0){
        if(strcmp(password,"admin123")==0) {

          printf("\nWelcome. You are logged in!\n");
          do {
          printf("Enter 1 if you would you like to change your username: \n");
          printf("Enter 2 if you would you like to change your password: \n");
          printf("Enter 3 if you would you like to add a user: \n");
          printf("Enter 4 if you would like to remove a user:\n");
          printf("Enter 5 to find the day\n");
          printf("Enter 6 to print calendar of a month\n");
          printf("Enter 7 to add note\n");
          printf("Enter 8 if you would you like to logout\n");
          printf("Enter your choice: ");
          scanf("%d", &input);
        
          switch (input) {
            case 1:
                    
                    userfile = fopen("user.txt","w+");
                    printf("What would you like your new username to be? : \n");
                    scanf("%s", username);
                    fprintf(userfile, "%s", username);
                    fputs(username, userfile);
                    printf("Here is your new username: %s\n", username);
                    fclose(userfile);
                    break;

            case 2:
                    userfile = fopen("user.txt","w+");
                    printf("Enter your new password.\n");                    scanf("%s", password);
                    pw = atoi(password);
                    if (pw < 8){
                        printf("The password you entered is not long enough. Try again.");
                    } else{
                    fprintf(userfile, "%s", username);
                    fputs(password, userfile);
                    printf("Here is your new password: %s\n", password);
                    printf("Password Changed!\n");
                    }
                    fclose(userfile);
                    break;
            case 3:
                  userfile = fopen("user.txt","r+");
                  printf("Create a new user! Enter their username: \n");
                  scanf("%s", username);
                  fprintf(userfile, "%s", username);
                  printf("Enter the user's password:\n");
                  scanf("%s", password);
                  fprintf(userfile, "%s", password);
                  printf("Username: %s" , username);
                  printf("\nPassword: %s \n", password);
                  fclose(userfile);
                  break;

            case 4:
                  userfile = fopen("userfile", "w+");
                  printf("Enter the username and password you want to remove:\n");
                  fscanf(userfile, "%s %s", username, password);
                  if (!userfile) {
                      printf("Sorry! We can't open that file!\n");
                  } else {
                    remove(username);
                    remove (password);
                  }
                fclose(userfile);
                return 0;
            case 5:
            // find day
            printf("Enter the day, month and year: ");
            scanf("%d %d %d", &day, &month, &year);
            printf("The day is : %s\n", getName(getDayNumber(day, month, year)));
            break;
            case 6:
            printf("Enter the month and year: ");
            scanf("%d %d", &month, &year);
            printf("Please enter 's' to see the notes\n Press any other key to continue\n");
            calendar(year, month);
            break;
            // print calendar of month
            // option to view notes
            case 7:
            printf("Enter the day, month and year: ");
            scanf("%d %d %d", &note.day, &note.month, &note.year);
            flush();
            printf("Enter the note: ");
            fgets(note.note, 255, stdin);
            userfile = fopen("note.bin", "a+");
            
            if (userfile == NULL) {
            printf("File note.bin can not be opened\n");
            exit(1);
            }
            fwrite(&note, sizeof(Note), 1, userfile);
            printf("Note added sucessfully\n");
            fclose(userfile);
            break;
            // add note
            case 8:
            // exit
            printf("goodbye!");
            return 0;
            break;
          }
          printf("%s", "Is there anything else you would like to do? Enter y/n. \n");
          scanf("%c", &again);
          }
          while (again == 'y');
          
          if (again == 'n'){
            printf("Thank you! Come back soon!");

        }}
        } else {
            printf("Uh oh! Your password is incorrect!");
            return 0;
          }
    return 0;
    }
    
void RoT1(char*username, char*password, int key){
  int i=0;
  int rotnum;
  int rotnum2;
  char rot;
  char rot2;

  while(username[i] !='\0' && strlen(username)-1 >i){
    rotnum=((int)username[i] + key);
    rot=(char)(rotnum);

    rotnum2=((int)password[i] + key);
    rot2=(char)(rotnum2);

    i++;
  }
}

int leapYear( int y ){
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

int leapYearNum( int y ){
    return y/4 - y/100 + y/400;
}

int todayOf( int y, int m, int d) {
    static int DayOfMonth[] =
        { -1,0,31,59,90,120,151,181,212,243,273,304,334};
    return DayOfMonth[m] + d + ((m>2 && leapYear(y))? 1 : 0);
}

long days( int y, int m, int d){
    int lastYear;
    lastYear = y - 1;
    return 365L * lastYear + leapYearNum(lastYear) + todayOf(y,m,d);
}

void calendar(int y, int m){
    FILE *fp;
    Note* notes, note;
    int len, j, hasNote = 0;
    char choice;
    const char *NameOfMonth[] = { NULL/*dummp*/,
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    char Week[] = "Su   Mo   Tu   We   Th   Fr   Sa";
    int DayOfMonth[] =
        { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;

    weekOfTopDay = days(y, m, 1) % 7;

    fp = fopen("note.bin", "rb");
    if (fp == NULL) {
      printf("Couldn't read notes\n");
    }
    len = 0;
    while(fread(&note, sizeof(Note), 1, fp)) {
      if (note.year == y && note.month == m) {
        len++;
      }
    }
    rewind(fp);
    j = 0;
    notes = (Note*) malloc (sizeof(Note) * len);
    while(fread(&note, sizeof(Note), 1, fp)) {
      if (note.year == y && note.month == m) {
        notes[j] = note;
        j++;
      }
    }

    fclose(fp);

    if(leapYear(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);

    for(i=0;i<weekOfTopDay;i++)
        printf("   ");
    for(i=weekOfTopDay,day=1;day <= DayOfMonth[m];i++,day++){
        hasNote = 0;
        for (j = 0; j < len; j++) {
          if (notes[j].day == day) {
            printf("|%2d| ",day);
            hasNote = 1;
            break;
          }
        }
        if (hasNote == 0) {
          printf("%2d   ",day);
        }
        if(i % 7 == 6)
            printf("\n");
    }
    printf("\n");
    scanf("\n%c", &choice);
    if (choice == 's') {
      printf("Here are list of notes for %d %d\n", m, y);
      for (j = 0; j < len; j++) {
        printf("%d: %s\n", notes[j].day, notes[j].note);
      }
    } else {
      return;
    }
}

int getDayNumber(int d, int m, int y){
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

char *getName(int day){
   switch(day){
      case 0 :return("Sunday");
      case 1 :return("Monday");
      case 2 :return("Tuesday");
      case 3 :return("Wednesday");
      case 4 :return("Thursday");
      case 5 :return("Friday");
      case 6 :return("Saturday");
      default:return("Error: Invalid Argument Passed");
   }
}
