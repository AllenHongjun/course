/*【例4-11】（中国古典算术问题）某工地需要搬运砖块，已知男人一人搬3块，女人一人搬2块，小孩两人搬一块。问用45人正好搬45块砖，有多少种搬法？*/

/* 45人正好搬45块砖，程序版本1 */
#include <stdio.h>
int main(void)
{    
    int child, women, men;

    for(men = 0; men <= 45; men++)
        for(women = 0; women <= 45; women++)
            for(child = 0; child <= 45; child++)
	        if(men+women+child==45 && men*3+women*2+child*0.5==45)
                    printf("men=%d,women=%d,child=%d\n", men, women, child);

    return 0;
}
