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

void rightsideQual(){
	intake.move(-127);
	pros::delay(100);
	intake.move(127);
	moveTest(1500, 1000);
	pros::delay(400);
	intake.move(0);
	moveTest(-1700, 1000);
	absTurn(-45, 750);
	vert_wings.set_value(true);
	moveTest(-1200, 800);
	vert_wings.set_value(false);
	moveTest(-100, 500);
	absTurn(-90, 500);
	moveTest(-800, 800);
	pros::delay(200);
	moveTest(500, 800);
	pros::delay(300);
	absTurn(90, 1000);
	intake.move(-127);
	pros::delay(300);
	moveTest(1000, 800);
	pros::delay(200);
	moveTest(-300, 500);
	absTurn(-45, 750);
	moveTest(1600, 1000);
	absTurn(0, 500);
	moveTest(1300, 750);

}

void leftsideQual(){
	// intake.move(-127);
	pros::delay(200);
	intake.move(127);
	vert_wings.set_value(true);
	absTurn(-45, 500);
	intake.move(0);
	absTurn(-20, 500);
	pros::delay(200);
	intake.move(-127);
	moveTest(2000, 1000);
	intake.move(0);
	pros::delay(200);
	moveTest(-500, 500);
	absTurn(-45, 500);
	moveTest(-1350, 1000);
	absTurn(90, 900);
	moveTest(1500, 1000);
}

void rightSideElims(){
	intake.move(-127);
	pros::delay(100);
	intake.move(127);
	moveTest(1500, 1000);
	pros::delay(400);
	intake.move(0);
	moveTest(-1700, 1000);
	absTurn(-45, 750);
	vert_wings.set_value(true);
	moveTest(-1200, 800);
	vert_wings.set_value(false);
	moveTest(-100, 500);
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
	// pros::delay(200);
	intake.move(0);
	absTurn(80, 700);
	intake.move(127);
	moveTest(1000, 800);
	intake.move(0);
	absTurn(180, 1000);
	moveTest(3000, 1200);
}