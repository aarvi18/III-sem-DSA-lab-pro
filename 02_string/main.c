/*

[Q2] Design, Develop and Implement a Program in C for the following operations on Strings
a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with REP if PAT exists in STR.
c. Report suitable messages in case PAT does not exist in STR.
Support the program with functions for each of the above operations. Don't use Built-in functions.

*/

#include<stdio.h>
char STR[100],PAT[100],REP[100],ANS[100];
int temp, s, p, r, a, flag = 0;
void read( );
void replace( );
void print( );
int main( )
{
    read( );
    replace( );
    print( );
    return 0;
}
void read( )
{
    printf("Enter the MAIN string: \n");
    gets(STR);
    printf("Enter a PATTERN string: \n");
    gets(PAT);
    printf("Enter a REPLACE string: \n");
    gets(REP);
}
void replace ( )
{
    temp = s = p = a = 0;
    while ( STR[temp] != '\0')
    {
// Checking for Match
        if ( STR[s] == PAT[p] )
        {
            p++;
            s++;
            if ( PAT[p] == '\0')
            {
//copy replace string in ans string
                for(r = 0; REP[r] != '\0'; r++, a++)
                    ANS[a] = REP[r];
                flag=1;
                p = 0;
                temp = s;
            }
        }
        else //Mismatch
        {
            ANS[a] = STR[temp];
            temp++;
            a++;
            s = temp;
            p = 0;
        }
    }
}
void print( )
{
    if(flag==0)
        printf("Pattern not found!!!\n");
               else
               {
               ANS[a] = '\0';
               printf("\nThe RESULTANT string is:\n%s\n" ,ANS);
           }
           }
