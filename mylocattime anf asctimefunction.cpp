/*Name:Fateh Ali Shahrukh Khan
sec C
roll:I17-0439
teacher :Sir Shahid Qureshi
Assignment 1.
*/

#include<iostream>
#include<ctime>
using namespace std;
tm mylocaltime(int value)
{
	value=value+(18000); //GMT+5hours so 18000+
int rt=value,cal=value,wdayval=value; //giving raw value to variables for calculations
tm str;
int nyr=31536000,leapyrs=0,lyr=31622400,mon=2592000,monl=2678400,monfeb=2419200,day=86400,hr=3600,min=60,ct=0,k,a2,fh,rd,a3,rh,a=0,b=0,s,mrt,a1=0,b1=0,c1=0,d=0,fm,fs,a4,sec;//current time //total no of leap years are 12/
s=cal/nyr;
str.tm_year=s+1970-1900;
	for(int i=0,j=0;i<s;i++,j++) //rawtime-leap year
	{
		k=1970+i; //adding values
		k=k%4; //for leap years
		if(k!=0) //condition
		{
		a=rt-nyr;
		rt=a;
		}
		else if(k==0) //non leap yaer
		{
		b=rt-lyr; //subrtacting again and again for raw time
		rt=b;
		}
}
//cout<<"leap "<<leapyrs<<"\n";
if(a<b) //we need minimum raw time
{
	cal=a;
	mrt=a;
}
if(b<a) //we need minimum raw time
{
	cal=b;
	mrt=b;
}
	int yday; //for raw days calculation
	s=cal/mon; 
	yday=s;
	str.tm_mon=s+1; //since we are starting from 0
	for(int i=0,j=0;i<s;i++,j++)
	{
		//cout<<"j"<<j<<endl;
		if(i==0||i==2||i==4||i==6||i==7||i==9||i==11)//31days
		{
			a1=mrt-monl;
			mrt=a1; //subrtacting again and again for raw time
		}
		if(i==1)//feb
		{
			b1=mrt-monfeb;
			mrt=b1;	//subrtacting again and again for raw time
		}
		if(i==3||i==5||i==8||i==10)//30
		{
			c1=mrt-mon;
			mrt=c1;
		}
	}
	if(c1<b1&&c1<a1)
	{
		rd=c1;	//we need to final rawtime that is minimum
	}
	if(b1<c1&&b1<a1)
	{
		rd=b1;
	}
	if(a1<c1&&a1<b1)
	{
		rd=a1;
	}
rd=a1;

d=a1/day;
str.tm_mday=d; //for raw days 
//cout<<"raw day"<<rd<<endl;
for(int i=0,j=0;i<d;i++)
{

	a2=rd-day;
	rd=a2; //for minimum raw hours
}
rh=a2;
fh=rh/hr;
str.tm_hour=fh;
for(int i=0;i<fh;i++) //final hours
{
	a3=rh-hr;
	rh=a3;
}
 str.tm_min=rh/60;
 fm=rh/min;
 sec=rh-(fm*60); //final raw minutes
 str.tm_sec=sec;
int nodays,wd; //for weekdays and year days
nodays=wdayval/day;
wd=nodays%7; //algo for week days
wd=wd+3;
if(wd>7)
{
	wd=wd-7;
}
str.tm_wday=wd;
int daydata=0;//for year days
for(int i=0;i<yday;i++)
{
	if(i==0||i==2||i==4||i==6||i==7||i==9||i==11)
	{
		daydata+=31; //addition according to months
	}
	if(i==1)
	{
		daydata+=28;
	}
	if(i==3||i==5||i==8||i==10)
	{
		daydata+=30;
	}
}
	daydata=daydata+d;
	str.tm_yday=daydata;
return str;
}
void myasctime(tm s)
{
	tm k;
	string month,day;
	switch (s.tm_mon) //switch case for months name
	{
		case 1:
		month="Jan";
		break;
		case 2:
		month="Feb";
		break;
		case 3:
		month="March";
		break;
		case 4:
		month="April";
		break;
		case 5:
		month="May";
		break;
		case 6:
		month="June";
		break;
		case 7:
		month="July";
		break;
		case 8:
		month="Aug";
		break;
		case 9:
		month="Sept";
		break;
		case 10:
		month="Oct";
		break;
		case 11:
		month="Nov";
		break;
		case 12:
		month="dec";
		break;
	}
	switch(s.tm_wday) //switch case for weeks
	{
		case 1:
		day="Mon";
		break;
		case 2:
		day="Tue";
		break;
		case 3:
		day="Wed";
		break;
		case 4:
		day="Thur";
		break;
		case 5:
		day="Fri";
		break;
		case 6:
		day="Sat";
		break;
		case 7:
		day="Sun";
		break;
	}
	s.tm_year=s.tm_year+1900;
	cout<<day<<" "<<month<<" "<<s.tm_mday<<" "<<s.tm_hour<<":"<<s.tm_min<<":"<<s.tm_sec<<" "<<s.tm_year;
}
int main()
{

  time_t rawtime; //time_t is just an int
  struct tm timeinfo;

  rawtime = time ( NULL ); //passing rawtime by refernce. time() will store the result into this variable
  cout<<"\nSeconds elapsed since midnight (00:00:00) Jan 1, 1970: "<< rawtime << endl;

  timeinfo = mylocaltime (rawtime);
  cout<<"\nStructure tm's memebers:\n";
  cout<<"\n    tm_sec: "<<timeinfo.tm_sec <<" tm_min: "<< timeinfo.tm_min<<"  tm_hour: "<< timeinfo.tm_hour<<endl<<endl<<"  tm_mday: "<<timeinfo.tm_mday<<" tm_mon: "<< timeinfo.tm_mon<<"    tm_year: " << timeinfo.tm_year<<endl<<endl<<"    tm_wday: "<< timeinfo.tm_wday<<"    tm_yday: "<< timeinfo.tm_yday<<endl;

  cout << "\n\nThe current date/time is: ";
  myasctime (timeinfo);
  return 0;

}
