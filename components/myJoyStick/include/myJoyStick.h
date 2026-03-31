typedef struct 
{
    int X_value;
    int Y_value;
    
}myJoyStick_t;



void myJoyStick_Setup(int pinX, int pinY, int pinClick);

myJoyStick_t myJoyStick_Read(void);

int myJoyStick_ReadButton(void);


