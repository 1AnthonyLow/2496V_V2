#include "chassis.h"
#include "robot.h"

void test() {
  lf.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  lm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  lb.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  rf.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  rm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  rb.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  moveTo(1700, 4000);
}

void noAuton() {}

void rightsideQual() {
  intake.move(-127);
  pros::delay(200);
  intake.move(127);
  side_hang.set_value(true);
  pros::delay(150);
  moveTest(800, 500);
  absTurn(-60, 600);
  side_hang.set_value(false);
  pros::delay(200);
  // horiz_wings.set_value(true);
  // pros::delay(500);
  // horiz_wings.set_value(false);
  // pros::delay(250);
  absTurn(-25, 400);
  pros::delay(100);
  intake.move(-127);
  moveTest(1200, 700);
  moveTest(-1000, 500);
  absTurn(-90, 700);
  intake.move(127);
  moveTest(3100, 1200);
  absTurn(45, 700);
  horiz_wings.set_value(true);
  pros::delay(150);
  intake.move(-127);
  moveTest(2000, 1000);
  moveTest(-300, 300);
  horiz_wings.set_value(false);
  intake.move(0);
  absTurn(-170, 1000);
  intake.move(127);
  moveTest(1500, 1000);
  pros::delay(100);
  intake.move(0);
  absTurn(30, 600);
  moveTest(1000, 1000);
  absTurn(45, 600);
  intake.move(-127);
  moveTest(1200, 800);
  moveTest(-600, 300);
  intake.move(0);
}

void leftsideQual() {

  intake.move(-127);
  horiz_wings.set_value(true);
  pros::delay(400);
  horiz_wings.set_value(false);
  intake.move(0);

  moveTest(2400, 1200);
  absTurn(90, 600);
  horiz_wings.set_value(true);
  intake.move(-127);
  pros::delay(200);
  moveTest(1500, 900);
  horiz_wings.set_value(false);

  moveTest(-1300, 900);
  absTurn(-180, 800);
  moveTest(1000, 600);
  absTurn(-135, 800);
  moveTest(1250, 900);
  absTurn(-210, 800);
  side_hang.set_value(true);
  moveTest(500, 400);
  absTurn(-270, 800);

  moveTest(2000, 1200);

  // absTurn(-225, 800);
  //  moveTest(500,400);
  //  absTurn(90, 800);
  // side_hang.set_value(true);
  // absTurn(90, 800);

  // intake.move(-127);
  // side_hang.set_value(true);
  // pros::delay(150);
  // absTurn(-50, 600);
  // side_hang.set_value(false);
  //   intake.move(-127);
  //   pros::delay(200);
  //   intake.move(127);
  //   pros::delay(300);
  //   intake.move(0);
  //   absTurn(-45, 500);
  //   side_hang.set_value(true);
  //   absTurn(-110, 400);
  //   pros::delay(200);
  //   absTurn(-45, 500);
  //   pros::delay(200);
  //   side_hang.set_value(false);
  //   pros::delay(200);
  //   absTurn(90, 500);
  //   intake.move(-127);
  //   moveTest(300, 300);
  //   pros::delay(200);
  //   intake.move(0);
  //   absTurn(-168, 700);
  //   intake.move(127);
  //   moveTest(2600, 1200);
  //   pros::delay(150);
  //   moveTest(-2800, 1500);
  //   absTurn(-90, 500);
  //   intake.move(-127);
  //   moveTest(1750, 900);

  // intake.move(-127);
  // pros::delay(200);
  // intake.move(127);
  // //side_hang.set_value(true);
  // absTurn(-60, 500);
  // intake.move(0);
  // //zzside_hang.set_value(false);
  // absTurn(-20, 500);
  // pros::delay(200);
  // intake.move(-127);
  // moveTest(2000, 1000);
  // intake.move(0);
  // pros::delay(200);
  // moveTest(-500, 500);
  // absTurn(-45, 500);
  // moveTest(-1350, 1000);
  // absTurn(90, 900);
  // intake.move(-127);
  // moveTest(1300, 1000);
}

void rightSideElims() {
  intake.move(-127);
  pros::delay(100);
  intake.move(127);
  moveTest(1500, 1000);
  pros::delay(400);
  intake.move(0);
  moveTest(-1600, 1000);
  absTurn(-45, 750);
  side_hang.set_value(true);
  moveTest(-1200, 800);
  side_hang.set_value(false);
  pros::delay(200);
  moveTest(-300, 500);
  absTurn(-90, 500);
  moveTest(-800, 800);
  pros::delay(200);
  moveTest(500, 800);
  pros::delay(300);
  absTurn(90, 800);
  intake.move(-127);
  // pros::delay(300);
  moveTest(1000, 800);
  // pros::delay(200);
  moveTest(-1000, 700);
  absTurn(10, 400);
  intake.move(127);
  moveTest(2800, 1200);
  intake.move(0);
  absTurn(135, 800);
  intake.move(-127);
  pros::delay(200);
  intake.move(0);
  absTurn(70, 700);
  intake.move(127);
  moveTest(1200, 800);
  intake.move(0);
  absTurn(180, 1000);
  intake.move(-127);
  horiz_wings.set_value(true);
  moveTest(3200, 1200);
  pros::delay(200);
  absTurn(0, 400);
}

void leftsideElims() {
  intake.move(-127);
  moveTest(2000, 1000);
  intake.move(127);
  moveTest(400, 300);
  moveTest(-200, 200);
  absTurn(82, 800);
  horiz_wings.set_value(true);
  moveTest(1000, 800);
  moveTest(-200, 200);
  horiz_wings.set_value(false);
  absTurn(-160, 800);
  moveTest(2500,1200);


  // moveTest(2700, 1200);
  // intake.move(0);
  // absTurn(-90, 800);
  // side_hang.set_value(true);
  // moveTest(-2500, 1000);
  // intake.move(-127);
  // moveTest(1600, 1200);
  // side_hang.set_value(false);
  // intake.move(0);
  // pros::delay(200);
  // moveTest(-200, 400);
  // absTurn(-180, 700);
}

void skills() {
  intake.move(-127);
  pros::delay(150);
  intake.move(127);
  absTurn(-30, 800);

  //arcTurnLeft(-500, 35, 1000);
  intake.move(0);
  //side_hang.set_value(true);

  slapper.move(127);
  pros::delay(10000);

  slapper.move(0);
  side_hang.set_value(false);

  moveTest(300, 300);
  absTurn(45, 800);
  moveTest(575, 400);
  absTurn(-5, 1000);
  moveTest(3700, 2000);
  intake.move(-127);
  side_hang.set_value(true);
  absTurn(-45, 800);
  moveTest(1500, 600);
  absTurn(-90, 800);
  side_hang.set_value(false);
  moveTest(1200, 600);
  pros::delay(150);

  moveTest(-700, 300);
  pros::delay(150);
  absTurn(-80, 800);
  moveTest(1200, 800);

  moveTest(-600, 400);
  intake.move(0);

  absTurn(-185, 900);
  moveTest(1400, 800);
  absTurn(-135, 800);
  horiz_wings.set_value(true);
  pros::delay(400);
  horiz_wings.set_value(false);
  absTurn(-180, 800);
  moveTest(600, 400);
  horiz_wings.set_value(true);
  pros::delay(150);
  absTurn(-84, 800);

  moveTest(800, 400);
  horiz_wings.set_value(false);
  absTurn(-187, 900);
  moveTest(-1700, 1000);
  pros::delay(150);
  moveTest(1500, 1000);

  absTurn(-90, 800);
  moveTest(700, 500);
  absTurn(7, 800);
  horiz_wings.set_value(true);
  intake.move(-127);
  pros::delay(150);

  moveTest(1700, 1000);
  pros::delay(150);
  horiz_wings.set_value(false);
  moveTest(-1700, 1200);
  intake.move(0);

  absTurn(-94, 800);
  moveTest(1300, 800);
  absTurn(30, 800);
  horiz_wings.set_value(true);
  intake.move(-127);
  moveTest(1700, 800);




  // arcTurnLeft(1200, 90, 1700);
  // absTurn(-90, 400);

  // moveTest(1200, 600);
  // moveTest(-300, 300);

  // intake.move(0);
  // absTurn(-180, 800);
  // moveTest(2300, 1000);

  // absTurn(-90, 800);
  // moveTest(800, 600);
  // absTurn(-180, 800);
  // moveTest(-1500, 800);
  // pros::delay(100);
  // moveTest(1500, 800);
  // absTurn(-90, 800);
  // pros::delay(100);
  // moveTest(1000, 800);
  // absTurn(-180, 800);
  // moveTest(-1500, 800);

  // pros::delay(150);
  // moveTest(1500, 800);

  // move(-60, -5);
  // pros::delay(300);
  // move(0, 0);
  // side_hang.set_value(true);
  // // slapper.move(127);
  // // pros::delay(35000);
  // // slapper.move(0);
  // side_hang.set_value(false);
  // pros::delay(200);

  // moveTest(200, 400);
  // absTurn(45, 400);
  // moveTest(700, 400);
  // absTurn(0, 800);
  // moveTest(4000, 1900);

  // absTurn(-90, 800);
  // moveTest(1000, 500);
  // absTurn(-180, 800);
  // moveTest(1000, 500);

  // absTurn(-90, 800);
  // moveTest(1500, 900);
  // absTurn(0, 800);
  // intake.move(-127);
  // horiz_wings.set_value(true);
  // pros::delay(200);
  // moveTest(1500, 900);

  // moveTest(-1500, 900);
  // horiz_wings.set_value(false);
  // intake.move(0);
  // pros::delay(200);
  // absTurn(-90, 800);

  // moveTest(1000, 500);
  // absTurn(0, 800);
  // intake.move(-127);
  // horiz_wings.set_value(true);

  // moveTest(1500, 900);
  // moveTest(-1500, 900);

  // arcTurn(70, 110, 2000);
  // moveTest(-800, 400);
  // moveTest(1000, 400);

  // moveTest(-500, 400);
  // horiz_wings.set_value(false);
  // pros::delay(200);
  // absTurn(-180, 800);
  // intake.move(0);
  // moveTest(2400, 1000);

  // absTurn(-90, 800);
  // moveTest(1000, 800);
  // absTurn(0, 400);

  // intake.move(-127);
  // horiz_wings.set_value(true);
  // pros::delay(200);
  // moveTest(1500, 850);

  // intake.move(0);
  // moveTest(-1500, 850);
  // horiz_wings.set_value(false);
  // absTurn(-90, 800);

  // moveTest(1000, 800);
  // absTurn(0, 800);
  // horiz_wings.set_value(true);
  // intake.move(-127);
  // pros::delay(200);
  // moveTest(1500, 800);
}
//     move(-55, -5);
//     pros::delay(300);
//     move(0,0);
//     slapper.move(127);
// 	pros::delay(27000);
// 	slapper.move(0);
//     moveTest(500, 250);
// 	absTurn(45, 400);
// 	moveTest(900, 400);
// 	absTurn(0, 450);
// 	moveTest(3000, 1200);
// 	absTurn(-40, 400);
// 	horiz_wings.set_value(true);
// 	moveTest(1500, 1000);
// 	intake.move(-127);
// 	horiz_wings.set_value(false);
// 	moveTest(400, 200);
// 	absTurn(-90, 600);
// 	moveTest(1200,700);

// 	moveTest(-500, 300);
// 	absTurn(-180, 600);
// 	moveTest(2500, 1200);
// 	absTurn(-90, 600);
// 	moveTest(1000, 500);
// 	absTurn(-180, 600);
// 	side_hang.set_value(true);
// 	moveTest(-1500, 900);
// 	side_hang.set_value(false);
// 	moveTest(1500, 900);
// 	absTurn(-90, 700);
// 	moveTest(1000, 800);
// 	absTurn(-180, 800);
// 	side_hang.set_value(true);
// 	moveTest(-1500, 800);

void safeLeft() {
  intake.move(-127);
  pros::delay(150);
  intake.move(127);
  side_hang.set_value(true);
  pros::delay(150);
  intake.move(0);
  absTurn(-75, 800);
  side_hang.set_value(false);
  pros::delay(250);
  absTurn(0, 800);
  moveTest(450, 300);
  absTurn(-47, 800);
  intake.move(-127);
  moveTest(1550, 1200);
}