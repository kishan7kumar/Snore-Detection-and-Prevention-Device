# Snore Detection and Prevention Device

##   <b>Brief Description</b>

Several studies have shown that snoring is the first symptom of Obstructive Sleep Apnea Syndrome. Snoring has also been reported in the literature as a risk factor in many diseases. ***To demonstrate the concept*** of detecting snoring and controlling it, In this project, we have developed a small-scale system that can detect snoring activity and reduce it by changing the person's head position. Our system uses Arduino Uno, which is a microcontroller based on Atmega1280. The snoring sound is detected by a sound sensor connected to an Arduino board. The sensitivity of this sensor can be controlled by a potentiometer connected to it. A micro air pump is used for changing the head position, which is controlled by an L293D motor driver connected to Arduino and fills the air inside the pillow. An alarm is used to wake up the person if snoring is too loud. 


![image](https://user-images.githubusercontent.com/53033119/148647177-042ce1b8-cfa0-4851-8b2b-5545f520894c.png)

##   <b>Flow of the System:</b>

STEP 1: The device is powered on using 9V DC battery<br/>
STEP 2: After powering on device the sound sensor connected to arduino starts to detect sound pulses from surrounding , the red led and blue led will be on representing power on and sound sensing operation respectively<br/>
STEP 3: If the sound pulse detected by sensor match the desired pulses of snoring activity then the detection process is successful<br/>
STEP 4: Now to stop snoring, the arduino power on the air pump, which inflates the air bag such that the head of the person snoring is lifted upwards. This process opens up the relaxed muscles of the air canal, which causes snoring. Here green led will be turned on to indicate air filling activity<br/>
STEP 5: Suppose the person continues to snore even after changing the head position. In that case, the device raises the alarm to wake the person. Here all led's will start to blink to represent the alarm activity<br/>

##   <b>Limitations & Future Scope:</b>

As snoring is the cause of many sleeping diseases, there is not yet any effective cure for it. The System designed here detects the snoring sound. It changes a person's head position by filling the air inside the pillow. However, ***it is just a concept and has not been tested on a real subject***. It has certain limitations; the sound sensor used here can detect sound from any source. It cannot differentiate the noises which are not snoring coming from the background. This produces an error in the System. So in the future, we can use signal processing techniques that will help us identify snoring sound from the background noises. Additionally, the Air pump used here inflates the airbag, but it can’t deflate, so in the future, we can use a particular motor that can do both the task. Some more advanced sensors can be used to gather more information during snoring activity so that it can be detected more effectively 





