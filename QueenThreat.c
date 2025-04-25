/*
Write a C program that takes the position of a queen on a chessboard as input,
then takes the position of another square (a potential move or target).
The program should output whether the queen can capture a piece on that square based on the rules of chess.
*/

#include "stdio.h"

#define VALID_POSITION(column, row) (((column >= 'A') && (column <= 'H')) && ((row >= 1) && (row <= 8)))

int main(void)
{
    char q_column = 0;
    char m_column = 0;
    unsigned short q_row = 0;
    unsigned short m_row = 0;

    printf("Enter the position of the Queen: ");
    scanf(" %c%hu", &q_column, &q_row);

    if(VALID_POSITION(q_column, q_row))
    {
        printf("Enter the position of the next move: ");
        scanf(" %c%hu", &m_column, &m_row);
        if(VALID_POSITION(m_column, m_row))
        {
            if( (m_row - q_row)*(m_row - q_row) == (m_column - q_column)*(m_column - q_column)
                || m_row == q_row
                || m_column == q_column
            ){
                printf("Warning!");
            }
            else
            {
                printf("No threat.");
            }
        }
        else
        {
            printf("Invalid position");
        }
    }
    else
    {
        printf("Invalid position");
    }

    return 0;
}