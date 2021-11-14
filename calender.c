#include <stdio.h>

int isleapyear(int year);
int daysinmonth(int m,int y);
int validdate(int d,int m, int y);
int datedifference(int d1,int m1,int y1,int d2,int m2,int y2);
int datecomparison(int d1,int m1,int y1,int d2,int m2,int y2);
int weekday(int n);
int dayforanydate(int d2,int m2,int y2);
int getWeekDayForDate(int d2,int m2,int y2);
int monthNames(int m);
int printingCalender(int month,int year);
int main()
{
    int year = 2022;
    for(int m=1;m<=12;m++)
    {
 printingCalender(m,year);
 printf("\n\n");
    }
}
int printingCalender(int month,int year)
{
    int startday=getWeekDayForDate(1,month,year);
int x = daysinmonth( month, year);
//printf("\nSTartday=%d\n",startday);

//printf("Month starts on %d and month has %d days.\n",startday,x);
            printf("%13s"," ");
            monthNames(month);
            printf(" - %d",year);
printf("\n");

   for(int n=0;n<=6;n++)
   {
    weekday(n);
   }
   printf("\n");
    for(int i =1 ; i<=startday;i++)
    {
    printf("%6s"," ");
    }
    //printf("%6s","1");
    for(int i =1 ; i<=x;i++)
    {
    printf("%6d",i);

     if((i + startday )%7==0)
        printf("\n");

    }
}
int isLeapYear(int yy)
{
    if(yy % 400 == 0 || (yy % 4 == 0 && yy % 100 !=0) )
    {
        return 1;
    }
    else
        return 0;
}
int daysinmonth(int m, int y)                  //function to check days in month..
{
if(m==4 || m==6 || m==9 || m==11)
return(30);
if(m==2)
{
if(isLeapYear(y))                              // year will be passed to leap year function
    return 29;
else
    return 28;
}
    return 31;
}
int validdate(int dd ,int mm, int yy)         // function to check date is valid or not
{
    if(yy<1)                // if entered year is less than zero
        return 0;
    if(mm<1 || mm>12)
        return 0;
    if(dd<1)
        return 0;
    int ndays=daysinmonth(mm,yy);
    if(dd>ndays)
        return 0;
    return 1;
}
       
int datedifference(int d1, int m1, int y1, int d2, int m2, int y2)
{   //D2>D1   +ve, D1>D2 -ve, 0 if equal
    //1-1-2021 to 31-12-2021 = + 365 31-12-2021 to 1-1-2021 =  -365
                    // if Day2>Day1  then only program will work correctly...
    //d2-m2-y2 to d1-m1-y1
    int cmp=datecomparison(d1,m1,y1,d2,m2,y2);
    if(cmp==0)
        return 0;

    if(cmp==-1)
    {
        int t=d1;                   // we will reverse the date here ....
        d1=d2;
        d2=t;


        t=m1;                       // we will reverse the month here ....
        m1=m2;
        m2=t;


        t=y1;                       // we are reversing year here ......
        y1=y2;
        y2=t;
    }
  int diff1 = d2 - 1;
  int diff2 = d1 - 1;

  int diff3 = 0;
  for (int m = 1; m <= m2 - 1; m++)
    diff3 = diff3 + daysinmonth(m, y2);
  int diff4 = 0;

  for (int m = 1; m <= m1 - 1; m++)
    diff4 = diff4 + daysinmonth(m, y1);
  int diff5 = 0;
  for (int y = y1; y <= y2 - 1; y++)
    if (isLeapYear(y))
      diff5 = diff5 + 366;
    else
      diff5 = diff5 + 365;
  int date = diff1 + diff3 + diff5 - diff4 - diff2;
  return date;
}
int datecomparison(int d1,int m1,int y1,int d2,int m2,int y2)
{
    //Return 0 if equal, -1 if D1<D2, 1 if D2>D1
    if(y2>y1)
        return 1;
    if(y2<y1)
        return -1;
        //y1 --y2
    if(m2>m1)
        return 1;
    if(m2<m1)
        return -1;
        // m1==m2
    if(d2>d1)
        return 1;
    if(d2<d1)
        return -1;
        //d1==d2
    return 0;
}

int weekday(int n)
{
switch (n)
{
case 0:
    printf("%6s","Sun");
    break;
case 1:
    printf("%6s","Mon");
    break;
case 2:
    printf("%6s","Tue");
    break;
case 3:
    printf("%6s","Wed");
    break;
case 4:
    printf("%6s","Thu");
    break;
case 5:
    printf("%6s","Fri");
    break;
case 6:
    printf("%6s","Sat");
    break;
default:
{
    printf("wrong day");
}
}
}
int dayforanydate(int d2,int m2,int y2)
{
int d1=31,m1=10,y1=2021;
    int ndays=datedifference(d1,m1,y1,d2,m2,y2);
    ndays = ndays % 7;
    ndays = ndays + 7;
    ndays=ndays%7;
    //ndays=(ndays + 2) %7;
    weekday(ndays);
}
int getWeekDayForDate(int d2,int m2,int y2)
{
int d1=31,m1=10,y1=2021;
    int ndays=datedifference(d1,m1,y1,d2,m2,y2);
    ndays = ndays % 7;
    ndays = ndays + 7;
    ndays=ndays%7;
    //ndays = (ndays + 2) %7;
    return ndays;
}
int monthNames(int m)
{
switch (m)
{
case 1:
    printf("January  ");
    break;
case 2:
    printf("February  ");
    break;
case 3:
    printf("March  ");
    break;
case 4:
    printf("April  ");
    break;
case 5:
    printf("May  ");
    break;
case 6:
    printf("June  ");
    break;
case 7:
    printf("July  ");
    break;
case 8:
    printf("August  ");
    break;
case 9:
    printf("September  ");
    break;
case 10:
    printf("October  ");
    break;
case 11:
    printf("November  ");
    break;
case 12:
    printf("December  ");
    break;

default:
{
    printf("wrong Month");
}
}
}



