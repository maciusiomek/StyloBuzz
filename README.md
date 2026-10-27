<center><h1>StyloBuzz</h1></center>
<h3>Stylophone in a card size!</h3> 
The purpose of this project was to create a cool looking business card. I really liked the <a href="https://mitxela.com/projects/stylocard">StyloCard</a> from Tim Jacobs so I made something like this, but with the ability to use it as a standalone instrument.<br>
<img width="500" height="auto" alt="image" src="https://github.com/user-attachments/assets/2462ca1c-d005-4f06-9061-b3c0277953cd" /><br>
<img width="500" height="auto" alt="image" src="https://github.com/user-attachments/assets/a6187d7d-f327-4ac7-8da0-10aaf30f8b18" />
<hr>
<h2>Features.</h2>
Basically, you just connect the USB C cable and can use it as a standalone instrument. You can also use it as a midi keyboard! There are two buttons on the side that you can use to change the range or add some vibrato (I haven't implemented vibrato to send midi commands, only octave buttons works for now). To play a sound, just connect a crocodile cable to the lighting in the top right corner and touch one of the pads with the other end!
<hr>
<h2>Connections and pricing.</h2>
The project is based around a clone of SparkFun Pro Micro, but not the typical micro USB B one. The pcb is designed around the version with USB C, I just accidentally ordered it some time ago so I just used it for this project. The micro USB B version is a bit shorter and because of that I think that it won't be possible to connect the power to it. Get a one like the one on the photo bellow!

<img width="400" height="auto" alt="0lDjr_tm" src="https://github.com/user-attachments/assets/26939e16-7dbf-44ec-a21c-46552f9c5a5e" />


The parts you'll need to get are listed in the table bellow:
<table>
  <tr>
    <th>Qty</th>
    <th>Part</th>
    <th>Price</th>
  </tr>
  <tr>
    <td>20</td>
    <td>200R resistors</td>
    <td>About $1-1.50 for 100pcs</td>
  </tr>
  <tr>
    <td>3</td>
    <td>1000R resistors</td>
    <td>About $1-1.50 for 100pcs</td>
  </tr>
  <tr>
    <td>1</td>
    <td>Passive buzzer 12x8,5mm</td>
    <td>About $1-1.50</td>
  </tr>
  <tr>
    <td>2</td>
    <td>6x6mm buttons</td>
    <td>About $1-2 for 50 on aliexpress</td>
  </tr>
  <tr>
    <td>1</td>
    <td>StyloBuzz PCB</td>
    <td>$2-5</td>
  </tr>
  <tr>
    <td>1</td>
    <td>SparkFun Pro Micro<br> USB C clone</td>
    <td>About $5 on aliexpress</td>
  </tr>
</table>
Also I don't know if this will be necesary because I haven't got the pcb yet, but I think the 3 caps on the bottom are likely necesary. The ADC pins just go crazy when nothing is connected to them, so I added a place to solder these caps. You should use 0.5-1uF 1206 SMD ceramic caps there to remove the noise on ADC lines.<br>
<br>
The overall price for me with shipping was about $18,50, but I already had the dev board and the buttons, so the price per card is likely about $30.<br>
<br>
<br>
<img width="500" height="auto" alt="ee" src="https://github.com/user-attachments/assets/74aa189b-66ad-4c5d-8206-af90a3fedae3" /><br>
Solder 1K ohm resistors in the place circled in the image above. Everywhere else solder in your 200 ohm resistors. Solder in your dev board, buttons and the buzzer. Boot up your ArduinoIDE and install MIDIUSB library made by Gary Grewal and flash the firmware (StyloBuzz.ino) onto your board (choose Arduino Leonardo)! Congrats, you're done! Enjoy your StyloBuzz stylophone thingy!
<br>
<br>
<br>
Btw, you can add your info (like your name, phone number, etc.) on the back of the PCB! Just import PCB1_StyloBuzz.epro2 to pro.easyeda.com and add an image to the back of your PCB. Remember to select bottom silkscreen as the layer! (also ignore all of the DRC warnings, they show up because I've use an image for the keyboard
<hr>
<h3>Projects and tutorials I used for some help:</h3><br>
https://github.com/guszhang/pcb-stylophone/tree/main<br>
https://projecthub.arduino.cc/pitpietro/midi-piano-keyboard-875eb7<br><br>
<hr>
No AI was used in making of this project.<br>
<img width="150" height="auto" alt="image" src="https://github.com/user-attachments/assets/31fa0a0f-d9f5-445f-b6bf-405257bba26e" />
