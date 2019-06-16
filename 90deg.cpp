#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "E101.h"

class Robot{
	private:
	int v_left, v_right, cam_tilt;
    int dv;
    double line_error =0;
    int quadrant = 3;
    const int cam_width = 320;
    const int cam_height = 240;
    const int v_left_go = 52;
    const int v_right_go = 44;
    double kp = 0.0003;
    double kd = 0.0007;
    double err;
    int line_present = 1;
    int prev_error;
    int turnLeftBool = 0;
    int turnRightBool = 0;
    int reverseBool = 0;
    int deadEndBool = 0;
    public:
    //Rob(){};
	int InitHardware();
	int reverse();
	int SetMotors();
	int MeasureLine();
	int FollowLine();
	void openGate();
	void turnRight();
	void turnLeft();
	void fullTurn();
		
};
int Robot::InitHardware(){
	init(0);
	open_screen_stream();
	take_picture();
	update_screen();
	v_left = v_left_go;
	v_right = v_right_go;
	SetMotors();
	hardware_exchange();
	
	return 0;
}
int Robot::SetMotors(){
	
	 set_motors(3, v_left);
	 set_motors(5, v_right);
	 printf("\nSet Motors: v_left: %d v_right: %d",v_left,v_right);
	 hardware_exchange();
	 return 0; 

}

int main(){
Robot robot;
	robot.InitHardware();
	//robot.turnLeft();
	//robot.turnRight();
	
		
	close_screen_stream();
		stoph();
		return 0;	
}
