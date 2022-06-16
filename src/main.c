/* bounce -- A ``UwU`` bouncing across the screen
  Copyright (C) 2020 Aidan Neal

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define DELAY 20000

int main(void)
{
  int x = 0, y = 0;
  int max_y = 0, max_x = 0;
  int next_x = 0;
  int direction = 1;

  /* It initializes the screen. */
  initscr();
  /* Preventing the characters being typed from being printed to the screen. */
  noecho();
  /* Hiding the cursor. */
  curs_set(FALSE);

  /* Creating an infinite loop. */
  while (1)
  {
    /* Getting the maximum y and x coordinates of the screen. */
    getmaxyx(stdscr, max_y, max_x);

    /* Clear the screen. */
    clear();

    /* Moving the cursor to the position (y, x) and printing the string "UwU". */
    mvprintw(y, x, "UwU");

    /* Updating the screen. */
    refresh();

    /* Delaying the execution of the program by 20,000 microseconds. */
    usleep(DELAY);

    /* Calculating the next x coordinate. */
    next_x = x + direction;

    /* This is checking if the next x coordinate is greater than the maximum x coordinate or less than
    0. If it is, then it changes the direction of the character. If it isn't, then it moves the
    character in the direction it was going. */
    if (next_x >= max_x || next_x < 0)
    {
      direction *= -1;
    }
    else
    {
      x += direction;
    }
  }

  /* Restoring the terminal to its original state. */
  endwin();
  return 0;
}
