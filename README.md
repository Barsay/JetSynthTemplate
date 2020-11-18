# JETSON NANO - PORTAUDIO TEMPLATE

My template for audio programming on a nVIDIA Jetson Nano using PortAudio. 
Uses CMAKE.
Created for myself in order to keep record of some hours of research, and I thought I could share this information with the world. Suggestions are very welcome! 
notice: 
Should works on C programs as well just create a new <code>main.c</code>. Works perfectly on CLion.

## Installantion and dependencies check
Disclaimer: the workflow could be messy, redundant or not efficient... But it works on a Jetson Nano and it should work anywhere else. So it's ok for now.
### ALSA
  1. Check if ALSA is installed on your system. If it isn't run <code>sudo apt install alsa-utils</code>
  2. Check if ALSA works typing <code>aplay -vv somefile.wav </code> </br>
  #### Documentation:
  1. Alsa Documentation for troubleshooting: <link>https://www.alsa-project.org/wiki/SoundcardTesting#Rule_of_Thumb</link>
  2. General Alsa documentation: <link>https://www.alsa-project.org/wiki/Documentation</link>
  
 ### PortAudio
  1. clone portAudio from <link>https://github.com/PortAudio/portaudio</link> into a folder
  2. open the cloned folder, type <code>./configure/code>
  3. type <code>cd build</code> (if build doesnt exist, type <code>mkdir build</code> )
  4. type <code>cmake .. -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/lib/portAudio</code>.
  5. type <code>sudo make </code> then <code> make install </code> </br>
  #### Documentation:
  Documentation for troubleshooting: <link>http://portaudio.com/docs/v19-doxydocs/compile_cmake.html</link>, <link>http://portaudio.com/docs/v19-doxydocs/compile_linux.html</link>
  General portaudio documentation  <link>http://portaudio.com/docs/v19-doxydocs/index.html</link></br>
  
  ### Set default soundcard in ALSA + some info about NANO audio devices
  If the following direcotires or files don't appear, you have a problem with your ALSA installation.
  1. type <code>cd /proc/asound</code>. The <code>cards</code> file contains informations about the soundcards that can be used by ALSA.
  2. type <code>cat cards</code> You will see all the devices that can be used. 
    The default devices are:
      <code>[tegrahda       ]</code>, witch is the audio device connected with HDMI output </br>
      <code>[tegrasndt210ref]</code> witch should be the device connected with I2S system (not sure about that....).</br>
      #### Enable a USB plug-and-play audio device, and understanding how soundcards are wired in the Nano </br>
      WARNING: I messed up my asound.conf file doing this. When asound.conf doesn't work, ALSA doesn't work. I am currently trying to find a way to restore the files.
      If you are using an USB pug-and-play sound device, it should appear as well in <code>cards</code>. If it doesn't check if it is correctly installed, and it's compatibility with ALSA
      1. type <code>cd /etc</code>. Here you can find a file called <code>asound.conf</code>. it contains the info for ALSA on how to use the soundcard system in the NANO.
  to change your device to another USB device, copy <code>asound.conf</code> in another folder (somewhere SAFE!) and create a new one. In it type: </br>
  ```
    pcm.!default {
    type hw
    card 2
}

ctl.!default {
    type hw
    card 2
}
```
changhing the number of the card with the one you found in <code>cards</code>.

#### Documentation:
1. Asound.conf settings: (go to "Configuration" chapter)<link><https://wiki.archlinux.org/index.php/Advanced_Linux_Sound_Architecture/link>
_TODO: ADD MORE INFORMATION ON HOW SOUNDCARD ROUTING IS WORKING ON NANO, FIND DOCUMENTATION ON HOW TO CHANGE DEFAULT CARDS WITHOUT DESTROYNG EVERYTHING. MAYBE ADD TO THE REPO THE FILES._
2. ALSA soundcard testing: <link>https://www.alsa-project.org/wiki/SoundcardTesting</link>
3. Some Jetson Nano audio configuration documentation: <link>https://docs.nvidia.com/jetson/l4t/index.html#page/Tegra%20Linux%20Driver%20Package%20Development%20Guide/asoc_driver.18.2.html</link>

## USE IT:
  1. Clone this repo
  2. On line 2 in CMakeLists.txt change <code>-insert projectname here</code> with the name of your project
  (otherise your project will be named "<code>-insert projectname here</code>", lol)
