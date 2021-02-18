/****************************************
Microphone Amplifier
****************************************/
 
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;


// int currentState; example led output
 
void setup() 
{
   Serial.begin(9600);
   
  // pinMode(2, OUTPUT);  example led output
}
 
 
void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  // convert to volts

   Serial.println(volts);



  /* example led output
   if (volts > 2){
    
      if (currentState == 0){
        
        digitalWrite(2, HIGH); // LED ON
        currentState = 1; 
        
        }
        else {
          digitalWrite(2, LOW); // LED OFF
          currentState = 0;
          
          }
    
    }
    */
    

    
}
