# LFR-BASIC-ALGORITHM
This code reads digital inputs from 5 IR sensors, then converts the BCD (binary coded decimal) to INT and follow cases by switch statement based on Bang-Bang approach to follow a line. The code also remembers left or right turns made by the robot to avoid overshooting i.e deviation of the bot from the line by counter-balancing the last turn made.

#Added auto-calibration feature.
The robot automatically detects whether arena is of type of black line on white background or white line on black background. To auto calibrate, place bot on the set point i.e center of the line, with middle sensor on it, wait for 5 seconds for calibration to be completed, which will be indicated by a LED glow. The code will take 5 readings at an interval of 1 second to detect the arena type so no re-programming of the bot is required again and again, which is a time-saving feature. After that switch on the Vss motor supply to run the bot.

# CONTRIBUTERS
* Sukhvinder Singh
