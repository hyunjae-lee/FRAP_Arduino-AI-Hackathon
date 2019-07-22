
# FRAP_Arduino-AI-Hackathon
#  Fire Report As soon as Possible
## All-In-One fire extinguisher for automatic reporting and maintenance

 ### Features 
 <p>
  <ol>
    <li> Automatic fire report.</li>
    
    
     Detecting fire extinguisher's weight through a pressure sensor in the box.
    
    
     If the fire extinguisher is off for a certain time, TTS ( Text to Speech ) will be initiated.
    
    
     After passing the certain time, it will notify gas and temperature values at the momenth 
      to users through an application.
      
      
  
  <li> Fire extinguisher maintenance. </li>
  
  
     There is a ON/OFF switch. When maintenance is began, the switch is supposed to be OFF.
    
    
     The switch will be ON after passing the certain maintenance time.
    
    
     As soon as the switch is ON, it will notify the info to the maintenaner.
    
    
  
  <li> Gas and Temperature remote detection. </li>
  
 
     Listening to detecting gas and temperature.
    
    
     If one of them is over its threshold, it will send both data to the main board. 
    
 </ol>

### Details in MAIN BORAD 
<p>
  <ol>
  <li> Listening to SLAVE BOARD through HC-05 </li>

  <li> Detecting fire extinguisher's existence through HC-SR04</li>

  <li> Switching to the maintenance mode that doesn't activate sending notifications through </li>

  <li> Sending notifications automatically if some conditions are satisfied through  </li>
   * conditions [ GAS / TEMPERATURE / PRESSURE ] 
  </ol>
</p>

### Features in SLAVE BOARD
<p>
  <ol>
  <li> Gas detection through FC-22. </li>
  
  <li> Temperature dection through TMP36. </li>
  
  <li> Sending gas and temperature every second to MAIN BOARD through HC-05. </li>
  </ol>
</p>
