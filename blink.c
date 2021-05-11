#include <wiringPi.h>
#include <stdio.h>

void display(int num);

int main(void){
  int BotLeft=0,BotDown=2,BotRight=3,BotUp=4,BotRes=5,BotSel=6,BotExt=7;
  int rele=21;
  
  int display = 10;
  int estado = 0;
  int pestado = 0;
  int open =3;
  
  wiringPiSetup();
  
  pinMode(BotLeft, INPUT);
  pullUpDnControl(BotLeft, PUD_UP);
  pinMode(BotDown, INPUT);
  pullUpDnControl(BotDown, PUD_UP);
  pinMode(BotRight, INPUT);
  pullUpDnControl(BotRight, PUD_UP);
  pinMode(BotLeft, INPUT);
  pullUpDnControl(BotLeft, PUD_UP);
  pinMode(BotUp, INPUT);
  pullUpDnControl(BotUp, PUD_UP);
  pinMode(BotRes, INPUT);
  pullUpDnControl(BotRes, PUD_UP);
  pinMode(BotSel, INPUT);
  pullUpDnControl(BotSel, PUD_UP);
  pinMode(rele, OUTPUT);
  
  
  while(1) {

   	switch (estado) {
        case 0:
            digitalWrite(rele,0);
            //led1 = false;
            //led2 = false;
            display(10);
            open = digitalRead(BotExt);
            if (open == 0){
            	delay_ms(30);
            	open = digitalRead(BotExt);
            	   if (open == 0){
            			//tira fotos para realizar a comparação
            			//realiza comparação
            			//if (reconhece == true){
            			//	pestado = 1;
            			//} else {
            			//	enviar email;
            			//	pestado = 0;
            			//}
            		}
            }
            break;
        case 1:
            rele = true;
            led1 = false;
            led2 = false;
            display = 10;
            reset = input(GPIOX);
            if (reset == true){
            	delay_ms(30);
            	reset = input(GPIOX);
            	   if (reset == true){
            	   	pestado  = 0;
            	   }
            add = input(GPIOX);
            else if (add == true){
            	delay_ms(30);
            	add = input(GPIOX);
            	   if (add == true){
            			pestado = 2;
            			display = 0;
            		}
            }
            del = input(GPIOX);
            else if (del == true){
            	delay_ms(30);
            	del = input(GPIOX);
            	   if (del == true){
            			pestado = 3;
            			display = 0;
            		}
            }
            break;
        case 2:
            rele = true;
            led1 = true;
            led2 = false;
            display = display;
            reset = input(GPIOX);
            if (reset == true){
            	delay_ms(30);
            	reset = input(GPIOX);
            	   if (reset == true){
            	   	pestado  = 0;
            	   }
            left = input(GPIOX);
            else if (left == true){
            	delay_ms(30);
            	left = input(GPIOX);
            	   if (left == true){
            			if (display == 0){
            				display = display;
            			} else {
            				display--;
            			}
            		}
            }
            right = input(GPIOX);
            else if (right == true){
            	delay_ms(30);
            	right = input(GPIOX);
            	   if (right == true){
            			if (display == 9){
            				display = display;
            			} else {
            				display++;
            			}
            		}
            }
            select = input(GPIOX);
            else if (select == true){
            	delay_ms(30);
            	select = input(GPIOX);
            	   if (select == true){
            			pestado = 4;
            		}
            }
            break;
        case 3:
            rele = true;
            led1 = false;
            led2 = true;
            display = display;
            reset = input(GPIOX);
            if (reset == true){
            	delay_ms(30);
            	reset = input(GPIOX);
            	   if (reset == true){
            	   	pestado  = 0;
            	   }
            left = input(GPIOX);
            else if (left == true){
            	delay_ms(30);
            	left = input(GPIOX);
            	   if (left == true){
            			if (display == 0){
            				display = display;
            			} else {
            				display--;
            			}
            		}
            }
            right = input(GPIOX);
            else if (right == true){
            	delay_ms(30);
            	right = input(GPIOX);
            	   if (right == true){
            			if (display == 9){
            				display = display;
            			} else {
            				display++;
            			}
            		}
            }
            select = input(GPIOX);
            else if (select == true){
            	delay_ms(30);
            	select = input(GPIOX);
            	   if (select == true){

            		}
            }
            break;
        case 4:
            rele = true;
            led1 = true;
            led2 = false;
            display = display;
            delay_ms(1000);
            // tira novas fotos para o usuario cujo id está no display
            // novo aprendizado
            // pestado = 1;
            break;
        case 5:
            rele = true;
            led1 = false;
            led2 = true;
            display = display;
            delay_ms(1000);
            // apaga as fotos do usuario cujo id está no display
            // novo aprendizado
            // pestado = 1;
            break;
        default:
            break;
    	}
    
  return 0;
}
void display(int num){
  int sega=25,segb=29,segc=28,segd=27,sege=26,segf=24,segg=22;
    
  pinMode(sega, OUTPUT);
  pinMode(segb, OUTPUT);
  pinMode(segc, OUTPUT);
  pinMode(segd, OUTPUT);
  pinMode(sege, OUTPUT);
  pinMode(segf, OUTPUT);
  pinMode(segg, OUTPUT);
  
  if(num == NULL) num=10;
  switch (num) {
    case 0:
        digitalWrite(sega,1);
        digitalWrite(segb,1);
        digitalWrite(segc,1);
        digitalWrite(segd,1);
        digitalWrite(sege,1);
        digitalWrite(segf,1);
        digitalWrite(segg,0);
        
        
        break;
    case 1:
        digitalWrite(sega,0);
        digitalWrite(segb,1);
        digitalWrite(segc,1);
        digitalWrite(segd,0);
        digitalWrite(sege,0);
        digitalWrite(segf,0);
        digitalWrite(segg,0);
        
        break;
    case 2:
        digitalWrite(sega,1);
        digitalWrite(segb,1);
        digitalWrite(segc,0);
        digitalWrite(segd,1);
        digitalWrite(sege,1);
        digitalWrite(segf,0);
        digitalWrite(segg,1);
        
        break;
    case 3:
        digitalWrite(sega,1);
        digitalWrite(segb,1);
        digitalWrite(segc,1);
        digitalWrite(segd,1);
        digitalWrite(sege,0);
        digitalWrite(segf,0);
        digitalWrite(segg,1);
       
        break;
    case 4:
        digitalWrite(sega,0);
        digitalWrite(segb,1);
        digitalWrite(segc,1);
        digitalWrite(segd,0);
        digitalWrite(sege,0);
        digitalWrite(segf,1);
        digitalWrite(segg,1);
        
        break;
    case 5:
        digitalWrite(sega,1);
        digitalWrite(segb,0);
        digitalWrite(segc,1);
        digitalWrite(segd,1);
        digitalWrite(sege,0);
        digitalWrite(segf,1);
        digitalWrite(segg,1);
        
        break;
    case 6:
        digitalWrite(sega,1);
        digitalWrite(segb,0);
        digitalWrite(segc,1);
        digitalWrite(segd,1);
        digitalWrite(sege,1);
        digitalWrite(segf,1);
        digitalWrite(segg,1);
        
        break;
    case 7:
        digitalWrite(sega,1);
        digitalWrite(segb,1);
        digitalWrite(segc,1);
        digitalWrite(segd,0);
        digitalWrite(sege,0);
        digitalWrite(segf,0);
        digitalWrite(segg,0);
        
        
        break;
    case 8:
        digitalWrite(sega,1);
        digitalWrite(segb,1);
        digitalWrite(segc,1);
        digitalWrite(segd,1);
        digitalWrite(sege,1);
        digitalWrite(segf,1);
        digitalWrite(segg,1);
       
        break;
    case 9:
        digitalWrite(sega,1);
        digitalWrite(segb,1);
        digitalWrite(segc,1);
        digitalWrite(segd,1);
        digitalWrite(sege,0);
        digitalWrite(segf,1);
        digitalWrite(segg,1);
       
        break;
    default:
        digitalWrite(sega,0);
        digitalWrite(segb,0);
        digitalWrite(segc,0);
        digitalWrite(segd,0);
        digitalWrite(sege,0);
        digitalWrite(segf,0);
        digitalWrite(segg,0);
        
        break;
  }
  
}
