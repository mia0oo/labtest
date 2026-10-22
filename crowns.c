#include "crowns.h"

bool is_valid_mark(char c)
{
    return(c == ' '||c == 'X'||c == '*');
}

void test(void)
{
    board b;
    char str[2*MXBSIZE*MXBSIZE];
    
    assert(str2board(&b, "aXbX|cXdX"));
    assert(b.sze == 2);
    assert(count_unknowns(b) == 0);
    
    assert (board2str(NULL, NULL) == false);
    
    assert(str2board(&b, "a b |c*d "));
    assert(count_unknowns(b) == 3);

    assert(str2board(&b, "aXbX|cXdX"));
    assert(board2str(str, &b));
    assert(strcmp(str, "aXbX|cXdX") == 0);

    assert(str2board(&b, "a b |a b "));
    assert(rule1(&b) == false);
}

bool str2board(board* b, char* str)
{
    int i = 0, j = 0;
    int size = 0;
    if (b == NULL||str == NULL||*str == '\0')
    {
        return false;
    }
    while (*str != '\0')
    {
        if (*str == '|')
        {
            if (size == 0)
            {
                size = j;
            }
            if (j != size)
            {
                return false;
            }
            j = 0;
            i++;
            str++;
            continue;
        }
        if (i >= MXBSIZE||j >= MXBSIZE)
        {
            return false;
        }
        char reg = *str++;
        char mar = *str++;
        if (!is_valid_mark(mar))
        {
            return false;
        }
        b->cs[i][j].region = reg;
        b->cs[i][j].mark = mar;
        j++;
    }
    i++;
    if(i != size||j != size)
    {
        return false;
    }
    b->sze = size;
    return true;
}

bool board2str(char* str, const board* b)
{
    char* nstr = str;
    if (b == NULL||str == NULL)
    {
        return false;
    }
    for (int i = 0; i < b->sze; i++)
    {
        for (int j = 0; j < b->sze; j++)
        {
            *nstr++ = b->cs[i][j].region;
            *nstr++ = b->cs[i][j].mark;
        }
        if (i < (b->sze)-1)
        {
            *nstr++ = '|';
        }
    }
    *nstr = '\0';
    return true;
}

int count_unknowns(board b)
{
    int count=0;
    for (int i = 0; i < b.sze; i++)
    {
        for (int j = 0; j < b.sze; j++)
        {
            if (b.cs[i][j].mark == ' ')
            {
                count++;
            }
        }
    }
    return count;
}

bool rule1(board* b)
{
    if (b == NULL)
    {
        return false;
    }
    bool change1 = false;
    for (int i = 0; i < b->sze; i++)
    {
        for (int j = 0; j < b->sze; j++)
        {
            if(b->cs[i][j].mark == '*')
            {
                //same row and column
                for (int k = 0; k < b->sze; k++)
                {
                    if (b->cs[i][k].mark == ' ')
                    {
                        b->cs[i][k].mark = 'X';
                        change1 = true;
                    }
                    if (b->cs[k][j].mark == ' ')
                    {
                        b->cs[k][j].mark = 'X';
                        change1 = true;
                    }
                }

                //same region
                char reg = b->cs[i][j].region;
                for (int r = 0; r < b->sze; r++)
                {
                    for (int c = 0; c < b->sze; c++)
                    {
                        if(b->cs[r][c].region == reg && b->cs[r][c].mark == ' ')
                        {
                            b->cs[r][c].mark = 'X';
                            change1 = true;
                        }
                    }
                }

                //neighbours
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        int nr = i + r;
                        int nc = j + c;
                        if (nr >= 0 && nr < b->sze && nc >= 0 && nc < b->sze)
                        {
                            if (b->cs[nr][nc].mark == ' ')
                            {
                                b->cs[nr][nc].mark = 'X';
                                change1 = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return change1;
}


bool rule2(board* b)
{
    if (b == NULL)
    {
        return false;
    }
    bool change2 = false;
    bool again = true;
    while (again)
    {
        again = false;
        bool newcrown[MXBSIZE][MXBSIZE] = {false};
        //row
        for (int i = 0; i < b->sze; i++)
        {
            int unk_cnt = 0;
            int unk_j = -1;
            for (int j = 0; j < b->sze; j++)
            {
                if (b->cs[i][j].mark == ' ')
                {
                    unk_cnt++;
                    unk_j = j;
                }
            }
            if (unk_cnt == 1)
            {
                newcrown[i][unk_j] = true;
            }
        }

        //column
        for (int j = 0; j < b->sze; j++)
        {
            int unk_cnt = 0;
            int unk_i = -1;
            for (int i = 0; i < b->sze; i++)
            {
                if (b->cs[i][j].mark == ' ')
                {
                    unk_cnt++;
                    unk_i = i;
                }
            }
            if (unk_cnt == 1)
            {
                newcrown[unk_i][j] = true;
            }
        }

        //region
        for (int i = 0; i < b->sze; i++)
        {
            for (int j = 0; j < b->sze; j++)
            {
                int unk_cnt = 0;
                int unk_i = -1, unk_j = -1; 
                if (b->cs[i][j].mark == ' ')
                {
                    char unk_reg = b->cs[i][j].region;
                    for (int r = 0; r < b->sze; r++)
                    {
                        for (int c = 0; c < b->sze; c++)
                        {
                            if (b->cs[r][c].region == unk_reg && b->cs[r][c].mark == ' ')
                            {
                                unk_cnt++;
                                unk_i = r;
                                unk_j = c;
                            }
                        }
                    }
                    if (unk_cnt == 1)
                    {
                        newcrown[unk_i][unk_j] = true;
                    }
                }
            }
        }
        for (int i = 0; i < b->sze; i++)
        {
            for (int j = 0; j < b->sze; j++)
            {
                if (newcrown[i][j])
                {
                    b->cs[i][j].mark = '*';
                    again = true;
                }
            }
        }
        if(rule1(b))
        {
            again = true;
        }
        if(again)
        {
            change2 = true;
        }
    }
    return change2;
}
    


bool rule3(board* b)
{
    if(b == NULL)
    {
        return false;
    }
    bool change3 = false;
    bool again = true;
    while (again)
    {
        again = false;
        for (int i = 0; i < b->sze; i++)
        {
            for (int j = 0; j < b->sze; j++)
            {
                if(b->cs[i][j].mark == ' ')
                {
                    board d = *b;
                    d.cs[i][j].mark = '*';
                    rule1(&d);
                    bool noway = false;
                    for (int i2 = 0; i2 < b->sze; i2++)
                    {
                        for (int j2 = 0; j2 < b->sze; j2++)
                        {
                            char reg = d.cs[i2][j2].region;
                            int unk_cnt = 0;
                            int cr_cnt = 0;
                            for (int i3 = 0; i3 < b->sze; i3++)
                            {
                                for (int j3 = 0; j3 < b->sze; j3++)
                                {
                                    if(b->cs[i3][j3].region == reg)
                                    {
                                        if(d.cs[i3][j3].mark == ' ')
                                        {
                                            unk_cnt++;
                                        }
                                        if(d.cs[i3][j3].mark == '*')
                                        {
                                            cr_cnt++;
                                        }
                                    }
                                }
                            }
                            if (unk_cnt == 0 && cr_cnt == 0)
                            {
                                noway = true;
                                break;
                            } 
                        }
                        if (noway)
                        {
                            break;
                        } 
                    }
                    if (noway)
                    {
                        b->cs[i][j].mark = 'X';
                        again = true;
                        change3 = true;
                         break;
                    }
                    
                }
            }
            if (again)
            {
                break;
            }
            
        }
        if (again)
        {
            rule1(b);
        }
    }
    return change3;
}


bool rule5(board* b)
{
    if (b == NULL)
    {
        return false;
    }
    char str_solu[MXBSIZE+1];
    for (int n = 0; lut(b->sze, n, str_solu); n++)
    {
        board solu = *b;
        for (int i = 0; i < b->sze; i++)
        {
            for (int j = 0; j < b->sze; j++)
            {
                solu.cs[i][j].mark = 'X';
            }
        }
        bool possible = true;
        for (int i = 0; i < b->sze; i++)
        {
            int j = str_solu[i] - 'A';
            if (j < 0||j >= b->sze)
            {
                possible = false;
                break;
            }
            solu.cs[i][j].mark = '*';
        }
        if (!possible)
        {
            continue;
        }
        bool is_valid = true;
        for (int i = 0; i < b->sze; i++)
        {
            for (int j = 0; j < b->sze; j++)
            {
                char reg = solu.cs[i][j].region;
                int cr_cnt = 0;
                for (int r = 0; r < b->sze; r++)
                {
                    for (int c = 0; c < b->sze; c++)
                    {
                        if (solu.cs[r][c].region == reg && solu.cs[r][c].mark == '*' )
                        {
                            cr_cnt++;
                        }
                    }
                }
                if (cr_cnt != 1)
                {
                    is_valid = false;
                    break;
                }
            }
            if (!is_valid)
            {
                break;
            }
        }
        if (is_valid)
        {
            for (int i = 0; i < b->sze; i++)
            {
                for (int j = 0; j < b->sze; j++)
                {
                    b->cs[i][j].mark = solu.cs[i][j].mark;
                }
            }
            return true;
        }
    }
    return true;
}
