/*
Write a C program that takes the position of a queen on a chessboard as input,
then takes the position of another square (a potential move or target).
The program should output whether the queen can capture a piece on that square based on the rules of chess.

Solution:

The Queen will capture any piece that is on the same line or diagonal as her.
If a piece is on the same line as the Queen, it means they share the same row or the same column.
If a piece is on a diagonal, the difference between its row and the Queen's row is equal to the difference between its column
and the Queen's column.
*/

#include "stdio.h"

/*
This macro-like function validate the input column and the input row
*/
#define VALID_POSITION(column, row) (((column >= 'A') && (column <= 'H')) && ((row >= 1) && (row <= 8)))

int main(void)
{
    char q_column = 0;  /* Queen column */
    char p_column = 0;  /* Piece column */
    unsigned short q_row = 0;   /* Queen row*/
    unsigned short m_row = 0;   /* Piece row*/

    printf("Enter the position of the Queen: ");
    scanf(" %c%hu", &q_column, &q_row);

    if(VALID_POSITION(q_column, q_row))
    {
        printf("Enter the position of the next move: ");
        scanf(" %c%hu", &p_column, &m_row);
        if(VALID_POSITION(p_column, m_row))
        {
            /* First condition compare the differences of rows and columns, the next two condition compare rows and columns*/
            if( (m_row - q_row)*(m_row - q_row) == (p_column - q_column)*(p_column - q_column)
                || m_row == q_row
                || p_column == q_column
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