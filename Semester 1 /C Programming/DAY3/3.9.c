//Conversion of Lowercase to uppercase and vice versa.
#include<stdio.h>
#include<string.h>
void main()
{
char s[100],c;
int i,count=0;
printf("Haritha\t126018017\n");
printf("Enter a string : ");
scanf("%[^\n]",s);
while(s[count]!='\0')
{
c=s[count];
if (c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')
{

printf("%c",c);
}
printf("\n");
count++;
}
for(i=0;i<=strlen(s);i++)
{
if (s[i]>=65 && s[i]<=90)
{
s[i]+=32;
}
else if (s[i]>=97 && s[i]<=122)
{
s[i]-=32;
}
}
printf("After conversion : %s ",s);

}