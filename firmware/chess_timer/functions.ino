void p1_timer() {   // Player 1's timer function

  if (Time_p1 == 0 and mins_p1 != 0 and p1_win == false and p2_win == false) { 
    // If player 1's seconds reach 0, but minutes are not 0 and neither player has won, decrement minutes by 1 and set seconds to 59
    mins_p1--;
    Time_p1 = 59;
  }
  else if (mins_p1 == 0 and Time_p1 == 0) {
    // If minutes and seconds both reach 0, player 1 loses
    Time_p1 = 0;
    p1_win = true;
  }
  else if (mins_p1 == 0 and Time_p1 == 0 and p1_win == true ) {
    // Display the "LOSE" text on the screen if player 1 has already won
    p1_lose();
  }
  else {
    // If there is still time left, decrement seconds to continue counting down
    Time_p1--;
    display_p1();
  }

}

void p2_timer() {  // Player 2's timer function

  if (Time_p2 == 0 and mins_p2 != 0 and p2_win == false) {
    // If player 2's seconds reach 0, but minutes are not 0 and player 2 has not won, decrement minutes by 1 and set seconds to 59
    mins_p2--;
    Time_p2 = 59;
  }
  else if (mins_p2 == 0 and Time_p2 == 0) {
    // If minutes and seconds both reach 0, player 2 loses
    Time_p2 = 0;
    p2_win = true;
  }
  else if (mins_p2 == 0 and Time_p2 == 0 and p2_win == true) {
    // Display the "LOSE" text on the screen if player 2 has already won
    p2_lose();
  }
  else {
    // If there is still time left, decrement seconds to continue counting down
    Time_p2--;
    display_p2();
  }

}

void p1_lose() {
  lc.setChar(0, 7, 'L', 0);    // Display 'L' on the screen
  lc.setChar(0, 6, 'o', 0);    // Display 'o' on the screen
  lc.setRow(0, 5, B01011011);  // Display 'S' on the screen
  lc.setRow(0, 4, B01011011);  // Display 'S' on the screen
}

void p2_lose() {
  lc.setChar(0, 3, 'L', 0);
  lc.setChar(0, 2, 'o', 0);
  lc.setRow(0, 1, B01011011);
  lc.setRow(0, 0, B01011011);
}

void display_p1() {                // Player 1's time display code
  lc.setDigit(0, 7, mins_p1, 1);
  lc.setDigit(0, 6, Time_p1 / 10 , 0);
  lc.setDigit(0, 5, Time_p1 % 10, 0);
}

void display_p2() {                // Player 2's time display code
  lc.setDigit(0, 2, mins_p2, 1);
  lc.setDigit(0, 1, Time_p2 / 10 , 0);
  lc.setDigit(0, 0, Time_p2 % 10, 0);
}

void p1_play() {
  Timer1.attachInterrupt(p1_timer);   // Attach player 1's timer function
}

void p2_play() {
  Timer1.attachInterrupt(p2_timer);   // Attach player 2's timer function
}
