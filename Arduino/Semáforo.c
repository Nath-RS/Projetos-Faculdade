int g1 = 11; //Led verde semáforo 1
int y1 = 12; //Led amarelo semáforo 1
int r1 = 13; // Led vermelho semáforo 1

int g2 = 10; //Led verde semáforo 2
int y2 = 9; //Led amarelo semáforo 2
int r2 = 8; // Led vermelho semáforo 2

void setup(){
  
pinMode(g1 , OUTPUT);
pinMode(y1 , OUTPUT);
pinMode(r1 , OUTPUT);
pinMode(g2 , OUTPUT);
pinMode(y2 , OUTPUT);
pinMode(r2 , OUTPUT);
    
  
}

void loop(){
  
digitalWrite(g1, HIGH);
digitalWrite(r1, LOW);
digitalWrite(g2, LOW);
digitalWrite(r2, HIGH);
digitalWrite(y1 , LOW);
delay(4000);
  
  
digitalWrite(g1, LOW);
digitalWrite(y1, HIGH);
delay(2000); 
  
for(int x = 0 ; x <5; x++){// Led amarelo piscando
digitalWrite(y1, HIGH);
delay(400);
digitalWrite(y1, LOW);
delay(400);
}
  
  
digitalWrite(g2, HIGH);
digitalWrite(r2, LOW);
digitalWrite(g1, LOW);
digitalWrite(r1, HIGH);
digitalWrite(y1 , LOW);
delay(4000); 
  
  
digitalWrite(g2, LOW);
digitalWrite(y2, HIGH); 
delay(2000); 
  
for(int x = 0 ; x <5; x++){ // Led amarelo piscando
digitalWrite(y2, HIGH);
delay(400);
digitalWrite(y2, LOW);
delay(400);
}
   
}
