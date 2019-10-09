#include <stdio.h>
     
int search_one_list(char **num, int row_num, int list_index, int *top, int *button)
{
    int i, top_temp, button_temp;
    int weigh = 0;
    int weigh_max = 0;
    top_temp = 0;
    button_temp = 0;
    
    //printf("row_num = %d, list_index = %d\n", row_num);
    for (i == 0; i < row_num; i++) {
        //printf("num[%d][%d] = %c\n", i, list_index, num[i][list_index]);
        
        if (num[i][list_index] == '1') {
            weigh++;
            button_temp = i;
        } else {
            weigh = 0;
        }
        if (weigh > weigh_max) {
            weigh_max = weigh;
            *top = i - weigh + 1;
            *button = button_temp;
        }
        
        //printf("weigh = %d, weigh_max = %d\n", weigh, weigh_max);
        
    }
    
    if (weigh_max == 0) {
        return 0;
    }
    //printf("top = %d, button = %d\n", top, button);
    return 1;
}

int compare_one_list(char **num, int list_index, int top, int button)
{
    int i;

    for(i = top; i <= button; i++) {
        if (num[i][list_index] != '1') {
            return 0;
        }
    }
    
    return 1;
}
struct recard_table{
    int high;
    int weigh;
    int sqr;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize)
{
    int i, j, right, left;
    int top, button;
    int col = *matrixColSize;
    int row = matrixSize;
    int recard[10000][10000][1] = {0};
    printf("row = %d, col = %d\n", row, col);
    struct recard_table **recard = malloc(sizeof(struct recard_table) * 10000);
    
    if ((matrix == NULL) || (col == 0) || (row == 0)) {
        return 0;
    }
    
    /* 初始化第一行 */
    for (i = 0; i < col; i++) {
        if (matrix[0][i] == '1') {
            recard[0][i].high = 1;
            recard[0][i].weigh = ((i == 0) ? 1 : (recard[i - 1].weigh + 1));
            recard[0][i].sqr = ((i == 0) ? 1 : (recard[i - 1].sqr + 1));
        } else {
            recard[0][i].high = 0;
            recard[0][i].weigh = 0;
            recard[0][i].sqr = 0;
        }
    }
    
    /* 初始化第一列 */
    for (i = 0; i < row; i++) {
        if (matrix[i][0] == '1') {
            recard[i][0].high = 1;
            recard[i][0].weigh = ((i == 0) ? 1 : (recard[i - 1].weigh + 1));
            recard[i][0].sqr = ((i == 0) ? 1 : (recard[i - 1].sqr + 1));
        } else {
            recard[i][0].high = 0;
            recard[i][0].weigh = 0;
            recard[i][0].sqr = 0;
        }
    }
    
    for (i = 1; i < col; i++) {
        for (j = 1; j < row; j++) {
            if(matrix[i][j] == '1') {
                recard[i][j].high = recard[i - 1][j].weigh + 1;
                recard[i][j].weigh = recard[i][j - 1].weigh + 1;
                recard[i][j].sqr = ((i == 0) ? 1 : (recard[i - 1].sqr + 1));k
            }
        }
    }
    
    for (i = 0; i < col; i++) {
        if (search_one_list(matrix, row, i, &top, &button) == 0) {
            continue;
        }
        
        printf("top = %d, button = %d, ", top, button);
       
        temp = button - top + 1;
        sqr_tmp = temp;

        for (left = i - 1; left >= 0; left--) {
            if (compare_one_list(matrix, left, top, button)) {
                sqr_tmp += temp;
                printf("compare_one_list left ok! ");
            } else {
                break;
            }
        }
        printf("i = %d, sqr_tmp = %d, ", i, sqr_tmp);
        for (right = i + 1; right < col; right++) {
            if (compare_one_list(matrix, right, top, button)) {
                sqr_tmp += temp;
                printf("compare_one_list right ok! ");
            } else {
                break;
            }
        }
        printf("sqr_tmp = %d, ", sqr_tmp);
        if (sqr_tmp > sqr_max)
            sqr_max = sqr_tmp;
        printf("sqr_max = %d\n", sqr_max);
        sqr_tmp = 0;
    }

    return sqr_max;
}
