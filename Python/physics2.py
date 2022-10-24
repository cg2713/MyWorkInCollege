import math
#import cmath

def tworamp(x,m,f,n,s):
  Fgrav = m * 10
  Fgrav2 = n * 10
  print ('Force of gravity is: ',Fgrav)
  Framp = math.sin(math.radians(x)) * Fgrav
  print ('Downhill force is: ',Framp)
  Fn = math.cos(math.radians(x)) * Fgrav
  print ('Normal Force is: ',Fn)
  sfric = Fn * s
  kfric = Fn * f
  totalm = n + m
  lostkf = Fgrav2 - Framp - kfric
  accel = (lostkf)/totalm
  if (accel > 0):
    print ('Acceleration is: ,',accel)
    print("The system is pulled by object 2",)
  if (accel < 0):
    accelup = (Framp - kfric - Fgrav2)/totalm
    print ('Acceleration is: ,', accelup)

def oneramp(a,b,c):
  Fgrav = b * 10
  print ('Force gravity is: ',Fgrav)
  Framp = math.sin(math.radians(a)) * Fgrav
  print ('Force of Ramp is: ',Framp)
  Fn = math.cos(math.radians(a)) * Fgrav
  print ('Normal Force is: ',Fn)
  fric = Fn * c
  accel = (Framp - fric)/b
  print ('Acceleration is: ',accel)

#Selection of an operation   
print ('Selection')
print ('1. One body ramp system')
print ('2. Two body ramp system')
#MAKE YOUR CHOOOICCCEEEEE
choice = input("Enter choice: ")

if choice == '2':
  print ('Object 1 is the object sitting on the ramp. ')
  print ('Object 2 is the object hanging off the ramp. ')
  m = float(input('Mass of first object is: '))
  n = float(input('Mass of second object: '))
  x = float(input('Write angle of ramp: '))
  f = float(input('Coefficient of kinetic friction: '))
  s = float(input('Coefficient of static friction:'))
  tworamp(x,m,f,n,s)
if choice == '1':
  a = float(input('Write angle of ramp: '))
  b = float(input('Write mass of object: '))
  c = float(input('Coefficient of kinetic friction: '))
  oneramp(a,b,c)
