

import matplotlib.pyplot as plt
import numpy as np


# draw sine and cosine functions
X = np.linspace(-np.pi, np.pi, 256, endpoint=True)
C = np.cos(X)
S = np.sin(X)

# create a new figure of size 8x6 points, using 100 dots per inch
plt.figure(figsize=(8, 5), dpi=80)

# create a new subplot from a grid of 1x1
ax = plt.subplot(111)

# moving spines to the middle
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.spines['bottom'].set_position(('data', 0))
ax.yaxis.set_ticks_position('left')
ax.spines['left'].set_position(('data', 0))

# plot cosine using blue color with a continuous line of width 2.5 (pixels)
plt.plot(X, C, color="blue", linewidth=2.5, linestyle="-", label="cosine")

# plot sine using red color with a continuous line of width 2.5 (pixels)
plt.plot(X, S, color="red", linewidth=2.5, linestyle="-",  label="sine")

# set limits and ticks for x
plt.xlim(X.min() * 1.1, X.max() * 1.1)
plt.xticks([-np.pi, -np.pi/2, 0, np.pi/2, np.pi],
           [r'$-\pi$', r'$-\pi/2$', r'$0$', r'$+\pi/2$', r'$+\pi$'])

# set limits and ticks for y
plt.ylim(C.min() * 1.1, C.max() * 1.1)
plt.yticks([-1, +1], [r'$-1$', r'$+1$'])

# add legend
plt.legend(loc='upper left', frameon=False)

# annotate interesting points
t = 2*np.pi/3
plt.plot([t, t], [0, np.cos(t)], color='blue', linewidth=1.5, linestyle="--")
plt.scatter([t, ], [np.cos(t), ], 50, color='blue')
plt.annotate(r'$\sin(\frac{2\pi}{3})=\frac{\sqrt{3}}{2}$',
             xy=(t, np.sin(t)),  xycoords='data',
             xytext=(+10, +30), textcoords='offset points', fontsize=16,
             arrowprops=dict(arrowstyle="->", connectionstyle="arc3, rad=.2"))
plt.plot([t, t], [0, np.sin(t)], color='red',  linewidth=1.5, linestyle="--")
plt.scatter([t, ], [np.sin(t), ], 50, color='red')
plt.annotate(r'$\cos(\frac{2\pi}{3})=-\frac{1}{2}$',
             xy=(t, np.cos(t)), xycoords='data',
             xytext=(-90, -50), textcoords='offset points', fontsize=16,
             arrowprops=dict(arrowstyle="->", connectionstyle="arc3, rad=.2"))

# enhance label visibility
for label in ax.get_xticklabels() + ax.get_yticklabels():
    label.set_fontsize(16)
    label.set_bbox(dict(facecolor='white', edgecolor='None', alpha=0.65))

plt.show()
