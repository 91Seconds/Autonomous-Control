# Autonomous-Control
Contains code for autonomous navigation of raspberry pi based robot around a line maze and some visualisations of the raw camera data 

Most code is runs in an inifinite while loop inside the main method which is not good practice but most of this code is experimental and was a loop by nature so that was the quickest way to rapidly try new ideas

## currently abbandoned
Was for a university course that is now finished

### Future plans
one of the visualisations was a real time digital image correlation which worked reliably but was way to slow ( ran in O(n^2) with a set of 360*240) which meant 8 second refresh period, which is not ideal, reasearch suggests that performing the fast fourier transform on the raw data will allow me to filter out many unnessairy aspects of the data and dramatically reduce computation time to a workable time.  I looked into improving speed by paralellisation on gpu but the raspberry pi2 does not have great documentation on gpu programming.

Also would like to refactor the whole code to object oriented, but currently do not have the time and expertise due to the mess of libraries required to get the raspberry pi to be an anutonomous vehicle.
