import numpy as np
import picamera as picam

cam = picam.PiCamera()
cam.capture("img/capture1.png")
