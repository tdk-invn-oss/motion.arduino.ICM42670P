# Requirements

- Arduino IDE
- Ubuntu 22.4 or WSL 1 

# Windows Subsystem for Linux (WSL) 1 
* WSL is a feature of Windows that allows to run a Linux environment on your Windows machine

wsl --install 
* Then reboot your PC
wsl --status 
* To check which version is installed, default is version 2

* Install WSL version 1 to have easy access to COM port: COMx => ttySx
wsl --set-version Ubuntu 1
wsl --set-default-version 1

# Verify the COM port is well connected

* First open a terminal on Windows side using Teraterm or Putty and verify the data outputted properly
* Then on Linux window :
* Install minicom
sudo apt install minicom
* Configure Serial port setup and Save as dfl
minicom -s 
* Listen the COM port
minicom
* To quit: ctrl-A then q

# ROS2 setup through WSL

Install ROS2 following official documentation for Ubuntu: https://docs.ros.org/en/iron/Installation/Ubuntu-Install-Debians.html
Test talker/listener examples

# MicroROS setup through WSL

* Create a workspace and download the micro-ROS tools:
cd
mkdir microros_ws
cd microros_ws

* Cloning microROS src file from github
git clone -b $ROS_DISTRO https://github.com/micro-ROS/micro_ros_setup.git src/micro_ros_setup

* Installing rosdep
sudo apt install python3-rosdep2

* Update dependencies using rosdep
sudo apt update && rosdep update
rosdep install --from-paths src --ignore-src -y

* Install pip
sudo apt-get install python3-pip

* Build micro-ROS tools and source them
sudo apt install python3-colcon-common-extensions
colcon build
source install/local_setup.bash

* To install the micro-ros Agent follow the steps below
ros2 run micro_ros_setup create_agent_ws.sh

* Build the agent packages
ros2 run micro_ros_setup build_agent.sh

* For using micro-ROS commands you need to run the command :
source ~/microros_ws/install/local_setup.bash

* Display ROS environment variables 
printenv | grep -i ROS

* Set ROS_DOMAIN_ID
export ROS_DOMAIN_ID=0
echo "export ROS_DOMAIN_ID=0" >> ~/.bashrc

# Arduino setup

Open MicroROS Arduino example
Download micro_ros_arduino 2.0.7-iron library: https://github.com/micro-ROS/micro_ros_arduino/releases
Include it in your project using Sketch -> Include library -> Add .ZIP Library
Build and verify
You can test MicroROS examples located in this repo in examples folder.

# Increase the serial interface speed on MicroROS serial protocol (Mandatory)

Default serial interface baudrate is 115200 baud/s

Open in micro_ros_arduino library: Arduino\libraries\micro_ros_arduino-2.0.7-iron\src\default_transport.cpp

Update the baudrate parameter in `c Serial.begin()` API. For example to 1Mbaud/s.
```c
  bool arduino_transport_open(struct uxrCustomTransport * transport)
  {
    Serial.begin(1000000);
    return true;
  }
```
Rebuild and flash MicroROS Arduino example

# Run Micro-ROS Agent through WSL

* Open a Linux window to connect to the ROS agent, and another one to receive message published.
* For using micro-ROS commands you need to run on both windows:
source /opt/ros/iron/setup.bash
source ~/microros_ws/install/local_setup.bash

* Window 1
* Run the Agent program 
ros2 run micro_ros_agent micro_ros_agent serial -b 1000000 --dev /dev/tty<COM port number>
* Verbose option: -v6

* Restart the Arduino board

* Window 2
* List the topic registered
ros2 topic list
* Listen from the topic (might need to be repeated in some case)
ros2 topic echo /IMU_publisher
