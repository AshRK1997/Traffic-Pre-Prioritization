# Traffic-Pre-Prioritization
An arduino program to smartly control traffic in a junction using traffic light and also bypasses ambulance detected by RFID. It seggregates the traffic based on density upon which maximum time is assigned to that specific lane. If that lane is empty before the specific time then traffic light is turned to red.
Additionally, we have used to rfid to detect ambulance in a given lane (representing GPS in the real world), then that specific lane is set to green and others to red. (The program for detecting ambulance is written only for one lane)
