/*
【例8-14】为了防止信息被别人轻易窃取，
需要把电码明文通过加密方式变换成为密文。
变换规则如下：小写字母z变换成为a，
其他字母变换成为该字母ASCII码顺序后1位的字母，比如o变换成为p。
*/

/* 密码变换问题 */
# include <stdio.h>
# include <string.h>
# define MAXLINE 100
void encrypt ( char *);
int main (void)
{
    char line [MAXLINE];
   
    printf ("Input the string:");
    gets(line);
    encrypt (line);
    printf ("%s%s\n", "After being encrypted: ", line);

    return 0;
}

void encrypt ( char *s)
{
    for ( ; *s != '\0'; s++)
        if (*s == 'z')
            *s = 'a';
        else
            *s = *s+1;
}

/*
void encrypt (char s[ ])
{
    int i;

    for(i = 0; s[i] != '\0'; i++)
        if (s[i] == 'z')
            s[i] = 'a';
	else
	    s[i] = s[i]+1;
}
*/
