//Hospital management system project in c
#include<stdio.h>//use for stander input output like printf(),scanf();
#include<windows.h>
#include<conio.h>//use for console input outpu functions like gotoxy(),getch(),getche()
#include<ctype.h>//use for isalpha(),toupper(),tolower()
#include<string.h>//use for the function strcmp(),strlen()
#include<stdlib.h>
char ans=0;
int yes,b;
int valid=0;
//Function decleration
void welcome();//WelcomeScreen function decleration
void title();//Title function decleration
void mainmenu();//MainMenu function decleration
void login();//Login function decleration
void addEntry();//addEntry function declaration
void patientDetailsList();//function to list the patient details
void search();//Search patient function declaration
void edit();//Edit patient function declaration
void dltRecord();//Dlt patient record function declaration
void ex_it();//exit function declaration


void gotoxy (int x,int y)
{
    COORD pstn={x,y};//sets co-ordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pstn);
}


struct patient
{
	char firstName[30];
	char lastName[30];
	int age;
	char mobileNo[20];
	char address[50];
	char gender;
	char email[40];
	char doctor[30];
	char disease[30];
};


struct patient  p,temp_c;
int main()
{
    welcome();
    title();
    login();
    return 0;


}


//welcome screen
void welcome()
{
    printf("\n\n\n\n\n\n\n\t\t\t\t****************************************");
	printf("\n\t\t\t\t*\t\t WELCOME TO\t\t*");
	printf("\n\t\t\t\t*   LAB-AID HOSPITAL MANAGEMENT SYSTEM    *");
	printf("\n\t\t\t\t*****************************************");
	printf("\n\n\n\n\n Press any key to continue......\n");
	getch();//Use to holds screen for some seconds
	system("cls");//Use to clear screen

}
//Title

void title()
{
    printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t       LAB-AID HOSPITAL         ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}
//main menu function
void mainmenu()
{
    system("cls");
    int c;
    title();
    printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
	printf("\n\t\t\t\t2. Patients Details Record\n");
	printf("\n\t\t\t\t3. Search For Patients Record\n");
	printf("\n\t\t\t\t4. Edit Patients Record\n");
	printf("\n\t\t\t\t5. Delete Patients Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &c);
	switch (c)
	{
    case 1:
        addEntry();
        break;
    case 2:
        patientDetailsList();
        break;
    case 3:
        search
        ();
        break;
    case 4:
        edit();
        break;
    case 5:
        dltRecord();
        break;
    case 6:
        ex_it();
        break;
    default:
        printf("\t\t\tInvalid entry!!! Please choose the  right option!!");
		getch();//hold screen for few seconds


	}

}
//Exit
void ex_it()
{

    system("cls");
    title();
    printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING MY HOSPITAL MANAGEMENT PROJECT !!!");
	getch();

}
//LOGIN
void login()
{

    int l=0;//limitation
    char userName[20];
    char password[20];
    char currentUserName[30]="Tanaya";
    char currentPassword[30]="123456789";
do
{
    printf("\n\n\n\n\t\t\t\tEnter your Username and Password:");
	printf("\n\n\n\t\t\t\t\tUSERNAME:");
	scanf("%s",&userName);

	printf("\n\n\t\t\t\t\tPASSWORD:");
	scanf("%s",&password);
		if (strcmp(userName,currentUserName)==0 && strcmp(password,currentPassword)==0)
	{
		printf("\n\n\n\t\t\t\t\t***Login Successfull***");


		getch();
		mainmenu();
		break;
	}
	else
	{
		printf("\n\t\t\tPassword is wrong..... Please enter the correct password!!!");
		l++;
		getch();//hold the screen for sometime
	}
}
while(l<=3);
   if(l>3)
   {
       printf("You have cross the limit!! you can't login in the system!!");
       getch();
       ex_it();
   }
   system("cls");
}
//Add Entry
void addEntry(void)
{
	system("cls");
	title();

	char ans;
	FILE*f;//file pointer
	f=fopen("Record.dat","a");//open file in write mode
	printf("\n\n\t\t\t************** Add Patients Record *************\n");

	//firstname
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",p.firstName);
	p.firstName[0]=toupper(p.firstName[0]);
	if(strlen(p.firstName)>30||strlen(p.firstName)<2)
	{
		printf("\n\t Invalid !! \t The maximum range for first name is 30 and minimum range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(p.firstName);b++)
		{
			if (isalpha(p.firstName[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character !!! Enter again :)");
			goto A;
		}
	}

	//lastname
	B:
	printf("\n\t\t\tLast Name: ");
    scanf("%s",p.lastName);
    p.lastName[0]=toupper(p.lastName[0]);
    if(strlen(p.lastName)>30||strlen(p.lastName)<2)
	{
		printf("\n\t Invalid !! \t The maximum range for last name is 30 and minimum range is 2 :)");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(p.lastName);b++)
		{
			if (isalpha(p.lastName[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last name contain Invalid character !!  Enter again :)");
			goto B;
		}
	}
//gender
	do
	{
	    printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&p.gender);
		if(toupper(p.gender)=='M'|| toupper(p.gender)=='F')
		{
			yes =1;
		}
		else
		{
		yes =0;
		}
        if(!yes)
	    {
	    	printf("\n\t\t Gender contain Invalid character !! Enter either F or M :)");
    	}
	 }	while(!yes);
//age
    printf("\n\t\t\tAge:");
    scanf(" %i",&p.age);
//Address
    do
    {
    O:
    printf("\n\t\t\tAddress: ");
    scanf("%s",p.address);
    p.address[0]=toupper(p.address[0]);
    if(strlen(p.address)>40||strlen(p.address)<3)
	{
		printf("\n\t Invalid !! \t The max range for address is 40 and min range is 3 !!");
		goto O;
	}

}while(!valid);
//Mobile no
do
{
	D:
    printf("\n\t\t\tMobile no: ");
    scanf("%s",p.mobileNo);
    if(strlen(p.mobileNo)>11||strlen(p.mobileNo)!=11)
	{
		printf("\n\t Sorry !!! Invalid. Mobile no. must contain 11 numbers. Enter again :)");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(p.mobileNo);b++)
		{
			if (!isalpha(p.mobileNo[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Mobile no. contain Invalid character !!!  Enter again ...");
			goto D;
		}
	}
}while(!valid);
//email
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",p.email);
    if (strlen(p.email)>30||strlen(p.email)<8)
    {
       printf("\n\t Invalid :( \t The maximum range for email is 30 and minimum range is 8 :)");
	}
}while(strlen(p.email)>30||strlen(p.email)<8);
//disease
    E:
    printf("\n\t\t\tDisease: ");
    scanf("%s",p.disease);
    p.disease[0]=toupper(p.disease[0]);
    if(strlen(p.disease)>20||strlen(p.disease)<3)
	{
		printf("\n\t Invalid !! \t The maximum range for disease is 20 and minimum range is 3 :)");
		goto E;
	}
	else
	{
		for (b=0;b<strlen(p.disease);b++)
		{
			if (isalpha(p.disease[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Disease contain Invalid character !!  Enter again ...");
			goto E;
		}
	}
//DOCTOR NAME
	F:
    printf("\n\t\t\tPrescribed Doctor:");
    scanf("%s",p.doctor);
    p.doctor[0]=toupper(p.doctor[0]);
    if(strlen(p.doctor)>30||strlen(p.doctor)<3)
	{
		printf("\n\t Invalid !! \t The max range for doctor name is 30 and min range is 3 :)");
		goto F;
	}
	else
	{
		for (b=0;b<strlen(p.doctor);b++)
		{
			if (isalpha(p.doctor[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Doctor name contain Invalid character.....  Enter again......");
			goto F;
		}
	}

    fprintf(f," %s %s %c %i %s %s %s %s %s\n", p.firstName, p.lastName, p.gender, p.age, p.address, p.mobileNo, p.email, p.disease, p.doctor);
    printf("\n\n\t\t\t.... Patient Information Loading Successfully Done ...");
    fclose(f);
    P:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	addEntry();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you !! !!");
    	getch();
    	mainmenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto P;
    }
}
//view the patients details

void patientDetailsList()
{
	int r;
	system("cls");
	title();
	FILE *f;
	f=fopen("Record.dat","r");
	printf("\n\n\t\t\t************** Patients Details Record *************\n");
	gotoxy(1,15);
		printf("Full Name");
		gotoxy(20,15);
		printf("Gender");
		gotoxy(32,15);
		printf("Age");
		gotoxy(37,15);
		printf("Address");
		gotoxy(49,15);
		printf("Mobile No.");
		gotoxy(64,15);
		printf("Email");
		gotoxy(88,15);
		printf("Disease");
		gotoxy(98,15);
		printf("Prescribed Doctor\n");
		printf("=================================================================================================================");
		r=17;
		while(fscanf(f,"%s %s %c %i %s %s %s %s %s\n", p.firstName, p.lastName,
					&p.gender, &p.age, p.address, p.mobileNo, p.email, p.disease, p.doctor)!=EOF)
		{
			gotoxy(1,r);
			printf("%s %s",p.firstName, p.lastName);
			gotoxy(20,r);
			printf("%c",p.gender);
			gotoxy(32,r);
			printf("%i",p.age);
			gotoxy(37,r);
			printf("%s",p.address);
			gotoxy(49,r);
			printf("%s",p.mobileNo);
			gotoxy(64,r);
			printf("%s",p.email);
			gotoxy(88,r);
			printf("%s",p.disease);
			gotoxy(98,r);
			printf("%s",p.doctor);
			r++;
		}
		fclose(f);
		getch();
		mainmenu();
}
//SEARCH
void search()
{
	char n[30];
	system("cls");
	title();// call Title function
	FILE *f;
	f=fopen("Record.dat","r");
	printf("\n\n\t\t\t************** Search Patients Record *************\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to be viewed:");
	scanf("%s",n);
	fflush(stdin);
	n[0]=toupper(n[0]);
	while(fscanf(f,"%s %s %c %i %s %s %s %s %s\n", p.firstName, p.lastName, &p.gender, &p.age, p.address, p.mobileNo, p.email, p.disease, p.doctor)!=EOF)
	{
		if(strcmp(p.firstName,n)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(25,15);
			printf("Gender");
			gotoxy(32,15);
			printf("Age");
			gotoxy(37,15);
			printf("Address");
			gotoxy(52,15);
			printf("Mobile No.");
			gotoxy(64,15);
			printf("Email");
			gotoxy(80,15);
			printf("Disease");
			gotoxy(95,15);
			printf("Prescribed Doctor\n");
			printf("=================================================================================================================");
			gotoxy(1,18);
			printf("%s %s",p.firstName, p.lastName);
			gotoxy(25,18);
			printf("%c",p.gender);
			gotoxy(32,18);
			printf("%i",p.age);
			gotoxy(37,18);
			printf("%s",p.address);
			gotoxy(52,18);
			printf("%s",p.mobileNo);
			gotoxy(64,18);
			printf("%s",p.email);
			gotoxy(80,18);
			printf("%s",p.disease);
			gotoxy(95,18);
			printf("%s",p.doctor);
			printf("\n");
			break;
		}
	   }
	   if(strcmp(p.firstName,n)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(f);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        search();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you!!!!!!");
    	getch();
		mainmenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
//Edit
void edit()
{
	FILE *f, *ft;
  int i,b, valid=0;
  char c;
  char n[30];

  system("cls");
  	title();// call Title window
 		ft=fopen("temp.dat","w+");
	   f=fopen("Record.dat","r");
	   if(f==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		mainmenu();
	   }
       	printf("\n\n\t\t\t************** Edit Patients Record *************\n");
	   	gotoxy(12,13);
	   	printf("Enter the First Name of the Patient : ");
	   	scanf(" %s",n);
	   	fflush(stdin);
	   	n[0]=toupper(n[0]);
		gotoxy(12,15);

		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			mainmenu();
		}
		while(fscanf(f,"%s %s %c %i %s %s %s %s %s\n", p.firstName, p.lastName, &p.gender, &p.age, p.address, p.mobileNo, p.email, p.disease, p.doctor)!=EOF)
		{
			if(strcmp(p.firstName, n)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.firstName,p.lastName,p.gender, p.age,p.address,p.mobileNo,p.email,p.disease,p.doctor);
				gotoxy(12,22);
				printf("Enter First Name: ");
				scanf("%s",p.firstName);
				gotoxy(12,24);
				printf("Enter Last Name: ");
				scanf("%s",p.lastName);
				gotoxy(12,26);
				printf("Enter Gender: ");
				scanf(" %c",&p.gender);
				p.gender=toupper(p.gender);
				gotoxy(12,28);
				printf("Enter age: ");
				scanf(" %i",&p.age);
				gotoxy(12,30);
				printf("Enter Address: ");
				scanf("%s",p.address);
				p.address[0]=toupper(p.address[0]);
				gotoxy(12,32);
				printf("Enter mobile no: ");
				scanf("%s",p.mobileNo);
				gotoxy(12,34);
				printf("Enter email: ");
				scanf("%s",p.email);
			    gotoxy(12,36);
				printf("Enter disease: ");
				scanf("%s",p.disease);
				p.disease[0]=toupper(p.disease[0]);
			    gotoxy(12,38);
				printf("Enter Doctor: ");
			    scanf("%s",p.doctor);
			    p.doctor[0]=toupper(p.doctor[0]);
			    printf("\nPress U charecter for the Update Information : ");
				c=getche();
				if(c=='u' || c=='U')
				{
				fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.firstName,p.lastName,p.gender, p.age,p.address,p.mobileNo,p.email,p.disease,p.doctor);
				printf("\n\n\t\t\tPatient record updated successfully...");
				}
			}
			else
			{
			fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.firstName,p.lastName,p.gender, p.age,p.address,p.mobileNo,p.email,p.disease,p.doctor);
			}
		 }
		 if(!valid) printf("\n\t\tNo Record Found...");
	   fclose(ft);
	   fclose(f);
	   remove("Record.dat");
   	   rename("temp.dat","Record.dat");
		getch();
		mainmenu();
}

void dltRecord()
{
    char n[30];
    int found=0;
    system("cls");
    title();
    FILE *f,*ft;
    ft=fopen("temp_file.dat","w+");
    f=fopen("Record.dat","r");
    printf("\n\n\t\t\t************** Delete Patients Record *************\n");
    gotoxy(12,8);
    printf("\n Enter Patient Name to delete: ");
    fflush(stdin);
    gets(n);
    n[0]=toupper(n[0]);
    while(fscanf(f,"%s %s %c %i %s %s %s %s %s\n", p.firstName, p.lastName,&p.gender, &p.age, p.address, p.mobileNo,p.email, p.disease, p.doctor)!=EOF)
    {
        if(strcmp(p.firstName,n)!=0)
        fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.firstName, p.lastName,p.gender,p.age, p.address, p.mobileNo,p.email, p.disease, p.doctor);
        else
        {
             printf("%s %s %c %i %s %s %s %s %s\n", p.firstName, p.lastName,p.gender,p.age, p.address, p.mobileNo,p.email, p.disease, p.doctor);
             found=1;
        }

    }
    if(found==0)
    {
        printf("\n\n\t\t\t Record not found....");
        getch();
        mainmenu();
    }
    else
    {
        fclose(f);
        fclose(ft);
        remove("Record.dat");
        rename("temp_file.dat","Record.dat");
        printf("\n\n\t\t\t Record deleted successfully!!!!!! ");
        getch();
        mainmenu();
    }


}
