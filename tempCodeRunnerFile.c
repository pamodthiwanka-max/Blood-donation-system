#include<stdio.h>
struct admin
{
  char username[50];
  char password[50];
  int loginattempts;
};
int login();
void changepassword();   // function declaration
void clearscreen();
void pausescreen();

int login()                  //function definition
{
  char user[30],pass[20];
  int maxattempts=3;

  while(admin.loginattempts<maxattempts)
    {
      printf("this is Admin login");
      printf("\n");
      printf("Enter username:");
      scanf("%s",&user);
      printf("Enter the password:");
      scanf("%s",&pass);

      if(user==admin.username&&pass==admin.password)
      {
        printf("\nYou successfully logged in");
        pausescreen();
        return 1;
      }
      admin.loginattempts++;
      printf("You have only %d attempts to login",maxattempts-admin.loginattempts);
      
    }
  return 0;
  
}

void changepassword()
{
  char crr[20],newpass[20],confirm[20];
  printf("Enter current password:");
  scanf("%s",&crr);
  if(crr!=admin.password)
  {
    printf("\n invalid current password");
    pausescreen();
    return;
    
  }
  printf("\nEnter your new password:");
  scanf("%s",&newpass);
  printf("confirm your password:");
  scanf("%s",&confirm);
  if(confirm!=newpass)
  {
    printf("\n password not match");
    pausescreen();
    return;
  }
  strcpy(admin.password,newpass);
  printf("\nPassword changed");
  pausescreen();
}


void clearscreen()
{
  printf("\n\n\n\n\n");
}


void pausescreen()
{
  printf("\n press the enter key to continue");
  getchar();
}

int main()
{
  struct admin admin;
  printf("Enter the username here:");
  scanf("%s",&admin.username);
  printf("Enter the password :");
  scanf("%s",&admin.password);
  admin.loginattempts=0;
  login();                                 //function calling
  changepassword();
  clearscreen();
  return 0;
  
}
  
