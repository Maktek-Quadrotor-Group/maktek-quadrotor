static float yaw_p = 0;
static float yaw_i = 0;
static float yaw_d = 0;

static float roll_p = 2;
static float roll_i = 0;
static float roll_d = 0;

static float pitch_p = 0;
static float pitch_i = 0;
static float pitch_d = 0;

static float baro_p = 0;
static float baro_i = 0;
static float baro_d = 0;

static float ref_roll = 180.0;
static float ref_pitch = 180.0;

// Error 0 -> Roll error
// Error 1 -> Pitch error
float error[2];
float old_error[2];
float dError[2];

void findError() {
  error[0] = kalman_angle_x - ref_roll;
  error[1] = kalman_angle_y - ref_pitch;
  
  dError[0] = error[0] - old_error[0];
  dError[1] = error[1] - old_error[1];
  
  old_error[0] = error[0];
  old_error[1] = error[1];
}

void calculatePid() {
  output[0] = roll_p * error[0] + roll_d * dError[0] / dt;
  output[1] = pitch_p * error[1] + pitch_d * dError[1] / dt;
}
