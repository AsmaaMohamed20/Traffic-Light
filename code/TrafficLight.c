//Emedded Systems Traning-Traffic light controller

#define red1 portd.b0
#define yellow1 portd.b1
#define green1 portd.b2
#define red2 portd.b3
#define yellow2 portd.b4
#define green2 portd.b5
#define tran1 porta.b0
#define tran2 porta.b1
#define tran3 porta.b2
#define tran4 porta.b3
signed char count1,count2,Mcount;

void main() {
   ADCON1=0x07;
   trisa=0x00;    porta=1;
   trisb=0x00;    portb=0;
   trisc=0x00;    portc=0;
   trisd=0x00;    portd=0;
   trise.B0=1;
   trise.B1=1;

   for(;;){
     if(porte.b0==0){
       portd=0;  porta=1;
       for(count2=5;count2>=0;count2--){
             red1=1; green1=0;  yellow1=0;
             red2=0; green2=1;  yellow2=0;
             porta=0;
             count1=1;
             portc=count1;
             portb=count2;
             delay_ms(1000);
         }

         for(count2=9;count2>=1;count2--){
             porta=0;
             count1=0;
             portc=count1;
             portb=count2;
             delay_ms(1000);
                if(count2==4||count2==3||count2==2||count2==1){
                     green2=0; yellow2=1;
                }
         }
          for(count2=3;count2>=0;count2--){
             red1=0;  green1=1; yellow1=0;
             red2=1;  green2=0; yellow2=0;
             porta=0;
             count1=2;
             portc=count1;
             portb=count2;
             delay_ms(1000);
         }
         for(count2=9;count2>=0;count2--){
             porta=0;
             count1=1;
             portc=count1;
             portb=count2;
             delay_ms(1000);
         }
         for(count2=9;count2>=1;count2--){
             porta=0;
             count1=0;
             portc=count1;
             portb=count2;
             delay_ms(1000);
                if(count2==4||count2==3||count2==2||count2==1){
                     green1=0; yellow1=1;
                }
         }
      }
      else{

        for(;;){
             portd=0;  porta=1;
             if(porte.B1){
                  red1=0;  green1=0; yellow1=1;
                  red2=1;  green2=0; yellow2=0;
                  tran1=0; tran2=0; tran3=1; tran4=1;
                  portb=3;  portc=0;   delay_ms(2000);
                  portb=2;  portc=0;   delay_ms(2000);
                  portb=1;  portc=0;   delay_ms(2000);
                  portb=0; portc=0;
                  tran1=1; tran2=1; tran3=1; tran4=1;
                  red1=1;  green1=0; yellow1=0;
                  red2=0;  green2=1; yellow2=0;
                  while(porte.b1);
             }
              else{
                  red1=1;  green1=0; yellow1=0;
                  red2=0;  green2=0; yellow2=1;
                  tran1=1; tran2=1; tran3=0; tran4=0;
                  portb=3;  portc=0;   delay_ms(2000);
                  portb=2;  portc=0;   delay_ms(2000);
                  portb=1;  portc=0;   delay_ms(2000);
                  portb=0; portc=0;
                  tran1=1; tran2=1; tran3=1; tran4=1;
                  red1=0;  green1=1; yellow1=0;
                  red2=1;  green2=0; yellow2=0;
                  while(porte.B1==0);
             }

          }


      }

   }
}