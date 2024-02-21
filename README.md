# solution
Solution for monitoring devices using unique names.

# How should the data shared by the Devices should be:
Data = System ID + Device Unique Name + size of the measurement characters + measurement.

### Example
### In this solution, there are 3 devices(A, B, C) to be monitored for the system(#).
Follow the data,
Enter #A31.2
The system would read the next 3 characters from index 2 and store measurements in double format under device A by incrementing the times of data entered for device A.

# Monitoring System 
The system should check if the shared string data sent by the devices belongs to it by checking the first character(can be many characters), 
then check if the string is constructed according to the data. The third character should mention the following size of the measurement in characters. 
The system after checking if the data is valid, then reads the respective character converts it to the respective data type, and stores the frequency of measurement acquired for individual devices. 
Updates the output accordingly if the variables are changed.


# How to use code?
1. Clone the repo to the working directory.
2. Run solution.cpp, enter the string referring to the example, and observe the change in the output.
