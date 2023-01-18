import RPi.GPIO as GPIO
import sys
import time

GPIO.setmode(GPIO.BCM) 

GPIO.setup(1, GPIO.OUT) 
GPIO.setup(2, GPIO.OUT) 
GPIO.setup(3, GPIO.OUT) 
GPIO.setup(4, GPIO.OUT) 
GPIO.setup(5, GPIO.OUT) 
GPIO.setup(6, GPIO.OUT) 
GPIO.setup(7, GPIO.OUT) 
GPIO.setup(8, GPIO.OUT) 
GPIO.setup(9, GPIO.OUT) 
GPIO.setup(10, GPIO.OUT) 
GPIO.setup(11, GPIO.OUT) 
GPIO.setup(12, GPIO.OUT) 
GPIO.setup(13, GPIO.OUT) 
GPIO.setup(14, GPIO.OUT) 
GPIO.setup(15, GPIO.OUT) 
GPIO.setup(16, GPIO.OUT) 

# clear_led()
# down pin 21 
# up pin 20 

GPIO.setup(26, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(19, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while(True): 
    input_state = GPIO.input(26)
    print(input_state)
    if input_state == 0: 
        print("button pressed") 
    time.sleep(0.5) 

# GPIO.output(1, False) #row 1
# GPIO.output(2, False) #row 2  
# GPIO.output(3, False) #row 3  
# GPIO.output(4, False) #row 4 
# GPIO.output(5, False) #col 1  
# GPIO.output(6, False) #col 2 
# GPIO.output(7, False) #col 3 
# GPIO.output(8, False) #col 4 
# GPIO.output(9, False) #row 8 
# GPIO.output(10, False) #row 7 
# GPIO.output(11, False) #row 6
# GPIO.output(12, False) #row 5 
# GPIO.output(13, False) #col 5 
# GPIO.output(14, False) #col 6 
# GPIO.output(15, False) #col 7 
# GPIO.output(16, False) #col 8 




# GPIO.output(1, False) #row 1
# GPIO.output(2, False) #row 2  
# GPIO.output(3, False) #row 3  
# GPIO.output(4, False) #row 4 
# GPIO.output(5, False) #col 1  
# GPIO.output(6, False) #col 2 
# GPIO.output(7, False) #col 3 
# GPIO.output(8, False) #col 4 
# GPIO.output(9, False) #row 8 
# GPIO.output(10, False) #row 7 
# GPIO.output(11, False) #row 6
# GPIO.output(12, False) #row 5 
# GPIO.output(13, False) #col 5 
# GPIO.output(14, False) #col 6 
# GPIO.output(15, False) #col 7 
# GPIO.output(16, False) #col 8 


def clear_led():
    GPIO.output(1, False) #row 1
    GPIO.output(2, False) #row 2  
    GPIO.output(3, False) #row 3  
    GPIO.output(4, False) #row 4 
    GPIO.output(5, False) #col 1  
    GPIO.output(6, False) #col 2 
    GPIO.output(7, False) #col 3 
    GPIO.output(8, False) #col 4 
    GPIO.output(9, False) #row 8 
    GPIO.output(10, False) #row 7 
    GPIO.output(11, False) #row 6
    GPIO.output(12, False) #row 5 
    GPIO.output(13, False) #col 5 
    GPIO.output(14, False) #col 6 
    GPIO.output(15, False) #col 7 
    GPIO.output(16, False) #col 8 

def turn_all_on(): 
    GPIO.output(1, False)  #row 1
    GPIO.output(2, False)  #row 2  
    GPIO.output(3, False) #row 3  
    GPIO.output(4, False)  #row 4 
    GPIO.output(5, True) #col 1  
    GPIO.output(6, True) #col 2 
    GPIO.output(7, True)  #col 3 
    GPIO.output(8, True) #col 4 
    GPIO.output(9, False) #row 8 
    GPIO.output(10,False) #row 7 
    GPIO.output(11,False) #row 6
    GPIO.output(12,False) #row 5 
    GPIO.output(13,True) #col 5 
    GPIO.output(14,True) #col 6 
    GPIO.output(15,True) #col 7 
    GPIO.output(16,True) #col 8 


# ROW1 = 1 # row 1 
# ROW2 = 2 #row 2  
# ROW3 =3 #row 3  
# ROW4 =4 #row 4 
# COL1 =5 #col 1  
# COL2 =6 #col 2 
# COL3 =7 #col 3 
# COL4 =8 #col 4 
# ROW8 =9 #row 8 
# ROW7 =10 #row 7 
# ROW6 =11 #row 6
# ROW5 =12 #row 5 
# COL5 =13 #col 5 
# COL6 =14 #col 6 
# COL7 =15 #col 7 
# COL8 =16 #col 8 

# COL1 = 1 # row 1 
# COL2 = 2 #row 2  
# COL3 =3 #row 3  
# ROW4 =4 #row 4 
# COL1 =5 #col 1  
# COL2 =6 #col 2 
# COL3 =7 #col 3 
# COL4 =8 #col 4 
# ROW8 =9 #row 8 
# ROW7 =10 #row 7 
# ROW6 =11 #row 6
# ROW5 =12 #row 5 
# COL5 =13 #col 5 
# COL6 =14 #col 6 
# COL7 =15 #col 7 
# COL8 =16 #col 8 
#COl and ROW switched
COL1 = 1   
COL2 = 2   
COL3 =3 
COL4 =4 
ROW1 =5 
ROW2 =6 
ROW3 =7 
ROW4 =8 
COL8 =9 
COL7 =10  
COL6 =11 
COL5 =12  
ROW5 =13  
ROW6 =14  
ROW7 =15  
ROW8 =16  

cols = [1, 2, 3, 4, 12, 11, 10, 9] 
rows = [5, 6, 7, 8, 16, 15, 14, 13]

# smile = [
#     0, 0, 0, 0, 0, 0, 0, 0, 
#     0, 0, 0, 0, 0, 0, 0, 0, 
#     0, 0, 0, 0, 0, 0, 0, 0, 
#     0, 0, 0, 0, 0, 0, 0, 0, 
#     0, 0, 0, 0, 0, 0, 0, 0, 
#     0, 0, 0, 0, 0, 0, 0, 0, 
#     0, 0, 0, 0, 0, 0, 0, 0, 
#     0, 0, 0, 0, 0, 0, 0, 0, 
# ]

down = [
    [0, 0, 0, 1, 1, 0, 0, 0], 
    [0, 0, 0, 1, 1, 0, 0, 0], 
    [0, 0, 0, 1, 1, 0, 0, 0], 
    [0, 0, 0, 1, 1, 0, 0, 0], 
    [1, 0, 0, 1, 1, 0, 0, 1], 
    [0, 1, 0, 1, 1, 0, 1, 0], 
    [0, 0, 1, 0, 0, 1, 0, 0], 
    [0, 0, 0, 1, 1, 0, 0, 0], 
]
up = [
    [0, 0, 0, 1, 1, 0, 0, 0], 
    [0, 0, 1, 1, 1, 1, 0, 0], 
    [0, 1, 0, 1, 1, 0, 1, 0], 
    [1, 0, 0, 1, 1, 0, 0, 1], 
    [0, 0, 0, 1, 1, 0, 0, 0], 
    [0, 0, 0, 1, 1, 0, 0, 0], 
    [0, 0, 0, 1, 1, 0, 0, 0], 
    [0, 0, 0, 1, 1, 0, 0, 0], 
]
# smile = [
#     [0, 0, 1, 1, 1, 1, 0, 0], 
#     [0, 1, 0, 0, 0, 0, 1, 0], 
#     [1, 0, 1, 0, 0, 1, 0, 1], 
#     [1, 0, 0, 0, 0, 0, 0, 1], 
#     [1, 0, 1, 0, 0, 0, 1, 1], 
#     [1, 0, 0, 1, 1, 1, 0, 1], 
#     [0, 1, 0, 0, 0, 0, 1, 0], 
#     [0, 0, 1, 1, 1, 1, 0, 0], 
# ]
def draw_face(matrix): 
    while(1): 
        for row in range(8): 
            GPIO.output(rows[row], True)
            for col in range(8): 
                if matrix[row][col] == 1: 
                    GPIO.output(cols[col], False)
                else: 
                    GPIO.output(cols[col], True)
            GPIO.output(rows[row], False) 


#     while(True):  
#         for row in range(8):
#             GPIO.output(row + 1, True)  
#             for col in range(8): 
#                 if matrix[row][col] == 1:
#                     GPIO.output(col + 1, False) 
#                 else: 
#                     GPIO.output(col + 1, True)
#         timer.sleep(0.001) 

# def draw_face(matrix):
#     while(True): 
#         for row in range(8): 
#             for col in range(8): 
#                 if matrix[row][col] == 1: 
#                     GPIO.output(col + 1, True)
#                     # time.sleep(0.001) 
#                 else: 
#                     GPIO.output(col + 1, False) 
#             GPIO.output(row + 5, True)
#             GPIO.output(row + 5, False) 

#         time.sleep(0.01)
#         for col in range(1, 9):  
#             GPIO.output(col, False)


def show_letter(letter): 
    if letter == "A": 
        GPIO.output(ROW1, True) 
        GPIO.output(ROW2, True) 
        GPIO.output(COL1, True)
        GPIO.output(COL2, True) 
        GPIO.output(COL3, True) 
        GPIO.output(COL5, True) 

    # if letter == "A": 
    #     GPIO.output(COL1, True) 
    #     GPIO.output(COL2, True) 
    #     GPIO.output(ROW1, True)
    #     GPIO.output(ROW2, True) 
    #     GPIO.output(ROW3, True) 
    #     GPIO.output(ROW5, True)


# turn_all_on()     
# show_letter("A")
# while(True): 
# draw_face(down) 
# draw_face(up) 
clear_led() 
print("hello world!") 