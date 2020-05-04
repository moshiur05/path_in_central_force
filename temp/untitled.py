from numpy import array, append, sort
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np
import math

plt.style.use('dark_background')

fig = plt.figure()
ax = plt.axes(xlim=(-2, 2), ylim=(-2, 2))
line, = ax.plot([], [], lw=2)

# initialization function
def init():
	# creating an empty plot/frame
	line.set_data([], [])
	return line,

# lists to store x and y axis points
xdata, ydata = [], []

x = array([])
y = array([])
f = open("data/1", "r")
f1 = f.readlines()
m = math.ceil(len(f1)/500);
for i in range(0, len(f1), m) :
    x = append(x, float(f1[i]))
    y = append(y, float(f1[i + 1]))

# animation function
def animate(i):
    xdata.append(x[i])
    ydata.append(y[i])
    line.set_data(xdata, ydata)
    return line,

# setting a title for the plot
plt.title('path in g force')
# hiding the axis details
plt.axis('off')

# call the animator
anim = animation.FuncAnimation(fig, animate, init_func=init, frames=500, interval=20, blit=True)

# save the animation as mp4 video file
anim.save('path_.gif',writer='imagemagick')
