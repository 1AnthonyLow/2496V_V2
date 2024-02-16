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
	intake.move(-127);
	pros::delay(200);
	intake.move(127);
	//side_hang.set_value(true);
	absTurn(-60, 500);
	intake.move(0);
	//zzside_hang.set_value(false);
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
	intake.move(-127);
	moveTest(1300, 1000);
}

void rightSideElims(){
	intake.move(-127);
	pros::delay(100);
	intake.move(127);
	moveTest(1500, 1000);
	pros::delay(400);
	intake.move(0);
	moveTest(-1600, 1000);
	absTurn(-45, 750);
	vert_wings.set_value(true);
	moveTest(-1200, 800);
	vert_wings.set_value(false);
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

void leftsideElims(){
	intake.move(-127);
	pros::delay(200);
	intake.move(127);
	moveTest(2700, 1200);
	intake.move(0);
	absTurn(-90, 800);
	vert_wings.set_value(true);
	moveTest(-2500, 1000);
	intake.move(-127);
	moveTest(1600, 1200);
	vert_wings.set_value(false);
	intake.move(0);
	pros::delay(200);
	moveTest(-200, 400);
	absTurn(-180,700);
}

void skills(){
    move(-55, -5);
    pros::delay(300);
    move(0,0);
    slapper.move(127);
	pros::delay(27000);
	slapper.move(0);
    moveTest(500, 250);
	absTurn(45, 400);
	moveTest(900, 400);
	absTurn(0, 450);
	moveTest(3000, 1200);
	absTurn(-40, 400);
	horiz_wings.set_value(true);
	moveTest(1500, 1000);
	intake.move(-127);
	horiz_wings.set_value(false);
	moveTest(400, 200);
	absTurn(-90, 600);
	moveTest(1200,700);
	
	moveTest(-500, 300);
	absTurn(-180, 600);
	moveTest(2500, 1200);
	absTurn(-90, 600);
	moveTest(1000, 500);
	absTurn(-180, 600);
	vert_wings.set_value(true);
	moveTest(-1500, 900);
	vert_wings.set_value(false);
	moveTest(1500, 900);
	absTurn(-90, 700);
	moveTest(1000, 800);
	absTurn(-180, 800);
	vert_wings.set_value(true);
	moveTest(-1500, 800);
}