#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int i,n,x,j,loc,item,ch;
int arr[100];
char s1[50];
int left,right,count;
//Structure to store data
typedef struct key_value
 {
     char name[50];
     char acn[50];
     char bal[10];
     char email[50];

 }dict;
dict values[100];
dict temp;

 int excel()
 {
	char s[50];
	fflush(stdin);
    printf("Enter the path of the file: ");
    scanf("%49[^\n]%*c", s);
    FILE *fp=fopen(s,"r");
    printf("Enter the number of rows to be read:");
	scanf("%d",&n);
    if(!fp)
    {
        printf("Error occured");
        return 0;
    }
    char buff[100];
    int row_count=0;
    int field_count=0;
    int i=0;
    do
    {
        char *ptr=fgets(buff,100,fp);
        if(ptr==NULL)
            break;

        field_count=0;
        row_count++;

        char *field=strtok(buff,",");
        while(field)
        {
            if(field_count==0)
                strcpy(values[i].name, field);
            if(field_count==1)
                strcpy(values[i].acn, field);
            if(field_count==2)
                strcpy(values[i].bal, field);
            if(field_count==3)
                strcpy(values[i].email, field);

            field=strtok(NULL,",");
            field_count++;
        }
        i++;
    }
    while(1);
    n=row_count;
    fclose(fp);
    return 0;
}
 void display(dict *values,int n)
 {
     printf("\n\n%-35s\t%-20s\t%-15s\t%s\n","NAME","ACCOUNT NUMBER","BALANCE","EMAIL");
     for(int i=1;i<n;i++)
     {
         printf("%-35s\t%-20s\t%-15s\t%s\n",values[i].name,values[i].acn,values[i].bal,values[i].email);
     }
 }

int name_search(dict *values,int n)
{
   fflush(stdin);
   int  found=0;
   printf("Enter a Name to search: ");
   gets(s1);
   for(i=0; i<n; i++)
   {
     if(strcmp(s1,values[i].name) == 0)
     {
       found=1;
       printf("Found in row: %d\n", i+1);
       printf("\n\n%-35s\t%-20s\t%-15s\t%s\n","NAME","ACCOUNT NUMBER","BALANCE","EMAIL");
       printf("%-35s\t%-20s\t%-15s\t%s\n",values[i].name,values[i].acn,values[i].bal,values[i].email);
     }
   }

   if(found==0)
    printf("Not found");
   return 0;
}
int acn_search(dict *values,int n)
{
    fflush(stdin);
   int  found=0;
   printf("Enter a Account Number to search: ");
   scanf("%s", s1);
   for(i=0; i<n; i++)
   {
     if(strcmp(s1, values[i].acn) == 0)
     {
       found=1;
       printf("Found in row: %d\n", i+1);
       printf("\n\n%-35s\t%-20s\t%-15s\t%s\n","NAME","ACCOUNT NUMBER","BALANCE","EMAIL");
       printf("%-35s\t%-20s\t%-15s\t%s\n",values[i].name,values[i].acn,values[i].bal,values[i].email);
     }
   }
   if(found==0)
    printf("Not found");
   return 0;
}

void quickSort(dict *values, int left, int right)
{
  char *x;
  i = left;
  j = right;
  x = values[(left+right)/2].name;
  do
  {
    while((strcmp(values[i].name,x) < 0) && (i < right))
    {
       i++;
    }//s1 small s2 big
    while((strcmp(values[j].name,x) > 0) && (j > left))
    {
        j--;
    }//s1 big s2 small
    if(i <= j) {
      temp=values[i];
      values[i]=values[j];
      values[j]=temp;
      i++;
      j--;
   }
  } while(i <= j);

  if(left < j)
  {
     quickSort(values, left, j);
  }
  if(i < right)
  {
     quickSort(values, i, right);
  }
}
void quickSortMain(dict *values, int count)
{
  quickSort(values, 0, count-1);
}

void qs_main(dict *values,int n)
{
    fflush(stdin);
  quickSortMain(values, n);
  printf("\n\n%-35s\t%-20s\t%-15s\t%s\n","NAME","ACCOUNT NUMBER","BALANCE","EMAIL");
  for(i=0; i<n-1; i++)
  {
     printf("%-35s\t%-20s\t%-15s\t%s\n",values[i].name,values[i].acn,values[i].bal,values[i].email);
  }
}
void bsort_bal(dict *values, int n)
{
    int i, j;
    for (i=0;i< n-1;i++)
    {
        for (j=0;j<(n-1-i); j++)
        {
            if (strcmp(values[j].bal,values[j+1].bal)<0)
            {
                temp = values[j];
                values[j] = values[j + 1];
                values[j+1] = temp;
            }
        }
    }
    printf("\n\n%-35s\t%-20s\t%-15s\t%s\n","NAME","ACCOUNT NUMBER","BALANCE","EMAIL");
    for(i=1; i<n; i++)
  {
     printf("%-35s\t%-20s\t%-15s\t%s\n",values[i].name,values[i].acn,values[i].bal,values[i].email);
  }
}
void bsort_acn(dict *values, int n)
{
    int i, j;
    for (i=0;i< n-1;i++)
    {
        for (j=0;j<(n-1-i); j++)
        {
            if (strcmp(values[j].acn,values[j+1].acn)<0)
            {
                temp = values[j];
                values[j] = values[j + 1];
                values[j+1] = temp;
            }
        }
    }
    printf("\n\n%-35s\t%-20s\t%-15s\t%s\n","NAME","ACCOUNT NUMBER","BALANCE","EMAIL");
    for(i=1; i<n; i++)
  {
     printf("%-35s\t%-20s\t%-15s\t%s\n",values[i].name,values[i].acn,values[i].bal,values[i].email);
  }
}

void search()
 {
    do
     {
         printf("\n--------SEARCH MENU--------\n");
         printf("\n1.Search by Account Number\n2.Search by Name\n3.Return to Main Menu");
         printf("\nEnter you Choice\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:acn_search(values,n);
                    break;
             case 2:name_search(values,n);
                    break;
             case 3:break;
             default:printf("\nInvalid Choice");
                    break;
         }
     }
   while(ch!=3);
 }
 void sort()
 {
    do
     {
         printf("\n--------SORT MENU--------\n");
         printf("\n1.Sort by Balance\n2.Sort by Account Number\n3.Sort by Name\n4.Return to Main Menu");
         printf("\nEnter you Choice\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:bsort_bal(values,n);
                    break;
             case 2:bsort_acn(values,n);
                    break;
             case 3:qs_main(values,n);
                    break;
             case 4:break;
             default:printf("\nInvalid Choice");
                    break;
         }
     }
   while(ch!=4);
 }
int main()
 {
     do
     {
         printf("\n--------MAIN MENU--------\n");
         printf("\n1.Extract data from Excel sheet\n2.Search for Data\n3.Sort the data\n4.Display the data\n5.Exit");
         printf("\nEnter you Choice\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:excel();
                    break;
             case 2:search();
                    break;
             case 3:sort();
                    break;
             case 4:display(values,n);
                    break;
             case 5:exit(0);
                    break;
             default:printf("\nInvalid Choice");
         }
     }
   while(1);
 }
