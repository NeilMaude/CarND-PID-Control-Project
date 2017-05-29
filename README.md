# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## PID Process
The basic PID process is used to control the car steering.  This is done with PID controller class to return the steering value for the current car cross-track-error (CTE) value.

Calculation of the PID controller is via the following sum:

`(-1.0 * Kp * p_error) + (-1.0 * Kd * d_error) + (-1.0 * Ki * i_error)`

This is simply the sum of the individual parameters * their error value (and * -1.0).

## P/I/D Component Effects
The effect of the P (proportional) component is to set a steering value proportional to the CTE value.  This will steer the car towards the centre line, but will also tend to overshoot the centre if this is the sole component of the calculation.

The effect of the D (differential) component is to correct the tendency of the proportional component calculation to overshoot the centre line.  The D component error is the difference between the current and previous CTE values (i.e. the CTE at the previous time step).  

The effect of the I (integral) component is to correct for a drift error due to a systemic tendency for the car to drift away from the straight ahead position.  The E component error is the sum of all previous CTE values.  

## Parameter Choice
The P/D values (control gains) were selected by manual tuning, starting with values of 1.0 and using interpolation to tune to appropriate values. 

This led to values of P=0.1, D=0.9, which successfully steer the car around the circuit at the default throttle setting (throttle=0.3).

Note: the I parameter was left at I=0.0 throughout, starting with the assumption that the simulation car has no systemic drift error.  This was not tested further, as the car is navigating the circuit successfully.

## Results
A recording of the performance of the current settings (P=0.1, D=0.9) can be seen at: [https://youtu.be/8TGDRP4xk0I].

This shows a successful lap of the lakeshore circuit at throttle = 0.3.  

Note: at a couple of points (notably the sharp left turn after the bridge and the following sharp right turn at the water's edge), the car gets close to the track edge - along with the remaining oscillations, this wouldn't be the best experience for passengers!

Note also that the above video was recorded on a Windows machine using uWebSockets v14 and with OpenGL3 graphics suppport.  To meet the grading requirements, the project has been modified to use uWebSockets v13.  Unfortunately this means using Ubuntu (messing about with the dependencies on Windows is very fiddly) and my Ubuntu VM doesn't support OpenGL3 - as the Udacity simulator for term2 requires OpenGL3, I'm having to use software OpenGL.  The net effect of this is that the system runs too slowly to work at the higher throttle settings.  Hence setting throttle = 0.1 and running really slowly... 

## Next Steps
The next steps are:

..* Use Twiddle to refine the hyperparameters further
..* Add a PID controller for the throttle setting, to adjust speed (either based on distance from CTE or steering angle)

These refinements can potentially improve the quality of the ride or lapping at higher speeds.

## Compiling on Windows
The `CMakeLists.txt` file has been modified to allow compiling on a Windows platform, using Visual Studio 2017 (thanks to the Udacity Forums and Slack channel members for suggestions as to how to modify these settings).  Note that the paths hardcoded for the includes on Windows do not appear to have any effect and the IDE refuses to accept the path to uWS and dependencies as correct, but the project compiles fine...

## Ubuntu
Why does the solution run slowly on Ubuntu?  The simulator now requires OpenGL3, which is ahead of the capabilites of the VMware environment used for previous simulator projects e.g. Behavioural Cloning.  Setting up on Windows (using vcpkg) ends up with uWebSockets v14 and the grading process requires v13.  It's much each easier to get a working setup on Ubuntu, but then there is the issue of OpenGL3 support required by the latest Udacity simulator version - running software emulation, within VMWare, instead of hardware graphics in the host O/S is painfully slow (even on an i7), hence slowing down the throttle setting.

Note: launch settings for the simulator:
`LIBGL_ALWAYS_SOFTWARE=1 ./term2_sim.x86_64`

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
