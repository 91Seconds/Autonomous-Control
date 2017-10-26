import numpy as np

import picamera



camera = picamera.Picamera()
camera.resolution = (320,240)
output = np.empty((240,320,3), dtype=np.uint8)
camera.capture(output, 'rgb')
