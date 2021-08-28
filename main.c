#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login(int z)
{
  char pass[35];
  char pass1[35];
  char username[35];
  int check;
  FILE*password1;
  mam:
  password1=fopen("password.txt","r");
  if(password1==NULL)
  {
      password1=fopen("password.txt","w");
      fprintf(password1,"1234");
      fclose(password1);
      goto mam;
  }
  fscanf(password1,"%s",pass);

  printf("\nplease Enter your Username and password\n");
  pam:
  printf("\nUsername :");
  fflush(stdin);
  scanf("%s",username);
  printf("\nPassword :");
  fflush(stdin);
  scanf("%s",pass1);

  check=strcmp(pass1,pass);
  if(check==0)
  {
      system("cls");
      printf("Welcome\n");
      z=1;
  }else
  {
      system("cls");
      printf("\n*******************\n");
      printf("\nyour username or password is incorrect\n");
      printf("please try again\n");
      printf("\n*******************\n");
      goto pam;
  }
  fclose(password1);
  return 0;
}

void changepass(int p2)
{

    FILE*password1;
    password1=fopen("password.txt","r");
    char lastpass[35];
    fscanf(password1,"%s",lastpass);
    fclose(password1);
    char ypass[35];
    int y;
    lam:
    printf("\nType your last password\n");
    fflush(stdin);
    scanf("%s",ypass);
    y=strcmp(ypass,lastpass);

    if(y==0)
    {
        char newpass1[35];
        char newpass2[35];
        bam:
        printf("Enter your New password\n");
        fflush(stdin);
        scanf("%s",newpass1);
        fflush(stdin);
        printf("Enter your Newpass again\n");
        scanf("%s",newpass2);
        int y0;
        y0=strcmp(newpass1,newpass2);
        if(y0==0)
        {

           FILE*password1;
           system("cls");
           printf("your password has successfully changed\n");
           printf("Your New Password is : %s\n",newpass1);
           password1=fopen("password.txt","w+");
           fprintf(password1,"%s",newpass1);
           fclose(password1);

        }
        else
            {printf("\n\a***************\a\n");
            printf("\n\aThey are not the same\a\n");
            printf("\n\a***************\a\n");
            goto bam;}
    }else
    {
    system("cls");
    printf("\n***************\n");
    printf("\nyour password is incorrect\n");
    printf("\n***************\n");
    goto lam;
    }
    return 0;
}

typedef struct
{
    int code;
    char FNAME[30];
    char LNAME[30];
    float grad;
}info;

void studentinfo(int y4)
{
    int l1;
    int l2;
    int number;

   FILE* num= fopen ("num.txt", "r");
        if(num!= NULL)
        {
            fscanf(num, "%d", &l1);
            fclose(num);

        }
        else
        {
            l1= 0;
        }
    printf("how many new student you want to add\n");
    fflush(stdin);
    scanf("%d",&l2);
    number= l1+ l2;
    num= fopen ("num.txt", "w");
    fprintf(num, "%d", number);
    fclose(num);

    fflush(stdin);

    info* Array= malloc(sizeof(info)* number);
    FILE *y2= fopen("studentinfo.txt","rb");
    if (y2!= NULL)
    {
        if(l1!= 0)
        {
            fread(Array, sizeof(info), l1, y2);
        }
        fclose(y2);
    }
    int i;
    int l3= 1;
    for(i=l1; i<number; i++)
    {
        maj:
        fflush(stdin);
        printf("\nEnter The code Of Your %d student:\t\n",l3);
        scanf("%d",&Array[i].code);
         int l4;
        for(l4= 0; l4< i; l4++)
        {
            if(Array[i].code== Array[l4].code)
            {
                    printf("\n********************\n");
                    printf("\nthis code has used \n");
                    printf("\nplease enter anouther student\n");
                    printf("\n********************\n");
                    goto maj;
            }
        }
        fflush(stdin);
        printf("\nEnter The first Name Of Your %d student:\t\n",l3);
        scanf("%s",&Array[i].FNAME);
        fflush(stdin);
        printf("\nEnter The last Name Of Your %d student:\t\n",l3);
        scanf("%s",&Array[i].LNAME);
        fflush(stdin);
        printf("\nEnter The grade Of student %d: \t\n",l3);
        scanf("%f",&Array[i].grad);
        fflush(stdin);
        l3++;
    }
    y2=fopen("studentinfo.txt","wb");
    fwrite(Array,sizeof(info),number,y2);
    fclose(y2);
    printf("\nyour information has been successfuly getten\n");
    rrm:
    printf("\nEnter  1  to going to menu\n");
    fflush(stdin);
    scanf("%d",&y4);
    if(y4!=1)
    {
        goto rrm;
    }
    free(Array);
    return 0;
}

void deletstudent()
{
    int l1;
   FILE* num= fopen ("num.txt", "r");
        if(num!= NULL)
        {
            fscanf(num, "%d", &l1);
            fclose(num);
        }
        else
        {
            l1= 0;
        }
    info* Array= malloc(sizeof(info)* l1);
    FILE* y2=fopen("studentinfo.txt","rb");
    fread(Array,sizeof(info),l1,y2);
    fclose(y2);

    int d57,f16,v53;
    f16=0;
    mar:
    printf("\nEnter The code Of Your %d student:\n",l1);
    scanf("%d", &d57);
    for(int i= 0; i< l1; i++)
    {
        if(d57= Array[i].code)
        {

                    f16++;
                    FILE* y2= fopen("studentinfo.txt","wb");

                    fwrite(Array, sizeof(info), i, y2);
                    fseek(y2, 0, SEEK_END);
                    fwrite(&Array[i+1], sizeof(info), (l1-(i+1)), y2);
                    FILE* num= fopen("num.txt","w");
                    fprintf(num, "%d", l1-1);
                    fclose(num);

                    if(l1- 1== 0)
                        remove("num.txt");
                    fclose(y2);
                    printf("\nDeleting was successful\n");
                maa:
                printf("\nEnter 1 to going to menu\n");
                scanf("%d",&v53);
                if(v53==1)
                {
                    goto man;
                }
                else
                    {
                        goto maa;
                    }

                break;
            }

        }
    if(f16== 0)
    {
        printf("this code has not found");
        goto mar;
    }
man:
    return 0;
}

void sortstudent(int a1)
{
    int l1;
   FILE* num= fopen ("num.txt", "r");
        if(num!= NULL)
        {
            fscanf(num, "%d", &l1);
            fclose(num);
        }
        else
        {
            l1= 0;
        }

    info* Array= malloc(sizeof(info)* l1);
    info* k11= malloc(sizeof(info)* 1);
    FILE *y2= fopen("studentinfo.txt","rb");
    fread(Array, sizeof(info), l1, y2);
    for(int i= 0; i< l1; i++)
    {
        for(int j= 0; j< l1-1; j++)
        {
            if(Array[j+1].grad > Array[j].grad)
            {
                k11[0]= Array[j+1];
                Array[j+1]= Array[j];
                Array[j]= k11[0];
            }
            if(Array[j+1].grad== Array[j].grad)
            {
                if(strcmp(Array[j+1].LNAME, Array[j].LNAME)< 0)
                {
                     k11[0]= Array[j+1];
                    Array[j+1]= Array[j];
                    Array[j]= k11[0];
                }
            }
        }
    }
    for(int i= 0; i< l1; i++)
    {
        printf("\n------------------------\n");
        printf("First Name: %s\n", Array[i].FNAME);
        printf("Last Name: %s\n", Array[i].LNAME);
        printf("Student-ID: %d\n", Array[i].code);
        printf("Student Grade: %f\n", Array[i].grad);
    }
    free(Array);
    vam:
    printf("\n------------------------\n");
    printf("Enter 1 for back to menu \n");
    fflush(stdin);
    scanf("%d",&a1);
    if(a1!=1)
    {
     goto vam;
    }
    return 0;
}

void serchtudent(int p5)
{
    int l1;
    info* Array= malloc(sizeof(info)* l1);
   FILE* num= fopen ("num.txt", "r");
        if(num!= NULL)
        {
            fscanf(num, "%d", &l1);
            fclose(num);

        }
        else
        {
            l1= 0;
            printf("you have not aaded any student");

        }
    char sname[20];
    int v,v1,v2,v3,v4,v5,v7,v9,t,r;
    float v6,v8;
    ram :
    system("cls");

    FILE *y2;
    y2=fopen("studentinfo.txt","rb");
    printf("\nEnter Your Choice\n");
    printf("\n1.Search By grade\n");
    printf("\n2.Search By code\n");
    fflush(stdin);
    scanf("%d",&t);
    if(t==1)
    {
        printf("Enter Your grade To Search For\n");
        fflush(stdin);
        scanf("%f",&v6);
        int l98= 0;
         fread(Array,sizeof(info),l1,y2);
         for(int x=0;x<l1;x++)
         {

            if(v6==Array[x].grad)
            {
                l98++;
                printf("\nYour first NAME Is = %s",Array[x].FNAME);
                printf("\nYour last NAME Is = %s",Array[x].FNAME);
                printf("\nYour code Is = %d",Array[x].code);
                printf("\nYour grad = %f\n",Array[x].grad);
                vham:
                printf("\nIf you want to try again enter 1 or enter 2 to go to menu\n");
                fflush(stdin);
                scanf("%d",&v3);
                if(v3==2)
                {goto vaam;}
                else if(v3==1)
                {goto ram;}
                else
                {goto vham;}

            }
        }
            if(l98== 0)
            {
                printf("\a\nNot Any Match Name Found\n");
                vram:
                printf("If you want to try again enter 1 or enter 2 to go to menu\n");
                fflush(stdin);
                scanf("%d",&v1);
                if(v1==2)
                {goto vaam;}
                else if(v1==1)
                {goto ram;}
                else
                {goto vram;}
            }


    }
    else if(t==2)
    {
        printf("Enter Your code To Search\n");
        fflush(stdin);
        scanf("%d",&r);

        int l99;
         fread(Array,sizeof(info),l1,y2);
         for(int x1=0;x1<l1;x1++)
           {



            if(r==Array[x1].code)
            {
                l99++;
                printf("\nYour firs NAME Is = %s",Array[x1].FNAME);
                printf("\nYour last NAME Is = %s",Array[x1].LNAME);
                printf("\nYour code Is = %d",Array[x1].code);
                printf("\nYour grad Is = %f\n",Array[x1].grad);
                vkam:
                printf("\nIf you want to try again enter 1 or enter 2 to go to menu\n");
                fflush(stdin);
                scanf("%d",&v2);
                if(v2==2)
                {goto vaam;}
                else if(v2==1)
                {goto ram;}
                else
                {goto vkam;}

            }

        }
        if(l99==0)
            {
                printf("\a\nNot Any Match ID Found\n");
                vvam:
                printf("If you want to try again enter 1 or enter 2 to go to menu\n");
                fflush(stdin);
                scanf("%d",&v4);
                if(v4==2)
                {goto vaam;}
                else if(v4==1)
                {goto ram;}
                else
                {goto vvam;}
            }
    }
    else if(t!=1 || t!=2)
    {
        vcam:
        printf("\n\aYou Have Entered A Wrong Number\a\n");
        printf("\nEnter 1 To Try Again\n");
        fflush(stdin);
        scanf("%d",&v5);
        if(v5==1)
        {goto ram;}
        else
        {goto vcam;}


    }
    vaam:
    fclose(y2);
    return 0;
}

int main()
{
    FILE*password1;
    int x,z;
    login(z);


    dam:
    printf(" Please Enter your Request\n\n");

    printf("1- Enter Info of New Students\n");
    printf("2- Delete a student\n");
    printf("3- Sort Students Info\n");
    printf("4- Search Students\n");
    printf("5- Change Password\n");
    printf("6- Logout\n");
    xam:
    fflush(stdin);
    scanf("%d",&x);
    if(x==1)
        {
          system("cls");
          int j;
          studentinfo(j);
          system("cls");goto dam;
        }

    else if(x==2)
        {
          system("cls");

         deletstudent();
          system("cls");
          goto dam;
        }

    else if(x==3)
       {
            system("cls");
            int p6;
            sortstudent(p6);
            system("cls");goto dam;

       }

    else if(x==4)
       {
            system("cls");
            int p5;
            serchtudent(p5);
            system("cls");goto dam;
       }

    else if(x==5)
        {
          system("cls");
          int p2;
          changepass(p2);
          goto dam;
        }

    else if(x==6)
       {

            system("cls"); printf("\nif you sure to exit press any key\n");
       }

    else
       {

            printf("\n*********************\n");
            printf("\nThis number is incorrect\n");
            printf("Please enter correct number\n");
            printf("\n*********************\n");
            goto dam;
       }
    return 0;
}
