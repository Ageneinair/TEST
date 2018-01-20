#include<Servo.h>
char Input[18];
int b[9]={0,90,82,88,92,90,79,93,83};
Servo E[9];

void Reset() //初始化子程序
{
    E[1].write(90);
    E[5].write(90);
    E[2].write(82);
    E[6].write(79);
    E[3].write(88);
    E[7].write(93);
    E[4].write(92);
    E[8].write(83);
    Serial.println("Reset successfully!");
}

void Turning(int n, int d) //减速转动到目标位置
{
  if (b[n]<d)
  {
    for (int j=b[n]; j<=d; j++)
    {                                        
    E[n].write(j);        
    delay(15);             
    }
  }
  
  if (b[n]>d)
  {
    for (int j=b[n]; j>=d; j--)
    {                                        
    E[n].write(j);        
    delay(15);             
    }
  }
  b[n]=d;
}


void setup() 
{
  for (int i=1; i<=8; i++)
  {
    E[i].attach(i+1);
  }
  Reset();//初始化
  delay(5000);
  Turning(4,125);delay(100);
  Turning(8,108);delay(100);
  Turning(2,150);delay(100);
  Turning(3,130);
  delay(100);Turning(4,92);
  delay(100);Turning(6,130);
  delay(100);Turning(7,110);
  delay(100);Turning(2,110);
  delay(100);Turning(6,150);
  delay(100);Turning(7,115);
  delay(100);Turning(7,130);
  delay(100);Turning(6,165);
  delay(100);Turning(7,140);
  delay(100);Turning(2,120);
  delay(100);Turning(3,140);
  delay(500);Turning(8,83);
  delay(1000);Turning(6,140);
  delay(100);Turning(2,120);
  delay(100);Turning(6,120);
  delay(100);Turning(2,140);
  delay(100);Turning(6,110);
  delay(100);Turning(2,150);
   delay(100);Turning(6,100);
  delay(100);Turning(2,160);
  delay(100);Turning(6,90);
  delay(100);Turning(2,170);
  delay(100);Turning(3,130);
  delay(100);Turning(6,75);
  delay(100);Turning(4,110);
  delay(100);Turning(8,60);
  delay(100);Turning(7,93);
  delay(1000);Turning(4,90);
  delay(1000);Turning(4,70);
  Serial.begin(9600);
  Serial.flush();
  delay(1000);

}

void loop() 
{
  if (Serial.available()>0)
  {
    int index=0;
    delay(100);
    int numChar = Serial.available();
    while(numChar--)
    {
      Input[index++]=Serial.read();
    }
    
    Reading(Input);
  }
}

void Reading(char* data)
{
  Serial.print("Data enterd:");
  Serial.println(data);
  char* parameter;
  parameter=strtok(data," ,");
  int number=strtol(parameter,NULL,10);
  number=constrain(number,0,8);
  parameter=strtok(NULL," ,");
  int degree=strtol(parameter,NULL,10);
  degree=constrain(degree,1,180);
  
  for (int x=0;x<16;x++)
  {
    Input[x]='\0';
  }
  Serial.flush();
  
  if (number == 0)
    {
      Reset();
    }
    else
    {
      Turning(number,degree);
      Serial.println("The Servo have turn to target degree!");
    }
}
